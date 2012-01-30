#ifndef SIMILARITYCONTENT_H
#define SIMILARITYCONTENT_H

#include <map>

#include "lear_gist/gist.h"

#include "vimage.h"

class SimilarityContent
{
public:
    SimilarityContent(vector<VImage*> allImages);
    ~SimilarityContent();

    float calculateSimilarity(const VImage* first, const VImage* second);

private:
    void addImage(VImage*);

    // Sum of square diffs
    float compareDescriptions(float* desc1, float* desc2);

    // Returns an image in the proper format for the library
    color_image_t* makeGistImage(const VImage* vim);

    std::map<const VImage*, float*> descriptions;
};

#endif // SIMILARITYCONTENT_H
