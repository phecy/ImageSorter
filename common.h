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
#define DEFAULT_LEARN_DIR "./trainingdata/"
#define CSV_FILE_NAME "all_csv_files.txt"
#define CSV_FILE_NAME_LENGTH 100
#define CMD_LENGTH 500
#define DEFAULT_SVR_FILENAME "default.tdat"

// Compute x^(1/3)
static double root3(double num);

// Compute x^3
static double pow3(double num);

// Compute x^2
static double pow2(double num);

#endif // COMMON_H
