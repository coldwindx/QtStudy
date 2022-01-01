#include "MainWindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QMouseEvent>

QVector<MoveButton*> MainWindow::mVecBtns;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mVecBtns.push_back(ui->zombie);
    mVecBtns.push_back(ui->skeleton);
    mVecBtns.push_back(ui->witch);
    mVecBtns.push_back(ui->creeper);
    mVecBtns.push_back(ui->slime);

}

MainWindow::~MainWindow()
{
    delete ui;
}
