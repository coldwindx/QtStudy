#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QVector>

class Generate : public QThread
{
    Q_OBJECT
private:
    int num;
protected:
    void run() override;
public:
    explicit Generate(QObject * parent = nullptr);
    void recvNum(int num);
signals:
    void sendArray(QVector<int> & list);
};

class BubbleSort : public QThread
{
    Q_OBJECT
private:
    QVector<int> list;
protected:
    void run() override;
public:
    explicit BubbleSort(QObject * parent = nullptr) {}
    void recvArray(QVector<int> & list)
    {
        this->list = list;
    }
signals:
    void finish(QVector<int> & list);
};

class QuickSort : public QThread
{
    Q_OBJECT
private:
    QVector<int> list;
protected:
    void run() override;
    void quickSort(int l, int r);
    int partition(int l, int r);
public:
    explicit QuickSort(QObject * parent = nullptr) {}
    void recvArray(QVector<int> & list)
    {
        this->list = list;
    }
signals:
    void finish(QVector<int> & list);
};

#endif // RANDTHREAD_H
