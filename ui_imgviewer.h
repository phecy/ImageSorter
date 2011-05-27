/********************************************************************************
** Form generated from reading UI file 'imgviewer.ui'
**
** Created: Fri May 27 14:11:43 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGVIEWER_H
#define UI_IMGVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgViewer
{
public:
    QWidget *widget;
    QPushButton *nextBut;
    QPushButton *prevBut;
    QLabel *rankText;
    QSlider *slider;
    QPushButton *prevSetBut;
    QPushButton *nextSetBut;
    QLabel *indivRanks;

    void setupUi(QWidget *ImgViewer)
    {
        if (ImgViewer->objectName().isEmpty())
            ImgViewer->setObjectName(QString::fromUtf8("ImgViewer"));
        ImgViewer->resize(650, 535);
        widget = new QWidget(ImgViewer);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(24, 10, 601, 400));
        widget->setBaseSize(QSize(600, 400));
        nextBut = new QPushButton(ImgViewer);
        nextBut->setObjectName(QString::fromUtf8("nextBut"));
        nextBut->setGeometry(QRect(550, 450, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Meiryo UI"));
        font.setBold(false);
        font.setWeight(50);
        nextBut->setFont(font);
        prevBut = new QPushButton(ImgViewer);
        prevBut->setObjectName(QString::fromUtf8("prevBut"));
        prevBut->setGeometry(QRect(30, 450, 75, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Meiryo UI"));
        prevBut->setFont(font1);
        rankText = new QLabel(ImgViewer);
        rankText->setObjectName(QString::fromUtf8("rankText"));
        rankText->setGeometry(QRect(140, 450, 361, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Meiryo UI"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        rankText->setFont(font2);
        slider = new QSlider(ImgViewer);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(30, 480, 601, 19));
        slider->setMaximum(1);
        slider->setValue(0);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickPosition(QSlider::TicksBelow);
        prevSetBut = new QPushButton(ImgViewer);
        prevSetBut->setObjectName(QString::fromUtf8("prevSetBut"));
        prevSetBut->setGeometry(QRect(30, 500, 75, 23));
        prevSetBut->setFont(font1);
        nextSetBut = new QPushButton(ImgViewer);
        nextSetBut->setObjectName(QString::fromUtf8("nextSetBut"));
        nextSetBut->setEnabled(true);
        nextSetBut->setGeometry(QRect(550, 500, 75, 23));
        nextSetBut->setFont(font);
        indivRanks = new QLabel(ImgViewer);
        indivRanks->setObjectName(QString::fromUtf8("indivRanks"));
        indivRanks->setGeometry(QRect(40, 430, 501, 20));
        indivRanks->setFont(font2);
        indivRanks->setAlignment(Qt::AlignCenter);

        retranslateUi(ImgViewer);

        QMetaObject::connectSlotsByName(ImgViewer);
    } // setupUi

    void retranslateUi(QWidget *ImgViewer)
    {
        ImgViewer->setWindowTitle(QApplication::translate("ImgViewer", "Form", 0, QApplication::UnicodeUTF8));
        nextBut->setText(QApplication::translate("ImgViewer", "Next", 0, QApplication::UnicodeUTF8));
        prevBut->setText(QApplication::translate("ImgViewer", "Previous", 0, QApplication::UnicodeUTF8));
        rankText->setText(QApplication::translate("ImgViewer", "Image %d/%d: Ranked %.03f/9 || set %d/%d", 0, QApplication::UnicodeUTF8));
        prevSetBut->setText(QApplication::translate("ImgViewer", "Prev. In Set", 0, QApplication::UnicodeUTF8));
        nextSetBut->setText(QApplication::translate("ImgViewer", "Next In Set", 0, QApplication::UnicodeUTF8));
        indivRanks->setText(QApplication::translate("ImgViewer", "Individual ranks", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImgViewer: public Ui_ImgViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGVIEWER_H
