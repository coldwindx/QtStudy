#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QDebug>
#include"GameObject.h"

class Plane : public GameObject
{
protected:
    int moveSpeed = 5;
    int shootSpeed = 200;
public:
    explicit Plane(QObject *parent = nullptr) {}
    ~Plane(){}

    virtual void move(QPoint dir) = 0;

    int getShootSpeed()
    {
        return this->shootSpeed;
    }
};

#endif // PLANE_H
