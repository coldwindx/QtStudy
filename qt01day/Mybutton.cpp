#include "Mybutton.h"

MyButton::MyButton()
{

}

MyButton::MyButton(const QString& name, QWidget * parent)
{
    this->setParent(parent);
    this->setText(name);
    this->show();
}
