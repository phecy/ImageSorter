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

using namespace vw;
using namespace vw::ip;

DuplicateIp::DuplicateIp(DuplicateRater* rater)
{
    this->rater = rater;
}

void DuplicateIp::addImage(VImage* vim) {
    VImage_t* im = vim->getVImage();

    ScaledInterestPointDetector<LogInterestOperator> detector;
    InterestPointList ips = detect_interest_points(*im, detector);
    vim->setIp(ips);

    // PatchDescriptorGenerator gen;
    // gen.compute_descriptor(*im, im->begin(), im->end());

    //*im = gaussian_filter( *im, 3.0, ConstantEdgeExtension());
    //im = im+im;
}

void DuplicateIp::rankOne(VImage* one, VImage* two) {
    InterestPointList match1, match2;
    InterestPointList onelist = one->getIp();
    InterestPointList twolist = two->getIp();

    // matcher(onelist, twolist, match1, match2); fuck this function
    qDebug("DuplicateIP: Match1 size=%d, Match2 size=%d", match1.size(), match2.size());
}
