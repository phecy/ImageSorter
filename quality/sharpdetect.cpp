#include "vw/Core.h"

#include "sharpdetect.h"

#define GAUSS_STRENGTH 3

SharpDetect::SharpDetect()
{
}

int SharpDetect::rankOne(VImage* vim) {
    // Get difference between image and blurred image
    QImage* im = vim->getQImage();
    QImage imref = QImage(*im);
    QImage blurred = VImage::gaussianFilter(imref, GAUSS_STRENGTH);

    // Compare blurred vs normal
    int rating = VImage::avgPixelDiff(*im, blurred);
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    //qDebug("SharpDetect rank of %s: %d (avg pixel diff=%lld)",
    //       vim->getFilename(), rating, total);
    return rating;
}
