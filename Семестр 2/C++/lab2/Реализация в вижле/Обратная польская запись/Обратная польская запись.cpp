#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPriority(char c)
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

string infixToPostfix(string infix)
{
    stack<char> dop;
    string postfix = "";

    int l = infix.length();

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (c == ' ')
        {
            continue;
        }
        else if (isdigit(c) || isalpha(c) || c == '.')
        {
            postfix += c;
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
    }
    while (!dop.empty())
    {
        postfix += dop.top();
        dop.pop();
    }

    return postfix;
}

string infixToPostfix1(string infix)
{
    stack<char> dop;
    string postfix = "";

    int l = infix.length();

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (c == ' ')
        {
            continue;
        }
        else if (isdigit(c) || isalpha(c) || c == '.')
        {
            postfix += c;
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
                dop.pop();
            }
            dop.push(c);
            postfix += " ";
        }
    }
    while (!dop.empty())
    {
        postfix += " ";
        postfix += dop.top();
        dop.pop();
    }

    return postfix;
}

double result(string str)
{
    stack<double> st;
    string s = str;
    double operand1, operand2, result;

    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        char c = str[i];
        if (c == ' ')
        {
            continue;
        }
        if (isdigit(c))
        {
            double num = c - '0';
            i++;
            while (isdigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            if (str[i] == '.')
            {
                double fraction = 0.1;
                i++;
                while (isdigit(str[i])) {
                    num += fraction * (str[i] - '0');
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



int main()
{
    setlocale(LC_ALL, "ru");
    std::string infix;
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "Инфиксная запись: " << infix << '\n';
    cout << "Префиксная запись: " << postfix << '\n';
    string str = infixToPostfix1(infix);
    cout << "\n\n" << str << "\n\n";
    double resu = result(str);
    cout << "Результат " << resu;

    return 0;
}