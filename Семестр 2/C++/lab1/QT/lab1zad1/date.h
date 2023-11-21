#ifndef DATE_H
#define DATE_H
#include <QString>

class Date
{
    //Q_OBJECT
private:
    QString day;

public:
    Date();
    void SetDate(QString day);
    QString getDate();
    QString NextDay(QString day);
    QString PreviosDay(QString day);
    int isLeap(QString day);
    int WeekNumber(QString day);
    int Duration(QString day, QString day2);
    int Duration1(QString day, QString day2);
    int DaysTillYourBithday(int d, int m, QString w);
    int Duration2(QString day, QString day2);
};

#endif // DATE_H
