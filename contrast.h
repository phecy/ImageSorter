#ifndef CONTRAST_H
#define CONTRAST_H

#include "vimage.h"

class Contrast
{
public:
    Contrast();
    float RMS(VImage *vim);
    float local_contrast(VImage *vim);
    int local_mid_grey(VImage *vim, int width, int height, int x, int y);
    int derivative(VImage *vim, int x, int y);
};

#endif // CONTRAST_H
