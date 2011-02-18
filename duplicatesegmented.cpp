#include <iostream>
#include <stdio.h>
#include <QImage>
#include <QRgb>
#include "math.h"
#include "assert.h"
#include "duplicatesegmented.h"
#include "duplicaterater.h"
#include "vimage.h"

#define BLOCKSACROSS 3 // How to place grid
#define NUMOFBLOCKS BLOCKSACROSS*BLOCKSACROSS
#define DISTANCE 40 // Between color pixels
#define NUMSECTIONALLOWANCE 2 // How many blocks can be off
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

    blocksAcross = BLOCKSACROSS;
    numBlocks = NUMOFBLOCKS;

    this->rater = rater;
}

DuplicateSegmented::~DuplicateSegmented() {
    delete allPics;
}

void DuplicateSegmented::addImage(VImage* vim) {
    QImage* image = vim->getQImage();

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
    segPair* imgpair = new segPair(image, imagehash);
    allPics->insert(allPics->end(), *imgpair);
}

void DuplicateSegmented::rankOne(VImage *first, VImage *second) {
    int rank = getSimilarity(first, second);
    rater->addRanking(first->getQImage(), second->getQImage(),
                      rank, DuplicateRater::DUPLICATE_SEGMENTED);
}

int DuplicateSegmented::getSimilarity(VImage* vim1, VImage* vim2) {
    QImage* first = vim1->getQImage();
    QImage* second = vim2->getQImage();

    segVector* vFirst = allPics->find(first)->second;
    segVector* vSecond = allPics->find(second)->second;

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
            rating -= (rating*(double)(min(min(rDist,gDist),bDist)) / DISTANCE) / (.5*BLOCKSACROSS*MAX_RATING);
        }
    }

//    qDebug("DuplicateSegmented: Img#%s->%s similarity hypothesis: %2.2f/10",
//           vim1->getFilename(), vim2->getFilename(), rating);

    if(rating < 0) rating = 0;

    return round(rating);
}
