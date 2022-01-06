#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create threads
    Generate * generate = new Generate(this);
    BubbleSort * bubble = new BubbleSort(this);
    QuickSort * quick = new QuickSort(this);
    // Stare threads
        // 这里lambda表达式引用Thread必须使用值引用
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        generate->recvNum(1000);
        generate->start();
    });
    // Recv list from thread
        // Cannot queue arguments of type 'QVector<int>&'
        // main.cpp use 'qRegisterMetaType' to register
    connect(generate, &Generate::sendArray, bubble, &BubbleSort::recvArray);
    connect(generate, &Generate::sendArray, quick, &QuickSort::recvArray);
    connect(generate, &Generate::sendArray, this, [=](QVector<int> & list){
        for(int i = 0; i < list.size(); ++i)
            ui->numWidget->addItem(QString::number(list[i]));
        bubble->start();
        quick->start();
    });
    connect(bubble, &BubbleSort::finish, this, [&](QVector<int> & list){
        for(int i = 0; i < list.size(); ++i)
            ui->bubbleWidget->addItem(QString::number(list[i]));
    });
    connect(quick, &QuickSort::finish, this, [&](QVector<int> & list){
        for(int i = 0; i < list.size(); ++i)
            ui->quickWidget->addItem(QString::number(list[i]));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
