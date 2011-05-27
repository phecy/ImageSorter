#include "setdisplay.h"
#include "ui_setdisplay.h"

SetDisplay::SetDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetDisplay)
{
    ui->setupUi(this);
}

SetDisplay::~SetDisplay()
{
    delete ui;
}

void SetDisplay::display(vector<VImage*> vims)
{
    qDebug("Initialize ui sets");

    QWidget* widgets[12] = { ui->widget_1, ui->widget_2,
        ui->widget_3, ui->widget_4, ui->widget_5, ui->widget_6,
        ui->widget_7, ui->widget_8, ui->widget_9, ui->widget_10,
        ui->widget_11, ui->widget_12 };

    int max = 12;
    if(vims.size() < 12) max = vims.size();
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
