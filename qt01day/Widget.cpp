#include "Widget.h"
#include<QPushButton>
#include"Mybutton.h"
#include<QDebug>
#include<QLabel>
#include<QSlider>
#include<QProgressBar>
#include<QTextEdit>
#include"Boss.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("hello,Qt!");
//    this->resize(400, 500);
//    this->setFixedSize(200, 200);       // 固定窗口大小

    QPushButton * btn = new QPushButton();  // 通过对象树自动释放
    btn->setParent(this);                   // 加入对象树
    btn->setText("this is a button!");
    btn->setFont(QFont("楷体", 20, 10, 1));
    btn->show();
    btn->setStyleSheet("QPushButton{ background-color: red; }\
                        QPushButton:hover{ background-color: green; }\
                        QPushButton:pressed{ background-color: rgb(170, 155, 221, 1); }");
    // 信号和槽
    connect(btn, &QPushButton::clicked, this, &QWidget::showMaximized);
    MyButton * mbtn = new MyButton("There is a mouse!", this);
    mbtn->move(200, 100);
    connect(mbtn, &QPushButton::pressed, []()->void{ qDebug() << "被打了！"; });
    connect(mbtn, &QPushButton::released, []()->void{ qDebug() << "反抗了！"; });
    // 常用控件
        /* 文本控件 */
    QLabel * label = new QLabel();
    label->setParent(this);
    label->move(0, 100);
    label->setText("How are you?");
        /* 滑动条控件 */
    QSlider * slider = new QSlider(this);
    slider->move(100, 100);
    slider->setValue(50);
        /* 进度条控件 */
    QProgressBar * proBar = new QProgressBar(this);
    proBar->move(0, 250);
    proBar->resize(this->size().width(), 20);
    proBar->setValue(50);
    proBar->setMaximum(99);
    connect(slider, &QSlider::valueChanged, [proBar](int v){
        proBar->setValue(v);
    });
        /* 文本编辑框 */
    QTextEdit * edit = new QTextEdit(this);
    edit->move(0, 280);
    edit->resize(500, 600);
    edit->setFontUnderline(1);
    edit->setFontPointSize(qreal(20.0f));
    edit->setText("This is a textedit!");
    connect(edit, &QTextEdit::textChanged, [edit, label](){
        label->setText(edit->toPlainText());
    });
    // 自定义信号和槽
    boss = new Boss(this);
    QPushButton * bbtn = new QPushButton("shoot", this);
    bbtn->move(300, 300);
    connect(bbtn, &QPushButton::clicked, this, &Widget::killBoss);
    connect(boss, &Boss::beKilled, boss, &Boss::isDead);
}
void Widget::killBoss(){
    qDebug() << "A boss will be killed!";
    emit boss->beKilled();
}
Widget::~Widget()
{

}
