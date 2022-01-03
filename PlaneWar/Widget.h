#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QKeyEvent>
#include<QVector>
#include"Plane.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QGraphicsView * view;                               // 游戏视图
    // 游戏场景
    QGraphicsScene startScene;                          // 开始游戏场景
    QGraphicsScene gScene;                              // 游戏主场景

    // 游戏元素
    Plane plane;                                        // 飞机
    QGraphicsPixmapItem startBackground;                // 开始游戏背景
    QGraphicsPixmapItem background1, background2;       // 背景

    QVector<int> keys;                                  // 按键表，用于支持多按键

    QTimer * bgTimer;                                   // 背景移动定时器
    QTimer * planeTimer;                                // 飞机移动定时器

    virtual void keyPressEvent(QKeyEvent *e);           // 按键监听
    virtual void keyReleaseEvent(QKeyEvent *e);

    void bgMove();          // 背景移动逻辑
    void planeMove();       // 飞机移动逻辑
};

#endif // WIDGET_H
