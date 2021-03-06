#ifndef LEARNER_H
#define LEARNER_H

#include "dlib/svm.h"
#include "traindata.h"

using namespace std;

// Samples will be variable-dimension column vectors.
typedef dlib::matrix<float, 0, 1> sample_type;

// Default good results without fiddling
typedef dlib::radial_basis_kernel<sample_type> kernel_type;


/**
Given a set of low level features and high level labels,
train each low level to each high level.
For now, each high level will get a weight. Later, we will
train high-levels to combine too.
*/
class LowLevelLearner
{
public:
    LowLevelLearner(int hlFeat_i); // Looks for most recent training data
    LowLevelLearner(TrainData* imageData, int hlFeat_i); // Uses specified data

    double predict(sample_type lowLevelSample);

    void normalize(std::vector<sample_type>& llsamples);
    sample_type normalize(sample_type lowLevelSample);

private:
    dlib::decision_function<kernel_type> llDecisionFcn;
    dlib::vector_normalizer<sample_type> normalizer;
    int hlFeat_i; // Which high level feature are we training to?

    // Calls loadFromFile and exits on failure
    void loadFromFileWrapper(string filename);
    // Returns true if file existed and successfully loaded
    bool loadFromFile(string filename,
                      std::vector<sample_type>& llsamples,
                      std::vector<float>& lltargets);

    // Learn each low level feature to each high level truth
    void loadSamples(TrainData* trainingset,
                     std::vector<sample_type>& llsamples,
                     std::vector<float>& lltargets);
    void train(std::vector<sample_type>& llsamples,
               std::vector<float>& lltargets);
};

#endif // LEARNER_H
