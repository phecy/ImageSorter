#include "getrating.h"
#include "vimage.h"

using namespace std;
using namespace dlib;

GetRating::GetRating(int numHlFeatures) {
    hlLearner = new HighLevelLearner(numHlFeatures);
}

GetRating::GetRating(TrainData* traindata, int numHlFeatures) {
    hlLearner = new HighLevelLearner(traindata, numHlFeatures);
}

GetRating::~GetRating() {
    delete hlLearner;
}

// Inserts rating into finalRating field in VImage
void GetRating::rate(std::vector<VImage*>& images) {
    // Gather info
    int numImages = images.size();
    int numLLFeatures = images[0]->getRanks().size();
    sample_type llSample; // A single low level sample, to be saved then
                          //  written over
    llSample.set_size(numLLFeatures);

    // Now we see how well we predicted on the training set
    for(int img_i=0; img_i<numImages; ++img_i) {
        const std::vector<pair<string, float> > features
                                         = images[img_i]->getRanks();
        for(int feat_i=0; feat_i < numLLFeatures; ++feat_i) {
            llSample(feat_i) = features[feat_i].second;
        }
        double predictedVal = prediction(llSample);
        images[img_i]->setRank(predictedVal);
    }
}

double GetRating::prediction(sample_type llSample) {
    hlLearner->prediction(llSample);
}
