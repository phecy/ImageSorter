#include <QImage>
#include <QRgb>
#include <vector>
#include <map>

#include "duplicaterater.h"
#include "vimage.h"

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
    void addImage(VImage*);

    // Adds a single ranking to the DuplicateRater
    void rankOne(VImage*, VImage*);
    void rankOneForeground(VImage*, VImage*);

private:
    // Helper function for addImage
    segPair* getSegpair(QImage* image, int numBlocks);

    // A list of QImages and their respective segmented grayval blocks
    segMap* allPics;
    segMap* allForegrounds;

    // Returns a number 0-9 of how similar two images are
    int getSimilarity(QImage*, QImage*, bool isForeground);

    // Holds each modules ranking
    DuplicateRater* rater;
} ;

#endif // DUPLICATESEGMENTED_H
