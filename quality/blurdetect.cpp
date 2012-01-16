/*
This file is part of ppm.

    ppm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ppm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ppm.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QImage>
#include <QLabel>
#include "assert.h"
#include "blurdetect.h"
#include "stdio.h"
#include "math.h"

#define PI 3.142

#define MIN_NUM_IPS 4
#define LOOK_FOR_CONTRAST_RADIUS 10
#define SENSITIVITY_THRESHOLD 96
#define EDGE_SIZE 5
#define DIST_BETWEEN_EDGES 20
#define ANGLE_CONSTITUTING_SHARPNESS 30
#define GOAL_EDGE_WIDTH 3
#define EDGE_WIDTH_PENALTY 1.2

#define UNSHARP_PENALTY 1.6
#define ANGLE_LENIENCY 400.0


// Result calc thresholds
#define BAD_ANGLE_THRESHOLD 4.0
#define GOOD_EDGE_THRESHOLD 4.75
#define BAD_EDGE_THRESHOLD 1.5
#define GOOD_CONTRAST_THRESHOLD 6.5
#define BAD_CONTRAST_THRESHOLD 2.0
#define GOOD_ANGLE_THRESHOLD 10.0 //ie none

#define RESULT_TOO_SMALL_PENALTY 1.5
#define GOOD_RESULT_REWARD 2.5

// What to do if it's inconclusive
#define INCONCLUSIVE_CONTRAST_WEIGHT 1
#define INCONCLUSIVE_ANGLE_WEIGHT 1
#define INCONCLUSIVE_EDGE_WEIGHT 4
#define INCONCLUSIVE_PENALTY 2

BlurDetect::BlurDetect()
{
    width = height = 0;
    radius = LOOK_FOR_CONTRAST_RADIUS;

    threshhold = SENSITIVITY_THRESHOLD;
    edgeRadius = EDGE_SIZE;
    highpassRadius = DIST_BETWEEN_EDGES;

    sharpness = ANGLE_CONSTITUTING_SHARPNESS;
}

float BlurDetect::calculateBlur(VImage* vim) {
    assert(highpassRadius > edgeRadius);

    // Test # IPs
#ifndef FAST_MODE
    if(vim->getIps().size() <= MIN_NUM_IPS)
        return 0;
#endif

    QImage* image = vim->getQImage();
    minColor = avgColor = maxColor = 0;
    assert(image != NULL);
    *image = image->scaledToWidth(600);
    width = image->width();
    height = image->height();

    sharpestAngles = vector<int>();
    sharpestDists = vector<int>();
    weightedContrast = vector<int>();

    // Load image into grayscale int-map
    // And calculate average color
    originalImage = new int*[width];
    unsigned long total = 0;
    for(int w=0; w<width; w++) {
        originalImage[w] = new int[height];
        for(int h=0; h<height; h++) {
            int grayVal = qGray(image->pixel(w,h));
            originalImage[w][h] = grayVal;

            // Average, max, and min calcs
            total += grayVal;
            if(minColor < grayVal) minColor = grayVal;
            if(maxColor > grayVal) maxColor = grayVal;
        }
    }
    avgColor = total /= (int)(height*width);

    // debugPrint(originalImage);

    // Compute
    edgeDetect();
    followEdges();
    float result = resultCalc();
    //cerr << "," << result << endl;

    for(int w=0; w<width; w++) {
        delete[] highPass[w];
    }

    return fmin(result, 10.0);
}

void BlurDetect::edgeDetect() {
    // Calculate the effective threshhold from the % away from avg color
    int grayThreshhold = avgColor;
    numColors = 0;
    int maxOrMin = threshhold < 0 ? minColor : maxColor;
    grayThreshhold += (int)((maxOrMin-avgColor) * (int)(threshhold/100));

    highPass = new int*[width];
    for(int w=0; w<width; w++) {
        highPass[w] = new int[height];
        for(int h=0; h<height; h++) {
            if(originalImage[w][h] < grayThreshhold) {
                highPass[w][h] = originalImage[w][h];
                correctSpacing(w, h);
                numColors++;
            }
            else
                highPass[w][h] = 255;
        }
    }
    debugPrint(highPass);
}

void BlurDetect::correctSpacing(int w, int h) {
    // Text edge width and spacing
    int currGrayValue = originalImage[w][h];
    for(int x=w-highpassRadius; x<w-edgeRadius; x++) {
        for(int y=h-highpassRadius; y<h-edgeRadius; y++) {
            if((x < 0     || y < 0)  ||     // Don't test if out of bounds
                highPass[x][y] == 255       // Or if it isn't in highPass
               )
                continue;

            if(currGrayValue < highPass[x][y]) {
                highPass[x][y] = 255;
            } else {
                highPass[w][h] = 255;
                break;
            }
        }
    }
}


void BlurDetect::followEdges() {
    for(int w=0; w<width; w++) {
        for(int h=1; h<height; h++) {
            if(highPass[w][h] != 255)
                calcEdgeWidthAndAngle(w,h);
        }
    }
    //debugPrint(angles, true, 1, 3);
}

void BlurDetect::calcEdgeWidthAndAngle(int w, int h) {
    int brightest_contr = 0; int darkest_contr = 255;
    int brightest_dist = 0; int darkest_dist = 255;
    //point brightloc_contr, darkloc_contr;
    point brightloc_dist, darkloc_dist;

    // Ensure its an edge
    if(highPass[w][h] == 255)
        return;

    // Distance from bottom left to top right
    int furthestDist = sqrt(2*
                            2*radius*
                            2*radius);

    for(int x=w-radius; x<=w+radius; x++) {
        for(int y=h-radius; y<=h+radius; y++) {
            // Check bounds
            if((x == w && y == h)  ||
                x<0 || y<0         ||
                x>=width || y>=height)
            continue;

            // Calculate the penalty as the width gets large, >=1
            int distFromCenter = sqrt((x-w)*(x-w)+(y-h)*(y-h));
            float sizePenalty = distFromCenter - GOAL_EDGE_WIDTH;
            sizePenalty *= EDGE_WIDTH_PENALTY;
            sizePenalty = fmax(sizePenalty, 1.0);

            // Weighted-contrast brightest and darkest points
            if(originalImage[x][y]*sizePenalty < darkest_contr) {
                // Check if darkest point
                darkest_contr = originalImage[x][y];
                //darkloc_contr = point(x, y);
            } else if(originalImage[x][y]/sizePenalty > brightest_contr) {
                // Check if brightest point
                brightest_contr = originalImage[x][y];
                //brightloc_contr = point(x, y);
            }

            // Biggest distance penalty
            if(originalImage[x][y] < darkest_dist) {
                // Check if darkest point
                darkest_dist = originalImage[x][y];
                darkloc_dist = point(x, y);
            } else if(originalImage[x][y] > brightest_dist) {
                // Check if brightest point
                brightest_dist = originalImage[x][y];
                brightloc_dist = point(x, y);
            }

        }
    }
    if(brightest_dist == 255 || darkest_dist == 0 ||
       brightest_dist == 0 || darkest_dist == 255 ) {
        // Not a real edge
        return;
    }

    // Calc angle
    int xLen = abs(brightloc_dist.first - darkloc_dist.first);
    int yLen = abs(brightloc_dist.second - darkloc_dist.second);

    int dirAngle;
    if(yLen == 0)
        dirAngle = 90;
    else if(xLen == 0)
        dirAngle = 0;
    else {
        dirAngle = (int)(atan((double)xLen / (double)yLen) * 180/PI);
        if(dirAngle < 0) dirAngle += 360;
    }
    dirAngle = dirAngle % 360;

    int dist = sqrt(xLen*xLen + yLen*yLen) * UNSHARP_PENALTY;

    if(dist == 0)
        dist = furthestDist; // No diff in pixels = very blur
                    // also how is it an edge

    //qDebug("Edge distance of %d, angle %d", dist, dirAngle);
    sharpestAngles.push_back(dirAngle);
    sharpestDists.push_back(dist);
    weightedContrast.push_back(brightest_contr - darkest_contr);

    //return dist;

}

/*
int BlurDetect::calcAngle(int w, int h) {
    int maxX = 0; int maxY = 0; int maxGray = 255;
    for(int x=w-radius; x<=w+radius; x++) {
        for(int y=h-radius; y<=h+radius; y++) {
            if((x == w && y == h)  ||
                x<0 || y<0         ||
                x>=width || y>=height ||
                highPass[x][y] == 255
               ) continue;
            if(highPass[x][y] < maxGray) {
                maxX = x; maxY=y; maxGray = highPass[x][y];
            }
        }
    }
    if(maxGray == 255){
        // This would be noise in the image I suppose. Don't let it get in the way.
        return 0;
    }

    // Calc angle
    int xLen = maxX - w;
    int yLen = maxY - h;

    int dirAngle;
    if(yLen == 0)
        dirAngle = 90;
    else if(xLen == 0)
        dirAngle = 0;
    else {
        dirAngle = (int)(atan((double)xLen / (double)yLen) * 180/PI); // The direction
        if(dirAngle < 0) dirAngle += 360;
    }
    dirAngle = dirAngle % 360;

    // Get difference of this and closest angle
    int closestAngleDiff = 361; // Start with far point
    for(int x=w-radius; x<w; x++) {
        for(int y=h-radius; y<h; y++) {
            if((x == w && y == h)  ||
                x<0 || y<0         ||
                angles[x][y] == 0
               ) continue;
            int currAngleDiff = abs(angles[x][y] - dirAngle);
            if(currAngleDiff > 180) currAngleDiff = 180 - currAngleDiff%180; // Loop around so 359 close to 1
            if(currAngleDiff < closestAngleDiff) {
                closestAngleDiff = currAngleDiff;
            }
        }
    }

    // printf("%d ", closestAngleDiff);

    return closestAngleDiff;
}
*/

// This function returns values prioritizing the most
// conclusive results based on training data.
// The order is not arbitrary.
float BlurDetect::resultCalc() {
    float angle = angleCalc();
    float edge = edgeCalc();
    float contr = contrastCalc();

    //cerr << contr << "," << angle << "," << edge;

    // Too blurry: return small
    if(angle < BAD_ANGLE_THRESHOLD) {
        return angle / RESULT_TOO_SMALL_PENALTY;
    }
    if(edge < BAD_EDGE_THRESHOLD) {
        return edge / RESULT_TOO_SMALL_PENALTY;
    }

    // Sharp: return high
    if(edge > GOOD_EDGE_THRESHOLD) {
        return edge * GOOD_RESULT_REWARD;
    }
    if(contr > GOOD_CONTRAST_THRESHOLD) {
        return edge * GOOD_RESULT_REWARD;
    }

    // Inconclusive. Do our best.
    if(angle > GOOD_ANGLE_THRESHOLD) {
        return angle;
    }
    if(contr < BAD_CONTRAST_THRESHOLD) {
        return contr;
    }

    // Nothing reasonable. Average the three.
    return (INCONCLUSIVE_ANGLE_WEIGHT * angle
           + INCONCLUSIVE_EDGE_WEIGHT * edge
           + INCONCLUSIVE_CONTRAST_WEIGHT * contr)
           /
           (INCONCLUSIVE_ANGLE_WEIGHT +
            INCONCLUSIVE_EDGE_WEIGHT +
            INCONCLUSIVE_CONTRAST_WEIGHT +
            INCONCLUSIVE_PENALTY);
}

float BlurDetect::angleCalc() {
    // Should be #define
    int numAngleBins = 10;

    // Angles separated into bins
    vector<int> angleHist(numAngleBins, 0);

    // Get info about angles
    unsigned long totalDiffs = 0;
    unsigned long totalAngs = 0;
    int lastAngle = 0;
    vector<int>::iterator angleIter = sharpestAngles.begin();
    for(; angleIter != sharpestAngles.end(); ++angleIter) {
        totalDiffs += abs(*angleIter-lastAngle % 180);
        totalAngs += *angleIter;
        lastAngle = *angleIter;
        angleHist[*angleIter%180 / numAngleBins]++;
        //qDebug("Curr diff =  %ld,   angle = %d", totalDiffs, lastAngle);
    }
    int avgAngle = totalAngs / (sharpestAngles.size()+1);

    int maxBinSize = 0; // Size of bin with most angles
    int maxBinAngle = 0; // The angle range containing ^
    unsigned long totalBinSize = 0;
    for(int i=0; i<angleHist.size(); ++i) {
        int binNumElems = angleHist[i];
        totalBinSize += binNumElems;

        // Is this the biggest bin?
        if(binNumElems > maxBinSize) {
            maxBinSize = binNumElems;
            maxBinAngle = i * numAngleBins;
        }
    }
    int avgBinSize = totalBinSize / numAngleBins;

    int distMaxBinFromAvg = maxBinSize - avgBinSize;
// TODO: second to last vs max  bin size

    float result = 10 -
                   (distMaxBinFromAvg*distMaxBinFromAvg)
                   / (ANGLE_LENIENCY*ANGLE_LENIENCY);

    // Debug out angle
/*
    qDebug("Total diff =  %ld, avg = %d,   avg bin=%d,   dist=%d",
             totalDiffs, avgAngle, avgBinSize, distMaxBinFromAvg);
    for(int i=0; i<numAngleBins; ++i) {
        cerr << i << "0: ";
        for(int j=0; j<angleHist[i]; j+=50) {
            cerr << "=";
        }
        cerr << endl;
    }
    cerr << endl << "---------------" << endl;
*/
    result = fmin(result, 10.0);
    result = fmax(result, 0.0);
    return result;
}

float BlurDetect::edgeCalc() {
    unsigned long long avgDist = 0;
    vector<int>::iterator distIter = sharpestDists.begin();
    for(; distIter != sharpestDists.end(); ++distIter) {
        avgDist += *distIter;
    }
    avgDist /= (sharpestDists.size()+1);


    // Distance from bottom left to top right
    int furthestDist = sqrt(2*
                            2*radius*
                            2*radius);

    // Penalize more as it gets closer to the maximum dist,
    // the LOOK_FOR_CONTRAST_RADIUS. (Returns 0 if avg=radius,
    // 10 if avg=0
    float distRate = 10.0-
            avgDist*avgDist*
            (10.0/(furthestDist*furthestDist));

    distRate = fmin(distRate, 10.0);
    distRate = fmax(distRate, 0.0);
    return distRate;
}

float BlurDetect::contrastCalc() {
    unsigned long long avgDist = 0;
    vector<int>::iterator contrIter = weightedContrast.begin();
    for(; contrIter != weightedContrast.end(); ++contrIter) {
        avgDist += *contrIter;
    }
    avgDist /= (weightedContrast.size()+1);
    return avgDist / 12.8; // 12.8: Max avg dist is 128 (256/2).
                           // Scale to 0-10
}

void BlurDetect::debugPrint(int **image,
                            bool stepped, int step1, int step2) {
    QImage i = QImage(width, height, QImage::Format_RGB32);

    for(int w=0; w<width; w++) {
        for(int h=0; h<height; h++) {
            int color = image[w][h];
            if(stepped) {
                if(color < step1)
                    i.setPixel(w, h, qRgb(color*100, 0, 0));
                else if(color < step2)
                    i.setPixel(w, h, qRgb(0, color*100, 0));
                else
                    i.setPixel(w, h, qRgb(0, 0, color*100));
            } else {
                i.setPixel(w, h, qRgb(color, color, color));
            }
        }
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