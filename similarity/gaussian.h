#ifndef DUPLICATEGAUSSIAN_H
#define DUPLICATEGAUSSIAN_H

#include "vimage.h"

using namespace std;

class SimilarityGaussian
{
public:
    SimilarityGaussian(vector<VImage*> allImages);

    // Adds the RGB difference between image and it's blurred copy
    float rankOne(VImage* first, VImage* second);

private:
    // Creates a small gaussian'd copy of the image
    void addImage(VImage*);

    map<VImage*, VImage_t> blurmap;
};

#endif // DUPLICATEGAUSSIAN_H
