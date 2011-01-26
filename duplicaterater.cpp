#include "duplicaterater.h"

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
    return moduleRanks[0]; // Do some complicated formula later
}
