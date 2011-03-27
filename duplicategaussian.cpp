#include "duplicategaussian.h"
#include "display.h"

#define GAUSS_DIVIDE_BY 8

DuplicateGaussian::DuplicateGaussian(DuplicateRater *rater) {
    this->rater = rater;
}

// Creates a small gaussian'd copy of the image
void DuplicateGaussian::addImage(VImage* vim) {
    VImage_t blurred = gaussian_filter(*vim->getVImage(), 2.0);
    blurmap[vim] = blurred;


//    display* d = new display();
//    vector<VImage*> v;
//    v.push_back(vim);
//    d->setImageData(v,1,1);
//    d->show();
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
