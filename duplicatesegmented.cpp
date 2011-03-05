#include <iostream>
#include <stdio.h>
#include <QImage>
#include <QRgb>
#include "math.h"
#include "assert.h"
#include "duplicatesegmented.h"
#include "duplicaterater.h"
#include "vimage.h"

#define BLOCKSACROSS_ALL 4 // How to place grid
#define BLOCKSACROSS_FG 4
#define DISTANCE_ALL 40 // Between color pixels
#define DISTANCE_FG 30
#define MAX_RATING 10

using namespace std;
RGB_set::RGB_set() {
    numCounted = 0;
    r=0;
    g=0;
    b=0;
}

void RGB_set::add_color(int R, int G, int B) {
    double ratio = (double)numCounted / (++numCounted);
    double numCounted_double = numCounted;
    r = r*ratio + R/numCounted_double;
    g = g*ratio + G/numCounted_double;
    b = b*ratio + B/numCounted_double;
}

void RGB_set::operator+=(QRgb color) {
    add_color(qRed(color), qBlue(color), qGreen(color));
}

QRgb RGB_set::get_avg() {
    return qRgb(r, g, b);
}

DuplicateSegmented::DuplicateSegmented(DuplicateRater* rater) {
    allPics = new segMap();
    allForegrounds = new segMap();

    this->rater = rater;
}

DuplicateSegmented::~DuplicateSegmented() {
    delete allPics;
}

void DuplicateSegmented::addImage(VImage* vim) {
    QImage* image = vim->getQImage();
    QImage* foreground = vim->getForeground();

    segPair* imgpair = getSegpair(image, BLOCKSACROSS_ALL);
    segPair* fgpair = getSegpair(foreground, BLOCKSACROSS_FG);

    allPics->insert(allPics->end(), *imgpair);
    allForegrounds->insert(allForegrounds->end(), *fgpair);
}

segPair* DuplicateSegmented::getSegpair(QImage* image, int blocksAcross) {
    int width = image->width();
    int height = image->height();

    int blockHeight = height / blocksAcross;
    int blockWidth  =  width / blocksAcross;

    // Initialize a numBlocksxnumBlocks array to 0

    segVector* imagehash = new segVector(blocksAcross);
    for(int i=0; i<blocksAcross; ++i) {
        imagehash->at(i) = new vector<RGB_set>(blocksAcross, RGB_set());
    }

    // Get total sum of grayvals in each block
    for(int w=0; w < width; w++) {
        int colNum = min(w / blockWidth, int(blocksAcross-1));

        // Add everything
        for(int h=0; h < height; h++) {
            int rowNum = min(h / blockHeight, int(blocksAcross-1));
            QRgb pix = image->pixel(w,h);
            (*(*imagehash)[rowNum])[colNum] += pix;
        }
    }

    // Add to allPics list
    return new segPair(image, imagehash);
}

void DuplicateSegmented::rankOne(VImage *first, VImage *second) {
    int rank = getSimilarity(first->getQImage(), second->getQImage(),
                             false);
    rater->addRanking(first, second, rank, DuplicateRater::DUPLICATE_SEGMENTED);
}

void DuplicateSegmented::rankOneForeground(VImage *first, VImage *second) {
    int rank = getSimilarity(first->getForeground(),second->getForeground(),
                             true);
    rater->addRanking(first, second, rank, DuplicateRater::DUPLICATE_FG);
}

int DuplicateSegmented::getSimilarity(QImage* first, QImage* second,
                                      bool isForeground) {
    segMap* map;
    int blocksAcross;
    int allowedDist;
    if(isForeground) {
        map = allForegrounds;
        blocksAcross = BLOCKSACROSS_FG;
        allowedDist = DISTANCE_FG;
    } else {
        map = allPics;
        blocksAcross = BLOCKSACROSS_ALL;
        allowedDist = DISTANCE_ALL;
    }
    segVector* vFirst = map->find(first)->second;
    segVector* vSecond = map->find(second)->second;

    double rating = 10.0;

    // Test every section. Return false if more than one is too far off.
    for(int r=0; r<blocksAcross; ++r) {
        for(int c=0; c<blocksAcross; ++c) {
            // Check if blocks are out of allowable distance
            QRgb firstPix = vFirst->at(r)->at(c).get_avg();
            QRgb secondPix = vSecond->at(r)->at(c).get_avg();

            int rDist = abs(qRed(firstPix) - qRed(secondPix));
            int gDist = abs(qGreen(firstPix) - qGreen(secondPix));
            int bDist = abs(qBlue(firstPix) - qBlue(secondPix));

            // Penalize average difference divided by allowed distance
            // Then, penalize less as the rating gets lower
            rating -=
               (rating*(double)((rDist+bDist+gDist)/3) / allowedDist) /
               (.5*blocksAcross*MAX_RATING);
        }
    }

//    qDebug("DuplicateSegmented: Img#%s->%s similarity hypothesis: %2.2f/10",
//           vim1->getFilename(), vim2->getFilename(), rating);

    if(rating < 0) rating = 0;

    return round(rating);
}
