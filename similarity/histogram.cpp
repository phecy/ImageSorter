#include <iostream>
#include <iomanip>
#include "histogram.h"

#define EDGE_BINS_TO_IGNORE 2

#define MULTIPLIER 8.0 // more = less tolerant to differences
#define STRICTNESS_K 0.2 * MULTIPLIER
#define STRICTNESS_R 1.0 * MULTIPLIER
#define STRICTNESS_G 1.5 * MULTIPLIER
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

    HistogramSet hist1 = vim1->getHistogram();
    HistogramSet hist2 = vim2->getHistogram();

    // Initialize
    float diffs[EDGE_BINS_TO_IGNORE*2+1][HNUMCOLORS] = 
                                {{3, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0}};

    // Ignore highlights/shadows
    for(int bin=EDGE_BINS_TO_IGNORE;
            bin<NUM_BINS-EDGE_BINS_TO_IGNORE;
            ++bin) {
        for(int c=0; c<HNUMCOLORS; ++c) {
            // Loop through a potential bin shifts
            for(int offset=-EDGE_BINS_TO_IGNORE;
                    offset <= EDGE_BINS_TO_IGNORE; ++offset) {
                diffs[offset+EDGE_BINS_TO_IGNORE][c] +=
                    fabs(hist1[c][bin+offset] - hist2[c][bin]);
            }
        }
    }

    float rating = 0;
    for(int i=0; i<EDGE_BINS_TO_IGNORE*2+1; ++i) {
        rating = fmax(rating,
                      floorf(MAX_RATING
                          - STRICTNESS_K*diffs[i][HBLACK]
                          - STRICTNESS_R*diffs[i][HRED]
                          - STRICTNESS_G*diffs[i][HGREEN]
                          - STRICTNESS_B*diffs[i][HBLUE]));
    }

    return rating / MAX_RATING;
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
