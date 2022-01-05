#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QGraphicsScene>
#include "Staff.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_selectbtn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery query;

    QGraphicsScene * scene;

};

#endif // MAINWINDOW_H
