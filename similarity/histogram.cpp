#include <iostream>
#include <iomanip>
#include "histogram.h"

#define EDGE_BINS_TO_IGNORE 2

#define MULTIPLIER 5 // more = less tolerant to differences
#define STRICTNESS_K 1.0 * MULTIPLIER
#define STRICTNESS_R 1.0 * MULTIPLIER
#define STRICTNESS_G 2.0 * MULTIPLIER
#define STRICTNESS_B 1.0 * MULTIPLIER

// Averages similarity of each segment
float SimilarityHistogram::calculateSimilarity(const VImage* first,
                                               const VImage* second) {
    float similarity = compareHistograms(first, second);

    return similarity;
}

float SimilarityHistogram::compareHistograms(const VImage* vim1,
                                           const VImage* vim2) {
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

    float rating = floorf(.5 +         // round
                 10.0 - STRICTNESS_K*diffs[HBLACK]
                      - STRICTNESS_R*diffs[HRED]
                      - STRICTNESS_G*diffs[HGREEN]
                      - STRICTNESS_B*diffs[HBLUE]);

    cout << "Diffs: " << diffs[0] << ", " << diffs[1] << ", "
         << diffs[2] << ", " << diffs[3] << endl;
    cout << "Rating: " << rating << endl;

    rating = fmax(0, rating);

    return rating;
}

void SimilarityHistogram::debugPrint(VImage* vim, HistogramSet hists) {
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
