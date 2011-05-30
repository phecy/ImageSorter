#include <QImage>
#include <QDebug>

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <math.h>

#include "exposure.h"
#include "vimage.h"
#include "grey.h"

using namespace std;

const int rows = 20;
const int columns = 15;
const int middle_grey = 128;
const int delta = 30;
const int big_delta = 80;

// r1 - piece
// r2 - foreground
double intersect(VImage *vim, boundingBox r1)
{
    /*double area = (double)(max(r1[0].first,r2[0].first) - min(r1[1].first,r2[1].first))*
(double)(max(r1[0].second,r2[0].second) - min(r1[1].second,r2[1].second));
*/

    //double area = (double)(max(r1.first.first,r2.first.first));

    double area = (double)vim->amountInForeground(r1);

    if (area == 0) return 1.;

    double r1_area = (r1.first.first-r1.second.first)*(r1.first.second-r1.second.second);

    //qDebug("piece area %d    intersection area %d\n");

    return ((area)*3. + (r1_area-area)*1.)/r1_area;

}



Exposure::Exposure(){
}

float Exposure::rate(VImage *vim) {
    QImage* im = vim->getQImage();
    char* imageName = vim->getFilename();

    if (!im) {
        cerr << "Could not load " << imageName << endl;
        exit (1);
    }


    int piece_width = im->width()/columns;
    int piece_height = im->height()/rows;

    // assumption: all images are resized to be 800x600
    // => let's divide the image into 8x4=32 rectangles
    // each rectamgle is 100x150 piexels
    int grey_vals[rows][columns] = {0};
    int low = 0, middle = 0, high = 0, very_low = 0, very_high = 0;
    grey newGrey;
    double sum = 0;
    double num_contributors = 0;
    //QImage* foreground = vim->getForeground();

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            QImage *piece = new QImage(im->copy(i*piece_width, j*piece_height, piece_width, piece_height));
              grey_vals[i][j] = newGrey.calcGrey(piece);

            // if fully intersect, weight is tripled
              // WITHOUT THE BOUNDING BOX

              //boundingBox piece_coords(point(i*piece_width, j*piece_height), point((i+1)*piece_width, (j+1)*piece_height));
              sum += (double)grey_vals[i][j];//*intersect(vim,piece_coords);
              num_contributors++;//= intersect(vim,piece_coords);

              if (grey_vals[i][j] - big_delta > middle_grey) very_high++;
              if (grey_vals[i][j] + big_delta < middle_grey) very_low++;
              if (grey_vals[i][j] - delta > middle_grey) high++;
              if (grey_vals[i][j] + delta < middle_grey) low++;
              if (grey_vals[i][j] >= middle_grey - delta  && grey_vals[i][j] <= middle_grey + delta) middle++;

 //             qDebug("%d,%d:  sum = %f        grey_vals = %d       coeff = %f   num_contributors = %f ----------------\n",
 //                    i,j, sum, grey_vals[i][j], intersect(vim,piece_coords), num_contributors);
        }
    }



   //printf("sum = %f, avg = %f\n", sum, ((double)sum/num_contributors));
/*
   if (middle > columns*rows/2)  // if there are more than half middle values"  --> low contrast, get one point of
   {
       printf("LOW CONTRAST!!!!!!!!!!!\n");
       return ((double)sum/num_contributors - 1.);
   }
   else
       */
    float avg = (float)sum/num_contributors;
    float out = 0;

    // the output values are the probabilities
    if (avg <= 20 || avg>= 125) out = 0;
    if (avg > 59. && avg < 100.) out = 3.;
    if (avg > 59. && avg < 70.)
    {
        if (very_low > 90 && low > 200) out = 1.;
    }
   /* {
        if (very_low >= 100)
        {
            if (low > 170) out = 1.;
            else out= 3.;
        }
        else 
        {
            if (very_low >= 80 && low > 200) out = 1.;
            else out = 3.;
        }
    }
*/

    if (avg > 20 && avg < 60) out = 1.;
    if (avg > 99 && avg < 125) out = 1.;
    if (avg > 124) out = 0;

// LETS IGNORE EVERYTHING ABOVE. XA--XA

    out = 10.;
    if (low > 240 || very_low > 140 || avg < 50) out = 1.;
    if (very_high >= 9 || high > 150 || low < 100 || avg > 120) out = 1.;
    if (out == 1.  && very_high > 0) out = 5.;





    //printf("%f,%f,%d,%d,%d,%d,%d\n", avg, out, very_high, high, middle, low, very_low);

    return out;

}
