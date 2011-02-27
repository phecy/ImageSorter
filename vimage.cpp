#include <QLabel>
#include <QPixmap>
#include <QImage>

#include "vimage.h"

using namespace vw;

VImage::VImage(char* filename) {
    vimage = new VImage_t();
    read_image(*vimage, filename);
    width = vimage->cols();
    height = vimage->rows();
    this->filename = filename;
    rankTotal = -1;
    makeQImage();
}

VImage::VImage(const VImage& that) {
    vimage = that.vimage;
    width = that.width;
    height = that.height;
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
    uchar* data = (uchar*)malloc(sizeof(uchar) * width * height * 4);

    qimage = new QImage(data,
              width, height, QImage::Format_RGB32);

    for(int h=0; h<height; ++h) {
        for(int w=0; w<width; ++w) {
            PixelRGB<uint8> pix = (*vimage)(w,h);
            qimage->setPixel(w,h,qRgb(pix.r(), pix.g(), pix.b()));
        }
    }

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
