/**
Use this class to get a ranking on a new image
Serves as a connection between VImages and learner
*/

#ifndef GETRATING_H
#define GETRATING_H

#include "common.h"
#include "vimage.h"
#include "ml/highlevellearner.h"

using namespace std;

class GetRating
{
public:
    // Constructors need to know how many weak learners to use

    // Use last .tdat, or a random if last not found
    GetRating(int numHlFeatures);

    // Train on given data
    GetRating(TrainData*, int numHLFeatures);
    ~GetRating();

    // Get a rating for all images
    void rate(vector<VImage*>& images);

private:
    HighLevelLearner* hlLearner;

    // Average over all svrs
    double prediction(sample_type llSample);
};

#endif // GETRATING_H
