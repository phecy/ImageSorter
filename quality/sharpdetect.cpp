#include "vw/Core.h"
#include "vw/Image.h"

#include "sharpdetect.h"

SharpDetect::SharpDetect()
{
}

int SharpDetect::rankOne(VImage* vim) {
    // Get difference between image and blurred image
    VImage_t im = *vim->getVImage();
    VImage_t blurred = gaussian_filter(im, 3.0);

    // Compare blurred vs normal
    int rating = VImage::avgPixelDiff(im, blurred);
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    //qDebug("SharpDetect rank of %s: %d (avg pixel diff=%lld)",
    //       vim->getFilename(), rating, total);
    return rating;
}
