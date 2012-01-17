#include <math.h>
#include "time.h"
#include "vimage.h"

#define WINDOWSIZE 9
#define MAXRANK 10 // Subtract MAXRANK-logdiff so lower diff = better
#define STRICTNESS_TIME 10

SimilarityTime::SimilarityTime(vector<VImage*> allImages) {
    vector<VImage*>::iterator it;
    for(it = allImages.begin(); it != allImages.end(); ++it) {
        addImage(*it);
    }
}

void SimilarityTime::addImage(VImage *vim) {
    QImage* im = vim->getQImage();

    ExifTime time = vim->getExif().getTime();

    // Add to map for quick indexing and time-retrieval
    int currIndex = times.size();

    times.push_back(time);
    timeIndexFinder[im] = currIndex;

    // Then calculate gap
    if(currIndex > 0) {
        int gap = abs((int)(time - times[currIndex-1]))+1;
        float logGap = log2(gap*STRICTNESS_TIME);
        sumGapLogs.push_back(logGap + sumGapLogs[currIndex-1]);
    } else {
        sumGapLogs.push_back(0);
    }
}

float SimilarityTime::calculateSimilarity(const VImage* vim1, const VImage* vim2) {
    // Get indeces of images
    int firstIndex = vim1->getIndex();
    int secondIndex = vim2->getIndex();
    int numPics = times.size();

    // Get boundaries
    int minIndex = (firstIndex < WINDOWSIZE) ? 0 : firstIndex - WINDOWSIZE;
    int maxIndex = ((numPics-1)-secondIndex < WINDOWSIZE)
                   ? numPics-1 : secondIndex+ WINDOWSIZE;
    int actualWindowSize = maxIndex - minIndex + 1;

    // Get the avg gap in the window (minIndex -> maxIndex)
    double sumOfLogsWindow = sumGapLogs[maxIndex] - sumGapLogs[minIndex];
    double avgGapWindow = sumOfLogsWindow/actualWindowSize;

    // Get the avg gap between the two images (firstIndex -> secondIndex)
    double gapImages = sumGapLogs[secondIndex] - sumGapLogs[firstIndex];

    // Finally, compare the current gap to the average window gap,
    //  scaling to account for image distance
    int rank = round(MAXRANK - gapImages/avgGapWindow);

    if(rank < 0) rank = 0;

    return rank;
}
