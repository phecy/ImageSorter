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
#include <string>
#include <map>

using namespace std;
class RGB_set;

// A NUMBLOCKS-by-NUMBLOCKS vector of the avg grayvals
// unsigned long to hold total, then average it
typedef vector<vector<RGB_set>* > segVector;
typedef map<QImage*, segVector*> segMap; // Maps im* to segmented
typedef pair<QImage*, segVector*> segPair; // A pair for segMap
typedef vector<vector<QImage*> > dupGroup;

class RGB_set {
public:
    RGB_set();
    void add_color(int, int, int);
    QRgb get_avg();
    void operator+=(QRgb);
private:
    // Floats to allow for precision in avg'ing
    float r;
    float g;
    float b;
    unsigned int numCounted;
};

class DuplicateSegmented
{
public:
    DuplicateSegmented();
    ~DuplicateSegmented();

    // Segments an image and stores the hash'd values
    void addImage(QImage*);

    // Returns a list of lists of duplicates
    vector< vector<QImage*> > findDuplicates();

private:
    // A list of QImages and their respective segmented grayval blocks
    segMap* allPics;

    // A list of near-duplicates
    dupGroup* allGroups;

    // Inserts the image into the correct group
    void insertGrouped(QImage*, dupGroup*);

    // Checks if two images are near-duplicates
    // returns true if they are
    bool isMatch(QImage*, QImage*);

    // Set by #defines (blocksAcross=sqrt(numblocks))
    int numBlocks, blocksAcross;

    // Set by #define of PCTSIMILARITYDIST% * numImages
    int similarityDist;
} ;

#endif
