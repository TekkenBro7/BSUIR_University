using Functions;
using Journal_Class;

namespace _253505_Снежко_Lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ShopSystem shop = new();
            Journal journal = new();
            shop.ProductRegistationMessageEvent += journal.Log;
            shop.AddProduct("Чебурек", 101.1234);
            shop.AddProduct("Квас", 114.129);
            shop.AddProduct("Хлеб", 10.555);
            shop.AddProduct("Батон", 15.12);
            Console.WriteLine(journal.GetLogs());
            shop.RegistationOrderMessageEvent += (string message) => Console.WriteLine(message);
            shop.RegistationCustomerMessageEvent += (string message) => Console.WriteLine(message);
            shop.RegisterOrder("Максим", "Чебурек", 2);
            shop.RegisterOrder("Ваня", "Чебурек", 10);
            shop.RegisterOrder("Максим", "Квас", 100);
            shop.RegisterOrder("Кирилл", "Квас", 100);
            Console.WriteLine();

            Console.WriteLine("Список продуктов, отсортированных по цене(по возрастанию):");
            var a = shop.GetSortedProductsByPrice();
            foreach(var product in a)
            {
                Console.WriteLine(product);
            }        
            Console.WriteLine();
            Console.WriteLine(shop.GetSumOfAllProducts());
            Console.WriteLine(shop.GetSumOfAllSales());
            Console.WriteLine(shop.GetClientNameWithMaxPayment());
            Console.WriteLine(shop.GetClientCountGreaterSum(10));

            Console.WriteLine();

            var b = shop.GetCustomerExpenses("Максим");
            foreach(var customer in b)
            {
                Console.WriteLine(customer);
            }            
        }
    }
}