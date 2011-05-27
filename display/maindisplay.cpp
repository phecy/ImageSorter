#include "maindisplay.h"
#include "ui_maindisplay.h"

MainDisplay::MainDisplay(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::MainDisplay)
{
    ui->setupUi(this);
    QObject::connect(ui->trainButton, SIGNAL(clicked()),
                     this, SLOT(loadFileTrain()));
    QObject::connect(ui->newImgButton, SIGNAL(clicked()),
                     this, SLOT(loadFileNew()));
}

MainDisplay::~MainDisplay()
{
    delete ui;
}

void loadFiles(bool isTrainingSet);
void MainDisplay::loadFileTrain() {
    loadFiles(true);
}
void MainDisplay::loadFileNew() {
    loadFiles(false);
}
