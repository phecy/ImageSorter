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
    int w_end = box.second.first;
    int h_start= box.first.second;
    int h_end = box.second.second;

    // Compare blurred vs normal
    unsigned long long int total = 0;
    for(int w=w_start; w<w_end; ++w) {
        for(int h=h_start; h<h_end; ++h) {
            // For now, just compare green channel2)
            PixelRGB<unsigned char> pix1 = im(w,h);
            PixelRGB<unsigned char> pix2 = blurred(w,h);
            int val1 = (pix1.r() + pix1.g() + pix1.b())/3;
            int val2 = (pix2.r() + pix2.g() + pix2.b())/3;
            total += abs(val1 - val2);
            // std::cout << "|" << abs(val1 - val2);
        }
    }
    // Get avg diff per pixel
    total /= (w_end-w_start)*(h_end-h_start);

    // Determine a ranking from it
    int rating = total;
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    //qDebug("SharpDetect rank of %s: %d (avg pixel diff=%lld)",
    //       vim->getFilename(), rating, total);
    return rating;
}
