#ifndef MODELWIDGET_H
#define MODELWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>

namespace Ui {
class ModelWidget;
}

class ModelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModelWidget(QWidget *parent = nullptr);
    ~ModelWidget();
private slots:
    void select();
private:
    Ui::ModelWidget *ui;
};

#endif // MODELWIDGET_H
