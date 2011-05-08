#ifndef LEARNER_H
#define LEARNER_H

using namespace std;

#include "vimage.h"

typedef pair<string, double> attribute;

class Learner
{
public:
    Learner(string relation);
    void addAttribute(VImage* vim, string name, double value);

private:
    map<VImage*, attribute> ranks; // Maps an attribute name to its rank
};

#endif // LEARNER_H
