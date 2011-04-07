#include "contrast.h"
#include "vimage.h"

contrast::contrast()
{
}

float contrast::RMS(VImage *vim)
{
    int avgGray = vim->getAvgGray();
    int area = vim->getWidth() * vim->getHeight();
    histogramChannel hist = vim->getHistogramK();

    unsigned long long int sumOfSquareDiffs = 0;
    for(int i=0; i<hist.size(); ++i) {
        int diff = (hist[i]*(float)area) * (i - avgGray);
        sumOfSquareDiffs += diff*diff;
    }
    sumOfSquareDiffs /= area;

    float rms = sqrt(sumOfSquareDiffs);

    int rank = rms;

    return rms;
}
