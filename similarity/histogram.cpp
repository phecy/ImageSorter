#include <iostream>
#include <iomanip>
#include "duplicates/histogram.h"

#define EDGE_BINS_TO_IGNORE 2

#define MULTIPLIER .08 // more = less tolerant to differences
#define STRICTNESS_K 1.0 * MULTIPLIER
#define STRICTNESS_R 1.0 * MULTIPLIER
#define STRICTNESS_G 2.0 * MULTIPLIER
#define STRICTNESS_B 1.0 * MULTIPLIER

DuplicateHistogram::DuplicateHistogram(vector<VImage*> allImages) {
}

void DuplicateHistogram::addImage(VImage* vim) {
    // Nothing to do; it's contained in VImage already
}

// Averages similarity of each segment
float DuplicateHistogram::getSimilarity(VImage* first, VImage* second) {
    int similarity = compareHistograms(first, second);

    return similarity;
}

int DuplicateHistogram::compareHistograms(VImage* vim1, VImage* vim2) {
    const vector<int> oneMeds = vim1->getMedians();
    const vector<int> twoMeds = vim2->getMedians();

    // Adjust based on exposure diffs
    int adjustments[HNUMCOLORS];
    for(int c=0; c<HNUMCOLORS; ++c) {
        adjustments[c] = oneMeds[c] - twoMeds[c];
    }

    HistogramSet hist1 = vim1->getHistogram();
    HistogramSet hist2 = vim2->getHistogram();

    // Initialize
    float diffs[HNUMCOLORS] = {0, 0, 0, 0};
    int area = vim1->getWidth() * vim2->getHeight();

    // Ignore highlights/shadows
    for(int bin=EDGE_BINS_TO_IGNORE;
            bin<NUM_BINS-EDGE_BINS_TO_IGNORE;
            ++bin) {
        for(int c=0; c<HNUMCOLORS; ++c) {
            float diff = hist1[c][bin] - hist2[c][bin];

            // Adjust for exposure diffs if it helps
            diffs[c] += fabs(min(diff,
                                 diff-adjustments[c]/area));
        }
    }

    int rating = floor(.5 +         // round
                 10.0 - STRICTNESS_K*diffs[HBLACK]
                      - STRICTNESS_R*diffs[HRED]
                      - STRICTNESS_G*diffs[HGREEN]
                      - STRICTNESS_B*diffs[HBLUE]);

    rating = max(0, rating);

    return rating;
}

void DuplicateHistogram::debugPrint(VImage* vim, HistogramSet hists) {
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
