#include "contrast.h"
#include "vimage.h"

const int local_width = 20;
const int local_height = 20;

Contrast::Contrast()
{
}

float Contrast::RMS(VImage *vim)
{
    int avgGray = vim->getAvgGray();
   // int area = vim->getWidth() * vim->getHeight();
    histogramChannel hist = vim->getHistogramK();

    double sumOfSquareDiffs = 0;

    for(int j=0; j<hist.size(); ++j) {
        double diff = hist[j]*(j - avgGray);
        sumOfSquareDiffs += diff*diff;
    }

    float rms = sqrt(sumOfSquareDiffs);
    printf("%f\n",        rms);

    return rms;
}


int Contrast::local_mid_grey(VImage *vim, int width, int height, int x, int y)
{
    QImage* qimage = vim->getQImage();
    int grey = 0;
    int cnt = 0;

    // Make histogram
    for(int h=max(y-height/2, 0);   h<min(height/2+y, qimage->height()); ++h) {
        for(int w=max(x-width/2,0); w<min(width/2+x,qimage->width());    ++w) {
            QRgb color = qimage->pixel(w, h);
            grey += qGray(color);
            cnt++;
        }
    }
    grey = grey/cnt;
    return grey;
}

int Contrast::derivative(VImage *vim, int x, int y)
{

    int w=0;
}


float Contrast::local_contrast(VImage *vim)
{
    QImage* qimage = vim->getQImage();
    int area = qimage->width() * qimage->height();
    int diff = 0;

    // Make histogram
    for(int h=0; h<qimage->height(); ++h) {
        for(int w=0; w<qimage->width(); ++w) {
            QRgb color = qimage->pixel(w, h);
            int grey = qGray(color);
            int local_grey = local_mid_grey(vim, local_width, local_height, w, h);
            diff += abs(grey - local_grey);

       //     printf("grey %d    local_mid %d      diff %d\n", grey, local_grey, diff);
        }

    }


    printf("local contrast = %d \n", diff);

    return diff/area;

}

// XXXX figure out how to scale to be from 0 to 10
