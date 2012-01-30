#ifndef HIGHLEVELLEARNER_H
#define HIGHLEVELLEARNER_H

#include "lowlevellearner.h"

class HighLevelLearner
{
public:
    HighLevelLearner(int numHlFeatures);
    HighLevelLearner(TrainData* traindata, int numHlFeatures);
    ~HighLevelLearner();
    double prediction(sample_type s);
private:
    vector<LowLevelLearner*> svrs;
};

#endif // HIGHLEVELLEARNER_H
