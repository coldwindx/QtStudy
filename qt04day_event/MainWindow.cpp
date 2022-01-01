#include "MainWindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QMouseEvent>
#include<QTimer>

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
    // set timer
    this->timer = this->startTimer(1000);

    QTimer * timer2 = new QTimer(this);
    timer2->start(1000);
    connect(timer2, &QTimer::timeout, [&]()->void{
                static int num = 0;
                ui->lcd2->display(++num);
    });
}
void MainWindow::timerEvent(QTimerEvent * event)
{
    if(event->timerId() == timer)
    {
        static int num = 0;
        ui->lcd1->display(++num);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
