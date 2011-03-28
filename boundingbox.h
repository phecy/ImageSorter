#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <cstdlib>
#include <vector>

#include "vw/InterestPoint.h"

#include "vimage.h"

typedef pair<boundingBox, double> densityBox;

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

class QMainWindow;
class BoundingBox: public QMainWindow
{
public:
    BoundingBox();
    boundingBox getBoundingBox(VImage*);

    // Debug outputs
    void debugPrint(VImage* image, point start, point fin);

private:
    // Get the boolean map of which points are IPs
    boolMap ipMap;
    boolMap getIpMap(VImage*);

    // Each point is the density from that point to (0,0)
    densityMap getTotalIpMap(boolMap&);

    // doubles: what 0<s<1 scale of image to start looking for a max
    // DO NOT CALL WITH ZERO OR ONE, must be strictly within bounds
    densityBox getMaxDensity(const densityMap, double startscale_x,
                                         double startscale_y);

    // PRECONDITION: (start < fin) in both dimensions (x and y)
    double getDensityFrom(densityMap&, point start, point fin);
    int getPtsFrom(densityMap&, point from, point to);
};

#endif // BOUNDINGBOX_H
