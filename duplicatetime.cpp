#include <math.h>
#include "duplicatetime.h"

#define WINDOWSIZE 3
#define MAXRANK 10 // Subtract MAXRANK-logdiff so lower diff = better

DuplicateTime::DuplicateTime(DuplicateRater *rater) {
    this->rater = rater;
}

void DuplicateTime::addImage(QImage *im) {
    // To do: fix random time. Then get a real time.
    int time = 6;

    // Add to map for quick indexing and time-retrieval
    int currIndex = times.size();

    times.push_back(time);
    timeIndexFinder[im] = currIndex;

    // Then calculate gap
    if(currIndex > 0) {
        int gap = abs(time - times[currIndex-1])+1;
        sumGapLogs.push_back(log2(gap) + sumGapLogs[currIndex-1]);
    } else {
        sumGapLogs.push_back(0);
    }
}

void DuplicateTime::rankOne(QImage* first, QImage* second) {
    // Initialize stuff
    int avgGap;
    int numPics = times.size();

    // Get indeces of images
    int firstIndex = getIndex(first);
    int secondIndex = getIndex(second);

    // Get boundaries
    int minIndex = (firstIndex < WINDOWSIZE) ? 0 : firstIndex - WINDOWSIZE;
    int maxIndex = ((numPics-1)-secondIndex < WINDOWSIZE) ? numPics-1 : secondIndex+ WINDOWSIZE;
    int actualWindowSize = maxIndex - minIndex;

    // Get the sum of all logs between
    int sumOfLogs = sumGapLogs[maxIndex] - sumGapLogs[minIndex];
    avgGap = sumOfLogs / actualWindowSize;

    qDebug("duplicateTime: Img#%p->%p similarity hypothesis: %d/10",
           first, second, MAXRANK-avgGap);

    rater->addRanking(first, second, MAXRANK-avgGap, DuplicateRater::DUPLICATE_TIME);
}

int DuplicateTime::getIndex(QImage* which) {
    return timeIndexFinder.find(which)->second;
}

int DuplicateTime::getTime(QImage* which) {
    return times[getIndex(which)];
}
