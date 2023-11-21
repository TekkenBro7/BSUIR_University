#ifndef FIRMA_H
#define FIRMA_H
#include <QString>

class firma
{
private:
    QString NameProekt;
    QString zadaniye;
    QString fioisp;
    QString fioruk;
    QString day;
    QString dayend;

public:
    firma();
    void Name(QString NameProekt);
    void zad(QString zadaniye);
    void fio(QString fioisp);
    void FIO(QString fioruk);
    void d1(QString day);
    void d2(QString dayend);

    QString getDate1();
    QString getDate2();
    QString getDate3();
    QString getDate4();
    QString getDate5();
    QString getDate6();


  //  firma SortByStaj(firma* b, int position, int t);


};



#endif // FIRMA_H
