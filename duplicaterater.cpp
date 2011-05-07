#include <iomanip>
#include <iostream>
#include "duplicaterater.h"
#include "vimage.h"

// Mins: Below this value on any module, fail
// Maxs: Above this value on any module, succeed
#define MIN_SEGMENTED_THRESHHOLD -1
#define MAX_SEGMENTED_THRESHHOLD 10
#define MIN_FOREGROUND_THRESHHOLD -1 // Possibly failed fg find
#define MAX_FOREGROUND_THRESHHOLD 11
#define MIN_TIME_THRESHHOLD -1
#define MAX_TIME_THRESHHOLD 10

#define TIME_WEIGHT .7
#define SEG_WEIGHT 1.0
#define IP_WEIGHT 5.0
#define GAUSS_WEIGHT 4.0
#define HIST_WEIGHT 10.0

#define MAX_RANK 10.0

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
#ifndef FAST_MODE
    int ipRating = moduleRanks[DUPLICATE_IP];
    int gaussRating = moduleRanks[DUPLICATE_GAUSSIAN];
#endif
    int histRating = moduleRanks[DUPLICATE_HISTOGRAM];

    if(timeRating <= MIN_TIME_THRESHHOLD ||
       timeRating >= MAX_TIME_THRESHHOLD)
        return timeRating;

    if(segRating <= MIN_SEGMENTED_THRESHHOLD ||
       segRating >= MAX_SEGMENTED_THRESHHOLD)
        return segRating;

#ifndef FAST_MODE
    if(ipRating <= MIN_FOREGROUND_THRESHHOLD ||
       ipRating >= MAX_FOREGROUND_THRESHHOLD)
        return ipRating;
#endif

    // No auto-pass or auto-fail. Calculate.
    rankCalc =  ( SEG_WEIGHT*segRating
#ifndef FAST_MODE
                + IP_WEIGHT*ipRating
                + GAUSS_WEIGHT*gaussRating
#endif
                + HIST_WEIGHT*histRating
                )
                / (SEG_WEIGHT
#ifndef FAST_MODE
                   + IP_WEIGHT
                   + GAUSS_WEIGHT
#endif
                   + HIST_WEIGHT);
    rankCalc *= 1 + TIME_WEIGHT*timeRating/MAX_RANK;
    rankCalc = min((float)10.0, rankCalc);

    return rankCalc;
}

void DuplicateRater::printRanks() {
    cerr << "    ";
    for(unsigned int i=0; i<ratings->size(); ++i) {
        cerr << "       " << i+1 << "              ";
    }
    cerr << endl;

    for(unsigned int i=0; i<ratings->size(); ++i) {
        cerr << i+1 << "||| ";
        for(unsigned int j=0; j<ratings[0].size(); ++j) {
            cerr << setw(2) << j+1 << "{";
            for(int k=0; k<NUM_MODULES; ++k) {
                int rank = (*ratings)[i][j][k];
                cerr << ((rank<0) ? 0 : rank);
                if(k != NUM_MODULES-1)
                    cerr << ", ";
            }
            cerr << "}   ";
        }
        cerr << endl << endl;
    }
}
