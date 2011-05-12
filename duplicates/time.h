#ifndef DUPLICATETIME_H
#define DUPLICATETIME_H

#include "duplicates/rater.h"
#include "qualityexif.h"
#include "vimage.h"

// For readability
typedef unsigned long long int exifTime;

class DuplicateTime
{
public:
    DuplicateTime(DuplicateRater* rater);

    // Get the time of this image from exif
    void addImage(VImage* im, QualityExif* exif);

    // Adds hypothesized ranking to the DuplicateRater
    // Given two images, compares averages of logs of gaps
    // of everything between, as well as outside of them within
    // the WINDOW_SIZE
    //
    // e.g. gets everything between two images, WINDOWSIZE before first,
    // and WINDOWSIZE after second
    void rankOne(VImage* first, VImage* second);

private:
    // Maps an image to its index in times and gapFinder
    map<QImage*, int> timeIndexFinder;

    // The list of times a picture was taken
    vector<exifTime> times;

    // index[i] = sum of logs of gaps between 0 and i
    vector<long double> sumGapLogs;

    // Returns the index in the gapFinder
    int getIndex(QImage*);

    // Returns the time this image was taken
    int getTime(QImage*);

    // Holds each modules ranking
    DuplicateRater* rater;

};

#endif // DUPLICATETIME_H
