using System;
using System.Collections.Generic;
using Magazin;

namespace Store
{
    class Program
    {
        static void Main(string[] args)
        {
            OnlineStore store = new();
            store.AddProduct("Телефон Samsung", 1000);
            store.AddProduct("Ноутбук Apple", 40);
            store.AddProduct("Умные часы Apple Watch", 70);
            store.AddCustomer("Максим");
            store.AddCustomer("Ваня");
            store.AddCustomer("Саня");
            store.BuyProduct("Максим", "Телефон Samsung");
            store.BuyProduct("Максим", "Умные часы Apple Watch");
            store.BuyProduct("Ваня", "Ноутбук Apple");
            store.BuyProduct("Саня", "Телефон Samsung");
            store.GetCustomerOrders("Саня");
            store.GetCustomerMoney("Саня");
            Console.ReadKey();
        }
    }
}