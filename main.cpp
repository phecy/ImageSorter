/*
    This file is part of the ImageSorter.

    ImageSorter is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ImageSorter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ImageSorter.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QApplication>
#include <QFileDialog>
#include <QtDebug>
#include <QImageReader>
#include <QtPlugin>
#include <QImage>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

#include "blurdetect.h"
#include "exposure.h"
#include "color.h"
#include "colorUtility.h"
#include "harmony.h"
#include "findDups.h"
#include "grey.h"
#include "display.h"
#include "insertionsort.h"
#include "duplicatesegmented.h"

#define NUM_WANTED_PICS 400



//used to locate duplicate files index
int findIndex(QImage *im, QImage *imageDatArray[], int size){
    for(int i=0; i < size; ++i){
        if(im==imageDatArray[i])
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStringList files = QFileDialog::getOpenFileNames(
            0,
            "Select the images you wish to use",
            NULL,
            "Images (*.png *.ppm *.jpeg *.gif *.pbm *.jpg)");
    int size = files.length();
    if(size == 0) return EXIT_SUCCESS;
    char *imageStrArray[size];
    QImage *imageDatArray[size];
    float picValue[size];
    exposure newExpose;
    Duplicates newDups(size);
    grey newGrey;
    BlurDetect* newBlur = new BlurDetect();

    //Set picture values to 0
    int exposeVals[size];
    int palletVals[size];
    int greyVals[size];
    int blurVals[size];
    int setNum[size]; int numSets = 0; // <= size
    for(int i=0; i < size; ++i){
        picValue[i] = 0.0f;
        exposeVals[i] = 0;
        palletVals[i] = 0;
        greyVals[i] = 0;
        blurVals[i] = 0;
        setNum[i] = 0;
    }

    //Sets the different methods respective weights.
    float exposeScale = 0.4;
    float palletScale = 0.1;
    float blurScale = 0.25;
    float greyScale = 0.25;

    //Creates a .txt file that stores the expanded results.
    ofstream resultsExpanded;
    resultsExpanded.open ("results_expanded.txt");
    resultsExpanded << "Expanded Values:" << endl;

    //Call different calculation methods
    QImage* currIm;
    for(int i=0;i<size; ++i){
        QByteArray temp = (files.at(i)).toLatin1();
        char* data = temp.data();
        imageStrArray[i] = strdup(data);

        currIm = new QImage(imageStrArray[i]);
        if(currIm->isNull()) {
            cout << "Image " << imageStrArray[i] << " failed to load!\n";
            return EXIT_FAILURE;
        }
        imageDatArray[i] = currIm;
        newDups.addImage(currIm);

        //exposeVals[i] = newExpose.expose(currIm);
        // qDebug() << "exposeVals" <<exposeVals[i] << "  image:" <<files[i];
        resultsExpanded << "   image: " <<imageStrArray[i] << " expose: " <<exposeVals[i];

        //palletVals[i] = colorAnalysis(currIm);
        // qDebug() << "palletVals" <<palletVals[i] << "  image:" <<files[i];
        resultsExpanded << " pallet: " <<palletVals[i];

        //greyVals[i] = newGrey.calcGrey(currIm);
        // qDebug() << "greyVals" <<greyVals[i] << "  image:" <<files[i];
        resultsExpanded <<" grey: " <<greyVals[i];

        blurVals[i] = newBlur->calculateBlur(currIm);
        // qDebug() << "blurVals" <<blurVals[i] << "  image:" <<files[i];
        resultsExpanded << " blur: " <<blurVals[i] <<endl;
        // newBlur->show();

        currIm->~QImage();
    }
    resultsExpanded.close();

    //Calculate picture values using respective weights.

    for(int i=0;i<size; ++i){
     //picValue[i] = exposeVals[i]*exposeScale+palletVals[i]*palletScale;
     //picValue[i] += blurVals[i]*blurScale+greyVals[i]*greyScale;
        picValue[i] = blurVals[i];
    }

    //Finds and combines duplicates.
    vector<vector<QImage*> > dupeList = newDups.findDuplicates();
    numSets=dupeList.size();

    for (int set_index = 0; set_index < numSets; ++set_index)
    {
       float max = 0;
       QImage *best;

       vector<QImage*> picList = dupeList[set_index];
       int picsInSet = picList.size();
       for (int picset_index=0; picset_index < picsInSet; ++picset_index){
           float rating = 0;
           QImage* currPic = picList[picset_index];
           int picIndex = findIndex(currPic, imageDatArray, size);
           rating = picValue[picIndex];
           setNum[picIndex] = set_index;

           if(rating > max){
               // picValue[findIndex(best, imageDatArray, size)] = 0;

               max = rating;
               best = currPic;
           }
           else{
               //set value of picture to zero since it is not a better duplicate
               //cout << "Deleting Duplicate: " << imageArray[findIndex(name, imageArray, argc)] << endl;
               // picValue[findIndex(currPic, imageArray, size)] = 0;
           }
       }
    }


    //Creates a .txt file "results" to store the final values.
    ofstream results;
    results.open ("results.txt");
    results << "Weights:\n" <<"   expose: " << exposeScale;
    results << " pallet: " << palletScale << " blur: " << blurScale;
    results << " grey: " << greyScale << endl << endl;

    //Prints Final Solution set.
    int wantedPics = NUM_WANTED_PICS;// changes how many pictures are wanted from group.

    // Sort
    insertion_sort(picValue, imageStrArray, size);

    // GUI
    display *disp = new display();
    disp->setImageData((char**)imageStrArray, (float*)picValue, setNum, numSets, size);
    disp->init();

    cout<<"\n<<<<<<<<<<<<  Printing Final Values >>>>>>>>>>>>>>>>>>\n" << endl;
    results << "Final Values:" << endl;
    for(int i=0; i<size; ++i) {
        if(picValue[i] != 0) {
           cout << "Picture:\"" << imageStrArray[i] << "\" has a Value of: " << picValue[i] << endl;
           results <<"   Picture:\"" << imageStrArray[i] << "\" has a Value of: " << picValue[i] << endl;
           wantedPics--;
        }
        if(wantedPics == 0) break;
    }

    results.close();
    return app.exec();
}
