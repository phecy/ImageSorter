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
class Learner
{
public:
    Learner(); // Looks for most recent training data
    Learner(TrainData* imageData); // Uses specified data
    Learner(string filename); // Loads from tdat file

    // Returns first tdat found
    string getAnyTdat();

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

    double predict(sample_type lowLevelSample);

private:
    dlib::decision_function<kernel_type> llDecisionFcn;
};

#endif // LEARNER_H
