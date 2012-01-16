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
#include "duplicates/rater.h"
#include "duplicates/time.h"
#include "duplicates/gaussian.h"
#include "qualityexif.h"

// Amount needed for two images to be considered similar on 0-10 scale

#define SIMILARITY_RANK_THRESHHOLD 6.1
// .1 because only images with rank 7 will accept, but its
// resistant to lower group ratings while clustering

// The minimum rating required to ensure that if one image ranks another
// highly, that rating can't be weakened through averaging
// (or, to claim two images are the "exact" same.)
#define MIN_EXACT_RATE 10

using namespace std;

// .first=sum avgs, .second=num avg'd
typedef pair<unsigned int, unsigned int> avgPair;

Duplicates::Duplicates(int numImages) {
    rater = new DuplicateRater(numImages);
    timed = new DuplicateTime(rater);
#ifndef FAST_MODE
    gaussian = new DuplicateGaussian(rater);
#endif
    histogram = new DuplicateHistogram(rater);

    setFinder = new map<VImage*, int>();
    allImages = new ImgList();
    allGroups = new DupGroup();
}

void Duplicates::addImage(VImage* vim, QualityExif* exif) {
    timed->addImage(vim, exif);

#ifndef FAST_MODE
    gaussian->addImage(vim);
#endif
    histogram->addImage(vim);
    allImages->insert(allImages->end(), vim);
}

DupGroup Duplicates::findDuplicates() {
    //qDebug("Gathering duplicates....");
    // Gather votes
    runModules();

    //qDebug("Creating a matrix of ranks");
    // Construct matrix of rankings
    rankVector* ranks = getRankVector();
    //debugPrintRanks(ranks);

    // Successively merge groupst
    //qDebug("Merging groups together");
    while(true) {
       pair<int,int> maxPair = getMaxPair(ranks);
       if(maxPair.first == -1) break;
       combineSets(maxPair.first, maxPair.second, ranks);
       //qDebug("Combined %d and %d:", (maxPair.first+1), (maxPair.second+1));
       //debugPrintRanks(ranks);
    }

    // Gather all imglists
    //qDebug("Gathering groups from live rows");
    for(unsigned int i=0; i<allImages->size(); ++i) {
        pair<vector<float>, ImgList> thisPair = ranks->at(i);
        if(thisPair.second.size() > 0) { // Ignore "dead rows"
            allGroups->push_back(thisPair.second);
        }
    }
    // debugPrintPhpRanks(getRankVector(true)); // For comparing against turk data
    // debugPrintPhpGroups(allGroups); // For comparing against turk data

    delete ranks;

    return *allGroups;
}

void Duplicates::debugPrintRanks(rankVector* ranks) {
    cerr << setiosflags(ios::left);
    cerr << "     ";
    for(unsigned int i=0;i<ranks->size();++i) {
        cerr << setw(4) << (i+1);
    }
    cerr << endl;
    for(unsigned int i=0;i<ranks->size();++i) {
        cerr << setw(4) << (i+1) << ": ";
        for(unsigned int j=0;j<ranks->size();++j) {
            float rank = ranks->at(i).first.at(j);
            if(rank==-1) cerr << "/   ";
            else if(rank==10) cerr << "=   ";
            else cerr << setw(4) << setprecision(1) << rank;
        }
        cerr << endl;
    }
}

rankVector* Duplicates::getRankVector(bool binary) {
    int size = allImages->size();
    rankVector* ranks = new rankVector();
    for(int i=0; i<size; ++i) {
        // Working on the row of *first
        VImage *first = allImages->at(i);
        pair<vector<float>, ImgList> row;
        row.second.push_back(first);

        // Add firsts rank of all other images
        for(int j=0; j<size; ++j) {
            // Comparing second to first
            VImage *second = allImages->at(j);

            float rank;
            if(binary)
                rank = (first->getSetNum() == second->getSetNum())
                        ? 1 : 0;
            else
                rank = rater->getRanking(first, second);
            row.first.push_back(rank);
        }
        ranks->push_back(row);
    }

    return ranks;
}

void Duplicates::createSimilarityVector() {
    int size = allImages->size();
    vector<vector<float> >* ranks = new vector<vector<float> >();
    for(int i=0; i<size; ++i) {
        // Working on the row of *first
        VImage *first = allImages->at(i);
        vector<float> row;

        // Add firsts rank of all other images
        for(int j=0; j<size; ++j) {
            // Comparing second to first
            VImage *second = allImages->at(j);

            float rank = rater->getRanking(first, second);
            row.push_back(rank);
        }
        ranks->push_back(row);
    }

    similarityRanks = ranks;
}

vector<vector<float> >* Duplicates::getSimilarityVector() {
    return similarityRanks;
}

float Duplicates::getUpdatedRank(const pair<vector<float>, ImgList> &firstRow,
                                 const pair<vector<float>, ImgList> &secondRow,
                                 int index) {
    int firstNumVoters = firstRow.second.size();
    int secondNumVoters = secondRow.second.size();

    float firstRank = firstRow.first.at(index);
    float secondRank = secondRow.first.at(index);

    // See if auto-include:
    if(firstRank >= MIN_EXACT_RATE)
        return firstRank;
    else if(secondRank >= MIN_EXACT_RATE)
        return secondRank;
    else // Get averages
        return (firstNumVoters * firstRank + secondNumVoters * secondRank) /
               (firstNumVoters + secondNumVoters);
}

// Merge second row into first
// Set second row vals to -1
void Duplicates::combineSets(int first, int second, rankVector* ranks) {
    pair<vector<float>, ImgList> firstRow = ranks->at(first);
    pair<vector<float>, ImgList> secondRow = ranks->at(second);

    // Average rankings and delete second row
    int size = ranks->size();
    for(int i=0; i<size; ++i) {
        // Delete vote for second in firstRow,
        // and the vote for itself
        if(i == first || i == second) {
            firstRow.first.at(i) = -1;
            secondRow.first.at(i) = -1;
            continue;
        }
        // Get averages
        firstRow.first.at(i) = getUpdatedRank(firstRow, secondRow, i);

        // Delete second row as we go
        secondRow.first.at(i) = -1;
    }

    // Combine two imglists
    ImgList firstList = firstRow.second;
    ImgList secondList = secondRow.second;
    ImgList combined;
    combined.insert(combined.end(), firstList.begin(), firstList.end());
    combined.insert(combined.end(), secondList.begin(), secondList.end());
    firstRow.second = combined;

    secondRow.second.clear(); // Empty the image list

    ranks->at(first) = firstRow;
    ranks->at(second) = secondRow;
}

// Returns (-1,-1) if the max ranking is below the threshold
// Otherwise, returns indeces
pair<int,int> Duplicates::getMaxPair(rankVector* ranks) {
    pair<int,int> maxPair;
    float max_rank = 0;

    for(unsigned int main_i = 0; main_i < ranks->size(); ++main_i) {
        for(unsigned int after_i = main_i+1; after_i < ranks->size(); ++after_i) {
            pair<vector<float>, ImgList> thisRow = ranks->at(main_i);

            // Skip if after_i is already in main_i's list
            if(contains(thisRow.second, allImages->at(after_i))) continue;

            // Check if max rank
            float rank = thisRow.first.at(after_i);
            if(rank > max_rank) {
                max_rank = rank;
                maxPair.first = main_i;
                maxPair.second = after_i;
            }
        }
    }
    if(max_rank < SIMILARITY_RANK_THRESHHOLD) {
        maxPair.first = -1;
        maxPair.second = -1;
        //qDebug("Failed to find max ranking. The closest is %d.", max_rank);
        return maxPair;
    }

    //qDebug("Found max pair of rank %.2f at (%d, %d).", max_rank,
    //       maxPair.first+1, maxPair.second+1);
    return maxPair;
}

bool Duplicates::contains(ImgList row, VImage* lookFor) {
    ImgList::iterator iter = row.begin();
    for(; iter != row.end(); ++iter) {
        if(*iter == lookFor) return true;
    }
    return false;
}

void Duplicates::runModules() {
    // Rank every image against every image after it.
    ImgList::iterator main_i, after_i;
    for(main_i = allImages->begin(); main_i != allImages->end(); ++main_i) {
        for(after_i = (++main_i)--; after_i != allImages->end(); ++after_i) {
            timed->rankOne(*main_i, *after_i);
#ifndef FAST_MODE
            gaussian->rankOne(*main_i, *after_i);
#endif
            histogram->rankOne(*main_i, *after_i);
        }
    }
}

void Duplicates::insertIntoList(VImage *one, VImage *two) {
    // First, look for *one in the setFinder
    map<VImage*, int>::iterator item = setFinder->find(one);
    assert(item != setFinder->end());

    // Then, insert at end of that list
    int index = item->second;
    ImgList set = allGroups->at(index);
    set.insert(set.end(), two);

    setFinder->insert(pair<VImage*,int>(two, index));
}

void Duplicates::removeFromList(VImage *one, VImage *two) {
    // First, look for *one in the setFinder
    map<VImage*, int>::iterator item = setFinder->find(one);
    assert(item != setFinder->end());

    // Then, search for and erase *two from *one's set
    int index = item->second;
    ImgList set = allGroups->at(index);
    for(ImgList::iterator i = set.begin(); i != set.end(); ++i)
        if(*i == two) { set.erase(i); break; }
    set.insert(set.end(), two);
}

void Duplicates::createNewList(VImage *one) {
    // Create a new list
    ImgList thisSet;
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
