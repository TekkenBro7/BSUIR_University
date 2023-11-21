using System.Drawing;

namespace lab7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Triangle triangle1 = new(3, 4, 5);
            Triangle triangle2 = new(40, 50, 60);
            Console.WriteLine(triangle1.ToString());
            Console.WriteLine(triangle2.ToString());
            triangle1.Perimetr();
            triangle2.Perimetr();
            Console.WriteLine("Площадь треугольника: " + triangle1.Square());
            Console.WriteLine("Площадь треугольника: " + triangle2.Square());
            triangle1++;
            triangle2++;
            Console.WriteLine(triangle1.ToString());
            Console.WriteLine(triangle2.ToString());
            triangle1--;
            triangle2--;
            Console.WriteLine(triangle1.ToString());
            Console.WriteLine(triangle2.ToString());
            triangle1[1] = 4;
            Console.WriteLine(triangle1[1]);
            Triangle triangle3 = triangle1 + triangle2;
            Console.WriteLine(triangle3.ToString());
            Triangle triangle4 = triangle2 - triangle1;
            Console.WriteLine(triangle4.ToString());
            Triangle triangle5 = triangle1 * triangle2;
            Console.WriteLine(triangle5.ToString());
            Triangle triangle6 = triangle1 / triangle2;
            Console.WriteLine(triangle6.ToString());
            Console.WriteLine(triangle1 == triangle2);
            Console.WriteLine(triangle1 != triangle2);
            Console.WriteLine(triangle1 > triangle2);
            Console.WriteLine(triangle1 < triangle2);
            Console.WriteLine(triangle1 >= triangle2);
            Console.WriteLine(triangle1 <= triangle2);
            Triangle triangle7 = 10;
            Console.WriteLine(triangle7.ToString());
            Triangle triangle8 = new(6, 8, 10);
            double side = (double)triangle8;
            Console.WriteLine(side);
            Console.ReadKey();
        }
    }
}