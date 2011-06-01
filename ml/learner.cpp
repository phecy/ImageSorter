#include <iostream>
#include <fstream>
#include <vector>
#include "dirent.h"

#include "dlib/svm.h"
#include "dlib/data_io.h"

#include "common.h"
#include "learner.h"

using namespace std;
using namespace dlib;

typedef std::map<unsigned long, float> sparse_sample;

Learner::Learner() {
    // Try default. If fail, try any. If fail, exit.
    string filename = DEFAULT_SVR_DIR
                      DEFAULT_SVR_FILENAME;
    ifstream ifile(filename.c_str());
    if (!ifile) {
        // Not default. Try to find any.
        filename = getAnyTdat();
        if(filename == "") {
            cerr << "No training data found!"
                 << "Please train the app first.\n"
                 << "Files belong in "
                 << DEFAULT_SVR_DIR << endl;
            exit(1);
        }
    }

    loadFromFileWrapper(filename);
}

void Learner::loadFromFileWrapper(string filename) {
    std::vector<float> lltargets;
    std::vector<sample_type> llsamples;

    if(!loadFromFile(filename, llsamples, lltargets)) {
        cerr << "Could not load the SVR: " + filename << endl;
        exit(1);
    }
    normalizer.train(llsamples);
    normalize(llsamples);
    train(llsamples, lltargets);
}

Learner::Learner(TrainData* trainingset)
{
    // Make features and label vectors
    std::vector<float> lltargets;
    std::vector<sample_type> llsamples;
    std::vector<sample_type> llsamples_norm;

    // Load, normalize, and train
    loadSamples(trainingset, llsamples, lltargets);
    normalizer.train(llsamples);
    llsamples_norm = llsamples;
    normalize(llsamples_norm);
    train(llsamples_norm, lltargets);

    // Save knowledge as hashed and as default
    // using unnormalized data!
    string filename = trainingset->genHashFilename();
    save_libsvm_formatted_data(filename, llsamples, lltargets);
    filename = DEFAULT_SVR_DIR
               DEFAULT_SVR_FILENAME;
    save_libsvm_formatted_data(filename, llsamples, lltargets);

    // Now we see how well we predicted on the training set
    int numImages = trainingset->size();
    int numFeatures = trainingset->numLLFeatures();
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

string Learner::getAnyTdat() {
    DIR *dir = opendir (DEFAULT_SVR_DIR);
    if (dir == NULL) return "";

    struct dirent *entry;
    while ((entry = readdir (dir)) != NULL) {
        string fn(entry->d_name);
        int fnsize = fn.size();
        if(fnsize > 7 && fn.substr(fnsize-6) == ".tdat") {
            closedir (dir);
            return fn;
        }
    }
    closedir (dir);
    return "";
}

bool Learner::loadFromFile(string filename,
                           std::vector<sample_type>& llsamples,
                           std::vector<float>& lltargets) {
    ifstream ifile(filename.c_str());
    if (!ifile) return false;

    std::vector<sparse_sample> sparsesamples;
    load_libsvm_formatted_data(filename, sparsesamples, lltargets);

    llsamples = sparse_to_dense(sparsesamples);
    return true;
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

    // Learn the mean and stddev of the samples
    normalizer.train(llsamples);
    std::vector<sample_type> normsamples;
    // Then normalize each sample
    for (unsigned long i = 0; i < llsamples.size(); ++i) {
        normsamples.push_back(normalizer(llsamples[i]));
    }
    // And save
    string fn = trainingset->genHashNormFilename();
    save_libsvm_formatted_data(fn, llsamples, normsamples);
}

void Learner::train(std::vector<sample_type>& llsamples,
                    std::vector<float>& lltargets) {
    // Now setup a SVR trainer object.  It has three parameters, the kernel and
    // two parameters specific to SVR.
    svr_trainer<kernel_type> trainer;
    trainer.set_kernel(kernel_type(1));

    // Smaller C = better generalization, Larger = Better fit
    trainer.set_c(5); // Default 10

    // What is "close enough"?
    trainer.set_epsilon_insensitivity(.1); // Default 0.001

    // Now do the training and save the results
    llDecisionFcn = trainer.train(llsamples, lltargets);
}

void Learner::normalize(std::vector<sample_type>& llsamples) {
    for (unsigned long i = 0; i < llsamples.size(); ++i) {
        llsamples[i] = normalizer(llsamples[i]);
    }
}

sample_type Learner::normalize(sample_type lowLevelSample) {
    return normalizer(lowLevelSample);
}

double Learner::predict(sample_type lowLevelSample) {
    return llDecisionFcn(normalize(lowLevelSample));
}
