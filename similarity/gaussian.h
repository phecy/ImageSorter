#ifndef SIMILARITYGAUSSIAN_H
#define SIMILARITYGAUSSIAN_H

#include <map>
#include "vimage.h"

using namespace std;

class SimilarityGaussian
{
public:
    SimilarityGaussian(vector<VImage*> allImages);

    // Adds the RGB difference between image and it's blurred copy
    float calculateSimilarity(VImage* first, VImage* second);

private:
};

#endif // SIMILARITYGAUSSIAN_H
