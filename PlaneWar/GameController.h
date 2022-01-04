#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
#include"GameDefine.h"
#include"Widget.h"
#include"include/Player.h"
#include"include/Enemy.h"
#include"include/Bullet.h"
#include"GameObjectPool.h"
// 单例类
class GameController : public QObject
{
    GameController()
    {
        // 加入对象树，窗口关闭时释放
        this->setParent(Widget::widget);
    }
    static GameController * instance;
protected:
    QGraphicsView * view;                               // 游戏视图
    // 游戏场景
    QGraphicsScene startScene;                          // 开始游戏场景
    QGraphicsScene gScene;                              // 游戏主场景
    // 游戏元素
    Player plane;                                        // 飞机
    QGraphicsPixmapItem startBackground;                // 开始游戏背景
    QGraphicsPixmapItem background1, background2;       // 背景
    // 容器
    QVector<int> keys;                                  // 按键表，用于支持多按键
    QVector<Bullet*> bullets;                           // 玩家子弹
    QVector<Enemy*> enemies;                            // 敌人

    // 定时器
    QTimer * bgTimer;                                   // 背景移动定时器
    QTimer * planeTimer;                                // 飞机移动定时器
    QTimer * shootTimer;                                // 飞机发射定时器
    QTimer * bulletTimer;                               // 子弹移动定时器
    QTimer * enemyCreateTimer;                          // 创建敌机定时器
    QTimer * enemyMoveTimer;                            // 敌机移动定时器

    QMediaPlayer bgMediaPlayer;                         // 背景音乐播放器
    // 开始场景
    void loadStartScene();
    // 游戏场景
    void loadGameScene();

public:
    // 获取单例
    static GameController * getInstance()
    {
        if(instance == nullptr)
            instance = new GameController();
        return instance;
    }
    // 游戏加载
    void GameInit();
    // 定时器开启
    void GameStart();
    // 定时器关闭
    void GameOver();

    ~GameController();

    // 背景移动逻辑
    void backgroundMove();
    // 飞机移动逻辑
    void planeMove();
    // 飞机射击逻辑
    void planeShoot();
    // 子弹移动逻辑
    void bulletMove();
    // 敌机生成逻辑
    void createEnemy();
    // 敌机移动逻辑
    void enemyMove();

    void pushOneKey(int key);

    void removeOneKey(int key);
};

#endif // GAMECONTROLLER_H
