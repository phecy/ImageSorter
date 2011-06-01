#include "getrating.h"
#include "vimage.h"

using namespace std;
using namespace dlib;

GetRating::GetRating(int numHlFeatures) {
    for(int i=0; i<numHlFeatures; ++i) {
        svrs.push_back(new Learner(i));
    }
}

GetRating::GetRating(TrainData* traindata, int numHlFeatures) {
    for(int i=0; i<numHlFeatures; ++i) {
        svrs.push_back(new Learner(traindata, i));
    }
}

GetRating::~GetRating() {
    for(int i=0; i<svrs.size(); ++i)
        delete svrs[i];
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
        double predictedVal = avgPrediction(llSample);
        images[img_i]->setRank(predictedVal);
    }
}

double GetRating::avgPrediction(sample_type llSample) {
    double avg = 0;
    for(int hlFeat_i=0; hlFeat_i < svrs.size(); ++hlFeat_i) {
        avg += svrs[hlFeat_i]->predict(llSample);
    }
    avg /= svrs.size();

    return avg;
}
