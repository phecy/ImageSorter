#include <iostream>

#include "content.h"
#include "vimage.h"

#define GIST_SIZE 32

// These constants taken from the example code in compute_gist.c
static const int NBLOCKS = 4;
static const int N_SCALE = 3;
static const int ORIENTATIONS_PER_SCALE[50]={8,8,4};
static const int DESCRIPTION_LENGTH = 960;

SimilarityContent::SimilarityContent(vector<VImage*> allImages) {
    vector<VImage*>::iterator it;
    for(it = allImages.begin(); it != allImages.end(); ++it) {
        addImage(*it);
    }
}

SimilarityContent::~SimilarityContent() {
    // Remove all the descriptions
    map<const VImage*, float*>::iterator it;
    for(it = descriptions.begin(); it != descriptions.end(); ++it) {
        free(it->second);
    }
}

void SimilarityContent::addImage(VImage *vim) {
    color_image_t* im = makeGistImage(vim);
    float* desc = color_gist_scaletab(
                im, NBLOCKS, N_SCALE, ORIENTATIONS_PER_SCALE);
    color_image_delete(im);

    descriptions[vim] = desc;
}

color_image_t* SimilarityContent::makeGistImage(const VImage* vim) {
    // Convert to a color_image_t
    QImage small = vim->getQImage()->scaled(GIST_SIZE, GIST_SIZE);
    const uchar* data = small.constBits();

    int width = small.width(), height = small.height();
    int area = width*height;
    color_image_t *im = color_image_new(width, height);
    for(int i=0, i3=0; i<area; ++i, i3+=3) {
        im->c1[i]=data[i3+0];
        im->c2[i]=data[i3+1];
        im->c3[i]=data[i3+2];
    }

    return im;
}

float SimilarityContent::compareDescriptions(float* desc1, float* desc2) {
    // Take the difference between the two descriptions
    float totalDiff = 0;
    for(int i=0; i<DESCRIPTION_LENGTH; i++) {
        float diff = desc1[i] - desc2[i];
        totalDiff += diff*diff;
    }

    return 1.f/(1+totalDiff);
}

float SimilarityContent::calculateSimilarity(const VImage* vim1,
                                             const VImage* vim2) {
    float* desc1 = descriptions[vim1];
    float* desc2 = descriptions[vim2];

    float score = compareDescriptions(desc1, desc2);

    return score;
}
