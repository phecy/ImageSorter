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
#include "duplicatetime.h"
#include "qualityexif.h"

// Amount needed for two images to be considered similar on 0-10 scale
#define SIMILARITY_RANK_THRESHHOLD 6

using namespace std;

// .first=sum avgs, .second=num avg'd
typedef pair<unsigned int, unsigned int> avgPair;

Duplicates::Duplicates(int numImages) {
    rater = new DuplicateRater(numImages);
    segmented = new DuplicateSegmented(rater);
    timed = new DuplicateTime(rater);
    interest = new DuplicateIp(rater);

    setFinder = new map<VImage*, int>();
    allImages = new imgList();
    allGroups = new dupGroup();
}

void Duplicates::addImage(VImage* vim, QualityExif* exif, const char*) {
    QImage* qim = vim->getQImage();
    segmented->addImage(qim);
    timed->addImage(qim, exif);
    interest->addImage(vim);
    allImages->insert(allImages->end(), vim);
}

dupGroup Duplicates::findDuplicates() {
    // Step 1: Gather votes
    runModules();

    // Step 2: Get graph of connected images
//    imgList::iterator main_i, after_i;
//    vector2d votes(allImages->size(), vector1d(allImages->size()));
////    for(main_i = allImages->begin(); main_i != allImages->end(); ++main_i) {
////        createNewList(*main_i);
////        for(after_i = (++main_i)--; after_i < allImages->end(); ++after_i) {
////            int rank = rater->getRanking(*main_i, *after_i);

////            if(rank > SIMILARITY_RANK_THRESHHOLD) {
////                insertIntoList(*main_i, *after_i);
////            }
////        }
//        /* Idea:
//                Depth-first traverse down every image > THRESHOLD. At each level,
//                add a half-vote of all of those images. Limit depth (at 3?).
//                So,
//                vector<pair<QImage*, int> recursiveVote(int imageIndex, int currentDepth);
//                imageIndex: The index in allImages to look down
//                return: a list of all potential duplicates.

//                At each level of recursion, multiply 1/currentDepth to the ranks,
//                and add that to the returned list of vectors.
//                Somehow keep track of how many have been added. Make sure that
//                the depth is accounted for, maybe return a pair<vector<pair>, int>
//                where the last int is the number to divide by to get the average.

//                The values in that vector are this group's vote for the image.

//                Put the vote in a 2d vector.

//                For each row in the 2d vector, find the largest, join that group,
//                and remove self from votes of other groups. Perhaps recalculate average?
//                Wasteful.
//                Somehow keep track of a way to delete self from averages.
//         */
//    }

//    // Step 3: Average votes
//    vector<avgPair> averages(allImages->size(), avgPair(0,0));
//    imgList::iterator main_i, after_i;
//    int avgPairIndex = 0;
//    for(main_i = allImages->begin(); main_i != allImages->end(); ++main_i) {
//        for(after_i = (++main_i)--; after_i < allImages->end(); ++after_i) {
//            int rank = rater->getRanking(*main_i, *after_i);
//            averages[avgPairIndex].first += rank;
//            averages[avgPairIndex].second += 1;
//        }
//        ++avgPairIndex;
//    }

    // TO DO: I want to use createNewList and insertIntoList but they use two variables that
    // I'll need to reconstruct later. Create two more variables that do the same job,
    // and let the two functions above take in a param that tells which list, the temp
    // or the final.
    // (Because right now, step 2 gives every image its own set.

    // Step 4: Find best fit group. Recalculate averages.
    /* For every image, find the largest average. Then for
       everything else in the connected set, remove the vote
       and the avg. */


    // Look past every image for potential duplicates,
    // mark them, and skip them when they are main_i
    imgList::iterator main_i, after_i;
    for(main_i = allImages->begin(); main_i != allImages->end(); ++main_i) {
        if(setExistsFor(*main_i)) continue; // Skip if previously found set
        createNewList(*main_i);
        for(after_i = (++main_i)--; after_i < allImages->end(); ++after_i) {
            int rank = rater->getRanking((*main_i)->getQImage(), (*after_i)->getQImage());
            qDebug("findDups: Img#%p->%p similarity hypothesis: %d/10",
                   *main_i, *after_i, rank);

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
    // Rank every image against every image after it.
    imgList::iterator main_i, after_i;
    for(main_i = allImages->begin(); main_i != allImages->end(); ++main_i) {
        for(after_i = (++main_i)--; after_i != allImages->end(); ++after_i) {
            QImage* one = (*main_i)->getQImage();
            QImage* two = (*after_i)->getQImage();
            segmented->rankOne(one, two);
            timed->rankOne(one, two);
            interest->rankOne(*main_i, *after_i);
        }
    }
}

void Duplicates::insertIntoList(VImage *one, VImage *two) {
    // First, look for *one in the setFinder
    map<VImage*, int>::iterator item = setFinder->find(one);
    assert(item != setFinder->end());

    // Then, insert at end of that list
    int index = item->second;
    imgList set = allGroups->at(index);
    set.insert(set.end(), two);

    setFinder->insert(pair<VImage*,int>(two, index));
}

void Duplicates::removeFromList(VImage *one, VImage *two) {
    // First, look for *one in the setFinder
    map<VImage*, int>::iterator item = setFinder->find(one);
    assert(item != setFinder->end());

    // Then, search for and erase *two from *one's set
    int index = item->second;
    imgList set = allGroups->at(index);
    for(imgList::iterator i = set.begin(); i != set.end(); ++i)
        if(*i == two) { set.erase(i); break; }
    set.insert(set.end(), two);
}

void Duplicates::createNewList(VImage *one) {
    // Create a new list
    imgList thisSet;
    thisSet.push_back(one);
    allGroups->push_back(thisSet);

    // Then map it
    setFinder->insert(pair<VImage*,int>(one, allGroups->size()-1));
}

bool Duplicates::setExistsFor(VImage* whichIm) {
    map<VImage*, int>::iterator item = setFinder->find(whichIm);
    return item != setFinder->end();
}

void Duplicates::printRanks() {
    rater->printRanks();
}
