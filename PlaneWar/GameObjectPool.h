#ifndef GAME_OBJECT_POOL_H
#define GAME_OBJECT_POOL_H
#include"GameDefine.h"
#include"include/Bullet.h"
#include"include/Enemy.h"

class GameObjectPool : public QObject
{
    GameObjectPool(QObject * parent = nullptr) {}
    static GameObjectPool * instance;
    // 子弹对象池
    QVector<Bullet*> bulletPool;
    // 敌机对象池
    QVector<Enemy*> enemyPool;
public:
    static GameObjectPool * getInstance();
    ~GameObjectPool();
    // 对象池初始化
    void init();
    // 获取子弹对象
    Bullet * createBullet();
    // 获取敌机对象
    Enemy * creaeteEnemy();
    // 回收子弹对象
    void recoverBullet(Bullet * bullet);
    // 回收敌机对象
    void recoverEnemy(Enemy * enemy);
    // 内存清除
    void clear();
};



#endif // GAME_OBJECT_POOL_H
