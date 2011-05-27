/********************************************************************************
** Form generated from reading UI file 'maindisplay.ui'
**
** Created: Fri May 27 14:43:22 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDISPLAY_H
#define UI_MAINDISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDisplay
{
public:
    QWidget *tab;
    QPushButton *trainButton;
    QPushButton *newImgButton;

    void setupUi(QTabWidget *MainDisplay)
    {
        if (MainDisplay->objectName().isEmpty())
            MainDisplay->setObjectName(QString::fromUtf8("MainDisplay"));
        MainDisplay->resize(658, 573);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        trainButton = new QPushButton(tab);
        trainButton->setObjectName(QString::fromUtf8("trainButton"));
        trainButton->setGeometry(QRect(560, 80, 91, 26));
        newImgButton = new QPushButton(tab);
        newImgButton->setObjectName(QString::fromUtf8("newImgButton"));
        newImgButton->setGeometry(QRect(560, 120, 91, 26));
        MainDisplay->addTab(tab, QString());

        retranslateUi(MainDisplay);

        MainDisplay->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainDisplay);
    } // setupUi

    void retranslateUi(QTabWidget *MainDisplay)
    {
        MainDisplay->setWindowTitle(QApplication::translate("MainDisplay", "TabWidget", 0, QApplication::UnicodeUTF8));
        trainButton->setText(QApplication::translate("MainDisplay", "Train on data...", 0, QApplication::UnicodeUTF8));
        newImgButton->setText(QApplication::translate("MainDisplay", "New images...", 0, QApplication::UnicodeUTF8));
        MainDisplay->setTabText(MainDisplay->indexOf(tab), QApplication::translate("MainDisplay", "Open files", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainDisplay: public Ui_MainDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDISPLAY_H
