#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // init
    strategyCache[CalEnum::Num] = new NumStrategy();
    strategyCache[CalEnum::Add] = new AddStrategy();
    strategyCache[CalEnum::Sub] = new SubStrategy();
    strategyCache[CalEnum::Mul] = new MulStrategy();
    strategyCache[CalEnum::Div] = new DivStrategy();
    strategyCache[CalEnum::Dot] = new DotStrategy();
    strategyCache[CalEnum::Equal] = new EqualStrategy();
    strategyCache[CalEnum::Back] = new BackStrategy();

    // connect num
    connect(ui->nbtn0, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "0"); });
    connect(ui->nbtn1, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "1"); });
    connect(ui->nbtn2, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "2"); });
    connect(ui->nbtn3, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "3"); });
    connect(ui->nbtn4, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "4"); });
    connect(ui->nbtn5, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "5"); });
    connect(ui->nbtn6, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "6"); });
    connect(ui->nbtn7, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "7"); });
    connect(ui->nbtn8, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "8"); });
    connect(ui->nbtn9, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Num, "9"); });
    // connect calculation
    connect(ui->oBtnAdd, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Add, "+"); });
    connect(ui->oBtnSub, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Sub, "-"); });
    connect(ui->oBtnMul, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Mul, "*"); });
    connect(ui->oBtnDiv, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Div, "/"); });
    connect(ui->oBtnEqual, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Equal, "="); });
    // connect other operation
    connect(ui->oBtnBack, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Back, "back"); });
    connect(ui->oBtnClear, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Clear, "clear"); });
    connect(ui->oBtnDot, &QPushButton::clicked, [&](){ this->onClicked(CalEnum::Dot, "."); });


}

void MainWindow::onClicked(CalEnum op, QString v){
    Strategy * strategy = strategyCache[op];
    strategy->onClicked(vc, v);
    QString str;
    for(auto & v : vc) str += v.val;
    ui->label->setText(str);
}
MainWindow::~MainWindow()
{
    for(auto & entry : strategyCache)
        delete entry;
    delete ui;
}
