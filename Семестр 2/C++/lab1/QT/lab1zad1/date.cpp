#include "date.h"
#include <cmath>
#include <QDateTime>
#include <QDate>
#include <mainwindow.h>

Date::Date()
{

}

void Date::SetDate(QString day)
{
    this->day = day;
}

QString Date::getDate()
{
    return day;
}


int Date::WeekNumber(QString day)
{
    int days=day[0].digitValue()*10+day[1].digitValue();
    int month=day[3].digitValue()*10+day[4].digitValue();
    int year=day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();

    int year1 = year;
    QDate date;

       year1 = 4;
    date.setDate(year1,month,days);
   int a = date.weekNumber();
    return a;
}


QString Date::NextDay(QString day)
{
    int days=day[0].digitValue()*10+day[1].digitValue();
    int month=day[3].digitValue()*10+day[4].digitValue();
    int year=day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();
    if (QDate::isValid(year, month, days))
    {
        bool err = false;
        if (month < 1 || month > 12 || days < 1)
        {
            err = true;
        }
        if (month == 2)
        {
            if (days > 28)
            {
                err = true;
            }
            if (days == 28)
            {
                days = 1;
                month = 3;
            }
            else
                ++days;
        }
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            if (days > 30)
            {
                err = true;
            }
            if (days == 30)
            {
                days = 1;
                ++month;
            }
            else
                ++days;
        }
        else
        {
            if (days > 31)
            {
                err = true;
            }
            if (days == 31)
            {
                days = 1;
                ++month;
                if (month == 13)
                {
                    month = 1;
                    year++;
                }
            }
            else
                ++days;
        }
        if (month == 2 && days == 30 && err == true)
        {
            month = 3;
            days = 1;
            err = false;
        }
        if (err == false)
        {

        }
        else
        {
            return 0;
        }
    QString answ;
    QString daynum = QString::number(days);
    if (daynum.length() == 1)
    {
        daynum = "0" + daynum;
    }
    QString monthnum = QString::number(month);
    if (monthnum.length() == 1)
    {
        monthnum = "0" + monthnum;
    }
    QString yearnum = QString::number(year);
    while (yearnum.length() < 4)
    {
       yearnum = "0" + yearnum;
    }
    answ = daynum + "." + monthnum + "." + yearnum;
    return answ;
    }
    else
    {
        return 0;
    }
}


QString Date::PreviosDay(QString day)
{

    int days=day[0].digitValue()*10+day[1].digitValue();
    int month=day[3].digitValue()*10+day[4].digitValue();
    int year=day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();

    if (QDate::isValid(year, month, days))
    {
        bool err = false;
        if (month < 1 || month > 12 || days < 1)
        {
            err = true;
        }
        if (month == 2)
        {
            if (days > 28)
            {
                err = true;
            }
            if (days == 1)
            {
                days = 31;
                --month;
            }
            else
            {
                --days;
            }
        }
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            if (days > 30)
            {
                err = true;
            }
            if (days == 1)
            {
                days = 31;
                --month;
            }
            else
            {
                --days;
            }
        }
        else
        {
            if (days > 31)
            {
                err = true;
            }
            if (days == 1)
            {
                if(month == 1)
                {
                    days = 31;
                    month = 12;
                    --year;
                }
                else if (month == 3)
                {
                    days = 28;
                    --month;
                }
                else if(month == 8)
                {
                    days = 31;
                    --month;
                }
                else
                {
                    days = 30;
                    --month;
                }
            }
            else
            {
                --days;
            }
        }
        if (days == 28 && month == 2 && err == 1)
        {
            days = 28;
            month = 2;
            err = 0;
        }
        if (err == 0)
        {

        }
        else
        {
        return 0;
        }
        QString answ;
        QString da=QString::number(days);
        if (da.length() == 1)
        {
            da="0"+da;
        }
        QString mou = QString::number(month);
        if (mou.length() == 1)
        {
            mou="0" + mou;
        }
        QString yea=QString::number(year);
        while (yea.length() < 4)
        {
           yea = "0" + yea;
        }
        answ=da+"."+mou+"."+yea;
        return answ;
    }
    else
    {
        return 0;
    }
}

int Date::isLeap(QString day)
{
    int days=day[0].digitValue()*10+day[1].digitValue();
    int mounth=day[3].digitValue()*10+day[4].digitValue();
    int year=day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();
    if (QDate::isValid(year, mounth, days))
    {
        int d = QDate::isLeapYear(year);
        return d;
    }
    else
    {
        return -1;
    }
}


int Date::DaysTillYourBithday(int d, int m, QString w)
{
    tm first{}, second{};
    int year2 = w[6].digitValue()*1000+w[7].digitValue()*100+w[8].digitValue()*10+w[9].digitValue();
    int days2 = w[0].digitValue()*10+w[1].digitValue();
    int mounth2 = w[3].digitValue()*10+w[4].digitValue();
    int year1 = year2;
    int first1 = year1*365+d+m*30;
    int end1 = year2*365 + days2 + mounth2 * 30;
    first.tm_mday = days2;
    first.tm_mon = mounth2;
    first.tm_year = year2;
    first.tm_mon--;
    first.tm_year -= 1900;
    int dd = d;
    int mm = m;
    int yyy = year2;
    second.tm_mday = dd;
    second.tm_mon = mm;
    second.tm_year = yyy;
    second.tm_mon--;
    second.tm_year -= 1900;
    int difference = difftime(mktime(&first), mktime(&second));
                    if (difference < 0)
                    {
                        difference *= -1;
                        std::swap(first, second);
                    }
           return fabs(365 - (difference / (60 * 60 * 24)));
    //return abs(end - first);
}


int Date::Duration2(QString day, QString day2)
{
    int year = day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();
    int days = day[0].digitValue()*10+day[1].digitValue();
    int mounth = day[3].digitValue()*10+day[4].digitValue();
    int year2 = day2[6].digitValue()*1000+day2[7].digitValue()*100+day2[8].digitValue()*10+day2[9].digitValue();
    int days2 = day2[0].digitValue()*10+day2[1].digitValue();
    int mounth2 = day2[3].digitValue()*10+day2[4].digitValue();
    int result;
        QDate date1;
        date1.setDate(year,mounth,days);
        QDate date2;
        date2.setDate(year2, mounth2, days2);
        result = date1.daysTo(date2);
         if (result < 0)
             return -1*result;
         else
        return result;
}


int Date::Duration(QString day, QString day2)
{
    int year = day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();
    int days = day[0].digitValue()*10+day[1].digitValue();
    int mounth = day[3].digitValue()*10+day[4].digitValue();
    int result;
        QDate date1;
        date1.setDate(year,mounth,days);
        result = date1.daysTo(QDate::currentDate());
         if (result < 0)
             return -1*result;
         else
            return result;

}
