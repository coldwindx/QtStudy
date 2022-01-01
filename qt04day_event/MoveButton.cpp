#include "MoveButton.h"
#include<QMouseEvent>
#include"MainWindow.h"
#include<QDebug>
MoveButton::MoveButton(QWidget * parent) : QToolButton (parent)
{

}

void MoveButton::mousePressEvent(QMouseEvent *event)
{
    pressPos = event->pos();
}

void MoveButton::mouseMoveEvent(QMouseEvent *event)
{
    QPoint offset = event->pos() - pressPos;
    this->move(this->pos() + offset);
}
// swap two pictures
void MoveButton::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse is released!";
    for(int i = 0, size = MainWindow::mVecBtns.size(); i < size; ++i)
    {
        if(MainWindow::mVecBtns[i] == this)
            continue;
        if(MainWindow::mVecBtns[i]->geometry().contains(this->pos() + event->pos()))
        {

            QIcon icon = this->icon();
            this->setIcon(MainWindow::mVecBtns[i]->icon());
            MainWindow::mVecBtns[i]->setIcon(icon);
            break;
        }
    }
}
