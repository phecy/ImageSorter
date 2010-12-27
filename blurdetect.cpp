/*
This file is part of ppm.

    ppm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ppm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ppm.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QImage>
#include <QLabel>
#include "assert.h"
#include "blurdetect.h"
#include "stdio.h"
#include "math.h"

#define PI 3.142

BlurDetect::BlurDetect()
{
    width = height = 0;
    radius = 5;

    threshhold = 98;
    edgeRadius = 5;
    highpassRadius = 10;

    sharpness = 30;
}

int BlurDetect::calculateBlur(QImage* im) {
    assert(highpassRadius > edgeRadius);

    // Open image
    // if(width == 0) { // If testing same file multiple times, don't reopen
        QImage* image = im;
        minColor = avgColor = maxColor = 0;
        assert(image != NULL);
        *image = image->scaledToWidth(600);
        width = image->width();
        height = image->height();

        // Load image into grayscale int-map
        // And calculate average color
        originalImage = new int*[width];
        unsigned long total = 0;
        for(int w=0; w<width; w++) {
            originalImage[w] = new int[height];
            for(int h=0; h<height; h++) {
                int grayVal = qGray(image->pixel(w,h));
                originalImage[w][h] = grayVal;

                // Average, max, and min calcs
                total += grayVal;
                if(minColor < grayVal) minColor = grayVal;
                if(maxColor > grayVal) maxColor = grayVal;
            }
        }
        avgColor = total /= (int)(height*width);

        // debugPrint(originalImage);
    // }

    // Compute
    edgeDetect();
    connectivity();
    int result = resultCalc();

    for(int w=0; w<width; w++) {
        delete[] angles[w];
        delete[] highPass[w];
    }

    return result;
}

void BlurDetect::edgeDetect() {
    // Calculate the effective threshhold from the % away from avg color
    int grayThreshhold = avgColor;
    numColors = 0;
    int maxOrMin = threshhold < 0 ? minColor : maxColor;
    grayThreshhold += (int)((maxOrMin-avgColor) * (int)(threshhold/100));

    highPass = new int*[width];
    for(int w=0; w<width; w++) {
        highPass[w] = new int[height];
        for(int h=0; h<height; h++) {
            if(originalImage[w][h] < grayThreshhold) {
                highPass[w][h] = originalImage[w][h];
                correctSpacing(w, h);
                numColors++;
            }
            else
                highPass[w][h] = 255;
        }
    }
    // debugPrint(highPass);
}

void BlurDetect::correctSpacing(int w, int h) {
    // Text edge width and spacing
    int currGrayValue = originalImage[w][h];
    for(int x=w-highpassRadius; x<w-edgeRadius; x++) {
        for(int y=h-highpassRadius; y<h-edgeRadius; y++) {
            if((x < 0     || y < 0)  ||     // Don't test if out of bounds
                highPass[x][y] == 255       // Or if it isn't in highPass
               )
                continue;

            if(currGrayValue < highPass[x][y]) {
                highPass[x][y] = 255;
            } else {
                highPass[w][h] = 255;
                break;
            }
        }
    }
}


void BlurDetect::connectivity() {
    angles = new int*[width];
    for(int w=0; w<width; w++) {
        angles[w] = (int*)calloc(height, sizeof(int)); // init to 0
        for(int h=1; h<height; h++) {
            angles[w][h] = calcAngle(w,h);
        }
    }
}

int BlurDetect::calcAngle(int w, int h) {
    int maxX = 0; int maxY = 0; int maxGray = 255;
    for(int x=w-radius; x<=w+radius; x++) {
        for(int y=h-radius; y<=h+radius; y++) {
            if((x == w && y == h)  ||
                x<0 || y<0         ||
                x>=width || y>=height ||
                highPass[x][y] == 255
               ) continue;
            if(highPass[x][y] < maxGray) {
                maxX = x; maxY=y; maxGray = highPass[x][y];
            }
        }
    }
    if(maxGray == 255){
        // This would be noise in the image I suppose. Don't let it get in the way.
        return 0;
    }

    // Calc angle
    int xLen = maxX - w;
    int yLen = maxY - h;
    int dirAngle;
    if(yLen == 0)
        dirAngle = 90;
    else if(xLen == 0)
        dirAngle = 0;
    else {
        dirAngle = (int)(atan((double)xLen / (double)yLen) * 180/PI); // The direction
        if(dirAngle < 0) dirAngle += 360;
    }
    dirAngle = dirAngle % 360;

    // Get difference of this and closest angle
    int closestAngleDiff = 361; // Start with far point
    for(int x=w-radius; x<w; x++) {
        for(int y=h-radius; y<h; y++) {
            if((x == w && y == h)  ||
                x<0 || y<0         ||
                angles[x][y] == 0
               ) continue;
            int currAngleDiff = abs(angles[x][y] - dirAngle);
            if(currAngleDiff > 180) currAngleDiff = 180 - currAngleDiff%180; // Loop around so 359 close to 1
            if(currAngleDiff < closestAngleDiff) {
                closestAngleDiff = currAngleDiff;
            }
        }
    }

    // printf("%d ", closestAngleDiff);

    return closestAngleDiff;
}

int BlurDetect::resultCalc() {
    unsigned long total = 0;
    for(int w=0; w<width; w++) {
        for(int h=1; h<height; h++) {
            if(angles[w][h] < sharpness)
                total += angles[w][h];
        }
    }
    double result = (total*threshhold*numColors) / (double)(180 * width * height);
    // printf("Picture quality rating: %f\%\n", result);
    if(result > 100) result = 100;
    result = (int)round((double)result / 10);
    return (int)result;
}

void BlurDetect::debugPrint(int **image,
                            bool stepped, int step1, int step2) {
    QImage i = QImage(width, height, QImage::Format_RGB32);

    for(int w=0; w<width; w++) {
        for(int h=0; h<height; h++) {
            int color = image[w][h];
            if(stepped) {
                if(color < step1)
                    i.setPixel(w, h, qRgb(color*2, 0, 0));
                else if(color < step2)
                    i.setPixel(w, h, qRgb(0, color*2, 0));
                else
                    i.setPixel(w, h, qRgb(0, 0, color*2));
            } else {
                i.setPixel(w, h, qRgb(color, color, color));
            }
        }
    }

    QLabel* imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(QPixmap::fromImage(i));

    setCentralWidget(imageLabel);

    int w = width > 600 ? 600 : width;
    int h = width > 600 ? (int)(600/(double)width * height) : height;
    resize(w, h);

    imageLabel->show();
}
