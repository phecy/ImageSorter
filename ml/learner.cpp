#include <iostream>
#include <fstream>
#include <vector>

#include "dlib/svm.h"
#include "dlib/data_io.h"

#include "common.h"
#include "learner.h"

using namespace std;
using namespace dlib;

typedef std::map<unsigned long, float> sparse_sample;

Learner::Learner(TrainData* trainingset)
{
    int numImages = trainingset->size();
    if(numImages == 0) return;
    int numFeatures = trainingset->numLLFeatures();


    // Make features and label vectors
    std::vector<float> lltargets;
    std::vector<sample_type> llsamples;

    // Read if file exists
    string filename = DEFAULT_CSV_DIR + trainingset->hash() + ".tdat";
    ifstream ifile(filename.c_str());
    if (ifile) {
        // This file exists already
        std::vector<sparse_sample> sparsesamples;
        load_libsvm_formatted_data(filename, sparsesamples, lltargets);
        llsamples = sparse_to_dense(sparsesamples);
    } else {
        loadSamples(trainingset, llsamples, lltargets);
    }
    train(llsamples, lltargets);

    // Save for future use
    save_libsvm_formatted_data(filename, llsamples, lltargets);

    // Now we see how well we predicted on the training set
    cerr << "TRAINING INFO -------------------" << endl;
    sample_type lowLevelSample;
    lowLevelSample.set_size(numFeatures);
    for(int img_i=0; img_i<numImages; ++img_i) {
        for(int feat_i=0; feat_i < numFeatures; ++feat_i) {
            lowLevelSample(feat_i)
                 = trainingset->getLLFeature(img_i, feat_i);
        }
        cerr << "actual = " << trainingset->getGroundTruth(img_i)
             << "      predicted = " << predict(lowLevelSample) << endl;
    }
}

void Learner::loadSamples(TrainData* trainingset,
                 std::vector<sample_type>& llsamples,
                 std::vector<float>& lltargets) {
    int numImages = trainingset->size();
    int numFeatures = trainingset->numLLFeatures();

    // Create the samples for the low-level features,
    // training them to the "ground truth" for now,
    // and later, to the high-level features
    sample_type lowLevelSample; // A single sample, to be saved then
                                //                  written over
    lowLevelSample.set_size(numFeatures);
    for (int img_i=0; img_i<numImages; ++img_i)
    {
        for(int llFeat_i=0; llFeat_i<numFeatures; ++llFeat_i) {
            lowLevelSample(llFeat_i) = trainingset->getLLFeature(img_i, llFeat_i);
        }

        llsamples.push_back(lowLevelSample);
        /*
        int hlFeat_i = 0; // Loop this after Low Levels work
        lltargets.push_back(trainingset->getHLFeature(img_i, hlFeat_i));
        */
        lltargets.push_back(trainingset->getGroundTruth(img_i));
    }
}

void Learner::train(std::vector<sample_type>& llsamples,
                 std::vector<float>& lltargets) {

    // Now setup a SVR trainer object.  It has three parameters, the kernel and
    // two parameters specific to SVR.
    svr_trainer<kernel_type> trainer;
    trainer.set_kernel(kernel_type(0.01));

    // Smaller C = better generalization, Larger = Better fit
    trainer.set_c(5); // Default 10

    // What is "close enough"?
    trainer.set_epsilon_insensitivity(.1); // Default 0.001

    // Now do the training and save the results
    llDecisionFcn = trainer.train(llsamples, lltargets);

    // 5-fold cross-validation and mean squared error.
    randomize_samples(llsamples, lltargets);
    cerr << "MSE: "<< cross_validate_regression_trainer(
                        trainer, llsamples, lltargets, 5) << endl;
}

double Learner::predict(sample_type lowLevelSample) {
    return llDecisionFcn(lowLevelSample);
}
