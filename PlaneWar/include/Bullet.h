#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include<QMediaPlayer>
#include<QDebug>
#include"GameObject.h"
class Bullet : public GameObject
{
public:
    enum BulletType
    {
        Player, Enemy
    };
private:
    BulletType bulletType;
    int speed = 5;
    QMediaPlayer mediaPlayer;
public:
    explicit Bullet(QObject *parent = nullptr) {}
    Bullet(QPoint & pos, const QPixmap & img, BulletType type)
    {
        this->setPos(pos);
        this->setPixmap(img);
        this->bulletType = type;
        // 播放音效
        if(bulletType == Player)
            mediaPlayer.setMedia(QUrl("qrc:/music/bullet.mp3"));
        mediaPlayer.play();
    }

    ~Bullet()
    {
        qDebug() << "This bullet is released!";
    }

    void init(QPoint & pos, const QPixmap & img, BulletType type)
    {
        this->setPos(pos);
        this->setPixmap(img);
        this->bulletType = type;
        // 播放音效
        if(bulletType == Player)
            mediaPlayer.setMedia(QUrl("qrc:/music/bullet.mp3"));
        mediaPlayer.play();
    }

    void move(QPoint dir)
    {
        dir *= speed;
        this->moveBy(dir.x(), dir.y());
    }
};

#endif // BULLET_H
