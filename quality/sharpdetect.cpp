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

    boundingBox box = vim->getForegroundCoords();
    int w_start = box.first.first;
    int width = box.second.first - w_start;
    int h_start= box.first.second;
    int height = box.second.second - h_start;

    BBox2 bbox(w_start, h_start, width, height);
    CropView<VImage_t> crop_main = crop(im, bbox);
    CropView<VImage_t> crop_blur = crop(blurred, bbox);


    // Compare blurred vs normal
    int rating = VImage::avgPixelDiff(im, blurred);
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    //qDebug("SharpDetect rank of %s: %d (avg pixel diff=%lld)",
    //       vim->getFilename(), rating, total);
    return rating;
}
