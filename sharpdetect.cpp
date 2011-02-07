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
    VImage_t result = blurred - im;

    // Compare blurred vs normal
    int width = result.cols();
    int height = result.rows();
    unsigned long long int total = 0;
    for(int w=0; w<width; ++w) {
        for(int h=0; h<height; ++h) {
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
    total /= width*height;

    // Determine a ranking from it
    int rating = total;
    rating = rating < 0 ? 0 : rating > 9 ? 9 : rating; // 0<=r<=9

    qDebug("SharpDetect rank of %s: %d (avg pixel diff=%lld)",
           vim->getFilename(), rating, total);
    return rating;
}
