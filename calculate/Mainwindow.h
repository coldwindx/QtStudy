#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
enum BtnType{
    Num, Op, Dot, Equal, Clear, Back
};
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString numl, op, numr;
public slots:
    void onClicked(BtnType btnType, QString btn);
};

#endif // MAINWINDOW_H
