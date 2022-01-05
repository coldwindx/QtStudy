#ifndef STAFF_H
#define STAFF_H
#include<QString>
class Staff
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
};

#endif // STAFF_H
