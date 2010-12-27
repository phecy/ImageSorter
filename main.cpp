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

#include <QApplication>
#include <QFileDialog>
#include <QtDebug>
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

#define NUM_WANTED_PICS 400

//used to locate duplicate files index
int findIndex(char *fileName, char *imageArray[], int argc){
    for(int i=0; i < argc-1;++i){
        if(strcmp(imageArray[i],fileName) == 0)
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
    char *imageArray[size];
    float picValue[size];
    exposure newExpose;
    findDups newDups;
    grey newGrey;
    BlurDetect* newBlur = new BlurDetect();

    //Fill imageArray with file names
    QStringList::Iterator it = files.begin();
    int index=0;
    while(it != files.end()) {
        QByteArray temp = (*it).toLatin1();
        char* data = temp.data();
        newDups.load(data);
        imageArray[index] = strdup(data);
        ++it; ++index;
    }

    //Set picture values to 0
    int exposeVals[size];
    int palletVals[size];
    int greyVals[size];
    int blurVals[size];
    for(int i=0; i < size; ++i){
        picValue[i] = 0.0f;
        exposeVals[i] = 0;
        palletVals[i] = 0;
        greyVals[i] = 0;
        blurVals[i] = 0;
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
        currIm = new QImage(imageArray[i]);
        if(currIm == NULL) {
            cout << "Image " << imageArray[i] << " failed to load!";
            continue;
        }

        exposeVals[i] = newExpose.expose(currIm);
        // qDebug() << "exposeVals" <<exposeVals[i] << "  image:" <<files[i];
        resultsExpanded << "   image: " <<imageArray[i] << " expose: " <<exposeVals[i];

        palletVals[i] = colorAnalysis(currIm);
        // qDebug() << "palletVals" <<palletVals[i] << "  image:" <<files[i];
        resultsExpanded << " pallet: " <<palletVals[i];

        greyVals[i] = newGrey.calcGrey(currIm);
        // qDebug() << "greyVals" <<greyVals[i] << "  image:" <<files[i];
        resultsExpanded <<" grey: " <<greyVals[i];

        blurVals[i] = newBlur->calculateBlur(currIm);
        // qDebug() << "blurVals" <<blurVals[i] << "  image:" <<files[i];
        resultsExpanded << " blur: " <<blurVals[i] <<endl;

        currIm->~QImage();
    }
    resultsExpanded.close();

    //Calculate picture values using respective weights.

    for(int i=0;i<size; ++i){
     picValue[i] = exposeVals[i]*exposeScale+palletVals[i]*palletScale;
     picValue[i] += blurVals[i]*blurScale+greyVals[i]*greyScale;
    }

    //Finds and "deletes" duplicates.
    list<list<string> > dupeList = newDups.findDuplicates();
    list<list<string> >::const_iterator i = dupeList.begin();
    list<list<string> >::const_iterator e = dupeList.end();

    for ( ; i != e; ++i)
    {
       list<string>::const_iterator j = i->begin();
       list<string>::const_iterator je = i->end();
       float max = 0;
       char *best="";

       for ( ; j != je; ++j){
           char name[512];
           float rating = 0;
           strcpy(name, j->c_str());
           rating = picValue[findIndex(name, imageArray, size+1)];
           if(rating > max){
               picValue[findIndex(best, imageArray, size+1)] = 0;
               if(picValue[findIndex(best, imageArray, size+1)] == -1)
                   qDebug() <<" Could not find picture:" << best ;
               max = rating;
               best = name;
           }
           else{
               //set value of picture to zero since it is not a better duplicate
               //cout << "Deleting Duplicate: " << imageArray[findIndex(name, imageArray, argc)] << endl;
               picValue[findIndex(name, imageArray, size-1)] = 0;
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
    insertion_sort(picValue, imageArray, size);

    // GUI
    display *disp = new display();
    disp->setImageData((char**)imageArray, (float*)picValue, size);
    disp->init();

    cout<<"\n<<<<<<<<<<<<  Printing Final Values >>>>>>>>>>>>>>>>>>\n" << endl;
    results << "Final Values:" << endl;
    for(int i=0; i<size; ++i){
        if(picValue[i] != 0) {
           cout << "Picture:\"" << imageArray[i] << "\" has a Value of: " << picValue[i] << endl;
           results <<"   Picture:\"" << imageArray[i] << "\" has a Value of: " << picValue[i] << endl;
           wantedPics--;
        }
        if(wantedPics == 0) break;
    }

    results.close();
    return app.exec();
}
