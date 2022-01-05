#include "Widget.h"
#include "ui_Widget.h"
#include <QtXml>
#include<QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_wBtn_clicked()
{
    // Write xml
    QDomDocument doc;
    // Create a label
    QDomElement root = doc.createElement("root");
    doc.appendChild(root);
    // Add a child label
    QDomElement hero = doc.createElement("Hero");
    root.appendChild(hero);
    // Add a property
    hero.setAttribute("id", "10010");
    // Add content
    auto name = doc.createElement("Name");
    hero.appendChild(name);
    name.appendChild(doc.createTextNode("Iron man"));
    // save this xml
    QString filename = QFileDialog::getSaveFileName(this, "please select a file!", "C:/");
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
        return;
    QTextStream stream(&file);
    doc.save(stream, 4);

}

void Widget::on_lBtn_clicked()
{
    struct Hero
    {
        int id;
        QString name;
        QString desc;
    };
    // create a file
    QFile file("://xml/test.xml");
    if(!file.open(QIODevice::ReadOnly))
        return ;
    // Encode xml
    QVector<Hero> vec;
    QDomDocument doc;
    doc.setContent(&file);
    QDomElement root = doc.firstChildElement("root");
    QDomElement hero = root.firstChildElement("Hero");
    while(!hero.isNull())
    {
        Hero heroInfo;
        heroInfo.id = hero.attribute("id").toInt();
        heroInfo.name = hero.firstChildElement("Name").text();
        heroInfo.desc = hero.firstChildElement("Desc").text();

        vec.append(heroInfo);
        // read next
        hero = hero.nextSiblingElement("Hero");
    }
    // show
    QString contents;
    for(auto & hero : vec) contents += "id:" + QString::number(hero.id) + ", name:" + hero.name + ", desc:" + hero.desc;
    ui->textEdit->setText(contents);
}
