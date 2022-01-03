#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QDebug>

class Plane : public QGraphicsPixmapItem
{
private:
    QPoint pos;
    int moveSpeed = 5;
public:
    explicit Plane(QObject *parent = nullptr)
    {
        pos = QPoint(100, 100);
        setPixmap(QPixmap("://img/plane.png"));
        setPos(pos);
        qDebug() << "A plane is generated!";
    }

    void move(QPoint & dir)
    {
        dir *= moveSpeed;
        this->moveBy(dir.x(), dir.y());
        // 边界检测
        static int width = this->pixmap().width();
        static int height = this->pixmap().height();
        if(this->x() < 0) this->setX(0);
        if(this->y() < 0) this->setY(0);
        if(512 - width < this->x()) this->setX(512 - width);
        if(768 - height < this->y()) this->setY(768 - height);
    }
};

#endif // PLANE_H
