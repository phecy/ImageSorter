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

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <assert.h>

#include <QApplication>
#include <QTabWidget>
#include <QFileDialog>
#include <QtDebug>
#include <QImageReader>
#include <QtPlugin>
#include <QImage>
#include <QPixmap>

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
#include "duplicates/findDups.h"
#include "grey.h"
#include "insertionsort.h"
#include "duplicates/segmented.h"
#include "qualityexif.h"
#include "vimage.h"
#include "algorithmPresets.h"
#include "ml/learner.h"
#include "ml/traindata.h"
#include "ml/getrating.h"
#include "common.h"
#include "display/imgviewer.h"
#include "display/maindisplay.h"
#include "display/setdisplay.h"

#define RANGE 10
#define RANK_THRESHOLD 4

// USE THIS TO IGNORE ALL SET COMPUTATIONS:
#define IGNORE_SETS

static QTabWidget *disp;

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
void loadExif(QualityExif& exifs, const char* fn) {
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

    exifs.parseData(data);
    exif_loader_unref(loader);
}

vector<VImage*> initVImages(vector<char*> imageStrArray) {
    vector<VImage*> imageInfoArray;
    int numims = imageStrArray.size();

    QImage* currQIm;
    for(int i=0;i<numims; ++i){
        char* fn = imageStrArray[i];
        VImage* currVIm = new VImage(fn);
        currVIm->setIndex(i);
        currQIm = currVIm->getQImage();
        if(currQIm == NULL) {
            cerr << "Image " << fn << " failed to load!\n";
            exit(1);
        }

        imageInfoArray.push_back(currVIm);

        // First get exif
        loadExif(currVIm->getExif(), fn);
    }
    return imageInfoArray;
}

void runAllModules(vector<VImage*> &imageInfoArray) {
    // Create each module object
    Exposure exposureRater;
    Contrast contrastRater;
    BlurDetect blurRater;
#ifndef FAST_MODE
    SharpDetect sharpRater;
#endif

    VImage* vim;
    for(int i=0;i<imageInfoArray.size(); ++i){
        vim = imageInfoArray[i];
#ifndef IGNORE_SETS
        // Find duplicates; use IPs to get foreground
        dupFinder.addImage(vim, vim->getExif());
#endif

#ifndef FAST_MODE
        vim->addRank("sharpness",
                       sharpRater.rankOne(vim));
#endif
        // newBlur->show();
        vim->addRank("blur",
                       blurRater.calculateBlur(vim));
        vim->addRank("exposure",
                       exposureRater.rate(vim));
        vim->addRank("contrast",
                       contrastRater.RMS(vim));
        vim->addRank("localcontrast",
                       contrastRater.local_contrast(vim));
    }
}


// Returns number of sets
int manageSets(vector<VImage*>& imageInfoArray, Duplicates& dupfinder) {
    int numSets;
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
       }
    }
#else
    numSets = 1;
    for(int i=0; i<imageInfoArray.size(); ++i) {
        imageInfoArray[i]->setSetNum(0);
    }
#endif

    return numSets;
}

void manageDisplays(vector<VImage*>& imageInfoArray, int numSets) {
    // Sort
    //insertion_sort(picValue, imageStrArray, numFiles);
    //imageInfoArray = similarity_sort(imageInfoArray, dupFinder);
    //imageInfoArray = set_sort(imageInfoArray);

    // GUI
    vector<string> ranksToDisplay;
    ranksToDisplay.push_back("blur");
    ranksToDisplay.push_back("exposure");
    ranksToDisplay.push_back("contrast");
    ranksToDisplay.push_back("localcontrast");

    ImgViewer *viewer = new ImgViewer();
    viewer->setImageData(imageInfoArray, numSets);
    viewer->setRanksToDisplay(ranksToDisplay);
    viewer->init();

    disp->addTab(viewer, QIcon(), "Image Browser");
    disp->setCurrentWidget(viewer);

    SetDisplay *setdisp_sorted = new SetDisplay();
    setdisp_sorted->display(imageInfoArray);
    disp->addTab(setdisp_sorted, QIcon(), "Top Images (incl. sets)");

}

vector<char*> makeCStringVector(QStringList files) {
    vector<char*> imageStrArray;
    // Get strings for each filename
    for(int i=0; i < files.size(); ++i) {
        QByteArray temp = (files.at(i)).toLatin1();
        char* data = temp.data();
        imageStrArray.push_back(strdup(data));
    }
    return imageStrArray;
}

TrainData* makeTrainingSet(vector<VImage*>& imageInfoArray) {
    // For testing
    TrainData* training = new TrainData();
    for(int i=0; i<imageInfoArray.size(); ++i) {
        vector<double> features;
        vector<pair<string, float> > ratings = imageInfoArray[i]->getRanks();

        for(int f=0; f<ratings.size(); ++f) {
            features.push_back(ratings[f].second);
        }
        training->addSample(features, features, features.at(0) + features.at(1));
    }
    return training;
}

void loadFiles(bool isTraining) {
    QStringList files = QFileDialog::getOpenFileNames(
            0,
            "Select the images you wish to use",
            NULL,
            "Images (*.jpeg *.jpg *.nef *.raw)");

    // Check validity of file dialog result
    int numFiles = files.length();
    if(numFiles == 0) return;

    // Initialization
    vector<char*> imageStrArray = makeCStringVector(files);
    Duplicates dupFinder(numFiles);
    vector<VImage*> imageInfoArray = initVImages(imageStrArray);

    // Calculations
    runAllModules(imageInfoArray);
    int numSets = manageSets(imageInfoArray, dupFinder);

    // Learning
    GetRating* rater;
    if(isTraining) {
        TrainData* t = makeTrainingSet(imageInfoArray);
        rater = new GetRating(t, 1);
        delete t;
    } else {
        rater = new GetRating(1); // Use default
    }
    rater->rate(imageInfoArray);
    delete rater;

    // Display
    manageDisplays(imageInfoArray, numSets);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    disp = new MainDisplay();
    disp->show();

    return app.exec();
}
