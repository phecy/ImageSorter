Similarity::Similarity(vector<VImage*> allImages) {
    int numImages = allImages.size();

    timed = new DuplicateTime();
    histogram = new DuplicateHistogram();
#ifndef FAST_MODE
    gaussian = new DuplicateGaussian();
#endif

    // Initialize a numImages-by-numImages array to -1
    similarityMatrix =
        vector<vector<float>(
              <vector<float>(-1, numImages),
                                 numImages);
}


VImage* Similarity::getSimilarity(VImage* one, VImage* two) {
    int one_i = one->getIndex();
    int two_i = two->getIndex();

    float rank = similarityMatrix[one_i][two_i];
    if(rank == -1) // Empty
        return calculateSimilarity(one, two);
    else
        return rank;
}

float Similarity::calculateSimilarity(VImage* one, VImage* two) {
    // Get each module's rating
    timed->calculateSimilarity(one, two);
    histogram->calculateSimilarity(one, two);
#ifndef FAST_MODE
    gaussian->calculateSimilarity(one, two);
#endif

    // Combine them TODO
    float rank = 0;

    // Update internal structure
    addSimilarityRating(one, two, rank);

    return rank;
}

void addSimilarityRating(VImage* one, VImage* two, float ranking) {
    int one_i = one->getIndex();
    int two_i = two->getIndex();

    similarityMatrix[one_i][two_i] = ranking;
    similarityMatrix[two_i][one_i] = ranking;
}
