/********************************************************************************
** Form generated from reading UI file 'setdisplay.ui'
**
** Created: Mon Apr 4 13:09:09 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDISPLAY_H
#define UI_SETDISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetDisplay
{
public:
    QWidget *centralwidget;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_12;
    QWidget *widget_7;
    QWidget *widget_1;
    QWidget *widget_5;
    QWidget *widget_2;
    QWidget *widget_11;
    QWidget *widget_8;
    QWidget *widget_6;
    QWidget *widget_9;
    QWidget *widget_10;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SetDisplay)
    {
        if (SetDisplay->objectName().isEmpty())
            SetDisplay->setObjectName(QString::fromUtf8("SetDisplay"));
        SetDisplay->resize(463, 282);
        SetDisplay->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(SetDisplay);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(230, 10, 100, 75));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(340, 10, 100, 75));
        widget_12 = new QWidget(centralwidget);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setGeometry(QRect(340, 170, 100, 75));
        widget_7 = new QWidget(centralwidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(230, 90, 100, 75));
        widget_1 = new QWidget(centralwidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setGeometry(QRect(10, 10, 100, 75));
        widget_1->setMaximumSize(QSize(400, 300));
        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(10, 90, 100, 75));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(120, 10, 100, 75));
        widget_11 = new QWidget(centralwidget);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setGeometry(QRect(230, 170, 100, 75));
        widget_8 = new QWidget(centralwidget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(340, 90, 100, 75));
        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(120, 90, 100, 75));
        widget_9 = new QWidget(centralwidget);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setGeometry(QRect(10, 170, 100, 75));
        widget_10 = new QWidget(centralwidget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setGeometry(QRect(120, 170, 100, 75));
        SetDisplay->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SetDisplay);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SetDisplay->setStatusBar(statusbar);

        retranslateUi(SetDisplay);

        QMetaObject::connectSlotsByName(SetDisplay);
    } // setupUi

    void retranslateUi(QMainWindow *SetDisplay)
    {
        SetDisplay->setWindowTitle(QApplication::translate("SetDisplay", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetDisplay: public Ui_SetDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDISPLAY_H
