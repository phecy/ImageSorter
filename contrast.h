#ifndef CONTRAST_H
#define CONTRAST_H

#include "vimage.h"

class contrast
{
public:
    contrast();
    float RMS(VImage *vim);
};

#endif // CONTRAST_H