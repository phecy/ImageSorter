#include "contrast.h"
#include "vimage.h"

const int local_width = 20;
const int local_height = 20;

Contrast::Contrast()
{
}

float Contrast::RMS(VImage *vim)
{
    int avgGray = vim->getAvgGray() / 255.f;
    QImage* im = vim->getQImage();

    double rms = 0;
    int height = vim->getHeight();
    int width = vim->getWidth();
    for(int x=0; x<width; ++x) {
        for(int y=0; y<height; ++y) {
            float currPixel = qGray(im->pixel(x,y))/255.0; // [0,1]
            rms += pow(currPixel - avgGray, 2);
        }
    }

    rms /= width*height;
    rms = sqrt(rms);
    // printf("%f\n",        rms);

    return rms;
}

sumMap* Contrast::makeGraySumMap(VImage* vim) {
    QImage* qimage = vim->getQImage();
    int width = qimage->width();
    int height = qimage->height();

    sumMap* densityMap = new sumMap();

    for(int y=0; y<height; ++y) {
        vector<unsigned long int> row(width);
        densityMap->push_back(row);
        for(int x=0; x<width; ++x) {
            unsigned long int currSum =
                  qGray(qimage->pixel(x, y));
            if(y > 0) {
                currSum +=
                  (*densityMap)[y][max(x-1, 0)]
                + (*densityMap)[max(y-1, 0)][x]
                - (*densityMap)[max(y-1, 0)][max(x-1, 0)];
            }

            (*densityMap)[y][x] = currSum;
        }
    }

    return densityMap;
}

int Contrast::local_mid_grey(sumMap* graySumMap, int width, int height, int x, int y)
{
    int starty = max(y-height/2, 0);
    int endy   = min(y+height/2, (int)graySumMap->size());
    int startx = max(x-width/2, 0);
    int endx   = min(x+width/2, (int)graySumMap[0].size());

    int area = (1+endy-starty) * (1+endx-startx);

    unsigned long totalGray =
         (*graySumMap)[endy][endx]
       + (*graySumMap)[starty][startx]
       - (*graySumMap)[starty][endx]
       - (*graySumMap)[endy][startx];

    return totalGray / (area+1);
}


float Contrast::local_contrast(VImage *vim)
{
    QImage* qimage = vim->getQImage();
    int area = qimage->width() * qimage->height();
    int diff = 0;

    sumMap* graySumMap = makeGraySumMap(vim);

    // Make histogram
    for(int h=0; h<qimage->height() - local_height; ++h) {
        for(int w=0; w<qimage->width() - local_width; ++w) {
            int grey = qGray(qimage->pixel(w, h));
            int local_grey = local_mid_grey(graySumMap, local_width, local_height, w, h);
            diff += abs(grey - local_grey);
        }

    }

    delete graySumMap;

    return (diff/255.f)/area;

}
