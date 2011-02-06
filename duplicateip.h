#ifndef DUPLICATEIP_H
#define DUPLICATEIP_H

#include "duplicaterater.h"
#include "vimage.h"

class DuplicateIp
{
public:
    DuplicateIp(DuplicateRater* rater);
    void addImage(VImage);

private:
    DuplicateRater* rater;
};

#endif // DUPLICATEIP_H
