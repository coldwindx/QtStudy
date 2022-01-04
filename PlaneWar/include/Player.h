#ifndef PLAYER_H
#define PLAYER_H
#include<QObject>
#include<QPoint>
#include<QPixmap>
#include"Plane.h"
#include"GameDefine.h"

class Player : public Plane
{
public:
    explicit Player(QObject *parent = nullptr) : Plane (parent)
    {
        setPixmap(QPixmap("://img/plane.png"));
        setPos(QPoint(100, 100));
    }

    void move(QPoint dir)
    {
        dir *= moveSpeed;
        this->moveBy(dir.x(), dir.y());
        // 边界检测
        static int width = this->pixmap().width();
        static int height = this->pixmap().height();
        if(this->x() < 0) this->setX(0);
        if(this->y() < 0) this->setY(0);
        if(GameDefine::ScreenWidth - width < this->x()) this->setX(GameDefine::ScreenWidth - width);
        if(GameDefine::Screenheight - height < this->y()) this->setY(GameDefine::Screenheight - height);
    }
};

#endif // PLAYER_H
