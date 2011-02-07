#ifndef DUPLICATEIP_H
#define DUPLICATEIP_H

#include "vw/Core.h"
#include "vw/InterestPoint.h"
#include "vw/Image.h"
#include "vw/FileIO.h"
#include "duplicaterater.h"
#include "vimage.h"

using namespace vw;
using namespace vw::ip;

class DuplicateIp
{
public:
    DuplicateIp(DuplicateRater* rater);
    void addImage(VImage*);
    void rankOne(VImage*, VImage*);

private:
    DuplicateRater* rater;
    vector<InterestPointList> ipList;
    InterestPointMatcher<RelativeEntropyMetric,ScaleOrientationConstraint> matcher;
};

#endif // DUPLICATEIP_H
