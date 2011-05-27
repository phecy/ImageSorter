/**
Use this class to get a ranking on a new image
*/

#ifndef GETRATING_H
#define GETRATING_H

#include "common.h"
#include "ml/learner.h"

using namespace std;

class GetRating
{
public:
    GetRating();
    double rate(const vector<double>& lowLevels);

private:
    Learner learner;
};

#endif // GETRATING_H
