/**
Use this class to get a ranking on a new image
Serves as a connection between VImages and learner
*/

#ifndef GETRATING_H
#define GETRATING_H

#include "common.h"
#include "vimage.h"
#include "ml/learner.h"

using namespace std;

class GetRating
{
public:
    GetRating(); // Use last .tdat, or a random if last not found
    GetRating(TrainData*); // Retrain on this data
    ~GetRating();
    void rate(vector<VImage*>& images);

private:
    Learner* svr;
};

#endif // GETRATING_H
