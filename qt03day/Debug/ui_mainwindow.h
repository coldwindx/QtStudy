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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openBtn;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *saveAsBtn;
    QPushButton *saveAsBinBtn;
    QPushButton *readBinBtn;
    QSlider *volumeSlider;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(476, 462);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openBtn = new QPushButton(centralWidget);
        openBtn->setObjectName(QStringLiteral("openBtn"));
        openBtn->setGeometry(QRect(40, 50, 89, 24));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 50, 261, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 100, 371, 181));
        saveAsBtn = new QPushButton(centralWidget);
        saveAsBtn->setObjectName(QStringLiteral("saveAsBtn"));
        saveAsBtn->setGeometry(QRect(40, 300, 89, 24));
        saveAsBinBtn = new QPushButton(centralWidget);
        saveAsBinBtn->setObjectName(QStringLiteral("saveAsBinBtn"));
        saveAsBinBtn->setGeometry(QRect(150, 300, 141, 24));
        readBinBtn = new QPushButton(centralWidget);
        readBinBtn->setObjectName(QStringLiteral("readBinBtn"));
        readBinBtn->setGeometry(QRect(300, 300, 141, 24));
        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(40, 340, 160, 18));
        volumeSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 340, 31, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        openBtn->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
        saveAsBtn->setText(QApplication::translate("MainWindow", "Save as", Q_NULLPTR));
        saveAsBinBtn->setText(QApplication::translate("MainWindow", "Save as binary", Q_NULLPTR));
        readBinBtn->setText(QApplication::translate("MainWindow", "read binary", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
