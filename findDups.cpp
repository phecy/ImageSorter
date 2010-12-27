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

#include "findDups.h"
#include <iostream>
#include <stdio.h>
#include <QImage>
#include <QRgb>
#include <string>
#include <math.h>
#include <vector>
#include <list>

// must be an integer and a perfect square ex 9, 16, 25 ...
#define NUMOFBLOCKS 9
#define DISTANCE 40
#define MATCHING 7

using namespace std;

void findDups::load(char * file)
{
    if(readFile(file))
        findAverageColor(file);
}



bool findDups::readFile(char *file)
{
    image = new QImage(file);
    if (image == NULL) {
       qDebug ("%s Not Loaded", file);
       return false;
       //exit(1);
   }



    int w = image->width();
    int h = image->height();

    vals = (QRgb**)malloc(w * sizeof(QRgb*));
    for (int a = 0; a < w; ++a)
        vals[a] = (QRgb*)malloc(h * sizeof(QRgb*));

    // read in color vales into array
    // could proabaly be optimized to do the next
    // two loops together
    for (int a = 0; a < w; ++a)
       for (int b = 0; b < h; ++b)
           vals[a][b] = image->pixel(a,b);

    int rows = sqrt(NUMOFBLOCKS);

    int xStart = 0;
    int yStart = 0;
    int xBound;
    int yBound;

    block.clear();
    block.resize(NUMOFBLOCKS);
    int xSection = w/rows;
    int ySection = h/rows;


    for ( int i = 0; i < NUMOFBLOCKS; ++i)
    {
        xBound = xStart + xSection;
        yBound = yStart + ySection;

        for (int a = xStart; a < xBound; ++a)
               for (int b = yStart; b < yBound; ++b)
                     block[i].push_back(vals[a][b]);

        xStart = (xStart + xSection)%w;
        // Because not all w,h values will be evenly divisible
        // by the row count, there is a chance that will increment
        // xStart over bounds rather that setting back to zero
        // same goes for yStart below
        if (xStart > w - xSection)
            xStart = 0;

        //only increment boounds if at edge
        if( i%rows == rows - 1)
        {
            yStart = (yStart + ySection)%h;
            if (yStart > h - ySection)
                yStart = 0;
        }
    }


    for (int a = 0; a < w; ++a)
       free(vals[a]);

    free(vals);
    image->~QImage();

    return true;
}

void findDups::findAverageColor(char * file)
{
     vector<QRgb> averages;

    for (int i = 0; i < NUMOFBLOCKS; ++i)
    {
        //temp float array, each pertaining to the sum of the color values
        int sumColor[4] = {0,0,0,0};

        // iterate vector of Colors, summing up each color compoenent
        vector<QRgb>::const_iterator iter = block[i].begin();
        for ( ; iter != block[i].end(); ++iter)
        {
            sumColor[0] += qRed(*iter);
            sumColor[1] += qGreen(*iter);
            sumColor[2] += qBlue(*iter);
            sumColor[3] += qAlpha(*iter);
        }

        int size = block[i].size();
        // Push in average color in to average array

        //qDebug("file: %s block: %d %d %d %d %d\n", file, i, sumColor[0]/size, sumColor[1]/size, sumColor[2]/size, sumColor[3]/size);
        QRgb color = qRgba(sumColor[0]/size, sumColor[1]/size, sumColor[2]/size, sumColor[3]/size);
        averages.push_back(color);
    }

    pair<string, vector<QRgb> > p(file, averages);
    allPics.push_back( p );
}

//The inner list being returned contains a list of pictures
// the porgram calculated to be very similar
// the string refers to the file name
list<list<string> > findDups::findDuplicates()
{
    list<list<string> > l;

    list<pair<string, vector<QRgb> > >::iterator i = allPics.begin();
    list<pair<string, vector<QRgb> > >::iterator end = allPics.end();

    list<pair<string, vector<QRgb> > >::iterator i2;


   // compare all pictures with all other pictures
    // and see if they are duplicates, or very similar
    for (; i!=end; ++i)
    {
        i2 = i;
        if (i2 != end)
            i2++;

       list<string> duplicatesToI;
       duplicatesToI.push_back(i->first);
       for ( ;i2 != end; )
        {
                 if( isSimilarPic(i->second, i2->second))
                {

                    duplicatesToI.push_back(i2->first);
                    i2 = allPics.erase(i2);
                    continue;
                }
            // if a duplicate is found then erase that duplicate from the list
            // so program will not find the duplicates of a duplicate b/c it is redundant
            // However when an element is erased from list via list.erase(iterator)
            // the iterator is automatically incremented so the iterator increment should not
            // occour if a picture was erased from the list, hence the continute and the
            // increment not in the for control structure.

            ++i2;

        }
       l.push_back(duplicatesToI);
    }






    return l;

}

// Loop through each block and see if each corrseponding block
// is similiar between eeach picture. If a single block is
// not similiar enough then it will not be marked as a duplciated
bool findDups::isSimilarPic(vector<QRgb> a, vector<QRgb> b)
{
    int count = 0;
    for (int i = 0; i < NUMOFBLOCKS; ++i)
    {
        if(isSimilarRGB(a[i], b[i]))
            count++;
    }
    if ( count >= MATCHING)
        return true;
    else return false;
}

// The smaller max disatance is the more sensitive
// the program will be in similary between "duplicates"
// HIgher values will allow less similiar pictures to
// be marked as duplicates
bool findDups::isSimilarRGB(QRgb a, QRgb b)
{
    int maxDistance = DISTANCE;

    if ( abs(qRed(a) - qRed(b)) > maxDistance)
        return false;

    if ( abs(qGreen(a) - qGreen(b)) > maxDistance)
        return false;

    if ( abs(qBlue(a) - qBlue(b)) > maxDistance)
        return false;

    return true;



}











