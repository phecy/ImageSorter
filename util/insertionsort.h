#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "duplicates/findDups.h"
#include "vimage.h"

// Sorts in descending order
void insertion_sort(float sortBy[], char* sortAlso[],int length);

// Sort by sets
// Find best, multiply that set's values by 90%, get next...
vector<VImage*> set_sort(vector<VImage*> unsorted);

// Sort by similarity
vector<VImage*> similarity_sort(vector<VImage*> imageInfo, Duplicates dups);
#endif
