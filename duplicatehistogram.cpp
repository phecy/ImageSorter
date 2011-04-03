#include "duplicatehistogram.h"

#define HIST_SEGMENTS_SIDE 2

#define EDGE_BINS_TO_IGNORE 2

#define HIST_FG_WEIGHT 20

#define MULTIPLIER .05 // more = less tolerant
#define STRICTNESS_K 1.0 * MULTIPLIER
#define STRICTNESS_R 1.0 * MULTIPLIER
#define STRICTNESS_G 2.0 * MULTIPLIER
#define STRICTNESS_B 1.0 * MULTIPLIER

DuplicateHistogram::DuplicateHistogram(DuplicateRater *rater) {
    this->rater = rater;
}

void DuplicateHistogram::addImage(VImage* vim) {
    allHistBins[vim] = histogramSegments();
    int width = vim->getWidth() / HIST_SEGMENTS_SIDE;
    int height = vim->getHeight() / HIST_SEGMENTS_SIDE;

    // For every segment, push back histogram
    for(int x = 0; x < width*HIST_SEGMENTS_SIDE; x+=width) {
        for(int y = 0; y < height*HIST_SEGMENTS_SIDE; y+=height) {
            histogramSet hist = VImage::makeHistograms
                                (vim, x, y, width, height);
            hist = makeBinFrom(hist);
            boundingBox box(point(x, y), point(x+width, y+height));
            allHistBins[vim].push_back(
                histogramOneSegment(hist, box));
        }
    }

    // And overall histogram
    histogramSet fullhist = vim->getHistogram();
    boundingBox fullbox(point(0,0),
                        point(vim->getWidth()-1,vim->getHeight()-1));
    allHistBins[vim].push_back(
        histogramOneSegment(fullhist, fullbox));

    //debugPrint(vim);
}

histogramSet DuplicateHistogram::makeBinFrom(const histogramSet& histograms) {
    // Bins holding multiple pixels
    histogramSet histBins = histogramSet(HNUMCOLORS,
                            histogramChannel(NUM_BINS, 0.0));

    // For every bin,
    for(int bin=0; bin<NUM_BINS; ++bin) {
        int startPixel = bin*PIXELS_PER_BIN;
        int endPixel = startPixel+PIXELS_PER_BIN;
        int leftwindow = startPixel < WINDOW_SIZE ? startPixel : WINDOW_SIZE;
        int rightwindow = endPixel > 255 ? 255 - endPixel : WINDOW_SIZE;

        // Ensure all bins have same # pixels
        leftwindow += WINDOW_SIZE - rightwindow;
        rightwindow += WINDOW_SIZE - leftwindow;

        // For every pixel in the bin
        for(int pixval = startPixel - leftwindow;
                pixval < endPixel + rightwindow;
                ++pixval) {
            // Add each color channel
            for(int c=0; c<HNUMCOLORS; ++c) {
                histBins[c][bin] += histograms[c][pixval];
            }
        }
    }
    return histBins;
}

// Averages similarity of each segment
void DuplicateHistogram::rankOne(VImage* first, VImage* second) {
    int numSets = allHistBins[first].size();
    int totalRanks = 0;
    for(int i=0; i<numSets; ++i) {
        totalRanks += compareHistograms
                      (allHistBins[first][i], allHistBins[second][i],
                       first, second);
    }
    int finalRank = totalRanks / numSets;
    rater->addRanking(first, second, finalRank, DuplicateRater::DUPLICATE_HISTOGRAM);
}

int DuplicateHistogram::compareHistograms(
        histogramOneSegment hist1, histogramOneSegment hist2,
        VImage* vim1, VImage* vim2) {
    const vector<int> oneMeds = vim1->getMedians();
    const vector<int> twoMeds = vim2->getMedians();

    boundingBox box1 = hist1.second;
    boundingBox box2 = hist2.second;

    // Adjust based on exposure diffs
    int adjustments[HNUMCOLORS];
    for(int c=0; c<HNUMCOLORS; ++c) {
        adjustments[c] = oneMeds[c] - twoMeds[c];
    }

    float diffs[HNUMCOLORS] = {0, 0, 0, 0};
    int area = vim1->getWidth() * vim2->getHeight() /
               HIST_SEGMENTS_SIDE*HIST_SEGMENTS_SIDE;
    int fgareaOne =
         vim1->getForeground()->width() * vim1->getForeground()->height();
    int fgareaTwo =
         vim2->getForeground()->width() * vim2->getForeground()->height();
    // Ignore highlights/shadows
    for(int bin=EDGE_BINS_TO_IGNORE;
            bin<NUM_BINS-EDGE_BINS_TO_IGNORE;
            ++bin) {
        for(int c=0; c<HNUMCOLORS; ++c) {
            // More weight to fg
            float weight = 1.0;
            weight += amountInForeground(vim1, box1) / (float)fgareaOne;
            weight += amountInForeground(vim2, box2) / (float)fgareaTwo;
            weight *= HIST_FG_WEIGHT;
            float diff = hist1.first[c][bin] - hist2.first[c][bin];

            // Adjust for exposure diffs if it helps
            diffs[c] += fabs(min(diff,
                                 diff-adjustments[c]/area))
                        * weight;
        }
    }

    int rating = floor(.5 +         // round
                 10.0 - STRICTNESS_K*diffs[HBLACK]
                      - STRICTNESS_R*diffs[HRED]
                      - STRICTNESS_G*diffs[HGREEN]
                      - STRICTNESS_B*diffs[HBLUE]);

//    qDebug("Histogram diff %d vs. %d: KRGB (%.1f,%.1f,%.1f,%.1f)=%d    adjustment: (%d, %d, %d, %d)",
//            vim1->getIndex()+1, vim2->getIndex()+1,
//            diffs[HBLACK], diffs[HRED], diffs[HGREEN], diffs[HBLUE], rating,
//            adjustments[HBLACK], adjustments[HRED],
//            adjustments[HGREEN], adjustments[HBLUE]
//            );

    rating = max(0, rating);

    return rating;
}

int DuplicateHistogram::amountInForeground(VImage* vim, boundingBox box) {
    point fgstart = vim->getForegroundCoords().first;
    point fgend = vim->getForegroundCoords().first;

    if(box.first.first > fgend.first  ||
       box.first.second > fgend.second ||
       box.second.first  < fgstart.first   ||
       box.second.second < fgstart.second)
        return 0;

    int xlen = box.second.first - fgstart.first;
    int ylen = box.second.second - fgstart.second;
    return xlen*ylen;
}

void DuplicateHistogram::debugPrint(VImage* vim, histogramSet hists) {
    int area = vim->getWidth() * vim->getHeight();
    for(int col=0; col<HNUMCOLORS; ++col) {
        cerr << "Printing " <<
                (col==0 ? "black" :
                 col==1 ? "red" :
                 col==2 ? "green" :
                          "blue")
                 << " histogram for image "
                 << vim->getIndex()+1 << endl;
        for(int bin=0; bin<NUM_BINS; ++bin) {
            int size = hists[col][bin]*100;
            cerr << setprecision(2) << bin << ": ";
            for(int i=0; i<size; ++i) {
                cerr << "=";
            }
            cerr << "\n";
        }
    }
}
