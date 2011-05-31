#ifndef RANKDATA_H
#define RANKDATA_H

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class TrainData
{
public:
    TrainData();
    void addSample(vector<double> lowLevelFeatures,
                   vector<double> highLevelFeatures,
                   double groundTruth);
    int size()
        { return trainingSet.size(); }
    int numLLFeatures()
        { return trainingSet[0].lowLevelFeatures.size(); }

    double getLLFeature(int img_i, int feature_i);
    double getHLFeature(int img_i, int feature_i);
    double getGroundTruth(int img_i);
    string hash(); // Unique string for this training set
    string genHashFilename(); // File name and directory

private:
    struct FeaturesStruct {
        vector<double> lowLevelFeatures;
        vector<double> highLevelFeatures;
        double groundTruth;
    };
    typedef FeaturesStruct Features;

    vector<Features> trainingSet;
};

#endif // RANKDATA_H
