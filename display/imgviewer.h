#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QLabel>

#include "vimage.h"

namespace Ui {
    class ImgViewer;
}

class ImgViewer : public QWidget
{
    Q_OBJECT

public:
    explicit ImgViewer(QWidget *parent = 0);
    ~ImgViewer();
    void setImageData(const vector<VImage*> &im,int ns)
        {images = im; size=im.size(); numsets=ns;}
    void setRanksToDisplay(vector<string> r) { ranksToImgViewer = r; }
    void init();

private:
    void newPic(int picnum = 0);
    void enableAllButtons();

    // Returns -1 if none other exist
    int findOthersInSet(bool lookForward);

    // Change ui to ImgViewer given image and update vars
    void goToPic(int whichPic);

    Ui::ImgViewer *ui;
    int size;
    int numsets;
    vector<VImage*> images;
    vector<string> ranksToImgViewer; // Text description for each rank

    QLabel* label;

    QPixmap currPix;
    int currPixIndex;

    int nextInCurrSet;
    int prevInCurrSet;

protected slots:
    void prevImage();
    void nextImage();
    void prevInSet();
    void nextInSet();
    void slid(int);
};

#endif // DISPLAY_H
