#ifndef CONTRAST_H
#define CONTRAST_H

#include "vimage.h"

class Contrast
{
public:
    Contrast();
    float RMS(VImage *vim);
};

#endif // CONTRAST_H
