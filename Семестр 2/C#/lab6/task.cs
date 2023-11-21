using System.Reflection;
using Transports;

namespace Task
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Car Audi = new("Ауди", 100, 1000, 2005);
            Console.WriteLine(Audi.GetModel());
            Console.WriteLine(Audi.GetSpeed());
            Audi.Move();
            Audi.ChangeSpeed(300);
            Audi.Massa();
            Console.WriteLine(Audi.GetWeight());
            Audi.Massa(200);
            Audi.Stop();
            Console.WriteLine(Audi.GetSpeed());
            Console.WriteLine();
            AirBalloon Balloon = new(1488, 1000, 2010, 1000);
            Console.WriteLine(Balloon.GetCapacity());
            Console.WriteLine(Balloon.GetSpeed());
            Balloon.Move();
            Balloon.ChangeSpeed(1000);
            Balloon.Massa();
            Balloon.Stop();
            Console.WriteLine(Balloon.GetSpeed());
            Console.ReadKey();
        }
    }
}