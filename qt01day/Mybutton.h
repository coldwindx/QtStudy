#ifndef MYBUTTON_H
#define MYBUTTON_H
#include<QPushButton>

class MyButton : public QPushButton
{
public:
    MyButton();
    MyButton(const QString& name, QWidget * parent);
};

#endif // MYBUTTON_H
