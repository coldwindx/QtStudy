#include"GameObjectPool.h"

GameObjectPool * GameObjectPool::instance = nullptr;

GameObjectPool * GameObjectPool::getInstance()
{
    if(instance == nullptr)
        instance = new GameObjectPool();
    return instance;
}
GameObjectPool::~GameObjectPool()
{
    clear();
}
// 对象池初始化
void GameObjectPool::init()
{
    // 预先缓存对象
    for(int i = 0; i < 20; ++i)
    {
        bulletPool.append(new Bullet());
        enemyPool.append(new Enemy());
    }

}
// 获取子弹对象
Bullet * GameObjectPool::createBullet()
{
    Bullet * bullet = bulletPool.back();
    bulletPool.pop_back();
    return bullet;
}
// 获取敌机对象
Enemy * GameObjectPool::creaeteEnemy()
{
    Enemy * enemy = enemyPool.back();
    enemyPool.pop_back();
    return enemy;
}
// 回收子弹对象
void GameObjectPool::recoverBullet(Bullet * bullet)
{
    bulletPool.push_back(bullet);
}
// 回收敌机对象
void GameObjectPool::recoverEnemy(Enemy * enemy)
{
    enemyPool.push_back(enemy);
}
// 内存清除
void GameObjectPool::clear()
{
    for(auto & bullet : bulletPool) delete bullet;
    for(auto & enemy : enemyPool) delete enemy;
}
