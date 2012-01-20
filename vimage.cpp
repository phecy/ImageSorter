#include <assert.h>
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

// Sqrt of sum of squared differences of the pixels
float VImage::l2norm(const QImage& one, const QImage& two) {
    assert(one.size() == two.size());

    int width = one.width();
    int height = one.height();
    // Compare blurred vs normal
    unsigned long long int total = 0;
    for(int w=0; w<width; ++w) {
        for(int h=0; h<height; ++h) {
            // For now, just compare green channel2)
            QRgb pix1 = one.pixel(w,h);
            QRgb pix2 = two.pixel(w,h);
            int valRed = abs(qRed(pix1) - qRed(pix2));
            int valBlu = abs(qBlue(pix1) - qBlue(pix2));
            int valGre = abs(qGreen(pix1) - qGreen(pix2));
            int sum = valRed*valRed + valBlu*valBlu + valGre*valGre;
            total += sum;
            // std::cout << "|" << abs(val1 - val2);
        }
    }
    // Get avg diff per pixel
    total /= width*height;

    return sqrt(total);
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
    qualitiesVec.push_back(pair<string, double>
                        (attributeName, value));
}

// From qpixmapfilter.cpp
static QImage blurred(const QImage& image, int radius) {
    int tab[] = { 14, 10, 8, 6, 5, 5, 4, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2 };
    int alpha = (radius < 1) ? 16 : (radius > 17) ? 1 : tab[radius-1];
     
    QImage result = image.convertToFormat(QImage::Format_ARGB32_Premultiplied);
    int r1 = 0;
    int r2 = image.height();
    int c1 = 0;
    int c2 = image.width();
     
    int bpl = result.bytesPerLine();
    int rgba[4];
    unsigned char* p;
     
    int i1 = 0;
    int i2 = 3;
     
    for (int col = c1; col <= c2; col++) {
    p = result.scanLine(r1) + col * 4;
    for (int i = i1; i <= i2; i++)
    rgba[i] = p[i] << 4;
     
    p += bpl;
    for (int j = r1; j < r2; j++, p += bpl)
    for (int i = i1; i <= i2; i++)
    p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }
     
    for (int row = r1; row <= r2; row++) {
    p = result.scanLine(row) + c1 * 4;
    for (int i = i1; i <= i2; i++)
    rgba[i] = p[i] << 4;
     
    p += 4;
    for (int j = c1; j < c2; j++, p += 4)
    for (int i = i1; i <= i2; i++)
    p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }
     
    for (int col = c1; col <= c2; col++) {
    p = result.scanLine(r2) + col * 4;
    for (int i = i1; i <= i2; i++)
    rgba[i] = p[i] << 4;
     
    p -= bpl;
    for (int j = r1; j < r2; j++, p -= bpl)
    for (int i = i1; i <= i2; i++)
    p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }
     
    for (int row = r1; row <= r2; row++) {
    p = result.scanLine(row) + c2 * 4;
    for (int i = i1; i <= i2; i++)
    rgba[i] = p[i] << 4;
     
    p -= 4;
    for (int j = c1; j < c2; j++, p -= 4)
    for (int i = i1; i <= i2; i++)
    p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }
     
    return result;
}

QImage VImage::gaussianFilter(const QImage& im, float strength) {
    const QSize& unscaledSize = im.size();
    QImage small = im.scaledToWidth(unscaledSize.width()/strength);
    QImage large = small.scaled(unscaledSize);
    return large;
/*
    return blurred(im, strength);
*/
}
