#include <iostream>
#include "duplicaterater.h"
#include "vimage.h"


// Mins: Below this value on any module, fail
// Maxs: Above this value on any module, succeed
#define MIN_SEGMENTED_THRESHHOLD 2
#define MAX_SEGMENTED_THRESHHOLD 9
#define MIN_FOREGROUND_THRESHHOLD -1 // Possibly failed fg find
#define MAX_FOREGROUND_THRESHHOLD 8
#define MIN_TIME_THRESHHOLD 2
#define MAX_TIME_THRESHHOLD 10

#define TIME_WEIGHT .3
#define SEG_WEIGHT 3
#define FG_WEIGHT 1
#define GAUSS_WEIGHT 4

#define MAX_RANK 10

using namespace std;

DuplicateRater::DuplicateRater(int numImages)
{
    // Initialize everything. Large overhead. Sorry.
    ratings = new vector3d(numImages,
                    vector2d(numImages,
                      vector1d(NUM_MODULES, -1)));
    imageIndeces = new map<VImage*, int>();
    lastIndex = 0;

}
void DuplicateRater::addRanking(VImage* first, VImage* second,
                int rank, module_type module) {
    int firstIndex = getIndex(first);
    int secondIndex = getIndex(second);

    // [m][n] = [n][m]
    (*ratings)[firstIndex][secondIndex][module] = rank;
    (*ratings)[secondIndex][firstIndex][module] = rank;
}

int DuplicateRater::getIndex(VImage *im) {
    map<VImage*, int>::iterator elem = imageIndeces->find(im);

    if(elem == imageIndeces->end()) {
        // Insert
        imageIndeces->insert(elem, pair<VImage*, int>(im, lastIndex));
        return lastIndex++;
    }
    else return elem->second;
}

float DuplicateRater::getRanking(VImage *first, VImage *second) {
    int firstIndex = getIndex(first);
    int secondIndex = getIndex(second);

    // [m][n] = [n][m]
    return calcRank((*ratings)[firstIndex][secondIndex]);
}

float DuplicateRater::calcRank(vector1d moduleRanks) {
    float rankCalc;

    int timeRating = moduleRanks[DUPLICATE_TIME];
    int segRating = moduleRanks[DUPLICATE_SEGMENTED];
    int fgRating = moduleRanks[DUPLICATE_FG];
    int gaussRating = moduleRanks[DUPLICATE_GAUSSIAN];

    if(timeRating <= MIN_TIME_THRESHHOLD ||
       timeRating >= MAX_TIME_THRESHHOLD)
        return timeRating;

    if(segRating <= MIN_SEGMENTED_THRESHHOLD ||
       segRating >= MAX_SEGMENTED_THRESHHOLD)
        return segRating;

    if(fgRating <= MIN_FOREGROUND_THRESHHOLD ||
       fgRating >= MAX_FOREGROUND_THRESHHOLD)
        return fgRating;

    // No auto-pass or auto-fail. Calculate.
    float scaleBy = timeRating/MAX_RANK;
    rankCalc = min(10.0,
                scaleBy*segRating*TIME_WEIGHT
                + ( SEG_WEIGHT*segRating
                    + FG_WEIGHT*fgRating
                    + GAUSS_WEIGHT*gaussRating
                    ) / (SEG_WEIGHT+FG_WEIGHT+GAUSS_WEIGHT)
               );

    return rankCalc;
}

void DuplicateRater::printRanks() {
    cerr << "    ";
    for(unsigned int i=0; i<ratings->size(); ++i) {
        cerr << "  " << i+1 << "     ";
    }
    cerr << endl;

    for(unsigned int i=0; i<ratings->size(); ++i) {
        cerr << i+1 << ": ";
        for(unsigned int j=0; j<ratings[0].size(); ++j) {
            cerr << " {";
            for(int k=0; k<NUM_MODULES; ++k) {
                int rank = (*ratings)[i][j][k];
                cerr << ((rank<0) ? 0 : rank);
                if(k != NUM_MODULES-1)
                    cerr << ", ";
            }
            cerr << "} ";
        }
        cerr << endl;
    }
}
