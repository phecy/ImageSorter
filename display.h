#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QLabel>

namespace Ui {
    class display;
}

class display : public QMainWindow
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = 0);
    ~display();
    void setImageData(char** fn, float* rnk, int* sn, int ns, int sz)
        {filenames = fn; ranks=rnk; size=sz; setnum=sn; numsets=ns;}
    void init();

private:
    void newPic(int picnum = 0);
    void enableAllButtons();

    // Returns -1 if none other exist
    int findOthersInSet(bool lookForward);

    // Change ui to display given image and update vars
    void goToPic(int whichPic);

    Ui::display *ui;
    char** filenames;
    float* ranks;
    int* setnum;
    int size;
    int numsets;
    QImage** images;
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
