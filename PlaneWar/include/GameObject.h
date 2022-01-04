#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include"GameDefine.h"

class GameObject : public QGraphicsPixmapItem
{
public:
    explicit GameObject(QObject *parent = nullptr)
    {
        static int num = 0;
        qDebug() << "The " << ++num << "th object is created!";
    }

    ~GameObject()
    {
        static int num = 0;
        qDebug() << "The " << ++num << "th object is released!";
    }

    virtual bool check()
    {
        int width = this->pixmap().width();
        int height = this->pixmap().height();
        // 边界检测
        if(this->x() < 0) return false;
        if(this->y() < 0) return false;
        if(GameDefine::ScreenWidth - width < this->x()) return false;
        if(GameDefine::Screenheight - height < this->y()) return false;
        return true;
    }
};

#endif // GAMEOBJECT_H
