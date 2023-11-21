using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class DateService
{
    public void GetDay(string date)
    {
        char da = date[0];
        char ys = date[1];
        string days = Convert.ToString(da) + Convert.ToString(ys);
        char mon = date[3];
        char th = date[4];
        string mont = Convert.ToString(mon) + Convert.ToString(th);
        char y = date[6];
        char e = date[7];
        char a = date[8];
        char r = date[9];
        string years = Convert.ToString(y) + Convert.ToString(e) + Convert.ToString(a) + Convert.ToString(r);
        int day = Convert.ToInt32(days);
        int month = Convert.ToInt32(mont);
        int year = Convert.ToInt32(years);
        DateTime someDate = new DateTime(year, month, day);
        if (Convert.ToString(someDate.DayOfWeek) == "Friday")
        {
            Console.WriteLine("Пятница");
        }
        else if (Convert.ToString(someDate.DayOfWeek) == "Saturday")
        {
            Console.WriteLine("Cуббота");
        }
        else if (Convert.ToString(someDate.DayOfWeek) == "Sunday")
        {
            Console.WriteLine("Воскресенье");
        }
        else if (Convert.ToString(someDate.DayOfWeek) == "Monday")
        {
            Console.WriteLine("Понедельник");
        }
        else if (Convert.ToString(someDate.DayOfWeek) == "Tuesday")
        {
            Console.WriteLine("Вторник");
        }
        else if (Convert.ToString(someDate.DayOfWeek) == "Wednesday")
        {
            Console.WriteLine("Среда");
        }
        else if (Convert.ToString(someDate.DayOfWeek) == "Thursday")
        {
            Console.WriteLine("Четверг");
        }
    }
    public void GetDaysSpan(int day, int month, int year, string date)
    {
        char da = date[0];
        char ys = date[1];
        string days = Convert.ToString(da) + Convert.ToString(ys);
        char mon = date[3];
        char th = date[4];
        string mont = Convert.ToString(mon) + Convert.ToString(th);
        char y = date[6];
        char e = date[7];
        char a = date[8];
        char r = date[9];
        string years = Convert.ToString(y) + Convert.ToString(e) + Convert.ToString(a) + Convert.ToString(r);
        int day1 = Convert.ToInt32(days);
        int month1 = Convert.ToInt32(mont);
        int year1 = Convert.ToInt32(years);
        DateTime date1 = new DateTime(year1, month1, day1);
        DateTime date2 = new DateTime(year, month, day);
        string rt = Convert.ToString(date2.Subtract(date1));
        string razn = "";
        for (int i = 0; i < rt.Length; i++)
        {
            if (rt[i] == '-')
            {
                continue;
            }
            else if (rt[i] != '.' && rt[i] != ':')
            {
                if (rt[0] == '0')
                {
                    Console.WriteLine("Дней - " + 0);
                    return;
                }
                razn += rt[i];
            }
            else
            {
                break;
            }
        }
        Console.WriteLine("Дней - " + razn);
    }
}