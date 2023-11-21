namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            string date;
            Console.WriteLine("Введите дату");
            date = Console.ReadLine();
            DateService data = new DateService();
            int length = date.Length;
            if (length != 10 || date[2] != '.' || date[5] != '.')
            {
                Console.WriteLine("Дата вводится в формате : дд.мм.гггг");
                return;
            }

            Console.WriteLine("Нажмите 1, чтобы определить день недели этой даты");
            Console.WriteLine("Нажмите 2, чтобы определит, между текущей датой и датой, заданной вами");

            int vibor = int.Parse(Console.ReadLine());
            if (vibor == 1)
            {
                data.GetDay(date);
            }
            else if (vibor == 2)
            {
                int day, month, year;
                Console.WriteLine("Введите день, потом месяц, потом год");
                day = int.Parse(Console.ReadLine());
                month = int.Parse(Console.ReadLine());
                year = int.Parse(Console.ReadLine());
                data.GetDaysSpan(day, month, year, date);
            }
            else
            {
                Console.WriteLine("Вы выбрали не то");
            }
        }
    }
}