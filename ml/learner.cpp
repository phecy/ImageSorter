#include <iostream>
#include <vector>

#include "dlib/svm.h"
#include "dlib/data_io.h"

#include "common.h"
#include "learner.h"

using namespace std;
using namespace dlib;

Learner::Learner()
{
}

void Learner::learn(TrainData trainingset) {
    int numImages = trainingset.size();
    if(numImages == 0) return;
    int numFeatures = NUM_LL_FEATURES;

    // Make features and label vectors
    std::vector<sample_type> llsamples;
    std::vector<float> lltargets;

    // Create the samples for the low-level features,
    // training them to the "ground truth" for now,
    // and later, to the high-level features
    sample_type lowLevelSample; // A single sample, to be saved then
                                //                  written over
    lowLevelSample.set_size(numFeatures);
    for (int img_i=0; img_i<numImages; ++img_i)
    {
        for(int llFeat_i=0; llFeat_i<numFeatures; ++llFeat_i) {
            lowLevelSample(llFeat_i) = trainingset.getLLFeature(img_i, llFeat_i);
        }

        llsamples.push_back(lowLevelSample);
        /*
        int hlFeat_i = 0; // Loop this after Low Levels work
        lltargets.push_back(trainingset.getHLFeature(img_i, hlFeat_i));
        */
        lltargets.push_back(trainingset.getGroundTruth(img_i));
    }

    // Now setup a SVR trainer object.  It has three parameters, the kernel and
    // two parameters specific to SVR.
    svr_trainer<kernel_type> trainer;
    trainer.set_kernel(kernel_type(0.01));

    // This parameter is the usual regularization parameter.  It determines the trade-off
    // between trying to reduce the training error or allowing more errors but hopefully
    // improving the generalization of the resulting function.  Larger values encourage exact
    // fitting while smaller values of C may encourage better generalization.
    trainer.set_c(5); // Default 10

    // Epsilon-insensitive regression means we do regression but stop trying to fit a data
    // point once it is "close enough" to its target value.  This parameter is the value that
    // controls what we mean by "close enough".  In this case, I'm saying I'm happy if the
    // resulting regression function gets within 1 of the target value.
    trainer.set_epsilon_insensitivity(.1); // Default 0.001

    // Now do the training and save the results
    llDecisionFcn = trainer.train(llsamples, lltargets);


    // The first column is the true value of the sinc function and the second
    // column is the output from the SVR estimate.

    // We can also do 5-fold cross-validation and find the mean squared error.  Note that
    // we need to randomly shuffle the samples first.  See the svm_ex.cpp for a discussion of
    // why this is important.
    randomize_samples(llsamples, lltargets);
    cout << "TRAINING INFO -------------------" << endl;
    cout << "MSE: "<< cross_validate_regression_trainer(
                        trainer, llsamples, lltargets, 5) << endl;

    // Now we see how well we predicted on the training set
    for(int img_i=0; img_i<numImages; ++img_i) {
        for(int feat_i=0; feat_i < numFeatures; ++feat_i) {
            lowLevelSample(feat_i)
                 = trainingset.getLLFeature(img_i, feat_i);
        }
        cout << "actual = " << trainingset.getGroundTruth(img_i) << endl
             << "predicted = " << llDecisionFcn(lowLevelSample) << endl;
    }

    // Save so we only train once
    save_libsvm_formatted_data(trainingset.hash(), llsamples, lltargets);
}
