#include <iostream>

#include "vw/Core.h"
#include <vw/Image/PixelTypeInfo.h>
#include "vw/InterestPoint.h"
#include "vw/InterestPoint/Detector.h"
#include "vw/Image.h"
#include "vw/FileIO.h"

#include "duplicateip.h"
#include "duplicaterater.h"
#include "vimage.h"

#include <stdint.h>

using namespace vw;
using namespace vw::ip;

DuplicateIp::DuplicateIp(DuplicateRater* rater)
{
    this->rater = rater;
}

void DuplicateIp::addImage(VImage vim) {
    VImage_t* im = vim.getVImage();


    //*im = gaussian_filter( *im, 3.0, ConstantEdgeExtension());
    //im = im+im;
}
