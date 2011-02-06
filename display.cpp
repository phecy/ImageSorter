#include <QPainter>
#include <QLabel>
#include <stdio.h>
#include <assert.h>
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

    currPix = QPixmap::fromImage(*images[picNum]);
    currPix.scaledToWidth(600);

    label->setPixmap(currPix);
    show();

    char text[52];
    // Ranks start at 1, not 0, for display; +1 to indeces
    sprintf(text, "Image %d/%d: Ranked %1.02f/9 || Set number %d/%d",
            picNum+1, size, ranks[picNum], setnum[picNum]+1, numsets);
    ui->rankText->setText(text);
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

    int tempIndex = currPixIndex + direction;
    while(setnum[tempIndex] != setnum[currPixIndex]) {
        tempIndex += direction;
        if(tempIndex < 0 || tempIndex >= size) {
            return -1; // Out of bounds
        }
    }
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
