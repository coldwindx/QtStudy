#include "Widget.h"
#include "ui_widget.h"
#include"GameDefine.h"
#include"GameController.h"

Widget * Widget::widget = nullptr;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(GameDefine::ScreenWidth, GameDefine::Screenheight);
    widget = this;
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    GameController * controller = GameController::getInstance();
    switch(event->key())
    {
        case Qt::Key_W:
        case Qt::Key_S:
        case Qt::Key_A:
        case Qt::Key_D:
            controller->pushOneKey(event->key());
            break;
        default: break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *e)
{
    GameController * controller = GameController::getInstance();
    GameController::getInstance()->removeOneKey(e->key());
}

Widget::~Widget()
{
    delete ui;
}
