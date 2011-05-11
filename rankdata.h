#ifndef RANKDATA_H
#define RANKDATA_H

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

struct AttributeStruct {
    string shortname; // For quick indexing
    string question; // What question does this number answer?
    double apprank; // What this application ouput
    double groundtruth; // What is the true value?
    bool interpret; // Is the question actually inteprpetable
                    // by humans? (ie can we ask Turk about it?)
};

typedef AttributeStruct Attribute;

class RankData
{
public:
    RankData();

private:
    vector<Attribute> attributes;


};

#endif // RANKDATA_H
