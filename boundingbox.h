#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <cstdlib>
#include <vector>

#include "vw/InterestPoint.h"

#include "vimage.h"

using namespace std;
struct densityNode;
typedef vector<vector<bool> > boolMap;
typedef vector<vector<densityNode> > densityMap;

// Describes the density of some region
// of an ipMap. The density is numPts/area
struct densityNode {
    // The start and finish of the boundingbox
    // Not necessarily at this index
    point startPoint;
    point endPoint;

    // The area from startpoint to endpoint
    int area;

    // Number of interestpoints in there
    int numPts;
};

class BoundingBox
{
public:
    BoundingBox();
    boundingBox getBoundingBox(QImage* qim, InterestPointList ips);

private:
    boolMap getIpMap(QImage* qim, InterestPointList ips);
    densityMap getTotalIpMap(boolMap);
    boundingBox getMaxDensity(densityMap);
};

#endif // BOUNDINGBOX_H
