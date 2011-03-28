#include <stdlib.h>

#include <QLabel>
#include <QPixmap>
#include <QImage>

#include "vimage.h"

using namespace vw;

VImage::VImage(char* filename) {
    vimage = new VImage_t();
    read_image(*vimage, filename);
    origwidth = vimage->cols();
    origheight = vimage->rows();

    this->fullpath = filename;
    this->filename = strrchr(filename, '/')+1;

    rankTotal = -1;
    adjustedRank = 0;
    makeQImage();
}

VImage::VImage(const VImage& that) {
    vimage = that.vimage;
    width = that.width;
    height = that.height;
    origwidth = that.origwidth;
    origheight = that.origheight;
    qimage = that.qimage;
    filename = that.filename;
}

VImage::~VImage() {
//    if(qimage != NULL)
//        delete qimage;
//    if(vimage != NULL)
//        delete vimage;
//    if(foreground != NULL)
//        delete foreground;
}

void VImage::makeQImage() {
    if(vimage == NULL) return;

    // *4: one per ARGB channel (yes, A is necessary)
    uchar* data = (uchar*)malloc(sizeof(uchar) * origwidth * origheight * 4);

    qimage = new QImage(data,
              origwidth, origheight, QImage::Format_RGB32);

    for(int h=0; h<origheight; ++h) {
        for(int w=0; w<origwidth; ++w) {
            PixelRGB<uint8> pix = (*vimage)(w,h);
            qimage->setPixel(w,h,qRgb(pix.r(), pix.g(), pix.b()));
        }
    }

    QImage* tmp = qimage;
    qimage = new QImage(qimage->scaledToWidth(800));
    delete tmp;
    height = qimage->height();
    width = qimage->width();

    /* DEBUG
    QLabel* imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(QPixmap::fromImage(*qimage));
    setCentralWidget(imageLabel);
    this->show();
    */
}

void VImage::setForeground(boundingBox coords) {
    this->foregroundCoords = coords;
    this->foreground = new QImage
            (this->qimage->copy(coords.first.first, coords.first.second,
                               coords.second.first, coords.second.second));
}


// For sharpdetect and duplicategaussian
// Returns 0-9 based on similarity
int VImage::avgPixelDiff(VImage_t one, VImage_t two) {
    int width = one.cols();
    int height = one.rows();
    // Compare blurred vs normal
    unsigned long long int total = 0;
    for(int w=0; w<width; ++w) {
        for(int h=0; h<height; ++h) {
            // For now, just compare green channel2)
            PixelRGB<unsigned char> pix1 = one(w,h);
            PixelRGB<unsigned char> pix2 = two(w,h);
            int val1 = (pix1.r() + pix1.g() + pix1.b())/3;
            int val2 = (pix2.r() + pix2.g() + pix2.b())/3;
            total += abs(val1 - val2);
            // std::cout << "|" << abs(val1 - val2);
        }
    }
    // Get avg diff per pixel
    total /= width*height;

    return total;
}
