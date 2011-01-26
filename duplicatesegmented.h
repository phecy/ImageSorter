#include <QImage>
#include <QRgb>
#include <vector>
#include <map>

#include "duplicaterater.h"

#ifndef DUPLICATESEGMENTED_H
#define DUPLICATESEGMENTED_H

using namespace std;

class RGB_set;

// A NUMBLOCKS-by-NUMBLOCKS vector of the avg grayvals
// unsigned long to hold total, then average it
typedef vector<vector<RGB_set>* > segVector;
typedef map<QImage*, segVector*> segMap; // Maps im* to segmented
typedef pair<QImage*, segVector*> segPair; // A pair for segMap

class RGB_set {
public:
    RGB_set();
    void add_color(int, int, int);
    QRgb get_avg();
    void operator+=(QRgb);
private:
    // Floats to allow for precision in avg'ing
    float r;
    float g;
    float b;
    unsigned int numCounted;
};

class DuplicateSegmented
{
public:
    DuplicateSegmented(DuplicateRater*);
    ~DuplicateSegmented();

    // Segments an image and stores the hash'd values
    void addImage(QImage*);

    // Returns a list of lists of duplicates
    void rankAll();

private:
    // A list of QImages and their respective segmented grayval blocks
    segMap* allPics;

    // Returns a number 0-9 of how similar two images are
    int getSimilarity(QImage*, QImage*);

    // Set by #defines (blocksAcross=sqrt(numblocks))
    int numBlocks, blocksAcross;

    // Set by #define of PCTSIMILARITYDIST% * numImages
    int similarityDist;

    // Holds each modules ranking
    DuplicateRater* rater;
} ;

#endif // DUPLICATESEGMENTED_H
