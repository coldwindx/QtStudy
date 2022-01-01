#include "MainWindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QDataStream>
#include<QSettings>
struct Student
{
    QString name;
    int id;
    bool sex;
    friend QDataStream& operator<<(QDataStream& stream, Student & student);
    friend QDataStream& operator>>(QDataStream& stream, Student & student);
    QString toString()
    {
        return "Name:" + name + " Id:" + QString::number(id) + " Sex:" + (sex ? "man" : "woman");
    }
};

QDataStream& operator<<(QDataStream& stream, Student & student)
{
    return stream << student.name << student.id << student.sex;
}

QDataStream& operator>>(QDataStream& stream, Student & student)
{
    return stream >> student.name >> student.id >> student.sex;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Setting volume from configuration
    ui->volumeSlider->setMaximum(100);
    QSettings settings("./config/config.ini", QSettings::IniFormat);
    int value = settings.value("Volume").toInt();
    ui->volumeSlider->setValue(value);
    ui->label->setText(QString::number(value));

    connect(ui->openBtn, &QPushButton::clicked, this, &MainWindow::onOpen);
    connect(ui->saveAsBtn, &QPushButton::clicked, this, &MainWindow::onSaveAs);
    connect(ui->saveAsBinBtn, &QPushButton::clicked, this, &MainWindow::onSaveAsBinary);
    connect(ui->readBinBtn, &QPushButton::clicked, this, &MainWindow::onReadBinary);
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::onVolumeChanged);
}
void MainWindow::onOpen()
{
    QString filename = QFileDialog::getOpenFileName(this, "Please open a file!");
    ui->lineEdit->setText(filename);
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return;
    QByteArray array;
    while(!file.atEnd())
        array += file.readLine();
    ui->textEdit->setText(array);
    file.close();
}
void MainWindow::onSaveAs()
{
    QString context = ui->textEdit->toPlainText();
    QString filename = QFileDialog::getSaveFileName(this, "Please select a file!", "C:/new.txt", "*txt");
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)) return ;
    file.write(context.toUtf8());
    file.close();
}
void MainWindow::onSaveAsBinary()
{
    QString filename = QFileDialog::getSaveFileName(this, "Please select a file!", "C:/new.bin", "*bin");
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QDataStream fin(&file);
    Student student { "Jack", 10010, true };
    fin << student;
    file.close();
}
void MainWindow::onReadBinary()
{
    QString filename = QFileDialog::getOpenFileName(this, "Please select a file!", "C:/new.bin", "*bin");
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QDataStream fout(&file);
    Student student;
    fout >> student;
    ui->textEdit->setText(student.toString());
    file.close();
}
void MainWindow::onVolumeChanged(int value)
{
    ui->label->setText(QString::number(value));
}
MainWindow::~MainWindow()
{
    // when window is closed, save volume to configuration
    QSettings settings("./config/config.ini", QSettings::IniFormat);
    settings.setValue("Volume", ui->volumeSlider->value());
    delete ui;
}
