#include <iomanip>
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

    similarityText[0] = ui->similarity_1;
    similarityText[1] = ui->similarity_2;
    similarityText[2] = ui->similarity_3;
    similarityText[3] = ui->similarity_4;
    similarityText[4] = ui->similarity_5;
    similarityText[5] = ui->similarity_6;
    similarityText[6] = ui->similarity_7;
    similarityText[7] = ui->similarity_8;
    similarityText[8] = ui->similarity_9;
    similarityText[9] = ui->similarity_10;
    similarityText[10] = ui->similarity_11;
    similarityText[11] = ui->similarity_12;

    for(int i=0; i<NUMSETWIDGETS; ++i) {
        widgets[i]->installEventFilter(this);
        similarityText[i]->setText("");
    }
    ui->uniquenessLabel->setText("");
    ui->qualityLabel->setText("");
}

SetDisplay::~SetDisplay()
{
    delete similarity;
    delete ui;
}

void SetDisplay::display(vector<VImage*> _images, Similarity* _similarity)
{
    images = _images;
    similarity = _similarity;

    int max = NUMSETWIDGETS;
    if(images.size() < NUMSETWIDGETS) max = images.size();
    for(int i=0; i<max; ++i) {
        images.at(i);
        QLabel* label = new QLabel(widgets[i]);
        label->setBackgroundRole(QPalette::Base);
        label->setScaledContents(true);

        QPixmap currPix = QPixmap::fromImage(*images.at(i)->getQImage());
        label->resize(widgets[i]->frameSize());
        currPix = currPix.scaledToWidth(label->width());
        label->setPixmap(currPix);
    }

    show();
}

int SetDisplay::getWidgetIndex(QObject *object) {
    for(int i=0; i<NUMSETWIDGETS; ++i) {
        if(widgets[i] == object) return i;
    }
    return -1;
}

bool SetDisplay::eventFilter(QObject *object, QEvent *event)
{
    int index = getWidgetIndex(object);
    if(index == -1 || event->type() != QEvent::MouseButtonRelease ||
       index >= images.size()) {
        return false;
    }

    std::stringstream qualityText;
    std::stringstream uniqueText;

    // Give it's total quality and uniqueness
    qualityText << "Quality: " << setprecision(2)
                << images[index]->getTotalQuality();
    uniqueText << "Uniqueness: "  << setprecision(2)
               << images[index]->getUniqueness();
    ui->qualityLabel->setText(qualityText.str().c_str());
    ui->uniquenessLabel->setText(uniqueText.str().c_str());

    // Show its similarity to every other image
    char text[32];
    int numims = min(NUMSETWIDGETS, (int)images.size());
    for(int i=0; i<numims; ++i) {
        if(i == index) {
            similarityText[i]->setText("X");
            continue;
        }

        float rating = similarity->getSimilarity(images[i], images[index]);
        sprintf(text, "%1.2f", rating);
        similarityText[i]->setText(text);
    }

    return true;
}
