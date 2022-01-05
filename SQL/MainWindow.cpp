#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ItemWindow.h"
#include <QDebug>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect to a database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("company.db");
    // open this database
    if(!db.open())
    {
        qDebug() << "Fail to open this database!" << db.lastError();
    }
    // create a table
    query = QSqlQuery(db);
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectbtn_clicked()
{
    // to inquery
    if(!query.exec("select * from staff"))
        qDebug() << "Fail to exec 'select * from staff'!";
    // clear UI
    ui->listWidget->clear();
    // get staffs' information
    while(query.next())
    {
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
