#include "maindisplay.h"
#include "ui_maindisplay.h"

#include "util/common.h"

MainDisplay::MainDisplay(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::MainDisplay)
{
    ui->setupUi(this);
    QObject::connect(ui->trainButton, SIGNAL(clicked()),
                     this, SLOT(loadFileTrain()));
    QObject::connect(ui->newImgButton, SIGNAL(clicked()),
                     this, SLOT(loadFileNew()));
    QObject::connect(ui->tdat_change, SIGNAL(clicked()),
                     this, SLOT(loadTrainData()));
    QObject::connect(this, SIGNAL(tabCloseRequested(int)),
                     this, SLOT(closeTab(int)));

    QString defaultname(DEFAULT_LEARN_DIR);
    defaultname.append(DEFAULT_SVR_FILENAME);
    ui->tdat_var->setText(defaultname);
}

MainDisplay::~MainDisplay() {
    delete ui;
}

void loadFiles(bool isTrainingSet);

void MainDisplay::loadFileTrain() {
    loadFiles(true);
}

void MainDisplay::loadFileNew() {
    loadFiles(false);
}

void MainDisplay::loadTrainData() {

}

void MainDisplay::closeTab(int tabIndex) {
    QWidget *widget = this->widget(tabIndex);
    if(widget != NULL) {
        this->removeTab(tabIndex);
        widget->deleteLater();
    }
}
