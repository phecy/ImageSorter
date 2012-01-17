#include "gaussian.h"

#define GAUSS_WIDTH_THUMBNAIL 25
#define GAUSS_DIVIDE_BY 10

SimilarityGaussian::SimilarityGaussian(vector<VImage*> allImages) {
}

// Adds a single ranking to the SimilarityRater
float SimilarityGaussian::calculateSimilarity(VImage* first, VImage* second) {
    QImage one = first->getQImage()->scaledToWidth(GAUSS_WIDTH_THUMBNAIL);
    QImage two = second->getQImage()->scaledToWidth(GAUSS_WIDTH_THUMBNAIL);

    int rating = VImage::avgPixelDiff(one, two) / GAUSS_DIVIDE_BY;
    rating = 10 - rating;
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    return rating;
}
