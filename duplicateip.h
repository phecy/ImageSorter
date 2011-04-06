#ifndef DUPLICATEIP_H
#define DUPLICATEIP_H

#include "vw/Core.h"
#include "vw/InterestPoint.h"
#include "vw/Image.h"
#include "vw/FileIO.h"

#include "duplicaterater.h"
#include "duplicatesegmented.h"
#include "duplicaterater.h"
#include "boundingbox.h"
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
    void findForeground(VImage* im);
    void cleanIps(InterestPointList ip, VImage* image);
    vector<InterestPoint> ipList;

    // Bounding Box finder and matcher
    boundingBox loadBox(VImage* vim); // pre-loaded images
    BoundingBox* foregroundDetect;
};

#endif // DUPLICATEIP_H
