namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Вариант 13. Какая из цифр трехзначного числа больше: первая или вторая");
            while (true)
            {
                int x;
                Console.WriteLine("Введите трехзначное число: ");
                x = int.Parse(Console.ReadLine());

                if (x < 100 || x > 999)
                {
                    Console.WriteLine("Число не трехзначное!");
                }
                else
                {
                    int first = x / 100;
                    int second = (x % 100) / 10;

                    Console.WriteLine("Первое число: " + first);
                    Console.WriteLine("Второе число: " + second);

                    if (first > second)
                    {
                        Console.WriteLine("Первое число больше второго");
                    }
                    else if (first == second)
                    {
                        Console.WriteLine("Первое и второе число равны");
                    }
                    else
                    {
                        Console.WriteLine("Второе число больше первого");
                    }
                }
                Console.WriteLine("Запустить программу заново? 1 - да, остальное - нет");
                string povtor;
                povtor = Console.ReadLine();
                switch (povtor)
                {
                    case "1":
                        continue;
                    default:
                        return;
                }
            }
        }
    }
}