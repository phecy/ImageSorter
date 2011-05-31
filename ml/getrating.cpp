#include "getrating.h"
#include "vimage.h"

using namespace std;
using namespace dlib;

GetRating::GetRating(TrainData* traindata)
{
    svr = new Learner(traindata);
}

GetRating::~GetRating() {
    delete svr;
}

// Inserts rating into finalRating field in VImage
void GetRating::rate(std::vector<VImage*>& images) {
    // Gather info
    int numImages = images.size();
    int numFeatures = images[0]->getRanks().size();
    sample_type lowLevelSample; // A single sample, to be saved then
                                //                  written over
    lowLevelSample.set_size(numFeatures);

    // Now we see how well we predicted on the training set
    for(int img_i=0; img_i<numImages; ++img_i) {
        const std::vector<pair<string, float> > features
                                         = images[img_i]->getRanks();
        for(int feat_i=0; feat_i < numFeatures; ++feat_i) {
            lowLevelSample(feat_i) = features[feat_i].second;
        }
        double predictedVal = svr->predict(lowLevelSample);
        cout << "predicted = " << predictedVal << endl;
        images[img_i]->setRank(predictedVal);
    }
}
