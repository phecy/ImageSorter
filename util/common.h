#ifndef COMMON_H
#define COMMON_H

#include "math.h"

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
#define DEFAULT_LEARN_FN "default"
#define DEFAULT_LEARN_BASENAME \
DEFAULT_LEARN_DIR DEFAULT_LEARN_FN

// Linear regressor weights
#define DEFAULT_LR_EXT ".wdat"
#define DEFAULT_LR_FILENAME \
DEFAULT_LEARN_BASENAME DEFAULT_LR_EXT

// Support vector regressor
#define DEFAULT_SVR_EXT ".tdat"
#define DEFAULT_SVR_FILENAME \
DEFAULT_LEARN_BASENAME DEFAULT_SVR_EXT

// CSV file loading
#define CSV_FILE_NAME "all_csv_files.txt"
#define CSV_FILE_NAME_LENGTH 100
#define CMD_LENGTH 500

// Compute x^(1/3)
double root3(double num);

// Compute x^3
double pow3(double num);

// Compute x^2
double pow2(double num);

#endif // COMMON_H
