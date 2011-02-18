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
#include "duplicateip.h"
#include "vimage.h"

using namespace std;

typedef vector<VImage*> imgList;
typedef vector<imgList > dupGroup;


// A list of sets of rankings and the images that voted
// float: the ranking
// imgList: the images that voted on this rank
typedef vector<pair<vector<float>, imgList> > rankVector;

class Duplicates {
public:
    Duplicates(int numImages);

    // Initialize anything needed by the modules for this im
    void addImage(VImage*, QualityExif*, const char*);

    dupGroup findDuplicates();

    // Debugging output
    void printRanks();
private:
    // Runs all of the modules, which should update rater.
    void runModules();

    /*
     * Work with near-duplicate sets
     */

    // Inserts two into one's list
    // ONE'S LIST MUST EXIST and be in setFinder!
    void insertIntoList(VImage* one, VImage* two);

    // When an image has been chosen, remove from other candidate lists
    void removeFromList(VImage *one, VImage *two);

    // Creates a list. Call this before insertIntoList on *one.
    void createNewList(VImage *one);

    // Checks if there exists a set list for whichIm
    bool setExistsFor(VImage* whichIm);

    /*
     * Clustering
     */
    // Get a 2d matrix of rankings. Destruct it when you're done.
    rankVector* getRankVector();

    // Prints out the current rank vector
    void debugPrintRanks(rankVector* ranks);

    // Get the max paired ranking in the rankVector
    pair<int,int> getMaxPair(rankVector* ranks);

    // True if "checking" is in the row
    bool contains(imgList row, VImage* lookfor);

    // Combine second row into first. Remove second row.
    // Return resulting duplicate group list
    void combineSets(int first, int second, rankVector* ranks);

    // A list of near-duplicates
    dupGroup* allGroups;

    // Maps an image to its set number (index in allGroups)
    map<VImage*, int>* setFinder;


    /*
     * Modules
     */

    // Maintains state of duplicate detection
    DuplicateRater* rater;

    // Segmentation-based module
    DuplicateSegmented* segmented;

    // Time-based module
    DuplicateTime* timed;

    // Interestpoint-based module
    DuplicateIp* interest;


    /*
     * Variables
     */
    // All images fed to the duplicate tester
    imgList* allImages;

};

#endif
