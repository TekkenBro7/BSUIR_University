#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <regex>
#include <QRegularExpression>
#include <QMessageBox>
#include <QMap>
#include <QPair>
#include <QFileDialog>
#include <QStack>


QString before;
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


void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit_2->clear();
    QString text = ui->plainTextEdit->toPlainText();
  //  QRegularExpression rx("\\b(unsigned|int|float|double|char|long)\\b\\s+\\w+.*;");
    QRegularExpression rx("((void|size_t|int|double|float|char|string|std::string|bool|long|short|long long|auto)\\s\\s*[\\*]*)\\s*(((\\,\\s)?([\\w\"]+)\\s*((=\\s*[\\w+\"\'\\.: &\\-()>\\*]*)?(\\{[\\w ,\"\' ]+\\})?)){0,});");
    QRegularExpressionMatchIterator i = rx.globalMatch(text);
    while (i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        QString matchedString = match.captured(0);
        ui->plainTextEdit_2->appendPlainText(matchedString);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->plainTextEdit_2->clear();
    QString str = ui->plainTextEdit->toPlainText();
    QRegularExpression re("(class)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*(\\{|;)");
//    QRegularExpression re("(class)""(\\s)""([\\w-]+)");
    QRegularExpressionMatchIterator i = re.globalMatch(str);
    int classCount = 0, structCount = 0, arrayCount = 0;
    while (i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        QString matchedString = match.captured(0);
        classCount++;
    }
    QRegularExpression rer("(struct)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*((\\{)|;)");
    QRegularExpressionMatchIterator ii = rer.globalMatch(str);
    while (ii.hasNext())
    {
        QRegularExpressionMatch match = ii.next();
        QString matchedString = match.captured(0);
        structCount++;
    }
  // QRegularExpression rerr("(int\\s+|double\\s+|float\\s+|long\\s+)[a-zA-Z_][a-zA-Z0-9_\\s+]*\[[\\s\\S]*?\\]");
    QRegularExpression rerr("\\s*\\w+\\s+(\\w+)\\s*((\\[[\\w]*\\])+)\\s*=?\\s*(\\{[^;]*\\})?\\s*;");
    QRegularExpressionMatchIterator iii = rerr.globalMatch(str);
    while (iii.hasNext())
    {
        QRegularExpressionMatch match = iii.next();
        QString matchedString = match.captured(0);
        arrayCount++;
    }
    ui->plainTextEdit_2->appendPlainText(QString::number(classCount));
    ui->plainTextEdit_2->appendPlainText(QString::number(structCount));
    ui->plainTextEdit_2->appendPlainText(QString::number(arrayCount));
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit_2->clear();
    QString str = ui->plainTextEdit->toPlainText();
//    QRegularExpression funcDeclarationRx("\\w+\\s+\\w+\\s*\\([^;]*\\);? ?");
    QRegularExpression funcDeclarationRx("(int|double|long|size_t|std::string|string|float|bool|char|char\\*|short|long long|void|auto)""(\\s*\\**\\s*)""([\\w-]+)""(( )*)""(\\()""(( )*(const )?(int|double|long|size_t|std::string|string|float|bool|char|char\\*|short|long long|void|auto)( )*\\**( )*([&\\w\\[\\]-])*[,]*)*""(\\))");
    QRegularExpressionMatchIterator it = funcDeclarationRx.globalMatch(str);
    while (it.hasNext())
    {
        QRegularExpressionMatch match = it.next();
        QString funcDeclaration = match.captured(0);
        ui->plainTextEdit_2->appendPlainText(funcDeclaration);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->plainTextEdit_2->clear();
    QString str = ui->plainTextEdit->toPlainText();
    QRegularExpression rx("while\\s*\\((true|false|[a-zA-Z_][a-zA-Z0-9_]*)\\)");
    QRegularExpressionMatchIterator i = rx.globalMatch(str);
    while (i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        QString matchedString = match.captured(0);
        ui->plainTextEdit_2->appendPlainText(matchedString);
    }
    QRegularExpression rxxx("\\bfor\\s*\\(\\s*(;;)\\s*\\)\\s*\\{");
    QRegularExpressionMatchIterator iii = rxxx.globalMatch(str);
    while (iii.hasNext())
    {
        QRegularExpressionMatch match = iii.next();
        QString matchedString = match.captured(0);
        ui->plainTextEdit_2->appendPlainText(matchedString);
    }
    QRegularExpression rxxxx("\\bif\\s*\\(\\s*(true|false)\\s*\\)\\s*\\{");
    QRegularExpressionMatchIterator iiii = rxxxx.globalMatch(str);
    while (iiii.hasNext())
    {
        QRegularExpressionMatch match = iiii.next();
        QString matchedString = match.captured(0);
        ui->plainTextEdit_2->appendPlainText(matchedString);
    }
    QRegularExpression rxxxxq("\\bconst\\s+bool\\s+(\\w+)\\s*=\\s*(true|false)\\s*;");
    QRegularExpressionMatchIterator iiiiq = rxxxxq.globalMatch(str);
    while (iiiiq.hasNext())
    {
        QRegularExpressionMatch match = iiiiq.next();
        QString matchedString = match.captured(0);
        ui->plainTextEdit_2->appendPlainText(matchedString);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->plainTextEdit_2->clear();
    QString str = ui->plainTextEdit->toPlainText();
    QRegularExpression re("\\b(unsigned|int|float|double|char|long)\\b\\s+\\w+.*;");
    QRegularExpressionMatchIterator it = re.globalMatch(str);
    while (it.hasNext())
    {
        QRegularExpressionMatch match = it.next();
        QString aaa = match.captured(0);
        int variablePos = match.capturedStart();
        int x = 0, y = 0;
        int c, s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == aaa[0] && str[i + 1] == aaa[1] && str[i + 2] == aaa[2] && str[i + 3] == aaa[3] && str[i + 4] == aaa[4] && str[i + 5] == aaa[5])
            {
                c = x;
                s = y;
                break;
            }
            else if (str[i] == '\n')
            {
                x++;
                y = 0;
            }
            else
            {
                y++;
            }
        }
        if (variablePos > str.indexOf("{") && variablePos < str.lastIndexOf("}"))
        {
            ui->plainTextEdit_2->appendPlainText(aaa);
            ui->plainTextEdit_2->appendPlainText(QString::number(c-1));
            ui->plainTextEdit_2->appendPlainText(QString::number(s));
        }
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    int before = -1;
    ui->plainTextEdit_2->clear();
    QString str = ui->plainTextEdit->toPlainText();
//    QRegularExpression re("(\\b\\w+\\b)\\s+(\\w+)\\s*\\(");
    QRegularExpression re("(int|double|long|size_t|std::string|string|float|bool|char|char\\*|short|long long|void|auto)""(\\s*\\**\\s*)""([\\w-]+)""(( )*)""(\\()""(( )*(const )?(int|double|long|size_t|std::string|string|float|bool|char|char\\*|short|long long|void|auto)( )*\\**( )*([&\\w\\[\\]-])*[,]*)*""(\\))");
    QRegularExpressionMatchIterator matchIterator = re.globalMatch(str);
    QMap<QString, QVector<int>> functionsMap;
    while (matchIterator.hasNext())
    { // проходимся по итератору совпадений
        QRegularExpressionMatch match = matchIterator.next();
        QString functionName = match.captured(2);
        int functionPosition = match.capturedStart(0);

        if (functionsMap.contains(functionName))
        {
            // если такая функция уже есть в словаре, добавляем координату перегрузки
            functionsMap[functionName].append(functionPosition);
        }
        else
        {
           // иначе создаем новую запись в словаре
            QVector<int> positions;
            positions.append(functionPosition);
            functionsMap.insert(functionName, positions);
        }
    }
    QString otvet = "";
    for (const QString& functionName : functionsMap.keys())
    {
        const QVector<int>& positions = functionsMap.value(functionName);
        otvet += functionName;;
        otvet += "Количество: ";
        otvet += QString::number(positions.count());
        otvet += " ";
        otvet += "Cтроки с функциями: ";
   //      ui->plainTextEdit_2->appendPlainText(functionName);
    //     ui->plainTextEdit_2->appendPlainText(QString::number(positions.count()));
         int x = 0, y = 0;
         int c, s;
         for (int i = 0; i < str.size(); i++)
         {
             if ((functionName.size() > 5 && str[i] == functionName[0] && str[i + 1] == functionName[1] && str[i + 2] == functionName[2]  && str[i+3] == functionName[3] && str[i+4] == functionName[4]) || (functionName.size() > 4 && str[i] == functionName[0] && str[i + 1] == functionName[1] && str[i + 2] == functionName[2] && str[i+3] == functionName[3]) || (functionName.size() > 3 && str[i] == functionName[0] && str[i + 1] == functionName[1] && str[i + 2] == functionName[2]) || (functionName.size() > 1 && str[i] == functionName[0] && str[i + 1] == functionName[1]) || (functionName.size() == 1 && str[i] == functionName[0]))
             {
                 c = x;
               //  s = y;
     //           ui->plainTextEdit_2->appendPlainText(QString::number(c));
      //          ui->plainTextEdit_2->appendPlainText(QString::number(s));
                 if (before != c)
                 {
                otvet += (QString::number(c));
               //otvet += " ";
               // otvet += (QString::number(s));
                otvet += "  ";
}
                before = c;
             }
             if (str[i] == '\n')
             {
                 x++;
                 y = 0;
             }
             else
             {
                 y++;
             }
         }
        QString f = functionName;
        otvet += '\n';
    }
    ui->plainTextEdit_2->setPlainText(otvet);

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->plainTextEdit_2->clear();
    QString str = ui->plainTextEdit->toPlainText();
//    QRegularExpression re("([a-zA-Z_]\\w*(?:\\[\\d+\\])?)\\s*([+\\-*/%])?=([^;]+);");
    QRegularExpression re("(([\\*]*\\s*)?\\w+(\\[\\w+\\])?\\s*?(([&|^]?=)|\\+=|-=|\\*=|/=|%=|&=|\\^=|\\|=|\\+\\+|--)(?!=))");
    QRegularExpressionMatchIterator matchIterator = re.globalMatch(str);
    QString otvet;
    while (matchIterator.hasNext())
    {
                QRegularExpressionMatch match = matchIterator.next();
                QString variableName = match.captured(0);
            //    ui->plainTextEdit_2->appendPlainText(variableName);
                int x = 0, y = 0;
                int c, s;
                for (int i = 0; i < str.size(); i++)
                {
                    if (str[i] == variableName[0] && str[i + 1] == variableName[1] && str[i + 2] == variableName[2])
                    {
                        c = x;
                        s = y;
                        QString qww = "";
                        qww += QString::number(c);
                        qww += " ";
                        qww += QString::number(s);
                        if(qww != before)
                        ui->plainTextEdit_2->appendPlainText(qww);
                   //    ui->plainTextEdit_2->appendPlainText(QString::number(s));
                   //    ui->plainTextEdit_2->appendPlainText(QString::number(c));
                        before = qww;

                       break;
                    }
                    else if (str[i] == '\n')
                    {
                        x++;
                        y = 0;
                    }
                    else
                    {
                        y++;
                    }
                }
    }

            QRegularExpression rer("(?:\\b)([a-zA-Z_]\\w*)(?:\[\\s*([0-9]+)\\s*\])(?:\\s*=\\s*(.*?))(?:\\s*)(?:,|;)");
            QRegularExpressionMatchIterator matchIteratorr = rer.globalMatch(str);
            QString otvett;
            while (matchIteratorr.hasNext())
            {
                        QRegularExpressionMatch match = matchIteratorr.next();
                        QString variableName = match.captured(0);
                    //    ui->plainTextEdit_2->appendPlainText(variableName);
                        int x = 0, y = 0;
                        int c, s;
                        for (int i = 0; i < str.size(); i++)
                        {

                            if (str[i] == variableName[0] && str[i + 1] == variableName[1] && str[i + 2] == variableName[2] && str[i + 3] == variableName[3] && str[i + 4] == variableName[4] && str[i + 5] == variableName[5])
                            {
                                c = x;
                                s = y;
                               ui->plainTextEdit_2->appendPlainText(QString::number(c));
                               ui->plainTextEdit_2->appendPlainText(QString::number(s));
                               break;
                            }
                            else if (str[i] == '\n')
                            {
                                x++;
                                y = 0;
                            }
                            else
                            {
                                y++;
                            }
                        }
            }
 //   QRegularExpression regex("([a-zA-Z_]\\w*(?:\\[\\d+\\])?)\\s*([+\\-*/%])?=([^;]+);");
       //    ui->plainTextEdit_2->setPlainText(otvet);
}


void MainWindow::on_pushButton_9_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, "Выбрать файл", "C:/Users", ".cpp or .h file (*.cpp *.h);");
     QFile file(str);
     file.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream stream(&file);
     QString ans;
     ans = file.readAll();
     ui->plainTextEdit->setPlainText(ans);
}



void MainWindow::on_pushButton_7_clicked()
{
    ui->plainTextEdit_2->clear();
    QString str = ui->plainTextEdit->toPlainText();
    int depth = 0;
        QStack<int> stack;
        int lineNumber = 0;

        int x;
        int y;

            for (int i = 0; i < str.length(); ++i)
            {
                if (str[i] == '{')
                {
                    stack.push(depth + 1);
                    ++depth;
                    x = lineNumber;
                } else if (str[i] == '}')
                {
                    if (!stack.isEmpty())
                    {
                       // qDebug() << "Branch depth:" << stack.top() << "Line:" << lineNumber;
                        y = lineNumber;
                        if (depth != 1)
                        ui->plainTextEdit_2->appendPlainText(QString::number(y - x + 1));
                        else
                        ui->plainTextEdit_2->appendPlainText(QString::number(lineNumber));
//                        ui->plainTextEdit_2->appendPlainText(QString::number(lineNumber));

                        stack.pop();
                    }
                    --depth;
                }
                if (str[i] == '\n')
                {
                    lineNumber++;
                }
            }
}

