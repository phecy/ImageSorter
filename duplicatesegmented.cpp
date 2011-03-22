#include <iostream>
#include <stdio.h>
#include <QImage>
#include <QRgb>
#include <assert.h>
#include "math.h"
#include "duplicatesegmented.h"
#include "duplicaterater.h"
#include "vimage.h"

#define BLOCKSACROSS_ALL 4 // How to place grid
#define BLOCKSACROSS_FG 3
#define DISTANCE_ALL 20 // Between color pixels
#define DISTANCE_FG 10
#define MAX_RATING 10

using namespace std;

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

    segAllBlockDiffs imgdiffs = getDifferences(image, BLOCKSACROSS_ALL);
    segAllBlockDiffs fgdiffs = getDifferences(foreground, BLOCKSACROSS_FG);

    allPics->insert(allPics->end(),
       pair<QImage*, segAllBlockDiffs>(image, imgdiffs));
    allForegrounds->insert(allForegrounds->end(),
       pair<QImage*, segAllBlockDiffs>(foreground, fgdiffs));
}

segAllBlockDiffs DuplicateSegmented::getDifferences(QImage* image, int blocksAcross) {
    // Resize to blocksAcross x blocksAcross
    QImage resizedIm = image->scaled(blocksAcross, blocksAcross);
    vector<QRgb> resized;
    for(int i=0; i<blocksAcross; ++i) {
        for(int j=0; j<blocksAcross; ++j) {
            resized.push_back(resizedIm.pixel(i,j));
        }
    }

    // Compare all pairs
    //QRgb allColorAvg =
    segAllBlockDiffs allBlocks;
    //qDebug("Looking at image %p", image);
    for(int main_i=0; main_i < blocksAcross*blocksAcross; ++main_i) {
        segOneBlockDiffs currBlock;

        QRgb mainColor = resized.at(main_i);
        // Compare single block to every other block
        for(int cmp_i=0; cmp_i<blocksAcross*blocksAcross; ++cmp_i) {
            QRgb compareColor = resized.at(cmp_i);
            int diff = qGray(mainColor) - qGray(compareColor);
            //int compardToTotal = qGray(compareColor) / qGray(allColorAvg);
            currBlock.push_back(diff);
            //qDebug("Block %d vs %d has %d diff", main_i, cmp_i, diff);
        }
        assert(currBlock.size() == blocksAcross*blocksAcross);
        allBlocks.push_back(currBlock);
    }

    return allBlocks;
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
    segAllBlockDiffs vFirst = map->find(first)->second;
    segAllBlockDiffs vSecond = map->find(second)->second;

    double rating = 10.0;

    // Test every section. Return false if more than one is too far off.
    int numBlocks = blocksAcross*blocksAcross;
    //qDebug("Looking at images %p and %p", first, second);
    for(int main_i=0; main_i<numBlocks; ++main_i) {
        for(int cmp_i=0; cmp_i<numBlocks; ++cmp_i) {
            // Check if blocks are out of allowable distance
            int firstImDiff = vFirst.at(main_i).at(cmp_i);
            int secondImDiff= vSecond.at(main_i).at(cmp_i);

            int distanceDifference = abs(firstImDiff - secondImDiff);

//            qDebug("Distance difference between block %d and %d: %d-%d=%d",
//                   main_i, cmp_i, firstImDiff, secondImDiff, distanceDifference);

            // Penalize average difference divided by allowed distance
            // Then, penalize less as the rating gets lower
            rating -=
               ((double)(distanceDifference) / allowedDist) /
               (blocksAcross*MAX_RATING*3);
        }
    }

//    qDebug("DuplicateSegmented: Img#%s->%s similarity hypothesis: %2.2f/10",
//           vim1->getFilename(), vim2->getFilename(), rating);

    if(rating < 0) rating = 0;

    return round(rating);
}
