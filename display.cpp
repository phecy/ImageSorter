#include <stdio.h>
#include <assert.h>
#include <algorithm>

#include <boost/lexical_cast.hpp>

#include <QPainter>
#include <QLabel>

#include "display.h"
#include "ui_display.h"

display::display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);

    connect(ui->prevBut, SIGNAL(released()), this, SLOT(prevImage()));
    connect(ui->nextBut, SIGNAL(released()), this, SLOT(nextImage()));
    connect(ui->prevSetBut, SIGNAL(released()), this, SLOT(prevInSet()));
    connect(ui->nextSetBut, SIGNAL(released()), this, SLOT(nextInSet()));
    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(slid(int)));
}

display::~display()
{
    delete ui;
}

void display::init()
{
    qDebug("Initialize ui");

    label = new QLabel(ui->widget);
    label->setBackgroundRole(QPalette::Base);
    label->setScaledContents(true);
    label->setFixedSize(600, 400);

    ui->slider->setMaximum(size-1);
    ui->slider->setTickInterval(size/20);

    goToPic(0);
}

void display::newPic(int picNum)
{
    if(picNum < 0 || picNum >= size)
        return;

    VImage* vim = images[picNum];
    QImage* i = vim->getQImage();

    // Gather bounding box info
    point start = vim->getForegroundCoords().first;
    point fin = vim->getForegroundCoords().second;
    float widthScale = (float)i->width() / vim->getOrigWidth();
    float heightScale = (float)i->height() / vim->getOrigHeight();
    start.first *= widthScale;
    fin.first *= widthScale;
    start.second *= heightScale;
    fin.second *= heightScale;

    // Draw bounding box
    for(int w=start.first; w<fin.first; w++) {
        i->setPixel(w, start.second, qRgb(0,255,0));
        i->setPixel(w, fin.second, qRgb(0,255,0));
    }
    for(int h=start.second; h<fin.second; h++) {
        i->setPixel(start.first, h, qRgb(0,255,0));
        i->setPixel(fin.first, h, qRgb(0,255,0));
    }

    currPix = QPixmap::fromImage(*i);

    label->setPixmap(currPix);
    show();

    stringstream indivRankText;
    char text[512];

    // Ranks start at 1, not 0, for display; +1 to indeces
    sprintf(text, "Image %d/%d: Ranked %1.02f/9 [%1.02f] || Set number %d/%d",
            picNum+1, size, vim->getRank(), vim->getAdjustedRank(), vim->getSetNum()+1, numsets);
    vector<pair<string, float> > ranks = vim->getRanks();
    for(int i=0; i<ranks.size(); ++i) {
        if(std::find(ranksToDisplay.begin(),
                ranksToDisplay.end(),
                ranks.at(i).first) == ranksToDisplay.end()) continue;
        indivRankText << ranks.at(i).first << ": " <<
                         setprecision(2) << ranks.at(i).second <<  " || ";
        if(indivRankText.str().size() > 80)
            indivRankText << "\n";
    }

    ui->rankText->setText(text);
    ui->indivRanks->setText(indivRankText.str().c_str());
}

void display::nextImage() {
    if(currPixIndex < size-1) {
        goToPic(currPixIndex+1);
    }
}

void display::prevImage() {
    if(currPixIndex > 0) {
        goToPic(currPixIndex-1);
    }
}

void display::nextInSet() {
    if(nextInCurrSet != -1)
        goToPic(nextInCurrSet);
}

void display::prevInSet() {
    if(prevInCurrSet != -1)
        goToPic(prevInCurrSet);
}

int display::findOthersInSet(bool lookForward) {
    int direction = lookForward ? 1 : -1; // Which way to iterate

    int tempIndex = currPixIndex;
    do {
        tempIndex += direction;
        if(tempIndex < 0 || tempIndex >= size)
            return -1; // Out of bounds
    } while(images[tempIndex]->getSetNum()!=images[currPixIndex]->getSetNum());

    return tempIndex; // Success
}

void display::goToPic(int whichPic) {
    assert(whichPic >= 0 && whichPic < size);

    enableAllButtons();
    currPixIndex = whichPic;

    // This will not display correctly in case size==1
    // Correct prev/next img buttons
    if(currPixIndex == 0) {
        ui->prevSetBut->setEnabled(false);
        ui->prevBut->setEnabled(false);
    } else if(currPixIndex == size-1) {
        ui->nextSetBut->setEnabled(false);
        ui->nextBut->setEnabled(false);
    }

    // Correct prev/next set buttons
    prevInCurrSet = findOthersInSet(false);
    nextInCurrSet = findOthersInSet(true);

    if(prevInCurrSet == -1)
        ui->prevSetBut->setEnabled(false);
    if(nextInCurrSet == -1)
        ui->nextSetBut->setEnabled(false);

    newPic(currPixIndex);
    ui->slider->setValue(currPixIndex);
}

void display::enableAllButtons() {
    ui->prevBut->setEnabled(true);
    ui->prevSetBut->setEnabled(true);
    ui->nextBut->setEnabled(true);
    ui->nextSetBut->setEnabled(true);
}

void display::slid(int pos) {
    goToPic(pos);
}
