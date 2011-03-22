#include <QImage>
#include <QRgb>
#include <vector>
#include <map>

#include "duplicaterater.h"
#include "vimage.h"

#ifndef DUPLICATESEGMENTED_H
#define DUPLICATESEGMENTED_H

using namespace std;

// Difference between one block and every other block in image
typedef vector<int> segOneBlockDiffs;

// Differences between every pair of blocks
typedef vector<segOneBlockDiffs> segAllBlockDiffs;

// A NUMBLOCKS-by-NUMBLOCKS vector of the differences
// between all pairs of blocks
typedef map<QImage*, segAllBlockDiffs > segMap; // Maps im* to segmented

class DuplicateSegmented
{
public:
    DuplicateSegmented(DuplicateRater*);
    ~DuplicateSegmented();

    // Segments an image and stores the hash'd values of color distribution
    void addImage(VImage*);

    // Adds a single ranking to the DuplicateRater
    void rankOne(VImage*, VImage*);
    void rankOneForeground(VImage*, VImage*);

private:
    // A list of QImages and their respective segmented grayval blocks
    segMap* allPics;
    segMap* allForegrounds;

    // Returns a number 0-9 of how similar two images are
    int getSimilarity(QImage*, QImage*, bool isForeground);

    // Compares each block of image to every other block,
    // returns differences between each block and every other
    // to show histogram-distribution
    segAllBlockDiffs getDifferences(QImage* image, int blocksAcross);

    // Holds each modules ranking
    DuplicateRater* rater;
};

#endif // DUPLICATESEGMENTED_H
