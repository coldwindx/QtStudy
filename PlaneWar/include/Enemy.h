#ifndef ENEMY_H
#define ENEMY_H
#include<QObject>
#include<QPoint>
#include<QPixmap>
#include"Plane.h"

class Enemy : public Plane
{
public:
    explicit Enemy(QObject *parent = nullptr) {}
    Enemy(QPoint pos, const QPixmap & img)
    {
        this->moveSpeed = 3;
        this->shootSpeed = 1000;
        this->setPos(pos);
        this->setPixmap(img);
    }

    void init(QPoint pos, const QPixmap & img)
    {
        this->moveSpeed = 3;
        this->shootSpeed = 1000;
        this->setPos(pos);
        this->setPixmap(img);
    }

    void move(QPoint dir)
    {
        dir *= this->moveSpeed;
        this->moveBy(dir.x(), dir.y());
    }

    virtual bool check()
    {
        int height = this->pixmap().height();
        // 边界检测
        if(GameDefine::Screenheight + height < this->y())
            return false;
        return true;
    }
};

#endif // ENEMY_H
