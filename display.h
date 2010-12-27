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
    void setImageData(char** fn, float* rnk, int sz) {filenames = fn; ranks=rnk; size=sz;}
    void init();

private:
    void newPic(int picnum = 0);

    Ui::display *ui;
    char** filenames;
    float* ranks;
    int size;
    QImage** images;
    QLabel* label;

    QPixmap currPix;
    int currPixIndex;

protected slots:
    void prevImage();
    void nextImage();
    void slid(int);
};

#endif // DISPLAY_H
