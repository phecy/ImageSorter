#include "insertionsort.h"

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
