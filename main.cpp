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
#include <cfloat>
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

#include "exifinfo.h"
#include "vimage.h"
#include "display/imgviewer.h"
#include "display/maindisplay.h"
#include "display/setdisplay.h"
#include "libexif/exif-loader.h"
#include "libexif/exif-data.h"
#include "ml/traindata.h"
#include "ml/getrating.h"
#include "quality/blurdetect.h"
#include "quality/sharpdetect.h"
#include "quality/exposure.h"
#include "quality/contrast.h"
#include "quality/grey.h"
#include "similarity/similarity.h"
#include "util/algorithmPresets.h"
#include "util/common.h"

#define QUALITY_WEIGHT 1
#define UNIQUENESS_WEIGHT 1

static QTabWidget *disp;
Similarity* similarity = NULL;

// Finds im in imageDatArray and returns its index
// -1 if not exist
int findIndex(QImage *im, vector<VImage*> &imageInfoArray, int size){
    for(int i=0; i < size; ++i) {
        if(im==imageInfoArray[i]->getQImage())
            return i;
    }
    return -1;
}

// Loads the exif data of the image into the ExifInfo object
void loadExif(ExifInfo& exifs, const char* fn) {
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

void getQualityRatings(vector<VImage*> &imageInfoArray) {
    // Create each module object
    Exposure exposureRater;
    Contrast contrastRater;
    BlurDetect blurRater;
#ifndef FAST_MODE
    SharpDetect sharpRater;
#endif

    VImage* vim;
    for(int i=0; i<imageInfoArray.size(); ++i){
        vim = imageInfoArray[i];

#ifndef FAST_MODE
        vim->setQuality("sharpness",
                       sharpRater.rankOne(vim));
#endif
        // newBlur->show();
        vim->setQuality("blur",
                       blurRater.calculateBlur(vim));
        vim->setQuality("exposure",
                       exposureRater.rate(vim));
        vim->setQuality("contrast",
                       contrastRater.RMS(vim));
        vim->setQuality("localcontrast",
                       contrastRater.local_contrast(vim));
    }
}

void manageDisplays(vector<VImage*>& unsorted,
                    vector<VImage*>& sorted,
                    Similarity* similarity) {
    // GUI
    vector<string> ranksToDisplay;
    ranksToDisplay.push_back("sharpness");
    ranksToDisplay.push_back("blur");
    ranksToDisplay.push_back("exposure");
    ranksToDisplay.push_back("contrast");
    ranksToDisplay.push_back("localcontrast");

    // Unsorted viewer
    ImgViewer *unsortedViewer = new ImgViewer();
    unsortedViewer->setImageData(unsorted);
    unsortedViewer->setRanksToDisplay(ranksToDisplay);
    unsortedViewer->init();
    disp->addTab(unsortedViewer, QIcon(), "Browse unsorted");

    // Sorted viewer
    ImgViewer *sortedViewer = new ImgViewer();
    sortedViewer->setImageData(sorted);
    sortedViewer->setRanksToDisplay(ranksToDisplay);
    sortedViewer->init();
    disp->addTab(sortedViewer, QIcon(), "Browse sorted");

    // Sorted top images
    SetDisplay *setdisp_sorted = new SetDisplay();
    setdisp_sorted->display(sorted, similarity);
    disp->addTab(setdisp_sorted, QIcon(), "Top 12");

    // Unsorted top images
    SetDisplay *setdisp_unsorted = new SetDisplay();
    setdisp_unsorted->display(unsorted, similarity);
    disp->addTab(setdisp_unsorted, QIcon(), "First 12");

    disp->setCurrentWidget(setdisp_sorted);
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
    map <string, vector<double> > data = TrainData::getCSVData();

    for(int i=0; i<imageInfoArray.size(); ++i) {
        // Get features
        vector<double> features;
        vector<pair<string, float> > ratings = imageInfoArray[i]->getQualities();
        for(int f=0; f<ratings.size(); ++f) {
            features.push_back(ratings[f].second);
        }

        // Get labels
        string filename = imageInfoArray[i]->getFilename();
        map <string, vector<double> >::iterator
                        foundpair = data.find(filename);
        if(foundpair == data.end()) {
            cerr << "No labels found for image " << filename << endl;
            continue;
        }
        vector<double> labels = foundpair->second;

        // Get ground truth
        double groundtruth = labels.back();
        labels.pop_back();

        training->addSample(features, labels, groundtruth);
    }
    return training;
}

// Fills the imageInfoArray with all individual qualities and their total quality
// If no training data, pass a null pointer and this function will try to load
// the default
void getTotalQuality(vector<VImage*>& imageInfoArray) {
    // Learning - combination of individual quality ratings
    GetRating rater(1); // Looad default, 1 HL feature
    rater.rate(imageInfoArray);
}

// Returns the total score of the given image:
// alpha*quality + beta*uniqueness
// Requires similarity to be initialized
// Will update image with uniqueness
float getScore(const vector<VImage*>& currList, VImage* image) {
    float qualityScore = image->getTotalQuality();

    float uniquenessScore = 0;
    for(int i=0; i<currList.size(); ++i) {
        uniquenessScore -= similarity->getSimilarity(currList[i], image);
    }

    // Update internal structure
    image->setUniqueness(uniquenessScore);

    //cout << "quality: " << qualityScore << ", unique: " << uniquenessScore << endl;

    float totalScore = QUALITY_WEIGHT*qualityScore +
                       UNIQUENESS_WEIGHT*uniquenessScore;

    return totalScore;
}

// Looks through candidates and push the best one to the end of the current set
// Requires similarity to be initialized
float addNextBestImage(vector<VImage*>& currList,
                       vector<VImage*>& candidates) {
    float maxScore = -FLT_MAX;
    vector<VImage*>::iterator maxScore_i;

    vector<VImage*>::iterator candidate;
    for(candidate = candidates.begin();
        candidate !=candidates.end();
        ++candidate) {
        float currScore = getScore(currList, *candidate);
        if(currScore > maxScore) {
            maxScore = currScore;
            maxScore_i = candidate;
        }
        cout << "Curr score: " << currScore
             << ", Max Score: " << maxScore << endl;
    }

    assert(*maxScore_i != NULL);

    // Add next image from list
    currList.push_back(*maxScore_i);
    candidates.erase(maxScore_i);

    return maxScore;
}

// Obtains quality ratings
// Requires similarity to be initialized
// And individual qualities to be initialized (not total)
vector<VImage*> sortImages(vector<VImage*>& imageInfoArray) {
    assert(similarity != NULL);
    assert(imageInfoArray[0]->getQualities().size() > 0);

    getTotalQuality(imageInfoArray);

    // Get individual quality rating
    // Create the newly sorted list
    int numIms = imageInfoArray.size();
    vector<VImage*> sortedList;
    vector<VImage*> remainingImages = imageInfoArray;
    for(int i=0; i<numIms; ++i) {
        addNextBestImage(sortedList, remainingImages);
    }

    return sortedList;
}

// Looks for matching MTurk files to go with the imageInfoArray
void trainModelOn(vector<VImage*>& imageInfoArray) {
    assert(imageInfoArray[0]->getQualities().size() > 0);
    TrainData* trainingData = makeTrainingSet(imageInfoArray);
    if(trainingData->size() == 0) {
        cerr << "No training data available!" << endl;
        delete trainingData;
        return;
    }
    GetRating rater(trainingData, 1);
    rater.rate(imageInfoArray);
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
    vector<VImage*> imageInfoArray = initVImages(imageStrArray);
    getQualityRatings(imageInfoArray);

    // Train if requested
    if(isTraining) {
        trainModelOn(imageInfoArray);
        return;
    }

    // Sort the list based on quality + uniqueness
    similarity = new Similarity(imageInfoArray);
    vector<VImage*> sortedImages = sortImages(imageInfoArray);

    // Display
    manageDisplays(imageInfoArray, sortedImages, similarity);
    // delete similarity; DISPLAY WILL DELETE SIMILARITY
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    disp = new MainDisplay();
    disp->setWindowTitle("ImageSorter");
    disp->show();

    return app.exec();
}
