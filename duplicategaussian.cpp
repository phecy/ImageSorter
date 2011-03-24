#include "duplicategaussian.h"

#define GAUSS_DIVIDE_BY 10

DuplicateGaussian::DuplicateGaussian(DuplicateRater *rater) {
    this->rater = rater;
}

// Creates a small gaussian'd copy of the image
void DuplicateGaussian::addImage(VImage* vim) {
    VImage_t blurred = gaussian_filter(*vim->getVImage(), 4.0);
    blurmap[vim] = blurred;
}

// Adds a single ranking to the DuplicateRater
void DuplicateGaussian::rankOne(VImage* first, VImage* second) {
    VImage_t one = blurmap[first];
    VImage_t two = blurmap[second];

    int rating = VImage::avgPixelDiff(one, two) / GAUSS_DIVIDE_BY;
    rating = 10 - rating;
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    rater->addRanking(first, second, rating, DuplicateRater::DUPLICATE_GAUSSIAN);
}
