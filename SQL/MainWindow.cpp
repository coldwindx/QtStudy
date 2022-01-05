#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QueryWidget.h"
#include "ModelWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setTabShape(QTabWidget::Triangular);
    ui->tabWidget->addTab(new QueryWidget(this), "QSqlQuery");
    ui->tabWidget->addTab(new ModelWidget(this), "QSqlQueryModel");
}

MainWindow::~MainWindow()
{
    delete ui;
}

