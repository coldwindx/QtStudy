#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connectBtn_clicked()
{
    // get Ip and port
    QString ip = ui->ipEdit->text();
    QString port = ui->portEdit->text();
    if(ip.isEmpty() || port.isEmpty())
        return ;
    // connect to host
    socket->connectToHost(ip, port.toInt());
    connect(socket, &QTcpSocket::connected, [&](){
        qDebug() << "Connecting is success!";
        ui->connectBtn->setEnabled(false);
    });
}

void Widget::on_sendBtn_clicked()
{
    QString msg = ui->textEdit->toPlainText();
    socket->write(msg.toUtf8());
}
