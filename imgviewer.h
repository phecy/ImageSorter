#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QLabel>

#include "vimage.h"

namespace Ui {
    class display;
}

class display : public QMainWindow
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = 0);
    ~display();
    void setImageData(const vector<VImage*> &im,int ns, int sz)
        {images = im; size=sz; numsets=ns;}
    void setRanksToDisplay(vector<string> r) { ranksToDisplay = r; }
    void init();

private:
    void newPic(int picnum = 0);
    void enableAllButtons();

    // Returns -1 if none other exist
    int findOthersInSet(bool lookForward);

    // Change ui to display given image and update vars
    void goToPic(int whichPic);

    Ui::display *ui;
    int size;
    int numsets;
    vector<VImage*> images;
    vector<string> ranksToDisplay; // Text description for each rank

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
