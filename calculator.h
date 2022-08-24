#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QWidget>
#include <QLineEdit>
#include <QDeadlineTimer>
#include <QLabel>
#include "mybutton.h"

class calculator : public QWidget
{Q_OBJECT
public:
    calculator();
private:
    double m_sum_in_memory;
    QString m_ending_operation;

    QLineEdit* m_display_up;
    QLineEdit* m_display_down;
    QLabel* m_sign_chosen;

    QString m_pending_operation;

    myButton* m_digitButton[10];

    void abortOperation();
    bool calculate(const double left_operand, const QString operation);

private slots:
    void digitClicked();
    void unaryOperatorClicked();
    void doubleOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();

private:
    myButton* createButton(QString button_text, const char* member);

};

#endif // CALCULATOR_H
