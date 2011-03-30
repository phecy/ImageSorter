#ifndef DUPLICATEHISTOGRAM_H
#define DUPLICATEHISTOGRAM_H

#include "duplicaterater.h"
#include "vimage.h"

#define PIXELS_PER_BIN 32 // divides 256
#define NUM_BINS 256 / PIXELS_PER_BIN
#define WINDOW_SIZE 10 // add how many pixels to
                       // each bin on either side

using namespace std;

class DuplicateHistogram
{
public:
    DuplicateHistogram(DuplicateRater *rater);

    // Creates a histogram
    void addImage(VImage*);

    // Adds a single ranking to the DuplicateRater
    void rankOne(VImage*, VImage*);

private:
    DuplicateRater* rater;

    map<VImage*, float*> allHistBins;
};
#endif // DUPLICATEHISTOGRAM_H
