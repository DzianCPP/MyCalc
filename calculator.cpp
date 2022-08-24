#include "calculator.h"
#include <QGridLayout>
#include "mybutton.h"

calculator::calculator()
{

    this->setMinimumSize(350, 400);
    //LineEdits

    m_display_up = new QLineEdit;
    m_display_up->setReadOnly(true);
    m_display_up->setAlignment(Qt::AlignRight);
    m_display_up->setMaxLength(15);
    QFont font = m_display_up->font();
    font.setPointSize(font.pointSize() + 10);
    m_display_up->setFont(font);
    m_display_up->setText("MyCalc");

    m_display_down = new QLineEdit;
    m_display_down->setAlignment(Qt::AlignRight);
    m_display_down->setMaxLength(15);
    m_display_down->setFont(font);

    m_sign_chosen  = new QLabel;
    m_sign_chosen->setFont(font);
    m_sign_chosen->setAlignment(Qt::AlignRight);

    m_display_down->setText("");

    //Buttons

    for (int i = 0; i < 10; i++) {
        m_digitButton[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    myButton* pointButton = createButton(".", SLOT(pointClicked()));
    myButton* changeSignButton = createButton("±", SLOT(changeSignClicked()));

    myButton* backspaceButton = createButton("←", SLOT(backspaceClicked()));
    myButton* clearButton = createButton("C", SLOT(clear()));
    myButton* clearAllButton = createButton("CA", SLOT(clearAll()));


    myButton* divisionButton = createButton("/", SLOT(doubleOperatorClicked()));
    myButton* multiplicationButton = createButton("*", SLOT(doubleOperatorClicked()));
    myButton* minusButton = createButton("-", SLOT(doubleOperatorClicked()));
    myButton* plusButton = createButton("+", SLOT(doubleOperatorClicked()));

    myButton* squareButton = createButton("x2", SLOT(unaryOperatorClicked()));
    myButton* powerButton = createButton("^", SLOT(unaryOperatorClicked()));
    myButton* reciprocalButton = createButton("1/x", SLOT(unaryOperatorClicked()));
    myButton* squareRootButton = createButton("Rx", SLOT(unaryOperatorClicked()));

    myButton* equalButton = createButton("=", SLOT(equalClicked()));

    //Layout

    QGridLayout* main_layout = new QGridLayout();
    main_layout->setSizeConstraint(QLayout::SetDefaultConstraint);

    //adding widgets

        //adding line_edits

    main_layout->addWidget(m_display_up, 0, 0, 1, 6);
    main_layout->addWidget(m_sign_chosen, 1, 0, 1, 6);
    main_layout->addWidget(m_display_down, 2, 0, 1, 6);

        //adding buttons

    main_layout->addWidget(backspaceButton, 3, 0, 1, 2);
    main_layout->addWidget(clearButton, 3, 2, 1, 2);
    main_layout->addWidget(clearAllButton, 3, 4, 1, 2);
    //main_layout->addWidget(clearMemoryButton, 4, 0, 1, 1);
    main_layout->addWidget(m_digitButton[7], 4, 0, 1, 1);
    main_layout->addWidget(m_digitButton[8], 4, 1, 1, 1);
    main_layout->addWidget(m_digitButton[9], 4, 2, 1, 1);
    main_layout->addWidget(plusButton, 4, 3, 1, 1);
    main_layout->addWidget(squareRootButton, 4, 4, 1, 2);
    //main_layout->addWidget(readmemoryButton, 5, 0, 1, 1);
    main_layout->addWidget(m_digitButton[4], 5, 0, 1, 1);
    main_layout->addWidget(m_digitButton[5], 5, 1, 1, 1);
    main_layout->addWidget(m_digitButton[6], 5, 2, 1, 1);
    main_layout->addWidget(multiplicationButton, 5, 3, 1, 1);
    main_layout->addWidget(squareButton, 5, 4, 1, 2);
    //main_layout->addWidget(minMemoryButton, 6, 0, 1, 1);
    main_layout->addWidget(m_digitButton[1], 6, 0, 1, 1);
    main_layout->addWidget(m_digitButton[2], 6, 1, 1, 1);
    main_layout->addWidget(m_digitButton[3], 6, 2, 1, 1);
    main_layout->addWidget(minusButton, 6, 3, 1, 1);
    main_layout->addWidget(reciprocalButton, 6, 4, 1, 2);
    //main_layout->addWidget(addMemoryButton, 7, 0, 1, 1);
    main_layout->addWidget(m_digitButton[0], 7, 0, 1, 1);
    main_layout->addWidget(pointButton, 7, 1, 1, 1);
    main_layout->addWidget(changeSignButton, 7, 2, 1, 1);
    main_layout->addWidget(divisionButton, 7, 3, 1, 1);
    main_layout->addWidget(equalButton, 7, 4, 1, 2);

    //style

    this->setStyleSheet("background-color: rgb(229, 208, 204)");
    m_display_down->setStyleSheet("background-color: rgb(191, 172, 181);"
                                  "border-radius: 5px;"
                                  "border-color: black;"
                                  "color: rgb(7, 9, 15);");
    m_display_up->setStyleSheet("background-color: rgb(191, 172, 181);"
                                "border-radius: 5px;"
                                "border-color: black;"
                                "color: rgb(7, 9, 15);"
                                "font-weight: bold;");

    //connections

    connect(m_display_down, &QLineEdit::editingFinished, this, &calculator::equalClicked);

    //setting layout

    setLayout(main_layout);

    setWindowTitle("MyCalc");

}

void calculator::abortOperation()
{
    m_display_down->setText("####");
    m_display_up->setText("####");

}

bool calculator::calculate(const double operand, const QString operation)
{
    double current_result = m_display_up->text().toDouble();

    if (operation == "+")
    {
        current_result += operand;
    }

    else if (operation == "-")
    {
        current_result -= operand;
    }

    else if (operation == "/")
    {
        if (operand == 0.0)
        {
            return false;
        }

        current_result /= operand;
    }

    else if (operation == "*")
    {
        current_result *= operand;
    }
    m_display_up->setText(QString::number(current_result));
    return true;
}

    //slots

void calculator::digitClicked()
{
    myButton* clickedDigit = (myButton*) sender();
    int digitFromButton = clickedDigit->text().toInt();

    if (m_display_down->text() == "0")
    {
        m_display_down->clear();
        m_display_up->clear();
    }

    m_display_down->setText(m_display_down->text() + QString::number(digitFromButton));
}

void calculator::unaryOperatorClicked()
{
    myButton* clickedButton = (myButton*) sender();
    QString operation = clickedButton->text();

    double operand = m_display_down->text().toDouble();

    double result = 0.0;

    if (operation == "Rx")
    {
        if (operand < 0.0)
        {
            abortOperation();
            return;
        }

        else {
            result = std::sqrt(operand);
        }
    }

    else if (operation == "x2")
    {
        result = std::pow(operand, 2);
    }

    else if (operation == "1/x")
    {
        if (operand == 0.0)
        {
            abortOperation();
            return;
        }

        result = 1.0 / operand;
    }

    m_display_up->setText(QString::number(result));
}

void calculator::doubleOperatorClicked()
{
    double operand = m_display_down->text().toDouble();
    myButton* clickedButton = (myButton*) sender();
    QString operation = clickedButton->text();

    m_sign_chosen->setText(operation);

    if (m_display_down->text() == "")
    {
        return;
    }

    if (m_pending_operation.isEmpty())
    {
        m_display_up->setText(QString::number(operand));
    }

    else
    {
        if (calculate(operand, m_pending_operation))
        {
            m_pending_operation.clear();
        }

        else
        {
            abortOperation();
            return;
        }
    }

    m_pending_operation = operation;
    m_display_down->clear();
}

void calculator::equalClicked() {
    double operand = m_display_down->text().toDouble();
    if (!m_pending_operation.isEmpty())
    {
        if (!calculate(operand, m_pending_operation))
        {
            abortOperation();
            return;
        }
    }

    m_pending_operation.clear();
    if (m_display_up->text()[0].isDigit())
    {
        m_display_down->setText(m_display_up->text());
    }
    m_display_up->clear();
    m_sign_chosen->clear();

}

void calculator::pointClicked()
{
    if (!m_display_down->text().contains('.'))
    {
        m_display_down->setText(m_display_down->text() + '.');
    }
}

void calculator::changeSignClicked()
{
    double enteredValue = m_display_down->text().toDouble();
    QString enteredText = m_display_down->text();
    if (enteredValue > 0.0)
    {
        enteredText.prepend("-");
    }

    else if (enteredValue < 0.0)
    {
        enteredText.remove(0, 1);
    }

    m_display_down->setText(enteredText);
}

void calculator::backspaceClicked()
{
    QString textEntered = m_display_down->text();
    textEntered.chop(1);
    if (textEntered.isEmpty())
    {
        textEntered = "0";
    }

    m_display_down->setText(textEntered);
}

void calculator::clear()
{
    m_display_down->setText("");
}

void calculator::clearAll()
{
    m_display_down->setText("");
    m_display_up->setText("0");
}

myButton *calculator::createButton(QString button_text, const char *member)
{
    myButton* new_button = new myButton(button_text);
    connect(new_button, SIGNAL(clicked()), this, member);
    return new_button;
}
