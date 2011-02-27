#include <math.h>
#include "duplicatetime.h"
#include "qualityexif.h"
#include "vimage.h"

#define WINDOWSIZE 10
#define MAXRANK 10 // Subtract MAXRANK-logdiff so lower diff = better

DuplicateTime::DuplicateTime(DuplicateRater *rater) {
    this->rater = rater;
}

void DuplicateTime::addImage(VImage *vim, QualityExif* exif) {
    QImage* im = vim->getQImage();
    // To do: fix random time. Then get a real time.
    exifTime time = exif->getTime();

    // Add to map for quick indexing and time-retrieval
    int currIndex = times.size();

    times.push_back(time);
    timeIndexFinder[im] = currIndex;

    // Then calculate gap
    if(currIndex > 0) {
        int gap = abs((int)(time - times[currIndex-1]))+1;
        float logGap = log2(gap)*2;
        sumGapLogs.push_back(logGap + sumGapLogs[currIndex-1]);
    } else {
        sumGapLogs.push_back(0);
    }
}

void DuplicateTime::rankOne(VImage* vim1, VImage* vim2) {
    QImage* first = vim1->getQImage();
    QImage* second = vim2->getQImage();

    int numPics = times.size();

    // Get indeces of images
    int firstIndex = getIndex(first);
    int secondIndex = getIndex(second);

    // Get boundaries
    int minIndex = (firstIndex < WINDOWSIZE) ? 0 : firstIndex - WINDOWSIZE;
    int maxIndex = ((numPics-1)-secondIndex < WINDOWSIZE) ? numPics-1 : secondIndex+ WINDOWSIZE;
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

//    qDebug("duplicateTime: Img#%p->%p similarity hypothesis: %d/10",
//           vim1->getFilename(), vim2->getFilename(), rank);

    rater->addRanking(vim1, vim2, rank, DuplicateRater::DUPLICATE_TIME);
}

int DuplicateTime::getIndex(QImage* which) {
    return timeIndexFinder.find(which)->second;
}

int DuplicateTime::getTime(QImage* which) {
    return times[getIndex(which)];
}
