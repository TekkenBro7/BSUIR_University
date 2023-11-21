using Collections;
using Functions;
using Journal_Class;
using CustomException;

namespace _253505_Снежко_Lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ShopSystem shop = new();
            Journal journal = new();
            shop.ProductRegistationMessageEvent += journal.Log;
            shop.AddProduct("Чебурек", 100);
            shop.AddProduct("Квас", 100);
            Console.WriteLine(journal.GetLogs());
            shop.RegistationOrderMessageEvent += (string message) => Console.WriteLine(message);
            shop.CustomerRegistationMessageEvent += journal.Log;
            shop.RegisterOrder("Максим", "Чебурек", 2);
            shop.RegisterOrder("Ваня", "Чебурек", 10);
            shop.RegisterOrder("Максим", "Квас", 100);
            Console.WriteLine(journal.GetLogs());
            Console.WriteLine();
            shop.GetOrdersByCustomer("Максим");
            Console.WriteLine(shop.CalculateProductSalesTotal("Чебурек"));
            Console.WriteLine(shop.CalculateOrderTotal("Максим"));
            MyCustomCollection<int> a = new MyCustomCollection<int>();
            try
            {
                a[2] = 4;
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.Message);
            }
            try
            {
                a.RemoveCurrent();
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.WriteLine(a.Counnt);
            a.Add(100);
            a[0] = 228;
            Console.WriteLine(a[0]);
            a.Add(500);
            Console.WriteLine(a.Current());
            a.Add(10000);
            Console.WriteLine(a.Current());
            a.Add(1337);
            Console.WriteLine(a.Current());
            a.Reset();
            Console.WriteLine(a.Current());
            a.Next();
            Console.WriteLine("\nЭлементы коллекции:");
            foreach (var item in a)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine();
            try
            {
                a.Remove(13373);
            }
            catch(MyCustomException ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.WriteLine(a.Current());
            a.RemoveCurrent();
            a.Next();
            Console.WriteLine(a.Current());
            Console.WriteLine(a.Counnt);
            Console.WriteLine();
            try
            {
                a.Remove(12);
            }
            catch (MyCustomException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}