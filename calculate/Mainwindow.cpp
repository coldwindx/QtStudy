#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect num
    connect(ui->nbtn0, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "0"); });
    connect(ui->nbtn1, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "1"); });
    connect(ui->nbtn2, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "2"); });
    connect(ui->nbtn3, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "3"); });
    connect(ui->nbtn4, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "4"); });
    connect(ui->nbtn5, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "5"); });
    connect(ui->nbtn6, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "6"); });
    connect(ui->nbtn7, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "7"); });
    connect(ui->nbtn8, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "8"); });
    connect(ui->nbtn9, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Num, "9"); });
    // connect calculation
    connect(ui->oBtnAdd, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Op, "+"); });
    connect(ui->oBtnSub, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Op, "-"); });
    connect(ui->oBtnMul, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Op, "*"); });
    connect(ui->oBtnDiv, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Op, "/"); });
    connect(ui->oBtnEqual, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Equal, "="); });
    // connect other operation
    connect(ui->oBtnBack, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Back, "back"); });
    connect(ui->oBtnClear, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Clear, "clear"); });
    connect(ui->oBtnDot, &QPushButton::clicked, [&](){ this->onClicked(BtnType::Dot, "."); });


}
double calculate(double x, double y, QString op){
    if(op == "+") return x + y;
    if(op == "-") return x - y;
    if(op == "*") return x * y;
    if(op == "/") return x / y;
    return 0.0;

}
void MainWindow::onClicked(BtnType btnType, QString v){
    static auto vaild = [&](QString & num)->void{
        if(!num.isEmpty() && !num.contains("."))
               num += v;
    };
    switch(btnType){
        case Num:
            op.isEmpty() ? numl += v : numr += v;
            break;
        case Op:
            op = v;
            break;
        case Dot:
            op.isEmpty() ? vaild(numl) : vaild(numr);
            break;
        case Equal:
            {
                double ans = calculate(numl.toDouble(), numr.toDouble(), op);
                ui->label->setText(QString::number(ans));
                return;
            }
        case Back:

            break;
        case Clear:
            numl = op = numr = "";
            break;
    }

    ui->label->setText(numl + op + numr);
}
MainWindow::~MainWindow()
{
    delete ui;
}
