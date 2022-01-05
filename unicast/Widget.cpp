#include "Widget.h"
#include "ui_Widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->sendBtn->setEnabled(false);

    socket = new QUdpSocket(this);

    connect(socket, &QUdpSocket::readyRead, [&](){
        char buf[1024] = {};
        socket->readDatagram(buf, sizeof buf);
        ui->textEdit->append(buf);
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sendBtn_clicked()
{
    QString ip = ui->ipEdit->text();
    QString port = ui->portEdit->text();
    QString text = ui->sendEdit->text();

    socket->writeDatagram(text.toUtf8(), QHostAddress(ip), port.toInt());
}

void Widget::on_bindBtn_clicked()
{
    QString port = ui->portEdit->text();
    if(!socket->bind(port.toInt()))
    {
        QMessageBox::information(this, "Information", "Bind failure!");
        return ;
    }
    ui->sendBtn->setEnabled(true);
    ui->bindBtn->setEnabled(false);
}
