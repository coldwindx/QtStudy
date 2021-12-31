#ifndef CALENTRY_H
#define CALENTRY_H
#include<QString>
#include<QMap>
enum CalEnum{
    Num, Dot,
    Equal, Clear, Back,
    Add, Sub, Mul, Div,
    LLP, RLP,
};

struct CalEntry
{
    CalEnum op;
    QString val;
    CalEntry(){}
    CalEntry(CalEnum op, QString  val) : op(op), val(val) {}
};

#endif // CALENTRY_H
