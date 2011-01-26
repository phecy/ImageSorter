/*
    DuplicateGlobal
    Will determine if two pictures are similar based on content color,
    looking at the entire image and splitting it into NUMOFBLOCKS segments.
    Phase 2 of duplicate detection.

    1. Timestamp-based weight
    2. DuplicateGlobal
    3. DuplicateLocal
*/

#include <iostream>
#include <stdio.h>
#include <QImage>
#include <QRgb>
#include <string>
#include <math.h>
#include <vector>
#include <assert.h>
#include "findDups.h"
#include "duplicaterater.h"
#include "duplicatesegmented.h"

// Amount needed for two images to be considered similar on 0-10 scale
#define SIMILARITY_RANK_THRESHHOLD 7

using namespace std;

Duplicates::Duplicates(int numImages) {
    rater = new DuplicateRater(numImages);
    segmented = new DuplicateSegmented(rater);
    setFinder = new map<QImage*, int>();
    allImages = new imgList();
    allGroups = new dupGroup();
}

void Duplicates::addImage(QImage *im) {
    segmented->addImage(im);
    allImages->insert(allImages->end(), im);
}

dupGroup Duplicates::findDuplicates() {
    runModules();

    // Look past every image for potential duplicates,
    // mark them, and skip them when they are main_i
    imgList::iterator main_i, after_i;
    for(main_i = allImages->begin(); main_i != allImages->end(); ++main_i) {
        if(setExistsFor(*main_i)) continue; // Skip if previously found set
        createNewList(*main_i);
        for(after_i = (++main_i)--; after_i < allImages->end(); ++after_i) {
            int rank = rater->getRanking(*main_i, *after_i);

            if(rank > SIMILARITY_RANK_THRESHHOLD) {
                insertIntoList(*main_i, *after_i);
            } else {
                continue;
            }
        }
    }

    return *allGroups;
}

void Duplicates::runModules() {
    segmented->rankAll();
}

void Duplicates::insertIntoList(QImage *one, QImage *two) {
    // First, look for *one in the setFinder
    map<QImage*, int>::iterator item = setFinder->find(one);
    assert(item != setFinder->end());

    // Then, insert at end of that list
    int index = item->second;
    imgList set = allGroups->at(index);
    set.insert(set.end(), two);

    setFinder->insert(pair<QImage*,int>(two, index));
}

void Duplicates::createNewList(QImage *one) {
    // Create a new list
    imgList thisSet;
    thisSet.push_back(one);
    allGroups->push_back(thisSet);

    // Then map it
    setFinder->insert(pair<QImage*,int>(one, allGroups->size()-1));
}

bool Duplicates::setExistsFor(QImage* whichIm) {
    map<QImage*, int>::iterator item = setFinder->find(whichIm);
    return item != setFinder->end();
}
