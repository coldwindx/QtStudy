#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"GameDefine.h"
//#include"GameController.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    static Widget * widget;
private:
    Ui::Widget *ui;


    virtual void keyPressEvent(QKeyEvent *e);           // 按键监听
    virtual void keyReleaseEvent(QKeyEvent *e);
};

#endif // WIDGET_H
