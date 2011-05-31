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
    GetRating(TrainData*);
    ~GetRating();
    void rate(vector<VImage*>& images);

private:
    Learner* svr;
};

#endif // GETRATING_H
