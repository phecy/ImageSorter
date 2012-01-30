#ifndef CONTRAST_H
#define CONTRAST_H

#include "vimage.h"

typedef vector<vector<unsigned long int> > sumMap;

class Contrast
{
public:
    Contrast();
    float RMS(VImage *vim);
    float local_contrast(VImage *vim);
    sumMap* makeGraySumMap(VImage* vim);
    int local_mid_grey(sumMap*, int width, int height, int x, int y);
};

#endif // CONTRAST_H
