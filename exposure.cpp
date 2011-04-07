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
const int middle_grey = 175;
const int delta = 30;


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



exposure::exposure(){
}

float exposure::expose(VImage *vim) {
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
    int low = 0, middle = 0, high = 0;
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
              boundingBox piece_coords(point(i*piece_width, j*piece_height), point((i+1)*piece_width, (j+1)*piece_height));
              sum += (double)grey_vals[i][j]*intersect(vim,piece_coords);
              num_contributors += intersect(vim,piece_coords);

              if (grey_vals[i][j] - delta > middle_grey) high++;
              else if (grey_vals[i][j] + delta < middle_grey) low++;
              else middle++;

 //             qDebug("%d,%d:  sum = %f        grey_vals = %d       coeff = %f   num_contributors = %f ----------------\n",
 //                    i,j, sum, grey_vals[i][j], intersect(vim,piece_coords), num_contributors);
        }
    }

   printf("sum = %f, avg = %f\n", sum, ((double)sum/num_contributors));

   if (middle > columns*rows/2)  // if there are more than half middle values"  --> low contrast, get one point of
   {
       printf("LOW CONTRAST!!!!!!!!!!!\n");
       return ((double)sum/num_contributors - 1.);
   }
   else return (double)sum/num_contributors;
}
