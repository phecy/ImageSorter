#ifndef DUPLICATERATER_H
#define DUPLICATERATER_H

#include <QImage>
#include <map>

#define NUM_MODULES 3 // add more as we go

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
           DUP_HISTOGRAM_DIST = 2
       };

    // Creates a numIm x numIm x NUM_MODULES 3d vector
    DuplicateRater(int numImages);

    // Adds a ranking from a module into the 3d vector
    void addRanking(QImage* first, QImage* second,
                   int rank, module_type module);

    // Gets the index of the image. If it doesn't exist, creates it.
    int getIndex(QImage*);

    // Retrieves similarity ranking between two images
    int getRanking(QImage*, QImage*);

    // For debugging purposes
    void printRanks();
private:
    // Given each modules rank, determine similarity
    int calcRank(vector1d moduleRanks);

    // Index [n][m] has a vector of size NUM_MODULES
    // each index in that vector tells the rating from
    // each duplicate detection module. Initialized to -1
    // if no rating available
    vector<vector<vector<int > > > *ratings;

    // This provides a mapping from a QImage* to the
    // index in the above 3d-vector for log(n) access time
    map<QImage*, int>* imageIndeces;

    // The last index used
    int lastIndex;
};

#endif // DUPLICATERATER_H
