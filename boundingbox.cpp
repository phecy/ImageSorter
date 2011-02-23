#include "boundingbox.h"

BoundingBox::BoundingBox()
{
}

boundingBox BoundingBox::getBoundingBox(QImage* qim, InterestPointList ips) {
    boolMap ipMap = getIpMap(qim, ips);
    densityMap totalIpMap = getTotalIpMap(ipMap);
    boundingBox box = getMaxDensity(totalIpMap);

    qDebug("We find box ((%d, %d),(%d,%d)) to be the most interesting!",
            box.first.first, box.first.second,
            box.second.first, box.second.second);

    return box;
}

boolMap BoundingBox::getIpMap(QImage* qim, InterestPointList ips) {
    boolMap ipMap(qim->height(),vector<bool>(qim->width(), false));

    InterestPointList::iterator ip = ips.begin();
    for(; ip != ips.end(); ++ip) {
        ipMap.at(ip->y).at(ip->x) = true;
    }

    return ipMap;
}

densityMap BoundingBox::getTotalIpMap(boolMap ipMap) {
    int height = ipMap.size();
    int width = ipMap[0].size();

    densityMap totalIpMap(height, vector<densityNode>(width));
    // Create density map with everything starting at (0,0)
    for(int h=0; h<height; ++h) {
        int rowcount = 0;
        for(int w=0; w<width; ++w) {
            if(ipMap[h][w]) ++rowcount;

            densityNode node;
            node.area = w * h;
            node.startPoint = pair<int,int>(0,0);
            node.endPoint = pair<int,int>(w,h);
            node.numPts = rowcount + (h > 0 ? totalIpMap[h-1][w].numPts : 0);

            totalIpMap[h][w] = node;
        }
    }

    return totalIpMap;
}

boundingBox BoundingBox::getMaxDensity(densityMap totalIpMap) {
    boundingBox maxDensityBox;
    int maxDensityVal;

    int height = totalIpMap.size();
    int width = totalIpMap[0].size();

    // Window size of 20% of the image
    int window_h = height * .2;
    int window_w = width * .2;

    // Run density map max-finder
    for(int h=window_h; h<height; ++h) {
        for(int w=window_w; w<width; ++w) {
            densityNode includeCurr = totalIpMap[h][w];
            densityNode ignoreCurr = totalIpMap[h-1][w-1];

            if(includeCurr.numPts/includeCurr.area >
               ignoreCurr.numPts/ignoreCurr.area) {
                // Add current point to [h-1][w-1] and insert here
                int startw = includeCurr.startPoint.first;
                int starth = includeCurr.startPoint.second;

                densityNode currNode;
                currNode.startPoint = includeCurr.startPoint;
                currNode.endPoint = point(w,h);
                currNode.area = (w - startw *
                                 h - starth);

                currNode.numPts = totalIpMap[h][w].numPts
                                - totalIpMap[starth-1][w].numPts
                                - totalIpMap[h][startw-1].numPts
                                + totalIpMap[h-1][w-1].numPts;

                // Is max?
                int densityVal = currNode.numPts / currNode.area;
                if(densityVal > maxDensityVal) {
                    // New maximum!
                    maxDensityBox = boundingBox(currNode.startPoint, currNode.endPoint);
                    maxDensityVal = densityVal;
                }
            } else {
                // Ignore current point and keep [h-1][w-1]
                totalIpMap[h][w] = totalIpMap[h-1][w-1];
            }
        }
    }

    return maxDensityBox;
}
