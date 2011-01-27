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

#include <map>
#include "duplicatesegmented.h"
#include "duplicatetime.h"

using namespace std;

typedef vector<QImage*> imgList;
typedef vector<imgList > dupGroup;

class Duplicates {
public:
    Duplicates(int numImages);

    void addImage(QImage*);

    dupGroup findDuplicates();
private:
    // Runs all of the modules, which should update rater.
    void runModules();

    // Inserts two into one's list
    // ONE'S LIST MUST EXIST and be in setFinder!
    void insertIntoList(QImage* one, QImage* two);

    // Creates a list. Call this before insertIntoList on *one.
    void createNewList(QImage *one);

    // Checks if there exists a set list for whichIm
    bool setExistsFor(QImage* whichIm);

    // A list of near-duplicates
    dupGroup* allGroups;

    // Maps an image to its set number (index in allGroups)
    map<QImage*, int>* setFinder;

    // Maintains state of duplicate detection
    DuplicateRater* rater;

    // Segmentation-based module
    DuplicateSegmented* segmented;

    // Time-based module
    DuplicateTime* timed;

    // All images fed to the duplicate tester
    imgList* allImages;

};

#endif
