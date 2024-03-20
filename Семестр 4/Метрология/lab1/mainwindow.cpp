#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <math.h>
#include "QFileDialog"
#include "QTextStream"

#define ll long long
#define pb push_back

QString Pathstr;
QString allTextOperator = "";
QString allTextOperand = "";



using namespace std;

const string ops[] = {
    "var",
    "val",
    ": Byte",
    ": Short",
    ": Float",
    ": Double",
    ": Int",
    ": Long",
    ": Boolean",
    ": Char",
    ": String",
    ": Array",

    "if",
    "else",
   // "do",
    "while (",
    "for (",
    "when",

    "(",
    "{",
    "[",


    // arithmetic
    "+",
    "-",
    "*",
    "/",
    "//",
    "%",
    "=",
    "++",
    "--",
    "::",

    // logical
    "<",
    ">",
    "<=",
    "===",
    ">=",
    "==",
    "!=",
    "&&",
    "||",
    "->",

    // keywords
    "println",
    "print",
    "readLine",
    "readInt",
    "break",
    "continue",
    "class",
    "default",
    "return",
    "as",
    "try",
    "throw",

};

set<string> operators;
map<string, int> operator_counts, operand_counts;
map<string, int> funcNames;
map<string, int> names;

class operators_pair
{
public:
    string f, s;
    int multiplicity;

    operators_pair(string a, string b, int multiplicity)
    {
        this->f = a, this->s = b, this->multiplicity = multiplicity;
    }
};

// redundancy pairs are necessary to remove matches that match multiple
// patterns for example c++ matches both '++' and '+', multiplicity is
// required to make adjustments to the count variables
vector <operators_pair> redundancy_pairs;

void operator_kratnost()
{
    for (set<string>::iterator i = operators.begin(); i != operators.end(); i++)
    {
        for (set<string>::iterator j = operators.begin(); j != operators.end(); j++)
        {
            if ((*i) != (*j))
            {
                // find num occurences in strings
                int num_occur = 0, pos = 0;
                while ((pos = (*i).find(*j, pos)) != string::npos)
                {
                    num_occur++;
                    pos += (*j).length();
                }
                if (num_occur > 0)
                    redundancy_pairs.push_back(operators_pair(*j, *i, num_occur));
            }
        }
    }
}

void insert_operators()
{
    int size = *(&ops + 1) - ops;
    for (int i = 0; i < size; i++)
        operators.insert(ops[i]);
}

void insert_operators_after()
{
    for (vector<operators_pair>::iterator it = redundancy_pairs.begin(); it != redundancy_pairs.end(); it++)
    {
        // second exists
        if (operator_counts.find((*it).s) != operator_counts.end())
            operator_counts[(*it).f] = operator_counts[(*it).f] - operator_counts[(*it).s] * ((*it).multiplicity);
    }

    return;
}




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




void MainWindow::on_Calculate_button_clicked()
{
    ui->textBrowserOperand->clear();
    ui->textBrowserOperator->clear();

    operators.clear();
    operator_counts.clear();
    operand_counts.clear();
    funcNames.clear();
    redundancy_pairs.clear();
    names.clear();

    allTextOperand = "";
    allTextOperator = "";

    // fill the operators
    insert_operators();
    operator_kratnost();

    // we now create a regex for identifier
    regex identifier_def("[A-Za-z][A-Za-z0-9]*");

    regex regexDo("do\\s*\\{");

    regex symb("'.'");

    regex number_def("[-+]?\\d+(\\.\\d+)?(?:[eE][-+]?\\d+)?[fFL]?");
// "\\b([0-9]+)\\b"

     regex regexxx("\"(.*?)\"");

     regex pattern_p("(\\b(?:var|val)\\s+(\\w+)\\s*)");

     regex pattern("\\b(false|true|null)\\b");

     regex func("fun\\s+(\\w+)\\s*\\(");

  //   regex cccca("while\\s+\\((.*?)\\) {");

   //  regex usagePattern(R"(\b(\w+)\b)");

    smatch sm;
    smatch sm2;

    ifstream file(Pathstr.toStdString());
    ifstream file1(Pathstr.toStdString());
    string input;
    string input2;
    QString qqqqq = "";


    if (file.is_open())
    {
        while (getline(file, input))
        {
            qqqqq += input;
            qqqqq += '\n';
            // now check for operators in the line
            for (set<string>::iterator op = operators.begin(); op != operators.end(); op++)
            {
                auto gey = *op;
                int pos = 0;
                // for every operator scan the entire line for multiple matches
                while ((pos = input.find(*op, pos)) != string::npos)
                {

                    auto zxc = *op;
                    // found an operator
                    if (operator_counts.find(*op) == operator_counts.end())
                        operator_counts.insert({ *op, 1 });
                    else
                        operator_counts[*op]++;

                    pos += (*op).length();
                }
            }



            // now lets check for identifiers
            string::const_iterator pos(input.cbegin());


            while (regex_search(pos, input.cend(), sm, pattern_p))
            {
                // check if identifier is an operator
                if (operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }

                string oper = sm[0];
                string operand = oper.substr(4, oper.size() - 1);
                if (operand[operand.size()-1] == ' ')
                    operand = operand.substr(0, operand.size()-1);
                // if not add to map
                if (operand_counts.find(operand) != operand_counts.end())
                {
                    operand_counts[operand]++;
                    names[operand] = 0;
                }
                else
                {
                    operand_counts.insert(make_pair(operand, 1));
                    names.insert(make_pair(operand, 0));
                }

                pos += sm.position() + sm.length();
            }





            pos = input.cbegin();
            while (regex_search(pos, input.cend(), sm, func))
            {
                // check if identifier is an operator
                if (operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }

                string oper = sm[0];
                string operand = oper.substr(4, oper.size() - 1);
                // if not add to map
                if (operand_counts.find(operand) != operand_counts.end())
                {
                   //  operator_counts[operand]++;
                    operand_counts[operand]++;
                    funcNames[operand] = 0;
                }
                else
                {
                  //   operator_counts.insert(make_pair(operand, 1));
                    operand_counts.insert(make_pair(operand, 1));
                    funcNames.insert(make_pair(operand, 0));
                }
                pos += sm.position() + sm.length();
            }

            pos = input.cbegin();
            while (regex_search(pos, input.cend(), sm, regexDo))
            {
                // check if identifier is an operator
                if (operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }

                string operand = sm[0];
                // if not add to map
                if (operator_counts.find(operand) != operator_counts.end())
                    operator_counts[operand]++;
                else
                    operator_counts.insert(make_pair(operand, 1));

                pos += sm.position() + sm.length();
            }

            pos = input.cbegin();
            while (regex_search(pos, input.cend(), sm, symb))
            {
                // check if identifier is an operator
                if (operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }

                string operand = sm[0];
                // if not add to map
                if (operand_counts.find(operand) != operand_counts.end())
                    operand_counts[operand]++;
                else
                    operand_counts.insert(make_pair(operand, 1));

                pos += sm.position() + sm.length();
            }

            pos = input.cbegin();
            while (regex_search(pos, input.cend(), sm, pattern))
            {
                // check if identifier is an operator
                if (operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }

                string operand = sm[0];
                // if not add to map
                if (operand_counts.find(operand) != operand_counts.end())
                    operand_counts[operand]++;
                else
                    operand_counts.insert(make_pair(operand, 1));

                pos += sm.position() + sm.length();
            }
/*
            while (regex_search(pos, input.cend(), sm, identifier_def))
            {
                // check if identifier is an operator
                if (operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }

                string operand = sm[0];
                // if not add to map
                if (operand_counts.find(operand) != operand_counts.end())
                    operand_counts[operand]++;
                else
                    operand_counts.insert(make_pair(operand, 1));

                pos += sm.position() + sm.length();
            }
*/

            pos = input.cbegin();
            while(regex_search(pos, input.cend(), sm, regexxx))
            {
                if(operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }
                string oper = sm[0];
                string operand = oper;
                if (operand_counts.find(operand) != operand_counts.end())
                    operand_counts[operand]++;
                else
                    operand_counts.insert(make_pair(operand, 1));

                pos += sm.position() + sm.length();
            }



            // search for numbers
            pos = input.cbegin();
            while (regex_search(pos, input.cend(), sm, number_def))
            {
                // check if identifier is an operator
                if (operators.find(sm[0]) != operators.end())
                {
                    pos += sm.position() + sm.length();
                    continue;
                }

                string operand = sm[0];
                //cout << "Operand : " << operand << endl;
                // if not add to map
                if (operand_counts.find(operand) != operand_counts.end())
                    operand_counts[operand]++;
                else
                    operand_counts.insert(make_pair(operand, 1));

                pos += sm.position() + sm.length();
            }

        }

        insert_operators_after();
    }

    string str = qqqqq.toStdString();

    for (const auto& pair : names) {
        string s1 = pair.first;
        int s2 = pair.second;
   //     names[s1]--;
        //  std::cout << pair.first << ": " << pair.second << std::endl;
    }

    if (file1.is_open())
    {
        while (getline(file1, input2))
        {
            string::const_iterator pos(input2.cbegin());
            while (regex_search(pos, input2.cend(), sm2, identifier_def))
            {
                // check if identifier is an operator
                if (operators.find(sm2[0]) != operators.end())
                {
                    pos += sm2.position() + sm2.length();
                    continue;
                }

                string operand = sm2[0];
                if (names.find(operand) != names.end())
                {
                    names[operand]++;
                }
                // if not add to map
                /*
                if (operand_counts.find(operand) != operand_counts.end())
                    operand_counts[operand]++;
                else
                    operand_counts.insert(make_pair(operand, 1));
*/
                pos += sm2.position() + sm2.length();
            }
            pos = input2.cbegin();
            while (regex_search(pos, input2.cend(), sm2, identifier_def))
            {
                // check if identifier is an operator
                if (operators.find(sm2[0]) != operators.end())
                {
                    pos += sm2.position() + sm2.length();
                    continue;
                }

                string operand = sm2[0];
                operand = operand + '(';
                if (funcNames.find(operand) != funcNames.end())
                {
                    funcNames[operand]++;
                }
                // if not add to map
                /*
                if (operand_counts.find(operand) != operand_counts.end())
                    operand_counts[operand]++;
                else
                    operand_counts.insert(make_pair(operand, 1));
*/
                pos += sm2.position() + sm2.length();
            }
        }
    }
    ui->textBrowserOperator_2->setText(qqqqq);


    for (const auto& pair : names) {

        string s1 = pair.first;
        int s2 = pair.second;
        operand_counts[s1] = s2;
      //  std::cout << pair.first << ": " << pair.second << std::endl;
    }
    for (const auto& pair : funcNames) {

        string s1 = pair.first;
        int s2 = pair.second;
        operand_counts[s1] = s2;
        //  std::cout << pair.first << ": " << pair.second << std::endl;
    }


    std::cout << "j\tf1j\n\n";

    int iff = 0;
    int elsee = 0;

    bool t = false;
    bool tt = false;

    for (map<string, int>::iterator it = operator_counts.begin(); it != operator_counts.end(); it++)
    {
        string ab = (*it).first;
        if ((*it).first == "if" || (*it).first == "if (" || (*it).first == "if(")
        {
            iff = (*it).second;
            t = true;
        }
        else if ((*it).first == "else")
        {
            elsee = (*it).second;
            tt = true;
        }

    }

    int razn = iff - elsee;


    int whilee = 0;
    int doooo = 0;
    bool z = false;
    bool zz = false;
    for (map<string, int>::iterator it = operator_counts.begin(); it != operator_counts.end(); it++)
    {
        string ab = (*it).first;
        if ((*it).first == "do {")
        {
            doooo = (*it).second;
            z = true;
        }
        else if ((*it).first == "while (")
        {
            whilee = (*it).second;
            zz = true;
        }
    }
    int raz = whilee - doooo;

    for (map<string, int>::iterator it = operator_counts.begin(); it != operator_counts.end(); it++)
    {
        if ((*it).first == "do {" and z and zz)
        {

        }
        else if ((*it).first == "while (" and z and zz)
        {
            (*it).second = raz;
        }
    }
    bool uuu =false;

    allTextOperator += "Операторы\n";
    list<string> lst;
    int N1 = 0, n1 = 0, n2 = 0, N2 = 0;
    int j = 1;
    int foor = 0;


    for (map<string, int>::iterator it = operator_counts.begin(); it != operator_counts.end(); it++)
    {
        string zxc = (*it).first;
        if ((*it).second == 0)
            continue;

        if ((*it).first == "if" and t and tt)
        {
            (*it).second = razn;
            if(razn == 0)
                continue;
        }
        else if ((*it).first == "else" and t and tt)
        {
            (*it).second = 0;
            continue;
        }
        if ((*it).first != "//")
        {
        if ((*it).second)
            n1++;
        N1 += (*it).second;
        cout << (*it).first << "\t" << (*it).second << "\n";
        allTextOperator += QString::number(j);
        allTextOperator += ". ";
        if ((*it).first == "while (")
        {
            allTextOperator += QString::fromStdString("while");
          //  uuu = true;
        }
        else if ((*it).first == "do {" )
        {
            allTextOperator += QString::fromStdString("do .. while");
        }
        else if ((*it).first == "for (" )
        {
            allTextOperator += QString::fromStdString("for");
        }
        else
        {
         //   if (!uuu)
                allTextOperator += QString::fromStdString((*it).first);
        }
        allTextOperator += "\t";
        allTextOperator += QString::number((*it).second);
        allTextOperator += "\n";
        j++;
        }
    }
    if (t && tt)
    {
        allTextOperator += QString::number(j);
        allTextOperator += ". ";
        allTextOperator += "if else";
        allTextOperator += '\t';
        allTextOperator += QString::number(elsee);
        n1++;
        j++;
        N1 += elsee;
    }

    ui->label->setText("Словарь операторов: " + QString::number(n1) + '\n' + "Общее число операторов в программе: " + QString::number(N1));

    cout << "\ni\tf2i\n\n";
    allTextOperand = "Операнды\n";
    int i = 1;
    for (map<string, int>::iterator it = operand_counts.begin(); it != operand_counts.end(); it++)
    {

        if ((*it).second) n2++;
        N2 += (*it).second;
        cout << (*it).first << "\t" << (*it).second << "\n";
        allTextOperand += QString::number(i);
        allTextOperand += ". ";
        allTextOperand += QString::fromStdString((*it).first);
        allTextOperand += "\t";
        allTextOperand += QString::number((*it).second);
        allTextOperand += "\n";
        i++;

    }

    ui->label_2->setText("Словарь операндов: " + QString::number(n2) + '\n' + "Общее число операндов в программе: " + QString::number(N2));


    printf("\nn1:%d\tN1:%d\tn2:%d\tN2:%d\n", n1, N1, n2, N2);

    int size = N1 + N2;
    int vocab_size = n1 + n2;
    double volume = size * log2(vocab_size);

    // Difficulty = ( n1/2 ) x ( N2/n2 ) and level = 1/difficulty
    // double difficulty = (double(n1) / 2) * (double(N2) / double(n2));
    // double level = (1 / difficulty);

    // effort = volume x difficulty
    // double effort = volume * difficulty;
    QString data = "";
    // cout << "n = " << vocab_size << endl;
    data+="Длина словаря: ";
    data+=QString::number(vocab_size);
    data+="\n";
    cout << "Длина программы: " << size << endl;
    data+="Длина программы: ";
    data+=QString::number(size);
    data+="\n";
    cout << "V = " << volume << endl;
    data+="Объем программы: ";
    data+=QString::number(volume);
    data+="\n";

    ui->textBrowserOperator->setText(allTextOperator);
    ui->textBrowserOperand->setText(allTextOperand);
    ui->Metrics_label->setText(data);
}


void MainWindow::on_File_button_clicked()
{
    Pathstr = QFileDialog::getOpenFileName(0, "Открыть", "", "*.txt");
}

