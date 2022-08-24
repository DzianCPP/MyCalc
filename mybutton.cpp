#include "mybutton.h"
#include <QFont>


myButton::myButton(const QString text_, QWidget *parent) : QToolButton(parent)
{
    setText(text_);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    QFont font = this->font();
    font.setPointSize(font.pointSize() + 4);
    this->setFont(font);
    this->setStyleSheet("background-color: rgb(127, 123, 130);"
                        "border-radius: 5px;"
                        "border-color: black;"
                        "color: white;");
}
