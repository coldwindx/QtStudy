#ifndef DBGLOBAL_H
#define DBGLOBAL_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class DBGlobal
{
    DBGlobal()
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("company.db");
        if(!db.open())
        {
            qDebug() << "Open company.db error!" << db.lastError();
        }
    }
    static DBGlobal * instance;
public:
    QSqlDatabase db;
    static DBGlobal * getInstance()
    {
        if(instance == nullptr)
            instance = new DBGlobal();
        return instance;
    }
};


#endif // DBGLOBAL_H
