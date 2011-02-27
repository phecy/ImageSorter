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

#ifndef BLURDETECT_H
#define BLURDETECT_H

#include <QMainWindow>

#include "vimage.h"

class QMainWindow   ;
class BlurDetect : public QMainWindow
{
public:
    BlurDetect();
    // We assume filename is valid and abort everything if it isn't.
        // Be sure to check validity of file before calling.
    int calculateBlur(VImage* im);

    // Minimum threshhold for high pass: -100-100% of colors from average
    void setThreshhold(int t) { threshhold = t; }
    int  getThreshhold()      { return threshhold; }

    // Radius to examine during angle calculations
    void setRadius(int r) { radius = r; }
    int  getRadius()      { return radius; }

    // How many pixels thick may an edge in highpass be?
    void setEdgeRadius(int r) { edgeRadius = r; }
    int  getEdgeRadius()      { return edgeRadius; }

    // How sharp is sharp? 0-180
    void setSharpness(int s) { sharpness = s; }
    int  getSharpness()      { return sharpness; }

    // How far apart do we want our edges?
    void setHighpassRadius(int r) { highpassRadius = r; }
    int  getHighpassRadius()      { return highpassRadius; }

    // Returns average color intensity
    int  getAverage()      { return avgColor; }

    // For debugging, see the high pass or angles as a grayscale image
    void debugPrint(int** image, bool stepped = false, int step1=4, int step2=25);
    int** getOriginalImage() { return originalImage; }
    int** getHighPass() { return highPass; }
    int** getAngles() { return angles; }

protected:
/*  Part 0: Color average, min, max
    Given some images are darker than others without loss of quality, an absolute
    threshhold in Part 1 is inadequate. The threshhold should be the percent deviation
    from this average, positive or negative. This is easily influenced by noise. */
    // (Implemented in calculateBlur())

/*  Part 1: Edge detection
    We want to focus our connectivity on important edges and not calculate angles
    for unimportant details within the image.*/
    void edgeDetect();
    void correctSpacing(int w, int h);

/*  Part 2: Calculate connectivity
    Ideally, an unblurry image would have a lot of continuous edges,
    and background blur will still be gradiented in a continuous direction. */
    void connectivity();
    int calcAngle(int w, int h);

/* Part 2: Calculate width of edges (not angles as above).
   Sillly: still uses angles[] */
    int calcEdgeWidth(int w, int h);

/*  Part 3: Calculate blur
    (Maximum angle differences is optimal: More sharp angles means more sharpness and less blur.) */
    int resultCalc();

private:
    int** originalImage; // The grayscale original image.
    int** highPass; // Stores gray vals of highest [threshhold] pixels
    int** angles;   // Stores differences in angles between [radius] pixels
    int width, height;

    // User-set constants
    int threshhold;  // -100-100%: how far from average we want to be
    int radius;     // >0: How many pixels around this pixel to look at?
    int edgeRadius;     // How many pixels thick may an edge in highpass be?
    int highpassRadius; // How far apart do we want our edges?
    int sharpness; // Angle required between two pixels to be considered sharp

    // Gray value stats for threshhold calcs
    int minColor;
    int avgColor;
    int maxColor;
    int numColors; // The number of colors entered into highPass[][]
};

#endif // BLURDETECT_H
