#include "Thread.h"
#include <QElapsedTimer>
#include <QDebug>

void Generate::run()
{
    QVector<int> list;
    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < num; ++i)
    {
        list.push_back(qrand() % num);
    }
    int milsec = timer.elapsed();
    qDebug() << "Generate " << num << "random numbers use time:" << milsec << " milsec";
    emit sendArray(list);
}

Generate::Generate(QObject *parent)
{

}

void Generate::recvNum(int num)
{
    this->num = num;
}

void BubbleSort::run()
{
    qDebug() << "Bubble thread address " << this->currentThread();
    QElapsedTimer timer;
    timer.start();
    int temp;
    for(int i = 0; i < list.size(); ++i)
        for(int j = list.size() - 1; j > i; --j)
            if(list[j - 1] > list[j])
            {
                temp = list[j - 1];
                list[j - 1] = list[j];
                list[j] = temp;
            }
    int milsec = timer.elapsed();
    qDebug() << "Bubble sort " << list.size() << "random numbers use time:" << milsec << " milsec";
    emit finish(this->list);
}

void QuickSort::run()
{
    qDebug() << "Quick thread address " << this->currentThread();
    QElapsedTimer timer;
    timer.start();
    quickSort(0, list.size() - 1);
    int milsec = timer.elapsed();
    qDebug() << "Quick sort " << list.size() << "random numbers use time:" << milsec << " milsec";
    emit finish(this->list);
}

void QuickSort::quickSort(int l, int r)
{
    if(r <= l) return ;
    int pivot = partition(l, r);
    quickSort(l, pivot - 1);
    quickSort(pivot + 1, r);
}

int QuickSort::partition(int l, int r)
{
    int pivot = list[l];
    while(l < r)
    {
        while(l < r && pivot <= list[r]) --r;
        list[l] = list[r];
        while(l < r && list[l] <= pivot) ++l;
        list[r] = list[l];
    }
    list[l] = pivot;
    return l;
}
