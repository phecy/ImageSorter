#include "insertionsort.h"
#include "vimage.h"

#define ECLECTIC .8

void insertion_sort(float sortBy[], char* sortAlso[],int length)
{
  float keySBy; char* keySAlso; int i;
  for(int j=1;j<length;j++)
  {
     keySBy=sortBy[j];
     keySAlso=sortAlso[j];
     i=j-1;
     while(sortBy[i]<keySBy && i>=0)
     {
         sortBy[i+1]=sortBy[i];
         sortAlso[i+1]=sortAlso[i];
         i--;
     }
     sortBy[i+1]=keySBy;
     sortAlso[i+1]=keySAlso;
  }
}

vector<VImage*> set_sort(vector<VImage*> imageInfo) {
    vector<VImage*> sorted;

    // For every image,
    while(imageInfo.size() != 0) {
        // Get max
        VImage* max; float maxVal = 0; vector<VImage*>::iterator max_i;
        vector<VImage*>::iterator image_i = imageInfo.begin();
        for(; image_i != imageInfo.end(); ++image_i) {
            if((*image_i)->getAdjustedRank() > maxVal) {
                max = *image_i;
                maxVal = (*image_i)->getAdjustedRank();
                max_i = image_i;
            }
        }
        imageInfo.erase(max_i);

        // Insert at front of new list
        sorted.push_back(max);

        // Multiply all in that set by ECLECTIC
        vector<VImage*>::iterator setfind_i = imageInfo.begin();
        for(; setfind_i != imageInfo.end(); ++setfind_i) {
            if((*setfind_i)->getSetNum() == max->getSetNum())
                (*setfind_i)->multiplyAdjustedRank(ECLECTIC);
        }
    }

    return sorted;
}
