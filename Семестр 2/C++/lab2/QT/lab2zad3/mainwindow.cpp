#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <stack.h>
#include <stt.h>
#include <stack>
using namespace  std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




bool isOperator(QString c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPriority(QString c)
{
    if (c == '+' || c == '-')
    {
        return 1;

    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

QString infixToPostfix(QString infix)
{
    Stack dop;
    QString postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        QString c = infix[i];
        if (c == ' ')
        {
            continue;
        }
        /*
        else if (isdigit(c) || isalpha(c))
        {
            postfix += c;
        }
        */
        else if (c == '(')
        {
            dop.push(c);
        }
        else if (c == ')')
        {
            while (!dop.empty() && dop.top() != '(')
            {
                postfix += dop.top();
                dop.pop();
            }
            dop.pop();
        }
        else if (isOperator(c))
        {
            while (!dop.empty() && getPriority(c) <= getPriority(dop.top()))
            {
                postfix += dop.top();
                dop.pop();
            }
            dop.push(c);
        }
        else if (c != '!' && c != '@' && c != '#' && c != '$' && c != '%' && c != '^' && c != '&' && c != '_' && c != '=' && c != '"' && c != ';' && c != '%' && c != '?' && c != ':' && c != '[' && c != ']' && c != '{' &&  c != '}' && c != '|' && c != ',')
        {
            postfix += c;
        }
    }
    while (!dop.empty())
    {
        postfix += dop.top();
        dop.pop();
    }

    return postfix;
}

QString infixToPostfix1(QString infix)
{
    Stack dop;
    //std::stack<char> dop;
    QString postfix = "";

    QString p = "";


    for (int i = 0; i < infix.length(); i++)
    {
        QString c = infix[i];

        if (c == ' ')
        {
            continue;
        }
        else if ((c != '/' && c!= '*' && c!= '+' && c!= '-' && c!= '(' && c!= ')' && c != '!' && c != '@' && c != '#' && c != '$' && c != '%' && c != '^' && c != '&' && c != '_' && c != '=' && c != '"' && c != ';' && c != '%' && c != '?' && c != ':' && c != '[' && c != ']' && c != '{' &&  c != '}' && c != '|' && c != ',') || c == '.')
        {
            postfix += c;
            p += c;
          //  postfix += " ";
        }
        else if (c == '(')
        {
            dop.push(c);
        }
        else if (c == ')')
        {
            while (!dop.empty() && dop.top() != '(')
            {
                postfix += dop.top();
                postfix += " ";

                p += dop.top();
                p += " ";
                dop.pop();
            }
            dop.pop();
        }
        else if (isOperator(c))
        {
            while (!dop.empty() && getPriority(c) <= getPriority(dop.top()))
            {
                postfix += " ";
                postfix += dop.top();

                p += " ";
                p += dop.top();

                dop.pop();
            }
            dop.push(c);
            postfix += " ";
        }
    }
    while (!dop.empty())
    {
        p += " ";
        p += dop.top();

        postfix += " ";
        postfix += dop.top();
        dop.pop();
    }

    return postfix;
}

double result(QString str)
{
  //  Stack1 st;
    std::stack<double> st;
    QString s = str;
    double operand1, operand2, result;

    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        QString c = str[i];
        /*
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        для целых
        */
        if (c == ' ')
        {
            continue;
        }
        // тут было isdigid(c)
        if (str[i].isDigit())
        {
            double num = c.toDouble();
            i++;
            while (str[i].isDigit())
            {
                num = num * 10 + (str[i].digitValue());
                i++;
            }
            if (str[i] == '.')
            {
                double fraction = 0.1;
                i++;
                while (str[i].isDigit())
                {
                    num += fraction * (str[i].digitValue());
                    fraction *= 0.1;
                    i++;
                }
            }
            i--;
            st.push(num);
        }
        else
        {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();
            if (c == '+')
            {
                result = operand1 + operand2;
            }
            else if (c == '-')
            {
                result = operand1 - operand2;
            }
            else if (c == '*')
            {
                result = operand1 * operand2;
            }
            else if (c == '/')
            {
                result = operand1 / operand2;
            }
            st.push(result);
        }
    }

    return st.top();
}


void MainWindow::on_pushButton_clicked()
{
    QString s, str = "a/(b-c)*(d+e)";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "8.6/(2.4-5.1)*(0.3+7.9)";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);

}


void MainWindow::on_pushButton_2_clicked()
{
    QString s, str = "(a+b)*(c-d)/e";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "(7.4+3.6)*(2.8-9.5)/0.9";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_3_clicked()
{
    QString s, str = "a-(b+c*d)/e";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "3.1-(5.4+0.2*9.6)/7.8";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_4_clicked()
{
    QString s, str = "a/b-((c+d)*e)";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "1.2/0.7-((9.3+6.5)*8.4)";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString s, str = "a*(b-c+d)/e";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "9.7*(8.2-3.6+4.1)/0.5";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_6_clicked()
{
    QString s, str = "(a+b)*(c-d)/e";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "(0.8+4.1)*(7.9-6.2)/3.5";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_7_clicked()
{
    QString s, str = "a*(b-c)/(d+e)";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "1.6*(4.9-5.7)/(0.8+2.3)";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_8_clicked()
{
    QString s, str = "a/(b*(c+d))-e";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "8.5/(0.3*(2.4+7.9))-1.6";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_9_clicked()
{
    QString s, str = "(a+(b/c-d))*e";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "(5.6+(7.4/8.9-3.1))*0.2";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_10_clicked()
{
    QString s, str = "a*(b+c)/(d-e)";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "0.4*(2.3+6.7)/(5.8-9.1)";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_12_clicked()
{
    QString s, str = "a-(b/c*(d+e))";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "5.6-(3.2/0.9*(1.7+4.8))";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_11_clicked()
{
    QString s, str = "(a-b)/(c+d)*e";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "(0.3-6.7)/(8.4+9.5)*1.2";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}

void MainWindow::on_pushButton_13_clicked()
{
    QString s, str = "a/(b+c-d*e)";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "7.6/(4.8+3.5-9.1*0.2)";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_14_clicked()
{
    QString s, str = "a*(b-c)/(d+e)";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "0.5*(6.1-8.9)/(2.4+7.3)";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_15_clicked()
{
    QString s, str = "(a+b*c)/(d-e)";
    s = infixToPostfix(str);
    ui->label_6->setText(s);

    str = "(9.1+0.6*2.4)/(3.7-8.5)";
    s = infixToPostfix1(str);

    double res = result(s);
    s = QString::number(res);

    ui->label_8->setText(s);
}


void MainWindow::on_pushButton_16_clicked()
{
    QString s, str = ui->lineEdit_6->text();
    s = infixToPostfix(str);
    ui->label_6->setText(s);
    s = infixToPostfix1(str);
    for(int i = 0; i < str.size(); i++)
    {
        /*
        if (str[i] >= '0' && str[i] <= '9')
        {
            continue;
        }
        else
        {
            ui->label_8->setText("Не может быть вычислено");
            return;
        }
        */
    }
    double res = result(s);
    s = QString::number(res);
    ui->label_8->setText(s);
}

