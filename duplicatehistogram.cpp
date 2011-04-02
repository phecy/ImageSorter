#include "duplicatehistogram.h"

#define HIST_SEGMENTS_SIDE 5

#define MULTIPLIER .4 // more = less tolerant
#define STRICTNESS_K 1.0 * MULTIPLIER
#define STRICTNESS_R 1.0 * MULTIPLIER
#define STRICTNESS_G 2.0 * MULTIPLIER
#define STRICTNESS_B 1.0 * MULTIPLIER

DuplicateHistogram::DuplicateHistogram(DuplicateRater *rater) {
    this->rater = rater;
}

void DuplicateHistogram::addImage(VImage* vim) {
    allHistBins[vim] = vector<histogramSet>();
    int width = vim->getWidth() / HIST_SEGMENTS_SIDE;
    int height = vim->getHeight() / HIST_SEGMENTS_SIDE;

    for(int x = 0; x < width*HIST_SEGMENTS_SIDE; x+=width) {
        for(int y = 0; y < height*HIST_SEGMENTS_SIDE; y+=height) {
            histogramSet hist = VImage::makeHistograms
                                (vim, x, y, width, height);
            allHistBins[vim].push_back(makeBinFrom(hist));
        }
    }

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
        totalRanks += compareHistograms(allHistBins[first][i],
                                        allHistBins[second][i],
                                        first, second);
    }
    int finalRank = totalRanks / numSets;
    rater->addRanking(first, second, finalRank, DuplicateRater::DUPLICATE_HISTOGRAM);
}

int DuplicateHistogram::compareHistograms(histogramSet one, histogramSet two,
                                         VImage* first, VImage* second) {
    const vector<int> oneMeds = first->getMedians();
    const vector<int> twoMeds = second->getMedians();

    // Adjust based on exposure diffs
    // Idea: just shift bins
    int adjustments[HNUMCOLORS];
    for(int c=0; c<HNUMCOLORS; ++c) {
        adjustments[c] = oneMeds[c] - twoMeds[c];
    }

    float diffs[HNUMCOLORS] = {0, 0, 0, 0};
    // Ignore highlights/shadows
    for(int bin=1; bin<NUM_BINS-1; ++bin) {
        for(int c=0; c<HNUMCOLORS; ++c) {
            diffs[c] += fabs(one[c][bin] - two[c][bin]
                            - adjustments[c]*NUM_BINS/256);
        }
    }

    int rating = floor(.5 +         // round
                 10.0 - STRICTNESS_K*diffs[HBLACK]
                      - STRICTNESS_R*diffs[HRED]
                      - STRICTNESS_G*diffs[HGREEN]
                      - STRICTNESS_B*diffs[HBLUE]);

    qDebug("Histogram diff %d vs. %d: KRGB (%.1f,%.1f,%.1f,%.1f)=%d    adjustment: (%d, %d, %d, %d)",
            first->getIndex()+1, second->getIndex()+1,
            diffs[HBLACK], diffs[HRED], diffs[HGREEN], diffs[HBLUE], rating,
            adjustments[HBLACK], adjustments[HRED],
            adjustments[HGREEN], adjustments[HBLUE]
            );

    rating = max(0, rating);

    return rating;
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
