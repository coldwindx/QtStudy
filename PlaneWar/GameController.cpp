#include"GameController.h"
#include"GameObjectPool.h"

GameController * GameController::instance = nullptr;
// 开始场景
void GameController::loadStartScene()
{
    startScene.setSceneRect(QRect(0, 0, GameDefine::ScreenWidth, GameDefine::Screenheight));

    startBackground.setPixmap(QPixmap("://img/start_background.jpg"));
    startScene.addItem(&startBackground);

    QToolButton * startBtn = new QToolButton();
    startBtn->setIconSize(QSize(161, 43));
    startBtn->setIcon(QIcon("://img/start.png"));
    startBtn->setAutoRaise(true);
    startBtn->setStyleSheet("QToolButton{border-style: flat;background: transparent;}");
    startBtn->move(GameDefine::ScreenWidth / 2 - 161 / 2, 400);
    startScene.addWidget(startBtn);
    // 设置当前场景为开始场景
    view->setScene(&startScene);

    connect(startBtn, &QToolButton::clicked, Widget::widget, [&](){
        // 场景切换
        view->setScene(&gScene);
        view->show();
        // 开启定时器
        this->GameStart();
    });
}

// 游戏场景
void GameController::loadGameScene()
{
    gScene.setSceneRect(QRect(0, 0, GameDefine::ScreenWidth, GameDefine::Screenheight));

    QPixmap bgImg("://img/background.jpg");
    // 背景图片1
    background1.setPixmap(bgImg);
    // 背景图片2
    background2.setPixmap(bgImg);
    background2.setY(-bgImg.size().height());
    // 元素添加至场景
    gScene.addItem(&background1);
    gScene.addItem(&background2);
    gScene.addItem(&plane);
    // 设置背景音乐
    bgMediaPlayer.setMedia(QUrl("qrc:/music/background.mp3"));
            bgMediaPlayer.play();
}
// 游戏加载
void GameController::GameInit()
{
    view = new QGraphicsView(Widget::widget);
    // 设置视图、场景属性
    view->setSceneRect(QRect(0, 0, GameDefine::ScreenWidth, GameDefine::Screenheight));

    loadStartScene();
    loadGameScene();
    // 显示视图
    view->show();
    // 背景移动定时器
    bgTimer = new QTimer(this);
    connect(bgTimer, &QTimer::timeout, this, &GameController::backgroundMove);
    // 飞机移动定时器
    planeTimer = new QTimer(this);
    connect(planeTimer, &QTimer::timeout, this, &GameController::planeMove);
    // 飞机发射定时器
    shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &GameController::planeShoot);
    // 子弹移动定时器
    bulletTimer = new QTimer(this);
    connect(bulletTimer, &QTimer::timeout, this, &GameController::bulletMove);
    // 创建敌机
    enemyCreateTimer = new QTimer(this);
    connect(enemyCreateTimer, &QTimer::timeout, this, &GameController::createEnemy);
    // 敌机移动
    enemyMoveTimer = new QTimer(this);
    connect(enemyMoveTimer, &QTimer::timeout, this, &GameController::enemyMove);
}

// 定时器开启
void GameController::GameStart()
{
    // 背景移动定时器
    bgTimer->start(GameDefine::BackgroundMoveTimeslot);
    // 飞机移动定时器
    planeTimer->start(GameDefine::PlayerMoveTimeslot);
    // 飞机发射定时器
    shootTimer->start(GameDefine::PlayerShootTimeslot);
    // 子弹移动定时器
    bulletTimer->start(GameDefine::BulletMoveTimeslot);
    // 创建敌机
    enemyCreateTimer->start(GameDefine::CreateEnemyTimeslot);
    // 敌机移动
    enemyMoveTimer->start(GameDefine::EnemyMoveTimeslot);
}

// 定时器关闭
void GameController::GameOver()
{

}

GameController::~GameController()
{
    // 已经加入对象树，不能手动释放，否则导致崩溃
//    delete instance;
}

// 背景移动逻辑
void GameController::backgroundMove()
{
    background1.moveBy(0, 2);
    background2.moveBy(0, 2);
    // 轮回滚动
    static int height = background1.pixmap().height();
    if(height <= background1.y())
        background1.setY(-height);
    if(height <= background2.y())
        background2.setY(-height);
}
// 飞机移动逻辑
void GameController::planeMove()
{
    QPoint dxy(0, 0);
    for(int & key : keys)
    {
        switch(key)
        {
            case Qt::Key_W:
                dxy.setY(-1); break;
            case Qt::Key_S:
                dxy.setY(1); break;
            case Qt::Key_A:
                dxy.setX(-1); break;
            case Qt::Key_D:
                dxy.setX(1); break;
            default: break;
        }
    }
    plane.move(dxy);
}
// 飞机射击逻辑
void GameController::planeShoot()
{
    // 子弹
    QPixmap img("://img/bullet.png");
    QPoint pos(plane.x() + plane.pixmap().width() / 2 - img.width() / 2, plane.y());
//    Bullet * bullet = new Bullet(pos, QPixmap("://img/bullet.png"), Bullet::BulletType::Player);
    Bullet * bullet = GameObjectPool::getInstance()->createBullet();
    bullet->init(pos, QPixmap("://img/bullet.png"), Bullet::BulletType::Player);
    // 显示
    this->gScene.addItem(bullet);
    // 加入容器
    this->bullets.push_back(bullet);
}
// 子弹移动逻辑
void GameController::bulletMove()
{
    GameObjectPool * pool = GameObjectPool::getInstance();
    for(int i = 0; i < bullets.size(); ++i)
    {
        bullets[i]->move(QPoint(0, -1));
        if(bullets[i]->check() == false)
        {
            // 从场景移除
            this->gScene.removeItem(bullets[i]);
            // 回收对象，防止内存泄露
            pool->recoverBullet(bullets[i]);
            // 从容器移除
            bullets.removeAt(i);
            continue;
        }
        // 碰撞检测
        for(int j = 0; j < enemies.size(); ++j)
        {
            if(!bullets[i]->collidesWithItem(enemies[j]))
                continue;
            // 从场景移除
            this->gScene.removeItem(bullets[i]);
            this->gScene.removeItem(enemies[j]);
            // 回收对象，防止内存泄露
            pool->recoverBullet(bullets[i]);
            pool->recoverEnemy(enemies[j]);
            // 从容器移除
            bullets.removeAt(i);
            enemies.removeAt(j);
            // 此时bullets[i]已经被释放，下一轮访问可能出错
            break;
        }
    }
}
// 敌机生成逻辑
void GameController::createEnemy()
{
    // 敌机
    QPixmap img("://img/enemy.png");
    int x = qrand() % (GameDefine::ScreenWidth - img.width());
//    Enemy * enemy = new Enemy(QPoint(x, -100), img);
    Enemy * enemy = GameObjectPool::getInstance()->creaeteEnemy();
    enemy->init(QPoint(x, -100), img);
    // 显示
    this->gScene.addItem(enemy);
    // 添加到容器
    enemies.push_back(enemy);
}
// 敌机移动逻辑
void GameController::enemyMove()
{
    GameObjectPool * pool = GameObjectPool::getInstance();
    for(int i = 0; i < enemies.size(); ++i)
    {
        enemies[i]->move(QPoint(0, 1));
        if(enemies[i]->check() == false)
        {
            // 从场景移除
            this->gScene.removeItem(enemies[i]);
            // 回收对象，防止内存泄露
            pool->recoverEnemy(enemies[i]);
            // 从容器移除
            enemies.removeAt(i);
        }
    }
}

void GameController::pushOneKey(int key)
{
    keys.push_back(key);
}

void GameController::removeOneKey(int key)
{
    keys.removeOne(key);
}
