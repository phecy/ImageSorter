#ifndef EXPOSURE_H
#define EXPOSURE_H

#include <QImage>
#include <vimage.h>

class exposure
{
public:
    exposure();
    float expose(VImage *im);
};

#endif // EXPOSURE_H
