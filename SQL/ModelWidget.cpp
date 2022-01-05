#include "ModelWidget.h"
#include "ui_ModelWidget.h"
#include <QDebug>
#include "DBGlobal.h"
#include "Staff.h"

ModelWidget::ModelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelWidget)
{
    ui->setupUi(this);
    connect(ui->selectBtn, &QPushButton::clicked, this, &ModelWidget::select);
}

ModelWidget::~ModelWidget()
{
    delete ui;
}

void ModelWidget::select()
{
    Staff * model = new Staff();
    model->setQuery("select * from staff", DBGlobal::getInstance()->db);
    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Age"));
    model->setHeaderData(3, Qt::Horizontal, tr("Address"));
    model->setHeaderData(4, Qt::Horizontal, tr("Salary"));

    ui->tableView->setModel(model);
    ui->tableView->show();
}
