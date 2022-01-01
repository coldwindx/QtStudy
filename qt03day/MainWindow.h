#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onOpen();
    void onSaveAs();
    void onSaveAsBinary();
    void onReadBinary();
    void onVolumeChanged(int value);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
