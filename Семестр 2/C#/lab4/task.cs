using System.Globalization;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Home home = Home.Initialization();

            NumberFormatInfo numberFormatInfo = new()
            {
                NumberDecimalSeparator = ".",
            };

            while (true)
            {
                Console.WriteLine("Введите информацию о ЖЭС, номер ЖЭС, число жильцов, оплата за месяц, число оплативших");
                home.information = Console.ReadLine();
                home.number = int.Parse(Console.ReadLine());
                home.people = int.Parse(Console.ReadLine());
                home.pay = double.Parse(Console.ReadLine(), numberFormatInfo);
                home.peoplePay = int.Parse(Console.ReadLine());
                if (home.people < home.peoplePay)
                {
                    Console.WriteLine("Ошибка ввода");
                    return;
                }
                Console.WriteLine("Увеличить тариф или нет? 1 - да, 2 - нет");
                double x;
                x = double.Parse(Console.ReadLine());
                if (x == 1)
                {
                    double change;
                    Console.Write("Введите тариф: ");
                    change = double.Parse(Console.ReadLine(), numberFormatInfo);
                    Tarif f1 = Home.Conteiner();
                    home = Tarif.Change(home, change);
                    double otvet = Home.Dolg(home.peoplePay, home.pay, home.people);
                    Console.WriteLine("Задолженность составляет - " + otvet);
                }
                else if (x == 2)
                {
                    double otvet = Home.Dolg(home.peoplePay, home.pay, home.people);
                    Console.WriteLine("Задолженность составляет - " + otvet);
                }
                else
                {
                    Console.WriteLine("Ошибка");
                    return;
                }
                Console.WriteLine("Выйти из программы? 1 - да, 2 - нет");
                double vibor;
                vibor = double.Parse(Console.ReadLine());
                if (vibor == 1)
                {
                    return;
                }
                else if (vibor == 2)
                {
                    continue;
                }
                else
                {
                    Console.WriteLine("Ошибка");
                    return;
                }
            }
        }
    }
}
class Home
{
    public static Home singel = new();
    private Home()
    {

    }
    public static Home Initialization()
    {
        if (singel == null)
        {
            singel = new Home();
        }
        return singel;
    }

    public string information;
    public int number;
    public int people;
    public double pay;
    public int peoplePay;

    public static Tarif Conteiner()
    {
        Tarif tarif = new();
        return tarif;
    }

    public static double Dolg(int peoplePay, double pay, int people)
    {
        int peoplepay = people - peoplePay;
        double money = peoplepay * pay;
        return money;
    }
    public static double Dolg(Home home)
    {
        int peoplepay = home.people - home.peoplePay;
        double money = peoplepay * home.pay;

        return money;
    }
}

class Tarif
{
    public static Home Change(Home home, double tarif)
    {
        home.pay = tarif;

        return home;
    }
}
