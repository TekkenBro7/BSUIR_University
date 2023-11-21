namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Вариант 13. Дана точка на плоскости с координатами (х, у). Составить программу, которая выдает одно из сообщений\n\"Да\", \"Нет\", \"На границе\" в зависимости от того, лежит ли точка внутри заштрихованной области, вне заштрихованной\r\nобласти или на ее границе.\r\n");
            while (true)
            {
                double x, y;
                Console.WriteLine("Введите координату х: ");
                x = double.Parse(Console.ReadLine());
                Console.WriteLine("Введите координату у: ");
                y = double.Parse(Console.ReadLine());
                if (x < -40 || x > 40 || y > 40 || y < -40)
                {
                    Console.WriteLine("Да");
                }
                else if (x > -40 && x < 40 && y > -40 && y < 40)
                {
                    Console.WriteLine("Нет");
                }
                else
                {
                    Console.WriteLine("На границе");
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