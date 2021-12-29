#include "Widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("hello,Qt!");
    this->resize(400, 500);
//    this->setFixedSize(200, 200);       // 固定窗口大小



    QPushButton * btn = new QPushButton();  // 通过对象树自动释放
//    btn->resize(20, 40);
    btn->setParent(this);                   // 加入对象树
    btn->setText("this is a button!");
    btn->setFont(QFont("楷体", 20, 10, 1));
    btn->show();
    btn->setStyleSheet("QPushButton{ background-color: red; }\
                        QPushButton:hover{ background-color: green; }\
                        QPushButton:pressed{ background-color: rgb(170, 155, 221, 1); }");

}

Widget::~Widget()
{

}
