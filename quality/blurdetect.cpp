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

#include <assert.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

#include <QImage>
#include <QLabel>

#include "blurdetect.h"
#include "util/kurtosis.h"

static const int NUM_BINS_EDGE_STRENGTH_HIST = 15;

BlurDetect::BlurDetect() {
}

float BlurDetect::calculateBlur(VImage* vim) {
    QImage* image = vim->getQImage();
    assert(image != NULL);

    // Compute edges + histogram
    QImage sobelEdges = sobelEdgeDetect(*image);

    vector<int> edgeStrengthHist = getEdgeHistogram(sobelEdges); // 15 bins
    float rating = calcBlurAmount(edgeStrengthHist);

    vector<double> edgeStrengthList = getEdgeStrengthList(sobelEdges);
    float rating2 = calcKurtosisRating(edgeStrengthList);

    cerr << "Blur result: " << rating2 << endl;

    return fmin(rating2, MAX_RATING);
}

vector<int> BlurDetect::getEdgeHistogram(const QImage& sobelEdges) {
    vector<int> hist(NUM_BINS_EDGE_STRENGTH_HIST);

    // Construct histogram
    for(int w=0; w<sobelEdges.width(); w++) {
        for(int h=0; h<sobelEdges.height(); h++) {
            int color = qGray(sobelEdges.pixel(w,h));
            int bin = color / (255/NUM_BINS_EDGE_STRENGTH_HIST); // == color/17
            if(bin == NUM_BINS_EDGE_STRENGTH_HIST) --bin; // Only if color=255
            ++hist[bin];
        }
    }

    return hist;
}

void BlurDetect::printHistogram(const vector<int> &hist) {
    int area = 0;
    for(int i=0; i<hist.size(); ++i) area+=hist[i];
    
    cout << "Edge strength histogram: " << endl;
    for(int i=0; i<15; ++i) {
        float numInBin = hist[i];
        numInBin /= area; // % in bin
        numInBin *= 100; // Make 100 *s total across histogram
        printf("%02d: ", i);
        for(int j=0; j<numInBin; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

/*
    Code from http://www.dewtell.com/code/cpp/sobel.htm
    Given image in source place Sobel edges in dest.
    Grayscale sort of, with (255,255,255) as brightest edge.
    sobelDestination should be same size and depth as source.
*/
QImage BlurDetect::sobelEdgeDetect(const QImage& source) {
    QImage sobelEdges(source.size(), source.format());
    int GX[3][3];
    int GY[3][3];

    /* 3x3 GX Sobel mask.  Ref: www.cee.hw.ac.uk/hipr/html/sobel.html */
    GX[0][0] = -1; GX[0][1] = 0; GX[0][2] = 1;
    GX[1][0] = -2; GX[1][1] = 0; GX[1][2] = 2;
    GX[2][0] = -1; GX[2][1] = 0; GX[2][2] = 1;

    /* 3x3 GY Sobel mask.  Ref: www.cee.hw.ac.uk/hipr/html/sobel.html */
    GY[0][0] =  1; GY[0][1] =  2; GY[0][2] =  1;
    GY[1][0] =  0; GY[1][1] =  0; GY[1][2] =  0;
    GY[2][0] = -1; GY[2][1] = -2; GY[2][2] = -1;

    int width = source.width();
    int height = source.height();
    int I, J;
    long sumX, sumY;
    int SUM;
    QRgb color;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if ( y == 0 || y >= height-1 || x == 0 || x >= width-1 ) {
                SUM = 0;
            }
            else {
                sumX = 0;
                sumY = 0;
                /*-------X and Y GRADIENT APPROXIMATION------*/
                for(I=-1; I<=1; I++) {
                    for(J=-1; J<=1; J++) {
                        color = source.pixel(x+I, y+J);
                        sumX += qGray(color) * GX[I+1][J+1];
                        sumY += qGray(color) * GY[I+1][J+1];
                    }
                }
                SUM = abs(sumX) + abs(sumY); /*---GRADIENT MAGNITUDE APPROXIMATION (Myler p.218)----*/
                if (SUM > 255) {
                    SUM = 255;
                }

            }
            sobelEdges.setPixel(x,y,qRgb(SUM, SUM, SUM));
        }
    }
    return sobelEdges;
}

float BlurDetect::calcBlurAmount(vector<int>& edgeStrengthHist) {
    // Get a list of all bins with components
    vector<int> sortedBinThatAreFilled;
    for(int i=0; i<edgeStrengthHist.size(); ++i) {
        if(edgeStrengthHist[i] > 20) {
            sortedBinThatAreFilled.push_back(i);
        }
    }

    /*
       Get the median of this list, truncated to an int.
    */
    int median = sortedBinThatAreFilled[sortedBinThatAreFilled.size()/2]; 
    cout << "Median bin is: " << median << endl;

    // Sum over all bins > median
    int numStrengthsOverMedianBin = 0;
    for(int i=median; i<edgeStrengthHist.size(); ++i) {
        numStrengthsOverMedianBin += edgeStrengthHist[i];
    }

    cout << "Num strengths over median bin: " << numStrengthsOverMedianBin
         << endl;

    return numStrengthsOverMedianBin / 1000.f;
}

vector<double> BlurDetect::getEdgeStrengthList(const QImage& sobelEdges) {
    vector<double> edges(sobelEdges.width() * sobelEdges.height());

    int width = sobelEdges.width();
    int height = sobelEdges.height();
    for(int x=0; x<width; ++x) {
        for(int y=0; y<height; ++y) {
            edges[x+width*y] = qGray(sobelEdges.pixel(x,y)) / 255.0;
        }
    }

    return edges;
}

float BlurDetect::calcKurtosisRating(vector<double>& edgeStrengthList) {
    float kurtosis = Kurtosis::calcKurtosis(edgeStrengthList);
    cout << "Kurtosis is: " << kurtosis << endl;
    return kurtosis;
}
