#include "Widget.h"
#include "ui_Widget.h"
#include<QTcpServer>
#include<QHostInfo>
#include<QList>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QTcpServer(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_computerBtn_clicked()
{
    // get host info
    QString hostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(hostName);
    QList<QHostAddress> addresses = info.addresses();
    ui->textEdit->append("HostName:" + hostName);
    for(auto & address : addresses)
    {
        ui->textEdit->append(address.toString());
    }
}

void Widget::on_listenBtn_clicked()
{
    // listen client
    if(server->listen(QHostAddress::Any, 6535) == false)
    {
        qDebug() << "listen fail!";
        return ;
    }
    connect(server, &QTcpServer::newConnection, [&](){
        // message
       socket = server->nextPendingConnection();
       // having new message
       connect(socket, &QTcpSocket::readyRead, [&](){
           char buf[1024] = {0};
           socket->read(buf, sizeof(buf));
           ui->textEdit->setText(buf);
       });
    });

}

void Widget::on_sendBtn_clicked()
{

}
