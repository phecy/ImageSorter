/*
    DuplicateGlobal
    Will determine if two pictures are similar based on content color,
    looking at the entire image and splitting it into NUMOFBLOCKS segments.
    Phase 2 of duplicate detection.

    1. Timestamp-based weight
    2. DuplicateGlobal
    3. DuplicateLocal
*/

#include "findDups.h"
#include <iostream>
#include <stdio.h>
#include <QImage>
#include <QRgb>
#include <string>
#include <math.h>
#include <vector>
#include <vector>

#define BLOCKSACROSS 3 // How to place grid
#define NUMOFBLOCKS BLOCKSACROSS*BLOCKSACROSS
#define DISTANCE 50 // Between color pixels
#define NUMSECTIONALLOWANCE 1 // How many blocks can be off
#define PCTSIMILARITYDIST 10.0 // % of the total pics in a set that an img can
                               // be different from before being rejected

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

DuplicateSegmented::DuplicateSegmented() {
    allPics = new segMap();
    blocksAcross = BLOCKSACROSS;
    numBlocks = NUMOFBLOCKS;
    similarityDist = 0; // temporarily
}

DuplicateSegmented::~DuplicateSegmented() {
    delete allPics;
    delete allGroups;
}

void DuplicateSegmented::addImage(QImage* image) {
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
            (*(*imagehash)[rowNum])[colNum] += image->pixel(w,h);
        }
    }

    // Add to allPics list
    segPair* imgpair = new segPair(image, imagehash);
    allPics->insert(allPics->end(), *imgpair);
}

dupGroup DuplicateSegmented::findDuplicates() {
    similarityDist = allPics->size() * PCTSIMILARITYDIST/100;

    segMap::iterator i = allPics->begin();
    allGroups = new dupGroup();
    for(; i != allPics->end(); ++i) {
        insertGrouped(i->first, allGroups);
    }
    return *allGroups;
}

void DuplicateSegmented::insertGrouped(QImage* im, dupGroup* list) {
    bool foundSetFlag = false; // True if a match was just found

    // Look for any set this could match
    dupGroup::iterator i = list->begin();
    // For every set, check if it matches all imgs but NUMSECTIONALLOWANCE
    for( ; i != list->end(); ++i) {
        int numNotRelatedTo = 0;

        // Look through every pic in this group, counting mismatches
        int picsInSet = i->size();
        for(int picNum=0; picNum < picsInSet; ++picNum) {
            QImage* currIm = (*i).at(picNum);
            if(!isMatch(currIm, im)) {
                // If not match, penalize.
                // If penalized too much, check next group.
                if(++numNotRelatedTo >= similarityDist) {
                    foundSetFlag = false;
                    break;
                }
            } else {
                foundSetFlag = true;
            }
        }
        if(foundSetFlag) {
            // Add to group if hadn't been overpenalized
            i->push_back(im);
            return;
        }
    }

    // Nothing matched. New entry.
    vector<QImage*> thisSet;
    thisSet.push_back(im);
    list->push_back(thisSet);
}

bool DuplicateSegmented::isMatch(QImage *first, QImage *second) {
    segVector* vFirst = allPics->find(first)->second;
    segVector* vSecond = allPics->find(second)->second;

    // Test every section. Return false if more than one is too far off.
    int failedSections = 0;
    for(int r=0; r<blocksAcross; ++r) {
        for(int c=0; c<blocksAcross; ++c) {
            // Check if blocks are out of allowable distance
            QRgb firstPix = vFirst->at(r)->at(c).get_avg();
            QRgb secondPix = vSecond->at(r)->at(c).get_avg();
            int rDist = abs(qRed(firstPix) - qRed(secondPix));
            int gDist = abs(qGreen(firstPix) - qGreen(secondPix));
            int bDist = abs(qBlue(firstPix) - qBlue(secondPix));

            if(rDist > DISTANCE ||
               gDist > DISTANCE ||
               bDist > DISTANCE) {
                // If out of allowable distance, add to failedSections
                if(++failedSections > NUMSECTIONALLOWANCE) {
                    // If too many failed sections, fail completely
                    return false;
                }
            }
        }
    }
    // If did not fail...succeeded!
    return true;
}
