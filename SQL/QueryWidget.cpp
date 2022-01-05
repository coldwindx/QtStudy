#include "QueryWidget.h"
#include "ui_QueryWidget.h"
#include "ItemWindow.h"
#include <QDebug>
#include <QListWidgetItem>
#include "DBGlobal.h"
#include <QPushButton>

QueryWidget::QueryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryWidget)
{
    ui->setupUi(this);
    connect(ui->selectbtn, &QPushButton::clicked, this, &QueryWidget::select);
    // create a table
    query = QSqlQuery(DBGlobal::getInstance()->db);
#if false
    if(!query.exec("create table staff(id integer primary key autoincrement,name varchar(20),age int,address varchar(50),salary int);"))
    {
        qDebug() << "Fail to create table staff!" << db.lastError();
    }
#endif
    // insert a record
//    if(!query.exec("insert into staff (name, age, address, salary) values ('Jack', 25, 'Beijing', 12000);"))
//    {
//        qDebug() << "Fail to insert a record to table staff!" << db.lastError();
//    }
}

QueryWidget::~QueryWidget()
{
    delete ui;
}

void QueryWidget::select()
{
    // to inquery
    if(!query.exec("select * from staff"))
        qDebug() << "Fail to exec 'select * from staff'!";
    // clear UI
    ui->listWidget->clear();
    // get staffs' information
    while(query.next())
    {
        qDebug() << "A staff";
        Staff staff;
        staff.id = query.value("id").toInt();
        staff.name = query.value("name").toString();
        staff.age = query.value("age").toInt();
        staff.address = query.value("address").toString();
        staff.salary = query.value("salary").toInt();
        // update UI
        ItemWindow * staffItem = new ItemWindow();
        QListWidgetItem * item = new QListWidgetItem();
        item->setSizeHint(staffItem->size());
        staffItem->setStaff(staff);

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, staffItem);
    }
}
