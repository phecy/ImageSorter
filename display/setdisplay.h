#ifndef SETDISPLAY_H
#define SETDISPLAY_H

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QLabel>

#include "vimage.h"

namespace Ui {
    class SetDisplay;
}

class SetDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit SetDisplay(QWidget *parent = 0);
    ~SetDisplay();

    void display(vector<VImage*> vims);

private:
    Ui::SetDisplay *ui;
};

#endif // SETDISPLAY_H
