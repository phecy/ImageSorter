#include <stdlib.h>

#include <QLabel>
#include <QPixmap>
#include <QImage>

#include "vimage.h"
#include "limits.h"

VImage::VImage(char* filename) {
    this->fullpath = filename;
    this->filename = strrchr(filename, '/')+1;
    this->ip_fullpath = filename;
    ip_fullpath.append(".iplist");

    quality = -1;
    makeQImage();
    origheight = qimage->height();
    origwidth = qimage->width();

    histograms = VImage::makeHistograms(this, 0, 0, width, height);
    makeMedianAndAvgColors();
}

VImage::~VImage() {
//    if(qimage != NULL)
//        delete qimage;
}

void VImage::makeQImage() {
    qimage = new QImage(fullpath);
    height = qimage->height();
    width = qimage->width();
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
int VImage::avgPixelDiff(const QImage& one, const QImage& two) {
    int width = one.width();
    int height = one.height();
    // Compare blurred vs normal
    unsigned long long int total = 0;
    for(int w=0; w<width; ++w) {
        for(int h=0; h<height; ++h) {
            // For now, just compare green channel2)
            QRgb pix1 = one.pixel(w,h);
            QRgb pix2 = two.pixel(w,h);
            int val1 = qGray(pix1);
            int val2 = qGray(pix2);
            total += abs(val1 - val2);
            // std::cout << "|" << abs(val1 - val2);
        }
    }
    // Get avg diff per pixel
    total /= width*height;

    return total;
}

HistogramSet VImage::makeHistograms(VImage* vim,
                       int x, int y, int width, int height) {
    HistogramSet histograms = HistogramSet(HNUMCOLORS,
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

void VImage::setQuality(string attributeName, double value)  {
    qualities.push_back(pair<string, double>
                        (attributeName, value));
}

QImage VImage::gaussianFilter(const QImage& im, float strength) {
    int unscaledWidth = im.width();
    QImage small = im.scaledToWidth(unscaledWidth/strength);
    QImage large = small.scaledToWidth(unscaledWidth);
    return large;
}
