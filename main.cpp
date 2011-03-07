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
#include "boundingbox.h"
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
#include "algorithmPresets.h"

#define NUM_MODULES 3
#define RANGE 10
#define RANK_THRESHOLD 1

// Finds im in imageDatArray and returns its index
// -1 if not exist
int findIndex(QImage *im, vector<VImage*> &imageInfoArray, int size){
    for(int i=0; i < size; ++i) {
        if(im==imageInfoArray[i]->getQImage())
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

// Compute antilog base 10
double alog10(double num) {
    return exp(num * log(10));
}

// Compute x^(1/3)
double root3(double num) {
    return pow(num, 1.0/3.0);
}

// Compute x^3
double pow3(double num) {
    return num*num*num;
}

// Compute x^2
double pow2(double num) {
    return num*num;
}

// Compute fourth-root x
double root4(double num) {
    return sqrt(sqrt(num));
}

// Calculates ranking for each image based on params. Puts into picValue.
// Then prints all info to cout
void calcAndPrintWeights(vector<VImage*> &imageInfoArray,
                 float* picValue, int* exposeVals,
                 int* palletVals, int* greyVals, int* blurVals,
                 int* sharpVals, int numPics) {
    float exposeScale = 0.4;
    float palletScale = 0.1;
    float blurScale = 0.4;

    cout<<"\n<<<<<<<<<<<<  Printing Final Values >>>>>>>>>>>>>>>>>>\n" << endl;
    for(int i=0;i<numPics; ++i){
        // Average of fourth-root of squared-squares
        double combinedBlur = .6*sharpVals[i]+.4*(blurVals[i]+4);
        double combinedExpose = .8*exposeVals[i]+.2*greyVals[i];

        float rank = root3((pow2(combinedExpose+4)-RANK_THRESHOLD))*exposeScale;
        rank += root3((pow2(palletVals[i]+4)-RANK_THRESHOLD))*palletScale;
        rank += root3((pow2(combinedBlur+4)-RANK_THRESHOLD))*blurScale;
        rank = pow3(rank);
        rank /= RANGE;

        if(rank > RANGE) rank = RANGE;
        --rank; // 1...10 -> 0...9
        if(rank < 0) rank = 0;
        picValue[i] =  rank;

        cout << "else if(strcmp(vim->getFilename(), \"" <<
                imageInfoArray[i]->getFilename() << "\") == 0) {\n";
        cout << "         exposeVals[i] = " << exposeVals[i] << ";\n";
        cout << "         palletVals[i] = " << palletVals[i] << ";\n";
        cout << "           greyVals[i] = " << greyVals[i] << ";\n";
        cout << "           blurVals[i] = " << blurVals[i] << ";\n";
        cout << "          sharpVals[i] = " << sharpVals[i] << ";\n";
        cout << "}\n";
    }
    cout<<"\n<<<<<<<<<<<<  Printing CONDENSED Values >>>>>>>>>>>>>>>>>>\n" << endl;
    for(int i=0;i<numPics; ++i){
        cout << picValue[i] << "," << imageInfoArray[i]->getFilename() << endl;
    }
}

// False on failure
bool calcAllModules(vector<VImage*> &imageInfoArray, char** imageStrArray,
                    int size, Duplicates dupFinder, float* finalValue) {
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
        blurVals[i] = -1;
        sharpVals[i] = 0;
    }

    //Call different calculation methods
    QImage* currQIm;
    for(int i=0;i<size; ++i){
        char* fn = imageStrArray[i];
        VImage* currVIm = new VImage(fn);
        currVIm->setIndex(i);
        currQIm = currVIm->getQImage();
        if(currQIm == NULL) {
            cout << "Image " << fn << " failed to load!\n";
            return false;
        }

        imageInfoArray[i] = currVIm;

        // Find duplicates; use IPs to get foreground
        dupFinder.addImage(currVIm, &exifs[i]);
        if(!loadPreset(currVIm, i, exposeVals, palletVals, greyVals, blurVals, sharpVals)) {
            // First get exif
            loadExif(&exifs[i], fn);

            // Calc ranks
            exposeVals[i] = newExpose.expose(currVIm) - 1;
            palletVals[i] = colorAnalysis(currQIm);
            greyVals[i] = newGrey.calcGrey(currQIm);
            blurVals[i] = newBlur->calculateBlur(currVIm);
            sharpVals[i] = sharpDetect.rankOne(currVIm);
    //        newBlur->show();
        }
    }

    // Sets the different methods' respective weights.
    // Puts it into calcWeights.
    calcAndPrintWeights(imageInfoArray, finalValue, exposeVals,
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
    vector<VImage*> imageInfoArray(size);
    char* imageStrArray[size];
    float picValue[size];

    // Get strings for each filename
    for(int i=0; i < size; ++i) {
        QByteArray temp = (files.at(i)).toLatin1();
        char* data = temp.data();
        imageStrArray[i] = strdup(data);
    }

    // Initialize duplicate stuff
    Duplicates dupFinder(size);
    int numSets = 0; // <= size

    // Calculate everything. Gather duplicates.
    bool succeeded = calcAllModules(imageInfoArray, imageStrArray, size, dupFinder, picValue);
    if(!succeeded) return EXIT_FAILURE;
    /*DEBUG return app.exec(); */

    //Finds and combines duplicates.
    vector<vector<VImage*> > dupList = dupFinder.findDuplicates();
    numSets=dupList.size();

    // Debug output
    dupFinder.printRanks();

    for (int set_index = 0; set_index < numSets; ++set_index)
    {
       int picsInSet = dupList[set_index].size();

       // Put data in VImage
       for (int picset_index=0; picset_index < picsInSet; ++picset_index){
           QImage* currPic = dupList[set_index][picset_index]->getQImage();
           int picIndex = findIndex(currPic, imageInfoArray, size);

           dupList[set_index][picset_index]->setSetNum(set_index);
           dupList[set_index][picset_index]->setRank(picValue[picIndex]);
       }
    }

    // Sort
    // insertion_sort(picValue, imageStrArray, size);
    //imageInfoArray = set_sort(imageInfoArray);

    // GUI
    display *disp = new display();
    disp->setImageData(imageInfoArray, numSets, size);
    disp->init();

    return app.exec();
}
