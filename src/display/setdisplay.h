#ifndef SETDISPLAY_H
#define SETDISPLAY_H

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QLabel>

#include "similarity/similarity.h"
#include "vimage.h"

#define NUMSETWIDGETS 12

namespace Ui {
    class SetDisplay;
}

class SetDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit SetDisplay(QWidget *parent = 0);
    ~SetDisplay();

    void display(vector<VImage*> vims, Similarity* similarity);

private:
    Ui::SetDisplay *ui;

    QWidget* widgets[NUMSETWIDGETS];
    QLabel* similarityText[NUMSETWIDGETS];
    QLabel* similarityVector[NUMSETWIDGETS];

    vector<VImage*> images;
    Similarity* similarity;

    // Returns the index of the object in widgets, or -1 if not found
    int getWidgetIndex(QObject *object);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // SETDISPLAY_H
