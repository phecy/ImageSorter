#include "duplicatehistogram.h"

DuplicateHistogram::DuplicateHistogram(DuplicateRater *rater) {
    this->rater = rater;
}

void DuplicateHistogram::addImage(VImage* vim) {
    const float* histogram = vim->getHistogram();
    int numbins = 256 / PIXELS_PER_BIN;
    int histBins[numbins];
    for(int bin=0; bin<numbins; ++bin) {
        histBins[bin] = 0;

        int startPixel = bin*PIXELS_PER_BIN;
        int endPixel = startPixel+PIXELS_PER_BIN;
        int leftwindow = startPixel < WINDOW_SIZE ? startPixel : WINDOW_SIZE;
        int rightwindow = endPixel > 255 ? 255 - endPixel : WINDOW_SIZE;

        // Ensure all bins have same # pixels
        leftwindow += WINDOW_SIZE - rightwindow;
        rightwindow += WINDOW_SIZE - leftwindow;

        for(int pixval = startPixel - leftwindow;
                pixval < endPixel + rightwindow;
                ++pixval) {
            histBins[bin] += histogram[pixval] * 10;
        }
    }
    allHistBins[vim] = histBins;
}

// Adds a single ranking to the DuplicateRater
void DuplicateHistogram::rankOne(VImage* first, VImage* second) {
    int* one = allHistBins[first];
    int* two = allHistBins[second];

    int diff = 0;
    int numbins = 256 / PIXELS_PER_BIN;
    for(int bin=0; bin<numbins; ++bin) {
        //todo: adjust for midgray
        diff += abs(one[bin] - two[bin]);
    }

    //rater->addRanking(first, second, rating, DuplicateRater::DUPLICATE_GAUSSIAN);
}
