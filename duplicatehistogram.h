#ifndef DUPLICATEHISTOGRAM_H
#define DUPLICATEHISTOGRAM_H

#include "duplicaterater.h"
#include "vimage.h"

#define PIXELS_PER_BIN 16 // divides 256
#define NUM_BINS (256 / PIXELS_PER_BIN)
#define WINDOW_SIZE 10 // add how many pixels to
                       // each bin on either side

using namespace std;

typedef pair<histogramSet, boundingBox> histogramOneSegment;
typedef vector<histogramOneSegment> histogramSegments;

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
    // Pushes bin from param to allHistBins
    histogramSet makeBinFrom(const histogramSet& histograms);

    // Compares two partial histograms
    int compareHistograms
        (histogramOneSegment one, histogramOneSegment two,
         VImage* first, VImage* second);

    DuplicateRater* rater;

    map<VImage*, histogramSegments> allHistBins;

    void debugPrint(VImage* vim, histogramSet);
};
#endif // DUPLICATEHISTOGRAM_H
