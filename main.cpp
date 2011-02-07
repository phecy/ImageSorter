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
#include <QPixmap>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

#include "libexif/exif-loader.h"
#include "libexif/exif-data.h"
#include "blurdetect.h"
#include "sharpdetect.h"
#include "exposure.h"
#include "color.h"
#include "colorUtility.h"
#include "harmony.h"
#include "findDups.h"
#include "grey.h"
#include "display.h"
#include "insertionsort.h"
#include "duplicatesegmented.h"
#include "qualityexif.h"
#include "vimage.h"

// Finds im in imageDatArray and returns its index
// -1 if not exist
int findIndex(QImage *im, QImage *imageDatArray[], int size){
    for(int i=0; i < size; ++i) {
        if(im==imageDatArray[i])
            return i;
    }
    return -1;
}

// Loads the exif data of the image into the QualityExif object
void loadExif(QualityExif* exifs, const char* fn) {
    ExifLoader* loader = exif_loader_new();
    if(!loader) {
        qDebug("No exif data available for %s", fn);
        return;
    }
    // return;
    exif_loader_write_file(loader, fn);
    ExifData* data = exif_loader_get_data(loader);
    if(!data) {
        qDebug("No exif data available for %s", fn);
        return;
    }

    exifs->parseData(data);
    exif_loader_unref(loader);
}

// Calculates ranking for each image based on params. Puts into picValue.
// Then prints all info to cout
void calcAndPrintWeights(char** imageStrArray,
                 float* picValue, int* exposeVals,
                 int* palletVals, int* greyVals, int* blurVals,
                 int* sharpVals, int numPics) {
    float exposeScale = 0.4;
    float palletScale = 0.1;
    float blurScale = 0.25;
    float greyScale = 0.25;

    cout<<"\n<<<<<<<<<<<<  Printing Final Values >>>>>>>>>>>>>>>>>>\n" << endl;
    for(int i=0;i<numPics; ++i){
        picValue[i] =  exposeVals[i]*exposeScale;
        picValue[i] += palletVals[i]*palletScale;
        picValue[i] += .2*blurVals[i]*blurScale + .8*sharpVals[i]*blurScale;
        picValue[i] += greyVals[i]*greyScale;

        cout << "Image \"" << imageStrArray[i] << "\"" << endl;
        cout << "   Total rank: " << picValue[i] << endl;
        cout << "-----------------------" << endl;
        cout << "  *       exposure: " << exposeVals[i] << endl;
        cout << "  *  color pallete: " << palletVals[i] << endl;
        cout << "  *    middle gray: " << greyVals[i] << endl;
        cout << "  *      sharpness: " << sharpVals[i] << endl;
        cout << "  *           blur: " << blurVals[i] << endl << endl;
    }
}

// False on failure
bool calcAllModules(char** imageStrArray, int size, Duplicates dupFinder,
                    QImage** imageDatArray, float* finalValue) {
    // Create each module object
    exposure newExpose;
    grey newGrey;
    BlurDetect* newBlur = new BlurDetect();
    SharpDetect sharpDetect;

    // Initialize ranks from all modules
    int exposeVals[size];
    int palletVals[size];
    int greyVals[size];
    int blurVals[size];
    int sharpVals[size];
    QualityExif exifs[size];
    for(int i=0; i < size; ++i){
        finalValue[i] = 0.0f;
        exposeVals[i] = 0;
        palletVals[i] = 0;
        greyVals[i] = 0;
        blurVals[i] = 0;
        sharpVals[i] = 0;
    }

    //Call different calculation methods
    QImage* currQIm;
    for(int i=0;i<size; ++i){
        char* fn = imageStrArray[i];
        VImage* currVIm = new VImage(fn);
        currQIm = currVIm->getQImage();
        if(currQIm == NULL) {
            cout << "Image " << fn << " failed to load!\n";
            return false;
        }
        imageDatArray[i] = currQIm;

        // First get exif
        loadExif(&exifs[i], imageStrArray[i]);

        dupFinder.addImage(currVIm, &exifs[i], fn);
        exposeVals[i] = newExpose.expose(currQIm);
        palletVals[i] = colorAnalysis(currQIm);
        greyVals[i] = newGrey.calcGrey(currQIm);
        blurVals[i] = newBlur->calculateBlur(currQIm);
        sharpVals[i] = sharpDetect.rankOne(currVIm);
        // newBlur->show();
    }

    // Sets the different methods' respective weights.
    // Puts it into calcWeights.
    calcAndPrintWeights(imageStrArray, finalValue, exposeVals,
                        palletVals, greyVals, blurVals, sharpVals, size);

    return true;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStringList files = QFileDialog::getOpenFileNames(
            0,
            "Select the images you wish to use",
            NULL,
            "Images (*.jpeg *.jpg *.nef *.raw)");

    // Check validity of file dialog result
    int size = files.length();
    if(size == 0) return EXIT_SUCCESS;

    // Some variables for each image
    QImage *imageDatArray[size];
    char *imageStrArray[size];
    float picValue[size];

    // Get strings for each filename
    for(int i=0; i < size; ++i) {
        QByteArray temp = (files.at(i)).toLatin1();
        char* data = temp.data();
        imageStrArray[i] = strdup(data);
    }

    // Initialize duplicate stuff
    Duplicates dupFinder(size);
    int setNum[size];
    int numSets = 0; // <= size
    for(int i=0; i < size; ++i)
        setNum[i] = 0;

    // Calculate everything. Gather duplicates.
    bool succeeded = calcAllModules(imageStrArray, size, dupFinder,
                                    imageDatArray, picValue);
    if(!succeeded) return EXIT_FAILURE;
    /*DEBUG return app.exec(); */

    //Finds and combines duplicates.
    vector<vector<VImage*> > dupList = dupFinder.findDuplicates();
    numSets=dupList.size();

    // Debug output
    dupFinder.printRanks();

    for (int set_index = 0; set_index < numSets; ++set_index)
    {
       float max = 0;
       QImage *best;

       vector<VImage*> picList = dupList[set_index];
       int picsInSet = picList.size();
       for (int picset_index=0; picset_index < picsInSet; ++picset_index){
           float rating = 0;
           QImage* currPic = picList[picset_index]->getQImage();
           int picIndex = findIndex(currPic, imageDatArray, size);
           rating = picValue[picIndex];
           setNum[picIndex] = set_index;

           if(rating > max){
               // picValue[findIndex(best, imageDatArray, size)] = 0;

               max = rating;
               best = currPic;
           }
           else {
               //set value of picture to zero since it is not a better duplicate
               //cout << "Deleting Duplicate: " << imageArray[findIndex(name, imageArray, argc)] << endl;
               // picValue[findIndex(currPic, imageArray, size)] = 0;
           }
       }
    }

    // Sort
    //insertion_sort(picValue, imageStrArray, size);

    // GUI
    display *disp = new display();
    disp->setImageData(imageDatArray, (char**)imageStrArray, (float*)picValue, setNum, numSets, size);
    disp->init();

    return app.exec();
}
