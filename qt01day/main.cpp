#include "Widget.h"
#include <QApplication>
/*  Qt快捷键
运行 ctrl+r
构建 ctrl+b
转到定义 F2
返回 alt+左
前进 alt+右
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);     // 定义应用程序对象
    Widget w;                       // 定义空窗口对象
    w.show();                       // 显示窗口

    return a.exec();                // 消息循环
}
