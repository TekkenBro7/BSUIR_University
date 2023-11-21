#include "firma.h"
#include <cmath>
#include <QDateTime>
#include <QDate>
#include <mainwindow.h>


firma::firma()
{

}

void firma::Name(QString NameProekt)
{
    this->NameProekt = NameProekt;
}

void firma::zad(QString zadaniye)
{
    this->zadaniye = zadaniye;
}

void firma::fio(QString fioisp)
{
    this->fioisp = fioisp;
}

void firma::FIO(QString fioruk)
{
    this->fioruk = fioruk;
}

void firma::d1(QString day)
{
    this->day = day;
}

void firma::d2(QString dayend)
{
    this->dayend = dayend;
}


QString firma::getDate1()
{
    return NameProekt;
}
QString firma::getDate2()
{
    return zadaniye;
}
QString firma::getDate3()
{
    return fioisp;
}
QString firma::getDate4()
{
    return fioruk;
}
QString firma::getDate5()
{
    return day;
}
QString firma::getDate6()
{
    return dayend;
}
/*
firma firma::SortByStaj(firma* b, int position, int t)
{
    for (int i = 0; i < t; i++)
    {
        int curretly = -1;
        QString str = b[i].getDate5();
        QString New = "";
        New += str[position - 1];
        New += str[position];
        int min = New.toInt();
        for (int q = i + 1; q < t; q++)
        {
          QString str1 = b[q].getDate5();
          QString New1 = "";
          New1 += str1[position - 1];
          New1 += str1[position];
          int min1 = New1.toInt();

          if (min1 < min)
          {
            curretly = q;
          }
        }


        if (curretly != -1)
        {
          std::swap(b[i], b[curretly]);
        }

      }
      if (position != 7)
      {
        return SortByStaj(b, position + 3, t);
      }
      return *b;
}
*/





