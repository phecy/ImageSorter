#include "duplicatehistogram.h"

#define STRICTNESS 5 // more = less tolerant

DuplicateHistogram::DuplicateHistogram(DuplicateRater *rater) {
    this->rater = rater;
}

void DuplicateHistogram::addImage(VImage* vim) {
    const vector<float> histogramK = vim->getHistogramK();
    const vector<float> histogramR = vim->getHistogramR();
    const vector<float> histogramG = vim->getHistogramG();
    const vector<float> histogramB = vim->getHistogramB();
    float* histBins = new float[NUM_BINS];
    for(int bin=0; bin<NUM_BINS; ++bin) {
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
            histBins[bin] += histogramK[pixval];
        }
    }
    allHistBins[vim] = histBins;
}

// Adds a single ranking to the DuplicateRater
void DuplicateHistogram::rankOne(VImage* first, VImage* second) {
    float* one = allHistBins[first];
    float* two = allHistBins[second];

    float diff = 0;
    for(int bin=0; bin<NUM_BINS; ++bin) {
        //todo: adjust for midgray
        // also multiple channels
        diff += fabs(one[bin] - two[bin]);
    }
    //qDebug("Histogram diff: %f", diff);

    int rating = 10 - STRICTNESS*diff;

    rater->addRanking(first, second, rating, DuplicateRater::DUPLICATE_HISTOGRAM);
}
