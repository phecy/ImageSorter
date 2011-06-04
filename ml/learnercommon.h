#ifndef LEARNERCOMMON_H
#define LEARNERCOMMON_H

#include "common.h"

class LearnerCommon
{
public:
    // defaultFn: Try this first
    // ext[4]: Will grab any file with this ending.
    static string findExistingFile(string ext);

private:
    // Returns random file with ext file ending
    static string findFiletype(string ext);

};

#endif // LEARNERCOMMON_H
