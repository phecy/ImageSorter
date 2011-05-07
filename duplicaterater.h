#ifndef DUPLICATERATER_H
#define DUPLICATERATER_H

#include <map>
#include "vimage.h"

#ifndef FAST_MODE
#define NUM_MODULES 5 // add more as we go
#else
#define NUM_MODULES 3 // add more as we go
#endif
using namespace std;

typedef vector<vector<vector<int > > > vector3d;
typedef vector<vector<int > > vector2d;
typedef vector<int > vector1d;

class DuplicateRater
{
public:
    // The module_type
    enum module_type {
           DUPLICATE_TIME = 0,
           DUPLICATE_SEGMENTED = 1,
           DUPLICATE_IP = 2,
           DUPLICATE_GAUSSIAN = 3,
           DUPLICATE_HISTOGRAM = 4
       };

    // Creates a numIm x numIm x NUM_MODULES 3d vector
    DuplicateRater(int numImages);

    // Adds a ranking from a module into the 3d vector
    void addRanking(VImage* first, VImage* second,
                   int rank, module_type module);

    // Gets the index of the image. If it doesn't exist, creates it.
    int getIndex(VImage*);

    // Retrieves similarity ranking between two images
    float getRanking(VImage*, VImage*);

    // For debugging purposes
    void printRanks();
private:
    // Given each modules rank, determine similarity
    float calcRank(vector1d moduleRanks);

    // Index [n][m] has a vector of size NUM_MODULES
    // each index in that vector tells the rating from
    // each duplicate detection module. Initialized to -1
    // if no rating available
    vector<vector<vector<int > > > *ratings;

    // This provides a mapping from a VImage* to the
    // index in the above 3d-vector for log(n) access time
    map<VImage*, int>* imageIndeces;

    // The last index used
    int lastIndex;
};

#endif // DUPLICATERATER_H
