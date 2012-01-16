//#include "gsl/gsl_fit.h"

#include "learnercommon.h"
#include "highlevellearner.h"
#include "util/common.h"

HighLevelLearner::HighLevelLearner(int numHlFeatures) {
    for(int i=0; i<numHlFeatures; ++i) {
        svrs.push_back(new LowLevelLearner(i));
    }

    string filename = LearnerCommon::findExistingFile
                                    (string(DEFAULT_SVR_EXT));

    //loadFromFileWrapper(filename);
}

HighLevelLearner::HighLevelLearner
                  (TrainData* traindata, int numHlFeatures) {
    for(int i=0; i<numHlFeatures; ++i) {
        svrs.push_back(new LowLevelLearner(traindata, i));
    }
}
HighLevelLearner::~HighLevelLearner() {
    for(int i=0; i<svrs.size(); ++i)
        delete svrs[i];
}

double HighLevelLearner::prediction(sample_type llSample) {
    double avg = 0;
    for(int hlFeat_i=0; hlFeat_i < svrs.size(); ++hlFeat_i) {
        avg += svrs[hlFeat_i]->predict(llSample);
    }
    avg /= svrs.size();

    return avg;
}
