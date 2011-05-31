#ifndef MAINDISPLAY_H
#define MAINDISPLAY_H

#include <QTabWidget>

namespace Ui {
    class MainDisplay;
}

class MainDisplay : public QTabWidget
{
    Q_OBJECT

public:
    explicit MainDisplay(QWidget *parent = 0);
    ~MainDisplay();

private:
    Ui::MainDisplay *ui;

protected slots:
    void loadFileTrain(); // Load training data files
    void loadFileNew(); // Load files to predict on

    void loadTrainData(); // Load a tdat file
};

#endif // MAINDISPLAY_H
