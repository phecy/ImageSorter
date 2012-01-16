#ifndef DUPLICATEHISTOGRAM_H
#define DUPLICATEHISTOGRAM_H

#include "duplicates/rater.h"
#include "vimage.h"

#define PIXELS_PER_BIN 16 // divides 256
#define NUM_BINS (256 / PIXELS_PER_BIN)
#define WINDOW_SIZE 10 // add how many pixels to
                       // each bin on either side

using namespace std;

class DuplicateHistogram
{
public:
    DuplicateHistogram(DuplicateRater *rater);

    // Throw groups of pixels into bins, with some pixels in
    // multiple bins
    void addImage(VImage*);

    // Adds a single ranking to the DuplicateRater
    void rankOne(VImage*, VImage*);

private:
    // Compares two partial histograms
    int compareHistograms(VImage* first, VImage* second);

    DuplicateRater* rater;

    void debugPrint(VImage* vim, HistogramSet);
};
#endif // DUPLICATEHISTOGRAM_H
