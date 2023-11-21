using Collections;
using Magazin;


namespace _253505_Снежко_Lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {        
            ShopSystem shop = new();
            shop.AddProduct("Чебурек", 100);
            shop.AddProduct("Квас", 110);
            shop.RegisterOrder("Максим", "Чебурек", 2);
            shop.RegisterOrder("Ваня", "Чебурек", 10);
            shop.RegisterOrder("Максим", "Квас", 100);
            shop.GetOrdersByCustomer("Максим");
            Console.WriteLine(shop.CalculateProductSalesTotal("Чебурек"));
            Console.WriteLine(shop.CalculateOrderTotal("Максим"));
        }
    }
}