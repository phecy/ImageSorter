#include "duplicaterater.h"

// Mins: Below this value on any module, fail
// Maxs: Above this value on any module, succeed
#define MIN_SEGMENTED_THRESHHOLD 2
#define MAX_SEGMENTED_THRESHHOLD 9
#define MIN_TIME_THRESHHOLD 2
#define MAX_TIME_THRESHHOLD 9

// Avg: A value over this will scale to assist other modules in success
#define AVG_EXPECTED_TIME 6

DuplicateRater::DuplicateRater(int numImages)
{
    // Initialize everything. Large overhead. Sorry.
    ratings = new vector3d(numImages,
                    vector2d(numImages,
                      vector1d(NUM_MODULES, -1)));
    imageIndeces = new map<QImage*, int>();
    lastIndex = 0;

}
void DuplicateRater::addRanking(QImage* first, QImage* second,
                int rank, module_type module) {
    int firstIndex = getIndex(first);
    int secondIndex = getIndex(second);

    // [m][n] = [n][m]
    (*ratings)[firstIndex][secondIndex][module] = rank;
    (*ratings)[secondIndex][firstIndex][module] = rank;
}

int DuplicateRater::getIndex(QImage *im) {
    map<QImage*, int>::iterator elem = imageIndeces->find(im);

    if(elem == imageIndeces->end()) {
        // Insert
        imageIndeces->insert(elem, pair<QImage*, int>(im, lastIndex));
        return lastIndex++;
    }
    else return elem->second;
}

int DuplicateRater::getRanking(QImage *first, QImage *second) {
    int firstIndex = getIndex(first);
    int secondIndex = getIndex(second);

    // [m][n] = [n][m]
    return calcRank((*ratings)[firstIndex][secondIndex]);
}

int DuplicateRater::calcRank(vector1d moduleRanks) {
    float rankCalc;

    int timeRating = moduleRanks[DUPLICATE_TIME];
    int segRating = moduleRanks[DUPLICATE_SEGMENTED];

    if(timeRating <= MIN_TIME_THRESHHOLD ||
       timeRating >= MAX_TIME_THRESHHOLD)
        return timeRating;

    if(segRating <= MIN_SEGMENTED_THRESHHOLD ||
       segRating >= MAX_SEGMENTED_THRESHHOLD)
        return segRating;

    // No auto-pass or auto-fail. Calculate.
    // Currently: Any time over AVG_EXP_TIME improves segRating
    rankCalc = timeRating/AVG_EXPECTED_TIME * segRating;

    return rankCalc;
}
