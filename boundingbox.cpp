#include <QLabel>

#include "boundingbox.h"

#define MIN_FOREGROUND_SIZE .2 // how much of image
#define STEP_SIZE .05 // distance between starting points

BoundingBox::BoundingBox()
{
}

boundingBox BoundingBox::getBoundingBox(QImage* qim, InterestPointList ips) {
    ipMap = getIpMap(qim, ips);
    densityMap totalIpMap = getTotalIpMap(ipMap);

    // Get max bounding box
    densityBox maxDensityBox =
            densityBox(boundingBox(point(-1,-1),point(-1,-1)),-1);
    for(double start = .01; start < 1-MIN_FOREGROUND_SIZE; start+=STEP_SIZE) {
        densityBox currDensityBox = getMaxDensity(totalIpMap, start, start);
        //qDebug("Density at %d\%=%f", (int)(start*100), currDensityBox.second);
        if(currDensityBox.second > maxDensityBox.second)
            maxDensityBox = currDensityBox;
    }
    boundingBox box = maxDensityBox.first;

//    qDebug("We find box ((%d, %d),(%d,%d)) to be the most interesting!",
//            box.first.first, box.first.second,
//            box.second.first, box.second.second);

    return box;
}

boolMap BoundingBox::getIpMap(QImage* qim, InterestPointList& ips) {
    boolMap ipMap(qim->height(),vector<bool>(qim->width(), false));

    InterestPointList::iterator ip = ips.begin();
    for(; ip != ips.end(); ++ip) {
        ipMap.at(ip->y).at(ip->x) = true;
    }

    return ipMap;
}

densityMap BoundingBox::getTotalIpMap(boolMap& ipMap) {
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

int BoundingBox::getPtsFrom(densityMap& totalIpMap,
                                point start, point fin) {
    int finx = fin.first;
    int finy = fin.second;
    int distx = finx - start.first + 1;
    int disty = finy - start.second + 1;

    int numPts;
    numPts = totalIpMap[finy][finx].numPts;
    if(finy-disty >= 0)
        numPts -= totalIpMap[finy-disty][finx      ].numPts;
    if(finx-distx >= 0)
        numPts -= totalIpMap[finy      ][finx-distx].numPts;
    if(finx-distx >= 0 && finy-disty >= 0)
        numPts += totalIpMap[finy-disty][finx-distx].numPts;

    return numPts;
}

double BoundingBox::getDensityFrom(densityMap& totalIpMap,
                                point start, point fin) {
    int numpts = getPtsFrom(totalIpMap, start, fin);
    int area =
            (fin.first - start.first + 1) *
            (fin.second - start.second + 1);

    double density = (double)numpts/area;
    return density;
}

densityBox BoundingBox::getMaxDensity(densityMap totalIpMap,
                              double startx_scale, double starty_scale) {
    boundingBox maxDensityBox;
    double maxDensityVal = 0;

    int height = totalIpMap.size();
    int width = totalIpMap[0].size();

    // Create starting point
    int starty = height * starty_scale;
    int startx = width * startx_scale;
    point startpt = point(startx, starty);

    // Create border of bad densities

    // Create row of starting densities
//    for(int x=startx; x<width; ++x) {
//        densityNode startnode;
//        startnode.area = x+1-startx;
//        startnode.startPoint = startpt;
//        startnode.endPoint = point(x, starty);
//        startnode.numPts = getDensityFrom(totalIpMap,
//                                          startpt, startnode.endPoint);

//        totalIpMap[starty][x] = startnode;
//    }

    int minarea = width * height * MIN_FOREGROUND_SIZE;

    // Run density map max-finder
    for(int h=starty; h<height; ++h) {
        for(int w=startx; w<width; ++w) {
            int area = ((w - startx) * (h - starty));

            densityNode includeCurr = totalIpMap[h][w];
            densityNode ignoreCurr = totalIpMap[h-1][w-1];

            double includePtDensity = getDensityFrom(totalIpMap, startpt,
                                                includeCurr.endPoint);

            double ignorePtDensity = getDensityFrom(totalIpMap, startpt,
                                                ignoreCurr.endPoint);


            // Is max? Include even if better to ignore point.
            // (Because sometimes ignoring is always better...want to
            // have at least one point)
            if(includePtDensity > maxDensityVal && area > minarea) {
                // New maximum of an appropriate size!
                maxDensityBox = boundingBox(startpt, point(w,h));
                maxDensityVal = includePtDensity;
                //qDebug("Found new max rating, %f at ((%d,%d)(%d,%d))!",
                //       includePtDensity, startx, starty, w, h);
            }

            // Is including this point beneficial?
            if(includePtDensity >= ignorePtDensity) {
                // Add current point to [h-1][w-1] and insert here
                densityNode currNode;
                currNode.startPoint = startpt;
                currNode.endPoint = point(w,h);
                currNode.area = area;

                currNode.numPts = getDensityFrom(totalIpMap, startpt, currNode.endPoint);
            } else {
                // Ignore current point and keep [h-1][w-1]
                totalIpMap[h][w] = totalIpMap[h-1][w-1];
            }
        }
    }

    return densityBox(maxDensityBox, maxDensityVal);
}

void BoundingBox::debugPrint(QImage* image, point start, point fin) {
    int width = ipMap[0].size();
    int height = ipMap.size();
    QImage i = QImage(width, height, QImage::Format_RGB32);

    // IPs
    for(int w=4; w<width-4; w++) {
        for(int h=4; h<height-4; h++) {
            if(!ipMap[h][w]) {
                i.setPixel(w, h, image->pixel(w,h));
            } else {
                for(int x=-4; x<=4; ++x) {
                    for(int y=-4; y<=4; ++y) {
                        i.setPixel(w-x, h-y, qRgb(0,255,0));
                    }
                }
            }
        }
    }

    for(int w=start.first; w<fin.first; w++) {
        i.setPixel(w, start.second, qRgb(0,255,0));
        i.setPixel(w, fin.second, qRgb(0,255,0));
    }
    for(int h=start.second; h<fin.second; h++) {
        i.setPixel(start.first, h, qRgb(0,255,0));
        i.setPixel(fin.first, h, qRgb(0,255,0));
    }

    QLabel* imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(QPixmap::fromImage(i));

    setCentralWidget(imageLabel);

    int w = width > 600 ? 600 : width;
    int h = width > 600 ? (int)(600/(double)width * height) : height;
    resize(w, h);

    imageLabel->show();
}
