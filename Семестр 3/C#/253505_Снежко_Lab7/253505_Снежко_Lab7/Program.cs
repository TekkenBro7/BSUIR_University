using System.Threading;
using Integral;

namespace _253505_Снежко_Lab7
{
    internal class Program
    {
        static void AchievementProgress(double progress)
        {

            string progressBar = new('=', (int)(progress * 0.2));
            int idOfThread = Thread.CurrentThread.ManagedThreadId;
            string message = $"Поток {idOfThread}: [{progressBar}{((int)progress == 100 ? '=' : '>')}] {progress}%";
            lock (Console.Out)
            {
                Console.SetCursorPosition(0, idOfThread);
                Console.Write(message);
            }
        }
        static void Main(string[] args)
        {
            IntegralCalculation integral = new();
            integral.AchievementProgressEvent += AchievementProgress;
            integral.SinResultEvent += (result) =>
            {
                int idOfThread = Thread.CurrentThread.ManagedThreadId;
                lock (Console.Out)
                {
                    Console.SetCursorPosition(0, idOfThread);
                    Console.Write($"Поток {idOfThread} закончился с результатом {result}");
                }
            };
            integral.ElapsedTimeEvent += (time) =>
            {
                int idOfThread = Thread.CurrentThread.ManagedThreadId;
                lock (Console.Out)
                {
                    Console.SetCursorPosition(54, idOfThread);
                    string priority = "";
                    if (Thread.CurrentThread.Priority == ThreadPriority.Highest) priority = "Высокий";
                    if (Thread.CurrentThread.Priority == ThreadPriority.Lowest) priority = "Низкий";
                    Console.Write($"Затраченное время в миллисекундах: {time} {priority}");
                }
            };

            Thread thread1 = new(integral.Integrate);
            thread1.Priority = ThreadPriority.Highest;
            thread1.Start();

            Thread thread2 = new(integral.Integrate);
            thread2.Priority = ThreadPriority.Lowest;
            thread2.Start();

            Thread thread3 = new(integral.Integrate);
            thread3.Start();

            Thread thread4 = new(integral.Integrate);
            thread4.Start();

            Thread thread5 = new(integral.Integrate);
            thread5.Start();
        }
    }
}