#ifndef COMMON_H
#define COMMON_H

#include "math.h"

#define FAST_MODE

#define BLUR_SHORTNAME "blur"
#define CONTRAST_SHORTNAME "contrast"
#define EXPOSURE_SHORTNAME "exposure"

#define BLUR_LONGNAME "Is this image blurry?"
#define CONTRAST_LONGNAME "Does this image have high contrast?"
#define EXPOSURE_LONGNAME "Is this image well-exposed?"

// Indeces for low level features
#define LL_BLUR_I 0
#define LL_EXPOSURE_I 1
#define LL_CONTRAST_I 2

// Loading SVR stuff:
#define DEFAULT_CSV_DIR "./trainingdata/"
#define DEFAULT_SVR_DIR "./trainingdata/"
#define DEFAULT_SVR_FILENAME "default.tdat"

// Compute x^(1/3)
static double root3(double num) {
    return pow(num, 1.0/3.0);
}

// Compute x^3
static double pow3(double num) {
    return num*num*num;
}

// Compute x^2
static double pow2(double num) {
    return num*num;
}

#endif // COMMON_H
