#ifndef SIMILARITYHISTOGRAM_H
#define SIMILARITYHISTOGRAM_H

#include "vimage.h"

#define PIXELS_PER_BIN 16 // divides 256
#define NUM_BINS (256 / PIXELS_PER_BIN)
#define WINDOW_SIZE 10 // add how many pixels to
                       // each bin on either side

using namespace std;

class SimilarityHistogram
{
public:
    SimilarityHistogram(vector<VImage*> allImages);

    // Adds a single ranking to the SimilarityRater
    float calculateSimilarity (VImage* first, VImage* second);

private:
    // Throw groups of pixels into bins, with some pixels in
    // multiple bins
    void addImage(VImage*);

    // Compares two partial histograms
    int compareHistograms(VImage* first, VImage* second);

    void debugPrint(VImage* vim, HistogramSet);
};
#endif // SIMILARITYHISTOGRAM_H
