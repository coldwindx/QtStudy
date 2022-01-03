#include "Widget.h"
#include "ui_widget.h"
#include<QToolButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(512, 768);
    view = new QGraphicsView(this);
    // 设置视图、场景属性
    view->setSceneRect(QRect(0, 0, 512, 768));
    startScene.setSceneRect(QRect(0, 0, 512, 768));
    gScene.setSceneRect(QRect(0, 0, 512, 768));
    // 设置元素
    QPixmap bgImg("://img/background.jpg");
        // 开始游戏按钮
    QToolButton * startBtn = new QToolButton();
    startBtn->setIconSize(QSize(161, 43));

    startBtn->setIcon(QIcon("://img/start.png"));
    startBtn->setAutoRaise(true);
    startBtn->setStyleSheet("QToolButton{border-style: flat;background: transparent;}");
    startBtn->move(512 / 2 - 161 / 2, 400);
    connect(startBtn, &QToolButton::clicked, this, [&](){
        view->setScene(&gScene);
        view->show();
    });
        // 开始游戏背景
    startBackground.setPixmap(QPixmap("://img/start_background.jpg"));
        // 背景图片1
    background1.setPixmap(bgImg);
        // 背景图片2
    background2.setPixmap(bgImg);
    background2.setY(-bgImg.size().height());
        // 飞机(见构造函数)
    // 元素添加至场景
    startScene.addItem(&startBackground);
    startScene.addWidget(startBtn);

    gScene.addItem(&background1);
    gScene.addItem(&background2);
    gScene.addItem(&plane);
    // 场景添加至视图
    view->setScene(&startScene);
    // 显示视图
    view->show();
    // 背景移动定时器
    bgTimer = new QTimer(this);
    bgTimer->start(10);
    connect(bgTimer, &QTimer::timeout, this, &Widget::bgMove);
    // 飞机移动定时器
    planeTimer = new QTimer(this);
    planeTimer->start(10);
    connect(planeTimer, &QTimer::timeout, this, &Widget::planeMove);
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_W:
        case Qt::Key_S:
        case Qt::Key_A:
        case Qt::Key_D:
            keys.push_back(event->key());
            break;
        default: break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
    keys.removeOne(e->key());
}
void Widget::bgMove()
{
    background1.moveBy(0, 2);
    background2.moveBy(0, 2);
    // 轮回滚动
    static int height = background1.pixmap().height();
    if(height <= background1.y())
        background1.setY(-height);
    if(height <= background2.y())
        background2.setY(-height);
}
void Widget::planeMove()
{
    QPoint dxy(0, 0);
    for(int & key : keys)
    {
        switch(key)
        {
            case Qt::Key_W:
                dxy.setY(-1); break;
            case Qt::Key_S:
                dxy.setY(1); break;
            case Qt::Key_A:
                dxy.setX(-1); break;
            case Qt::Key_D:
                dxy.setX(1); break;
            default: break;
        }
    }
    plane.move(dxy);
}

Widget::~Widget()
{
    delete ui;
}
