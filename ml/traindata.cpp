#include <sstream>
#include <math.h>

#include "common.h"
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

string TrainData::hash() {
    double hashnum=1;

    vector<Features>::iterator img_i;
    vector<double>::iterator feat_i;
    for(img_i=trainingSet.begin(); img_i!=trainingSet.end(); ++img_i) {
        for(feat_i  = img_i->lowLevelFeatures.begin();
            feat_i != img_i->lowLevelFeatures.end();
            ++feat_i) {
            hashnum *= (*feat_i) * (*feat_i);
            hashnum *= img_i->groundTruth;
        }
        for(feat_i  = img_i->highLevelFeatures.begin();
            feat_i != img_i->highLevelFeatures.end();
            ++feat_i) {
            hashnum *= (*feat_i) * (*feat_i);
            hashnum *= img_i->groundTruth;
        }
    }

    stringstream hashstream;
    hashstream << "trainset_";
    hashstream << hashnum;

    string hashed = hashstream.str();
    // Magic number 9 is for size of "trainset_"
    hashed = hashed.substr(0, min(24, 9+(int)hashed.size()-1));
    for(unsigned int i=9; i<hashed.size(); ++i) {
        if(hashed[i]=='.') hashed[i] = '-';
        else if(hashed[i]=='+') hashed[i] = char(i%10 + '0');
        else if(hashed[i]=='e') hashed[i] = char(i%10 + '0');
    }

    cout << "Hashed val: " << hashed << endl;
    return hashed;
}

string TrainData::genHashFilename() {
    return DEFAULT_CSV_DIR + hash() + ".tdat";
}
