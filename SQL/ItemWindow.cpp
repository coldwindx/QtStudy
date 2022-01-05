#include "ItemWindow.h"
#include "ui_ItemWindow.h"
#include <QDebug>

ItemWindow::ItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ItemWindow)
{
    ui->setupUi(this);
}

void ItemWindow::setStaff(Staff & staff)
{
    ui->idEdit->setText(QString::number(staff.id));
    ui->nameEdit->setText(staff.name);
    ui->ageEdit->setText(QString::number(staff.age));
    ui->addressEdit->setText(staff.address);
    ui->salaryEdit->setText(QString::number(staff.salary));
}
ItemWindow::~ItemWindow()
{
    qDebug() << "Release a ItemWindow!";
    delete ui;
}
