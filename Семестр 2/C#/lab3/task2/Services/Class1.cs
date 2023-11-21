using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;



class func
{
    public double n, k, m;

    public void Function(double n, double k, double m)
    {
        double y, z, x;

        Console.WriteLine("Введите число z");
        z = double.Parse(Console.ReadLine());

        if (z > 1)
        {
            Console.WriteLine("Ветка z > 1");
            x = Math.Exp(z) + z;
            Console.Write("Ответ равен: ");
            y = Math.Sin(n * x) + Math.Cos(k * x) + Math.Log(m * x);
            Console.WriteLine(y);
        }
        else
        {
            Console.WriteLine("Ветка z <= 1");
            x = z * z + 1;
            Console.Write("Ответ равен: ");
            y = Math.Sin(n * x) + Math.Cos(k * x) + Math.Log(m * x);
            Console.WriteLine(y);            
        }
    }
}
