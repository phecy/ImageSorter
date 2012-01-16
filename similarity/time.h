#ifndef DUPLICATETIME_H
#define DUPLICATETIME_H

#include "vimage.h"

// For readability
typedef unsigned long long int ExifTime;

class SimilarityTime
{
public:
    SimilarityTime(vector<VImage*> allImages);

    // Given two images, compares averages of logs of gaps
    // of everything between, as well as outside of them within
    // the WINDOW_SIZE
    //
    // e.g. gets everything between two images, WINDOWSIZE before first,
    // and WINDOWSIZE after second
    float getSimilarity const(VImage* first, VImage* second);

private:
    // Add this image to the internal structure (updates sumGapLogs)
    void addImage(VImage*);

    // Maps an image to its index in times and gapFinder
    map<QImage*, int> timeIndexFinder;

    // The list of times a picture was taken
    vector<ExifTime> times;

    // index[i] = sum of logs of gaps between 0 and i
    vector<long double> sumGapLogs;

};

#endif // DUPLICATETIME_H
