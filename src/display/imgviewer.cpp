#include <cstdio>
#include <assert.h>
#include <algorithm>
#include <iomanip>

#include <boost/lexical_cast.hpp>

#include <QPainter>
#include <QLabel>

#include "imgviewer.h"
#include "ui_imgviewer.h"

ImgViewer::ImgViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImgViewer)
{
    ui->setupUi(this);

    connect(ui->prevBut, SIGNAL(released()), this, SLOT(prevImage()));
    connect(ui->nextBut, SIGNAL(released()), this, SLOT(nextImage()));
    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(slid(int)));
}

ImgViewer::~ImgViewer()
{
    delete ui;
}

void ImgViewer::init()
{
    // qDebug("Initialize ui");

    label = new QLabel(ui->widget);
    label->setBackgroundRole(QPalette::Base);
    label->setScaledContents(true);
    label->setFixedSize(600, 400);

    ui->slider->setMaximum(size-1);
    ui->slider->setTickInterval(size/20);

    goToPic(0);
}

void ImgViewer::newPic(int picNum)
{
    if(picNum < 0 || picNum >= size)
        return;

    VImage* vim = images[picNum];
    QImage* i = vim->getQImage();

    currPix = QPixmap::fromImage(*i);

    label->setPixmap(currPix);
    show();

    stringstream indivRankText;
    char text[512];

    // Ranks start at 1, not 0, for ImgViewer; +1 to indeces
    sprintf(text, "Image %d/%d: Ranked %1.02f/10",
            picNum+1, size, vim->getTotalQuality()*10);
    vector<pair<string, float> > ranks = vim->getQualities();
    for(int i=0; i<ranks.size(); ++i) {
        // If current image isn't found, skip it
        if(std::find(ranksToImgViewer.begin(),
                     ranksToImgViewer.end(),
                     ranks.at(i).first) == ranksToImgViewer.end()) {
            continue;
        }

        indivRankText << ranks.at(i).first << ": " <<
                         setprecision(2) << ranks.at(i).second <<  " || ";
        if(indivRankText.str().size() > 80)
            indivRankText << "\n";
    }

    ui->rankText->setText(text);
    ui->indivRanks->setText(indivRankText.str().c_str());
}

void ImgViewer::nextImage() {
    if(currPixIndex < size-1) {
        goToPic(currPixIndex+1);
    }
}

void ImgViewer::prevImage() {
    if(currPixIndex > 0) {
        goToPic(currPixIndex-1);
    }
}

void ImgViewer::goToPic(int whichPic) {
    assert(whichPic >= 0 && whichPic < size);

    enableAllButtons();
    currPixIndex = whichPic;

    // This will not ImgViewer correctly in case size==1
    // Correct prev/next img buttons
    if(currPixIndex == 0) {
        ui->prevBut->setEnabled(false);
    } else if(currPixIndex == size-1) {
        ui->nextBut->setEnabled(false);
    }

    newPic(currPixIndex);
    ui->slider->setValue(currPixIndex);
}

void ImgViewer::enableAllButtons() {
    ui->prevBut->setEnabled(true);
    ui->nextBut->setEnabled(true);
}

void ImgViewer::slid(int pos) {
    goToPic(pos);
}
