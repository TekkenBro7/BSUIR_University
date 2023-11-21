using System.Globalization;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Max e = new();

            double f1, f2;
            Console.WriteLine("Разработать метод f(x), который вычисляет значение по следующей формуле:f(x)=x-sinx. Определить, в какой из точек а или b, функция принимает наименьшее значение.");
            Console.Write("Введите значение а и b: ");

            NumberFormatInfo numberFormatInfo = new NumberFormatInfo()
            {
                NumberDecimalSeparator = ".",
            };

            e.a = double.Parse(Console.ReadLine(), numberFormatInfo);
            e.b = double.Parse(Console.ReadLine(), numberFormatInfo);
            f1 = e.Maxim(e.a);
            f2 = e.Maxim(e.b);

            Console.WriteLine("--------------------");
            Console.WriteLine(f1);
            Console.WriteLine(f2);
            Console.WriteLine("--------------------");

            if (f1 > f2)
            {
                Console.WriteLine(f2 + " Принимает наименьшее значение");
            }
            else if (f1 == f2)
            {
                Console.WriteLine(f1 + " и " + f2 + " Равны");
            }
            else
            {
                Console.WriteLine(f1 + " Принимает наименьшее значение");
            }
        }
    }
}