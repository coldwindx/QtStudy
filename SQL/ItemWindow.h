#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QMainWindow>
#include "Staff.h"

namespace Ui {
class ItemWindow;
}

class ItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ItemWindow(QWidget *parent = nullptr);
    ~ItemWindow();
    void setStaff(Staff & staff);
private:
    Ui::ItemWindow *ui;
};

#endif // ITEMWINDOW_H
