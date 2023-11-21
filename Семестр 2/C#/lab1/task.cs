namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            double x, y, z;
            Console.WriteLine("Введите первое число: ");
            x = double.Parse(Console.ReadLine());
            Console.WriteLine("Введите второе число: ");
            y = double.Parse(Console.ReadLine());
            z = x / y;
            Console.WriteLine("Частное от деления числа " + x + " на " + y + " = " + z);
        }
    }
}