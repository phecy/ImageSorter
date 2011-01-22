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

#ifndef FINDDUPS_H
#define FINDDUPS_H

#include <QImage>
#include <QRgb>
#include <vector>
#include <list>
#include <string>


using namespace std;

class DuplicateSegmented
{
public:

    void addImage(QImage*);

    // First string in inner list is the picture, and the following
    // strings are pictures that are duplicates to it
    list< list<string> > findDuplicates();

private:

    bool readFile(char * file);
    void findAverageColor(char * file);
    bool isSimilarRGB(QRgb a, QRgb b);
    bool isSimilarPic(vector<QRgb> a, vector<QRgb> b);

    QImage* image;

    // vals[a][a] = QRGB color at given pixel
    QRgb ** vals;

    // block does not need per pixel data. no need to store pixel location
    // block[a] refers to block number
    // block[a][a] refers to given value in block

    vector<vector<QRgb> > block;

   // the vector holds 9 QRgb objects. Each Qrgb has the average
   //values for the 9 quadrants in row major order
   //The lists contains a pair with a string (filename) and the saidvectors.
    //each list element refers to one picture
    list<pair<string, vector<QRgb> > > allPics;
} ;

#endif
