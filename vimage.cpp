#include <stdlib.h>

#include <QLabel>
#include <QPixmap>
#include <QImage>

#include "vimage.h"
#include "limits.h"

using namespace vw;

VImage::VImage(char* filename) {
    vimage = new VImage_t();
    read_image(*vimage, filename);
    origwidth = vimage->cols();
    origheight = vimage->rows();

    this->fullpath = filename;
    this->filename = strrchr(filename, '/')+1;
    this->ip_fullpath = filename;
    ip_fullpath.append(".iplist");

    quality = -1;
    makeQImage();
    histograms = VImage::makeHistograms(this, 0, 0, width, height);
    makeMedianAndAvgColors();
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
#ifndef FAST_MODE
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
#else
    qimage = new QImage(fullpath);
#endif
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

void VImage::makeMedianAndAvgColors() {
    medianColors = vector<int>(HNUMCOLORS, 0);
    int area = width * height;
    int mid = area / 2;
    int colorCounts[HNUMCOLORS] = {0, 0, 0, 0};
    unsigned long long int colorSums[HNUMCOLORS] = {0, 0, 0, 0};
    for(int h=0; h<256; ++h) {
        for(int i=0; i<HNUMCOLORS; ++i) {
            colorCounts[i] += histograms[i][h] * area;
            if(colorCounts[i] >= mid && colorCounts[i] <= area) {
                medianColors[i] = h;
                colorCounts[i] = area+1; // ignore from now on
            }
            colorSums[i] += histograms[i][h]*area * h;
        }
    }

    // Make avg
    avgColors = vector<int>(HNUMCOLORS);
    for(int i=0; i<HNUMCOLORS; ++i) {
        avgColors[i] = colorSums[i] / area;
    }
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

histogramSet VImage::makeHistograms(VImage* vim,
                       int x, int y, int width, int height) {
    histogramSet histograms = histogramSet(HNUMCOLORS,
                              vector<float>(256, 0.0));

    if(x+width > vim->getWidth() ||
       y+height > vim->getHeight()) {
        qDebug("Invalid histogram dimension.");
        return histograms;
    }

    QImage* qimage = vim->getQImage();

    // Make histogram
    for(int h=y; h<height+y; ++h) {
        for(int w=x; w<width+x; ++w) {
            QRgb color = qimage->pixel(w, h);
            int gray = qGray(color);
            int red = qRed(color);
            int green = qGreen(color);
            int blue = qBlue(color);

            ++histograms[HBLACK][gray];
            ++histograms[HRED][red];
            ++histograms[HGREEN][green];
            ++histograms[HBLUE][blue];
        }
    }

    // Scale hist to get %
    int area = width * height;
    for(int h=0; h<256; ++h) {
        for(int i=0; i<HNUMCOLORS; ++i) {
            histograms[i][h] /= area;
        }
    }

    return histograms;
}

void VImage::addQuality(string attributeName, double value)  {
    qualities.push_back(pair<string, double>
                        (attributeName, value));
}
