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
#include "contrast.h"
#include "harmony.h"
#include "findDups.h"
#include "grey.h"
#include "display.h"
#include "insertionsort.h"
#include "duplicatesegmented.h"
#include "qualityexif.h"
#include "vimage.h"
#include "algorithmPresets.h"
#include "setdisplay.h"

#define RANGE 10
#define RANK_THRESHOLD 4

// USE THIS TO IGNORE ALL SET COMPUTATIONS:
//#define IGNORE_SETS

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
// Then prints all info to cerr
void calcAndPrintWeights(vector<VImage*> &imageInfoArray,
                 float* picValue, float* exposeVals, float* contrastVals,
                 float* localContrastVals,
                 int* palletVals, int* greyVals, float* blurVals,
                 int* sharpVals, int numPics) {
    float exposeScale = .35; // correlation: .27turk / .058ke
                            // Exposure: .26turk.051ke
                            // Middle gray: .11turk / .10ke
    float palletScale = .05; // correlation: .01turk / -.3 ke
    float blurScale = .6; // correlation: .26turk / .15ke
                         // sharp: .45turk / .33ke
                         // blur: shit.

    //cerr<<"\n<<<<<<<<<<<<  Printing Final Values >>>>>>>>>>>>>>>>>>\n" << endl;
    for(int i=0;i<numPics; ++i){
        // Average of fourth-root of squared-squares
        float combinedBlur = 1*blurVals[i] + 0*sharpVals[i];
        float combinedExpose = 1*exposeVals[i]+0*greyVals[i];
        float contrast = contrastVals[i];
        float local_contrast = localContrastVals[i];

        /*
        double rank=0;
        int xVals[3];
        double yVals[3];
        xVals[0]=combinedBlur;
        yVals[0]=combinedBlur/100.0 + .1;
        xVals[1]=combinedExpose;
        yVals[1]=combinedExpose/100.0 + .1;
        xVals[2]=palletVals[i];
        yVals[2]=palletVals[i]/100.0 + .1;
        for(int i=0; i<3; ++i) {
            rank += xVals[i] / pow2(yVals[i]);
        }
        double d=0;
        for(int i=0; i<3; ++i) {
            d += (1 / pow2(yVals[i]));
        }
        rank/=d;
        */

        float rank = root3((pow2(combinedExpose+RANK_THRESHOLD)))*exposeScale;
        rank += root3((pow2(palletVals[i]+RANK_THRESHOLD)))*palletScale;
        rank += root3((pow2(combinedBlur+RANK_THRESHOLD)))*blurScale;
        rank = pow3(rank);
        rank = sqrt(rank);
        rank-=RANK_THRESHOLD;


        if(rank > RANGE) rank = RANGE;
        --rank; // 1...10 -> 0...9
        if(rank < 0) rank = 0;
        picValue[i] =  rank;

        vector<float> finalRank;
        finalRank.push_back(combinedBlur);
        finalRank.push_back(combinedExpose);
        finalRank.push_back(contrast);
        finalRank.push_back(local_contrast);
        imageInfoArray[i]->setRanks(finalRank);
/*
        cerr << "else if(strcmp(vim->getFilename(), \"" <<
                imageInfoArray[i]->getFilename() << "\") == 0) {\n";
        cerr << "         exposeVals[i] = " << exposeVals[i] << ";\n";
        cerr << "         palletVals[i] = " << palletVals[i] << ";\n";
        cerr << "           greyVals[i] = " << greyVals[i] << ";\n";
        cerr << "           blurVals[i] = " << blurVals[i] << ";\n";
        cerr << "          sharpVals[i] = " << sharpVals[i] << ";\n";
        cerr << "//          picValue[i] = " << picValue[i] << ";\n";
        cerr << "//   Blur: " << combinedBlur << endl;
        cerr << "//   Exposure: " << combinedExpose << endl;
        cerr << "//   Color: " << palletVals[i] << endl;
        cerr << "}\n";*/

  }
    cerr<<"\n<<<<<<<<<<<<  Printing CONDENSED Values >>>>>>>>>>>>>>>>>>\n" << endl;
    for(int i=0;i<numPics; ++i){
        cerr << picValue[i] << "," << imageInfoArray[i]->getFilename() << endl;
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
    Contrast contrastRater;
#ifdef IGNORE_SETS

#endif

    // Initialize ranks from all modules
    float exposeVals[size];
    float contrastVals[size];
    float localContrastVals[size];
    int palletVals[size];
    int greyVals[size];
    float blurVals[size];
    int sharpVals[size];
    QualityExif exifs[size];
    for(int i=0; i < size; ++i){
        finalValue[i] = 0.0f;
        exposeVals[i] = 0;
        palletVals[i] = 0;
        greyVals[i] = 0;
        blurVals[i] = -1;
        sharpVals[i] = 0;
        contrastVals[i] = 0;
        localContrastVals[i] = 0;
    }

    //Call different calculation methods
    QImage* currQIm;
    for(int i=0;i<size; ++i){
        char* fn = imageStrArray[i];
        VImage* currVIm = new VImage(fn);
        currVIm->setIndex(i);
        currQIm = currVIm->getQImage();
        if(currQIm == NULL) {
            cerr << "Image " << fn << " failed to load!\n";
            return false;
        }

        imageInfoArray[i] = currVIm;

        // First get exif
        loadExif(&exifs[i], fn);

        // Find duplicates; use IPs to get foreground
#ifndef IGNORE_SETS
        dupFinder.addImage(currVIm, &exifs[i]);
#endif

        if(!loadPreset(currVIm, i, exposeVals, palletVals,
                       greyVals, blurVals, sharpVals)) {
            // Calc ranks
            exposeVals[i] = newExpose.expose(currVIm) - 1;
            //palletVals[i] = colorAnalysis(currQIm);
            //greyVals[i] = newGrey.calcGrey(currQIm);
            //blurVals[i] = newBlur->calculateBlur(currVIm);
            //sharpVals[i] = sharpDetect.rankOne(currVIm);
        }
        //blurVals[i] = newBlur->calculateBlur(currVIm);
        // newBlur->show();
        exposeVals[i] = newExpose.expose(currVIm);
        contrastVals[i] = contrastRater.local_contrast(currVIm);
        localContrastVals[i] = contrastRater.RMS(currVIm);
    }

    // Sets the different methods' respective weights.
    // Puts it into calcWeights.
    calcAndPrintWeights(imageInfoArray, finalValue, exposeVals, contrastVals,
                        localContrastVals,
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

#ifndef IGNORE_SETS
    //Finds and combines duplicates.
    dupFinder.createSimilarityVector();
    vector<vector<VImage*> > dupList = dupFinder.findDuplicates();
    numSets=dupList.size();

    // Debug output
    //dupFinder.printRanks();

    // Fill in VImage info
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
#else
    numSets = 1;
    for(int i=0; i<size; ++i) {
        imageInfoArray[i]->setSetNum(0);
        imageInfoArray[i]->setRank(picValue[i]);
    }
#endif

//    SetDisplay *setdisp_unsorted = new SetDisplay();
//    setdisp_unsorted->display(imageInfoArray);
//    setdisp_unsorted->setWindowTitle("Unsorted");

    // Sort
    insertion_sort(picValue, imageStrArray, size);
    //imageInfoArray = similarity_sort(imageInfoArray, dupFinder);
    //imageInfoArray = set_sort(imageInfoArray);

    // GUI
    const char* ranktext[4] = {"Blur", "Exposure", "Contrast", "Local "};
    display *disp = new display();
    disp->setImageData(imageInfoArray, numSets, size);
    disp->setRankText(ranktext);
    disp->init();

//    SetDisplay *setdisp_sorted = new SetDisplay();
//    setdisp_sorted->display(imageInfoArray);
//    setdisp_sorted->setWindowTitle("Sorted");

    return app.exec();
}
