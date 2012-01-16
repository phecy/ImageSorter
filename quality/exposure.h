#ifndef EXPOSURE_H
#define EXPOSURE_H

#include <QImage>
#include <vimage.h>

class Exposure
{
public:
    Exposure();
    float rate(VImage *im);
};

#endif // EXPOSURE_H
