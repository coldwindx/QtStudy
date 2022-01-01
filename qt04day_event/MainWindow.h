#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QVector>
#include"MoveButton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static QVector<MoveButton*> mVecBtns;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
//    virtual void mouseMoveEvent(QMouseEvent *event);
//    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
