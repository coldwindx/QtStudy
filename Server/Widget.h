#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_computerBtn_clicked();

    void on_listenBtn_clicked();

    void on_sendBtn_clicked();

private:
    Ui::Widget *ui;
    QTcpServer * server;
    QTcpSocket * socket;
};

#endif // WIDGET_H
