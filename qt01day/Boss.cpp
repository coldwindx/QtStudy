#include "Boss.h"
#include<QDebug>
Boss::Boss(QWidget *parent) : QWidget(parent)
{

}

void Boss::isDead(){
    qDebug() << "Boss is dead!";
}
