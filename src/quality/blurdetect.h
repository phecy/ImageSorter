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
    float calculateBlur(VImage* im);

    // For debugging, see the high pass or angles as a grayscale image
    void debugPrint(int** image, bool stepped = false, int step1=4, int step2=25);

protected:
    // Returns a sobel edge detected image
    QImage sobelEdgeDetect(const QImage& source);

    // Bins the edge image
    vector<int> getEdgeHistogram(const QImage& sobelEdges);

    // Converts the sobel edge image into one long vector of values in [0,1]
    vector<double> getEdgeStrengthList(const QImage& sobelEdges);

    // Get the final rating based on the number > median
    float calcBlurAmount(vector<int>& edgeStrengthHist);

    // Get the final rating based on the kurtosis
    float calcKurtosisRating(vector<double>& edgeStrengthList);

    // For debugging
    void printHistogram(const vector<int> &hist);

private:
};

#endif // BLURDETECT_H
