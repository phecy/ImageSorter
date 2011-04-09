#include "contrast.h"
#include "vimage.h"

Contrast::Contrast()
{
}

float Contrast::RMS(VImage *vim)
{
    int avgGray = vim->getAvgGray();
    int area = vim->getWidth() * vim->getHeight();
    histogramChannel hist = vim->getHistogramK();

    double sumOfSquareDiffs = 0;

    for(int j=0; j<hist.size(); ++j) {
        double diff = hist[j]*(j - avgGray);
        sumOfSquareDiffs += diff*diff;
    }

    float rms = sqrt(sumOfSquareDiffs);
    printf("  RMS %f   \n",        rms);

    return rms;
}

// XXXX figure out how to scale to be from 0 to 10
