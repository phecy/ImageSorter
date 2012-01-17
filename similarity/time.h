#ifndef SIMILARITYTIME_H
#define SIMILARITYTIME_H

#include <map>
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
    float calculateSimilarity(VImage* first, VImage* second);

private:
    // Add this image to the internal structure (updates sumGapLogs)
    void addImage(VImage*);

    // Maps an image to its index in times and gapFinder
    std::map<QImage*, int> timeIndexFinder;

    // The list of times a picture was taken
    vector<ExifTime> times;

    // index[i] = sum of logs of gaps between 0 and i
    vector<long double> sumGapLogs;

};

#endif // SIMILARITYTIME_H
