#ifndef DUPLICATEGAUSSIAN_H
#define DUPLICATEGAUSSIAN_H

#include "duplicaterater.h"
#include "vimage.h"

using namespace std;

class DuplicateGaussian
{
public:
    DuplicateGaussian(DuplicateRater *rater);

    // Creates a small gaussian'd copy of the image
    void addImage(VImage*);

    // Adds a single ranking to the DuplicateRater
    void rankOne(VImage*, VImage*);

private:
    map<VImage*, VImage_t> blurmap;

    DuplicateRater* rater;
};

#endif // DUPLICATEGAUSSIAN_H
