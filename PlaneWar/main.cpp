
#include <QApplication>
#include"GameController.h"
//#include"GameObjectPool.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    // 游戏加载
//    GameObjectPool::getInstance()->init();
    GameController::getInstance()->GameInit();


    return a.exec();
}
