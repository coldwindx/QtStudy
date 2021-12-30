#ifndef BOSS_H
#define BOSS_H

#include <QWidget>

class Boss : public QWidget
{
    Q_OBJECT
public:
    explicit Boss(QWidget *parent = nullptr);

signals:
    void beKilled();
public slots:
    void isDead();
};

#endif // BOSS_H
