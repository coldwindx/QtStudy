#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QTextEdit>
#include<QDockWidget>
#include<QDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QMenuBar * menuBar = new QMenuBar(this);
//    this->setMenuBar((menuBar));
//    QMenu * act = menuBar->addMenu("File");
//    act->addAction("open");
//    act->addAction("new");

//    QToolBar * toolBar = new QToolBar();
//    this->addToolBar(Qt::LeftToolBarArea, toolBar);
//    toolBar->addAction("edit");
//    toolBar->addSeparator();    // 添加分割线
//    toolBar->setAllowedAreas(Qt::LeftToolBarArea);  // 设置允许停靠位置

//    QStatusBar * statusBar = new QStatusBar();
//    statusBar->addWidget(new QLabel("FPS, 300"));
//    this->setStatusBar(statusBar);

//    this->setCentralWidget(new QTextEdit("Please input ..."));

//    QDockWidget * dock = new QDockWidget("text");
//    this->addDockWidget(Qt::LeftDockWidgetArea, dock);
    // 对话框
    connect(ui->nbtn, &QPushButton::clicked, [&](){
        QDialog dialog(this);
        dialog.resize(200, 200);
        dialog.exec();      // 开启消息循环
    });
    connect(ui->btn, &QPushButton::clicked, [&](){
        QDialog * dialog = new QDialog(this);
        dialog->resize(200, 200);
        dialog->show();
        dialog->setAttribute(Qt::WA_DeleteOnClose);     // 设置关闭时释放
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
