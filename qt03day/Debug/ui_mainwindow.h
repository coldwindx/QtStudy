/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "MoveButton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    MoveButton *zombie;
    MoveButton *creeper;
    MoveButton *skeleton;
    MoveButton *witch;
    MoveButton *slime;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcd1;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *lcd2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(415, 357);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        zombie = new MoveButton(centralWidget);
        zombie->setObjectName(QStringLiteral("zombie"));
        zombie->setGeometry(QRect(80, 70, 51, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/zombie.png"), QSize(), QIcon::Normal, QIcon::Off);
        zombie->setIcon(icon);
        zombie->setIconSize(QSize(80, 80));
        creeper = new MoveButton(centralWidget);
        creeper->setObjectName(QStringLiteral("creeper"));
        creeper->setGeometry(QRect(190, 70, 51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/creeper.png"), QSize(), QIcon::Normal, QIcon::Off);
        creeper->setIcon(icon1);
        creeper->setIconSize(QSize(80, 80));
        skeleton = new MoveButton(centralWidget);
        skeleton->setObjectName(QStringLiteral("skeleton"));
        skeleton->setGeometry(QRect(290, 70, 51, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/skeleton.png"), QSize(), QIcon::Normal, QIcon::Off);
        skeleton->setIcon(icon2);
        skeleton->setIconSize(QSize(80, 80));
        witch = new MoveButton(centralWidget);
        witch->setObjectName(QStringLiteral("witch"));
        witch->setGeometry(QRect(130, 170, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/witch.png"), QSize(), QIcon::Normal, QIcon::Off);
        witch->setIcon(icon3);
        witch->setIconSize(QSize(80, 80));
        slime = new MoveButton(centralWidget);
        slime->setObjectName(QStringLiteral("slime"));
        slime->setGeometry(QRect(250, 170, 51, 51));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/png/slime.png"), QSize(), QIcon::Normal, QIcon::Off);
        slime->setIcon(icon4);
        slime->setIconSize(QSize(80, 80));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 250, 171, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lcd1 = new QLCDNumber(horizontalLayoutWidget);
        lcd1->setObjectName(QStringLiteral("lcd1"));

        horizontalLayout->addWidget(lcd1);

        horizontalSpacer = new QSpacerItem(35, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lcd2 = new QLCDNumber(horizontalLayoutWidget);
        lcd2->setObjectName(QStringLiteral("lcd2"));

        horizontalLayout->addWidget(lcd2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        zombie->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        creeper->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        skeleton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        witch->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        slime->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
