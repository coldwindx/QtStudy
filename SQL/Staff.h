#ifndef STAFF_H
#define STAFF_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include "DBGlobal.h"
#include <QSqlQuery>

class Staff : public QSqlQueryModel
{
public:
    int id;
    QString name;
    int age;
    QString address;
    int salary;
    Staff() {}
    Staff(int id,QString name,int age,QString address,int salary)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->address = address;
        this->salary = salary;
    }
    // the index can be edited;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const
    {
        Qt::ItemFlags flags = QSqlQueryModel::flags(index);
        return  flags | Qt::ItemIsEditable;
    }

    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)
    {
        if(index.column() < 1 || index.column() > 4) return false;
        // get the id of this index
        QModelIndex primaryIndex = QSqlQueryModel::index(index.row(), 0);
        int id = this->data(primaryIndex).toInt();
        // clear this model
        this->clear();
        bool ok = false;
        if(index.column() == 1)
            ok = this->setName(value.toString(), id);
        return ok;
    }

    bool setName(QString name, int id)
    {
        qDebug() << "update!";
        QSqlQuery query(DBGlobal::getInstance()->db);
        query.prepare("update staff set name = ? where id = ?;");
        query.addBindValue(name);
        query.addBindValue(id);
        return query.exec();
    }

};

#endif // STAFF_H

