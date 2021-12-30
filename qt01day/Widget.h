#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Boss.h"

class Widget : public QWidget
{
    Q_OBJECT    // 支持信号和槽
    Boss * boss;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void killBoss();
};

#endif // WIDGET_H
