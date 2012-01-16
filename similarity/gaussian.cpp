#include "duplicates/gaussian.h"
#include "display/imgviewer.h"

#define GAUSS_DIVIDE_BY 10

SimilarityGaussian::SimilarityGaussian(SimilarityRater *rater) {
    vector<VImage*>::iterator it;
    for(it = allImages.begin(); it != allImages.end(); ++it) {
        addImage(*it);
    }
}

// Creates a small gaussian'd copy of the image
void SimilarityGaussian::addImage(VImage* vim) {
    VImage_t blurred = gaussian_filter(*vim->getVImage(), 1.0);
    blurmap[vim] = blurred;
}

// Adds a single ranking to the SimilarityRater
float SimilarityGaussian::rankOne(VImage* first, VImage* second) {
    VImage_t one = blurmap[first];
    VImage_t two = blurmap[second];

    int rating = VImage::avgPixelDiff(one, two) / GAUSS_DIVIDE_BY;
    rating = 10 - rating;
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    return rating;
}
