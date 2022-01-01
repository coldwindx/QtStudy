#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include<QToolButton>
class MoveButton : public QToolButton
{
private:
    QPoint pressPos;
protected:
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void mousePressEvent(QMouseEvent *event);
        virtual void mouseReleaseEvent(QMouseEvent *event);
//        virtual void keyPressEvent(QKeyEvent *event);
//        virtual void keyReleaseEvent(QKeyEvent *event);
public:
    MoveButton(QWidget * parent = nullptr);
};

#endif // MOVEBUTTON_H
