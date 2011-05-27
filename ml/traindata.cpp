#include "traindata.h"

TrainData::TrainData()
{
}

double TrainData::getLLFeature(int img_i, int feature_i) {
    return trainingSet.at(img_i).lowLevelFeatures.at(feature_i);
}
double TrainData::getHLFeature(int img_i, int feature_i) {
    return trainingSet.at(img_i).highLevelFeatures.at(feature_i);
}
double TrainData::getGroundTruth(int img_i) {
    return trainingSet.at(img_i).groundTruth;
}
void TrainData::addSample(
        vector<double> lowLevelFeatures,
        vector<double> highLevelFeatures,
        double groundTruth) {

    Features features;
    features.lowLevelFeatures = lowLevelFeatures;
    features.highLevelFeatures = highLevelFeatures;
    features.groundTruth = groundTruth;

    trainingSet.push_back(features);
}
