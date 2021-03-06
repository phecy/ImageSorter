#include <iostream>
#include "similarity.h"

using namespace std;

Similarity::Similarity(vector<VImage*> allImages) {
    int numImages = allImages.size();

    content = new SimilarityContent(allImages);
    timed = new SimilarityTime(allImages);
    histogram = new SimilarityHistogram(allImages);
#ifndef FAST_MODE
    gaussian = new SimilarityGaussian(allImages);
#endif

    // Initialize a numImages-by-numImages array to -1
    similarityMatrix = vector<vector<float> >(numImages);
    for(int i=0; i<numImages; ++i) {
        similarityMatrix[i] = vector<float>(numImages, -1);
    }
}


float Similarity::getSimilarity(const VImage* one, const VImage* two) {
    int one_i = one->getIndex();
    int two_i = two->getIndex();

    float rank = similarityMatrix[one_i][two_i];
    if(rank == -1) // Empty
        return calculateSimilarity(one, two);
    else
        return rank;
}

float Similarity::calculateSimilarity(const VImage* one, const VImage* two) {
    // Get each module's rating
    float contentSimilarity = content->calculateSimilarity(one, two);
    float timeSimilarity = timed->calculateSimilarity(one, two);
    float histSimilarity = histogram->calculateSimilarity(one, two);
#ifndef FAST_MODE
    float gausSimilarity = gaussian->calculateSimilarity(one, two);
#endif

    float rank = timeSimilarity + histSimilarity +
                 gausSimilarity + contentSimilarity;;
    rank = contentSimilarity + timeSimilarity; // TODO remove this?
    // cout << "Rank is " << rank << ": time=" << timeSimilarity << ", hist="
    //      << histSimilarity << ", gaus=" << gausSimilarity 
    //      << ", content=" << contentSimilarity << endl;

    // Update internal structure
    addSimilarityRating(one, two, rank);

    return rank;
}

void Similarity::addSimilarityRating(const VImage* one, const VImage* two, float ranking) {
    int one_i = one->getIndex();
    int two_i = two->getIndex();

    similarityMatrix[one_i][two_i] = ranking;
    similarityMatrix[two_i][one_i] = ranking;
}
