#ifndef STRATEGY_H
#define STRATEGY_H
#include"CalEntry.h"
#include<QVector>
#include<QDebug>
#include<QString>
#include<QStack>

class Strategy
{
public:
    virtual void onClicked(QVector<CalEntry> & vc, QString & buf) = 0;
    virtual double exec(double x, double y) = 0;
};

static QMap<CalEnum, Strategy*> strategyCache;

class NumStrategy : public Strategy
{
    public:
    void onClicked(QVector<CalEntry> & vc, QString & buf){
        if(vc.isEmpty() || vc.back().op != CalEnum::Num)
        {
            vc.push_back(CalEntry(CalEnum::Num, buf));
            return;
        }
        vc.back().val += buf;
    }
    double exec(double x, double y)
    {
        return 0;
    }
};

class AddStrategy : public Strategy
{
    public:
    void onClicked(QVector<CalEntry> & vc, QString & buf){
        vc.push_back(CalEntry(CalEnum::Add, "+"));
    }
    double exec(double x, double y)
    {
        return x + y;
    }
};

class SubStrategy : public Strategy
{
    public:
    void onClicked(QVector<CalEntry> & vc, QString & buf){
        vc.push_back(CalEntry(CalEnum::Sub, "-"));
    }
    double exec(double x, double y)
    {
        return x - y;
    }
};

class MulStrategy : public Strategy
{
    public:
    void onClicked(QVector<CalEntry> & vc, QString & buf){
        vc.push_back(CalEntry(CalEnum::Mul, "*"));
    }
    double exec(double x, double y)
    {
        return x * y;
    }
};

class DivStrategy : public Strategy
{
    public:
    void onClicked(QVector<CalEntry> & vc, QString & buf){
        vc.push_back(CalEntry(CalEnum::Div, "/"));
    }
    double exec(double x, double y)
    {
        return x / y;
    }
};

class DotStrategy : public Strategy
{
    public:
    void onClicked(QVector<CalEntry> & vc, QString & buf){
        if(!vc.isEmpty() && !vc.back().val.contains("."))
               vc.back().val += ".";
    }
    double exec(double x, double y)
    {
        return 0;
    }
};

class EqualStrategy : public Strategy
{
    int isp(CalEnum cal)
    {
        switch(cal)
        {
        case CalEnum::Equal: return 0;
        case CalEnum::Add:
        case CalEnum::Sub: return 3;
        case CalEnum::Mul:
        case CalEnum::Div: return 5;
        case CalEnum::LLP: return 1;
        case CalEnum::RLP: return 8;
        }
    }
    int osp(CalEnum cal)
    {
        switch(cal)
        {
        case CalEnum::Equal: return 0;
        case CalEnum::Add:
        case CalEnum::Sub: return 2;
        case CalEnum::Mul:
        case CalEnum::Div: return 4;
        case CalEnum::LLP: return 8;
        case CalEnum::RLP: return 1;
        }
    }
public:
    void onClicked(QVector<CalEntry> & vc, QString & buf){
        vc.push_back(CalEntry(CalEnum::Equal, "="));
        QStack<CalEnum> opSck;
        QStack<double> numSck;
        opSck.push(CalEnum::Equal);
        for(int i = 0, size = vc.size(); i < size; ++i)
        {
            if(vc[i].op == CalEnum::Num)
            {
                numSck.push(vc[i].val.toDouble());
                continue;
            }
            int opIn = isp(opSck.back());
            int opOut = osp(vc[i].op);
            while(opOut < opIn)
            {
                Strategy * strategy = strategyCache[opSck.pop()];
                double y = numSck.pop();
                double x = numSck.pop();
                numSck.push(strategy->exec(x, y));
                opIn = isp(opSck.top());
            }
            if(opIn == opOut)
            {
                opSck.pop();
                continue;
            }
            if(opIn < opOut)
            {
                opSck.push(vc[i].op);
                continue;
            }
        }
        vc.clear();
        vc.push_back(CalEntry(CalEnum::Num, QString::number(numSck.back())));
    }
    double exec(double x, double y)
    {
        return 0;
    }
};

#endif // STRATEGY_H
