#ifndef GAME_DEFINE_H
#define GAME_DEFINE_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QKeyEvent>
#include<QVector>
#include<QMediaPlayer>
#include<QToolButton>

// 单例类 游戏定义类
class GameDefine
{
    GameDefine(){}
public:
    // 定时器属性
    static const int PlayerShootTimeslot = 250;
    static const int PlayerMoveTimeslot = 10;
    static const int EnemyMoveTimeslot = 20;
    static const int EnemyShootTimeslot = 50;
    static const int BulletMoveTimeslot = 10;
    static const int BackgroundMoveTimeslot = 50;
    static const int CreateEnemyTimeslot = 1000;
    // 窗口属性
    static const int ScreenWidth = 512;
    static const int Screenheight = 768;

};

#endif // GAMEDEFINE_H
