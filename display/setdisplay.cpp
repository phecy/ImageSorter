#include <iostream>
#include <fstream>
#include <sstream>
#include "setdisplay.h"
#include "ui_setdisplay.h"

SetDisplay::SetDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetDisplay)
{
    ui->setupUi(this);

    widgets[0] = ui->widget_1;
    widgets[1] = ui->widget_2;
    widgets[2] = ui->widget_3;
    widgets[3] = ui->widget_4;
    widgets[4] = ui->widget_5;
    widgets[5] = ui->widget_6;
    widgets[6] = ui->widget_7;
    widgets[7] = ui->widget_8;
    widgets[8] = ui->widget_9;
    widgets[9] = ui->widget_10;
    widgets[10] = ui->widget_11;
    widgets[11] = ui->widget_12;

    for(int i=0; i<NUMSETWIDGETS; ++i) {
        widgets[i]->installEventFilter(this);
    }
}

SetDisplay::~SetDisplay()
{
    delete ui;
}

void SetDisplay::display(vector<VImage*> vims)
{
    images = vims;

    int max = NUMSETWIDGETS;
    if(vims.size() < NUMSETWIDGETS) max = vims.size();
    for(int i=0; i<max; ++i) {
        vims.at(i);
        QLabel* label = new QLabel(widgets[i]);
        label->setBackgroundRole(QPalette::Base);
        label->setScaledContents(true);

        QPixmap currPix = QPixmap::fromImage(*vims.at(i)->getQImage());
        currPix = currPix.scaledToWidth(label->width());
        label->setPixmap(currPix);
    }

    show();
}

int getWidgetIndex(QObject *object) {
    for(int i=0; i<NUMSETWIDGETS; ++i) {
        if(images[i] == object) return i;
    }
    return -1;
}

bool SetDisplay::eventFilter(QObject *object, QEvent *event)
{
    int index = getWidgetIndex(object);
    if(index == -1 || event->type() == QEvent::MouseButtonRelease) {
        return false;
    }

    int index = 1;
    cout << "LOL CAUGHT" << endl;
    std::stringstream qualityText;
    std::stringstream uniqueText;

    qualityText << "Quality: " << images[index]->getTotalQuality();
    uniqueText << "Uniqueness: " << images[index]->getUniqueness();
    ui->qualityLabel->setText(qualityText.str().c_str());
    ui->uniquenessLabel->setText(uniqueText.str().c_str());
    return true;
}
