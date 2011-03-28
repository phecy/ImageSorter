#include <iostream>

#include "vw/Core.h"
#include "vw/InterestPoint.h"
#include "vw/InterestPoint/Matcher.h"
#include "vw/Image.h"
#include "vw/FileIO.h"

#include "duplicateip.h"
#include "duplicaterater.h"
#include "vimage.h"

#include <stdint.h>

#include "boundingBoxPresets.h"

#define MATCHER_THRESHOLD .6 // from ipmatch.cc
#define MAX_IPS 50

using namespace vw;
using namespace vw::ip;

DuplicateIp::DuplicateIp(DuplicateRater* rater,
                         DuplicateSegmented* segmented)
{
    this->rater = rater;
    foregroundDetect = new BoundingBox();
    foregroundRec = segmented;
}

void DuplicateIp::addImage(VImage* vim) {
    boundingBox fgBox = loadBox(vim);
    if(fgBox.first.first != -1) {
        vim->setForeground(fgBox);
        return;
    }

    DiskImageView<PixelGray<float> > im(vim->getFullpath());

    HarrisInterestOperator interest_op(1e-9, .15);
    ScaledInterestPointDetector<HarrisInterestOperator> detector(interest_op);
    InterestPointList ips = detect_interest_points(im, detector);

    vim->setIp(ips);

    findForeground(vim);
}

void DuplicateIp::findForeground(VImage* vim) {
    // Find bounding box
    boundingBox fgBox = foregroundDetect->getBoundingBox(vim);
    vim->setForeground(fgBox);

    qDebug("else if(strcmp(vim->getFilename(), \"%s\") == 0)\n"
           "      fgBox = boundingBox(point(%d,%d),point(%d,%d));",
           vim->getFilename(), fgBox.first.first,fgBox.first.second,fgBox.second.first,fgBox.second.second);

    // Debug output
    foregroundDetect->debugPrint(vim, fgBox.first, fgBox.second);
    foregroundDetect->show();
}

void DuplicateIp::rankOne(VImage* one, VImage* two) {
    foregroundRec->rankOneForeground(one,two);
}
