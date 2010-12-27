#include <QPainter>
#include <QLabel>
#include <stdio.h>
#include "display.h"
#include "ui_display.h"

display::display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);

    connect(ui->prevBut, SIGNAL(released()), this, SLOT(prevImage()));
    connect(ui->nextBut, SIGNAL(released()), this, SLOT(nextImage()));
    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(slid(int)));
}

display::~display()
{
    delete ui;
}

void display::init()
{
    qDebug("Init window");
    images = new QImage*[size];
    for(int i=0; i<size; i++) {
        qDebug("Loading image %s", filenames[i]);
        images[i] = new QImage(filenames[i]);
    }

    label = new QLabel(ui->widget);
    label->setBackgroundRole(QPalette::Base);
    label->setScaledContents(true);
    label->setFixedSize(600, 400);

    currPixIndex = 0;
    newPic(currPixIndex);

    ui->slider->setMaximum(size-1);
    ui->slider->setTickInterval(size/20);
}

void display::newPic(int picNum)
{
    if(picNum < 0 || picNum >= size)
        return;

    currPix = QPixmap::fromImage(*images[picNum]);
    currPix.scaledToWidth(600);

    label->setPixmap(currPix);
    show();

    char text[20];
    sprintf(text, "Image %d/%d: Ranked %1.02f/9", picNum+1, size, ranks[picNum]);
    ui->rankText->setText(text);
}

void display::nextImage() {
    if(currPixIndex >= size-1) {
        return;
    } else {
        ++currPixIndex;
        if(currPixIndex == size-1)
            ui->nextBut->setEnabled(false);
        ui->prevBut->setEnabled(true);

        newPic(currPixIndex);
        ui->slider->setValue(currPixIndex);
    }
}

void display::prevImage() {
    if(currPixIndex <= 0) {
        return;
    } else {
        --currPixIndex;
        if(currPixIndex == 0)
            ui->prevBut->setEnabled(false);
        ui->nextBut->setEnabled(true);

        newPic(currPixIndex);
        ui->slider->setValue(currPixIndex);
    }
}

void display::slid(int pos) {
    if(pos == 0)
        ui->prevBut->setEnabled(false);
    else if(currPixIndex == size-1)
        ui->nextBut->setEnabled(false);

    newPic(pos);
}
