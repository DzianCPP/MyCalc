#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QToolButton>


class myButton : public QToolButton
{ Q_OBJECT
public:
    explicit myButton(const QString text_, QWidget* parent = nullptr);
};

#endif // MYBUTTON_H
