using Collections;
using Shop;
using System;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using OrderRealization;
using ProductRealization;

namespace Magazin
{
    public class ShopSystem
    {
        private MyCustomCollection<Product> products;
        private MyCustomCollection<Order> orders;
        public ShopSystem()
        {
            products = new();
            orders = new();
        }
        public void AddProduct(string name, int price)
        {
            products.Add(new() { Name = name, Price = price });
        }
        public void RegisterOrder(string customerName, string productName, int quantity)
        {
            Order order = new()
            {
                CustomerName = customerName,
                ProductName = productName,
                Quantity = quantity
            };
            for (int i = 0; i < products.Count; i++)
            {
                if (productName == products[i].Name)
                {
                    orders.Add(order);
                    return;
                }
            }
        }
        public void GetOrdersByCustomer(string customerName)
        {
            Console.WriteLine("Список заказов " + customerName + ": ");
            for (int i = 0; i < orders.Count; i++)
            {
                Order order = orders[i];
                if (order.CustomerName == customerName)
                {
                    Console.WriteLine("-" + order.ProductName + ", количество: " + order.Quantity);
                }
            }
        }
        public int CalculateOrderTotal(string customerName)
        {
            int total = 0;
            for (int i = 0; i < orders.Count; i++)
            {
                if (orders[i].CustomerName == customerName)
                {
                    for (int j = 0; j < products.Count; j++)
                    {
                        if (orders[i].ProductName == products[j].Name)
                        {
                            total += orders[i] * products[j].Price;
                        }
                    }
                }
            }
            return total;
        }
        public int CalculateProductSalesTotal(string product)
        {
            int price = 0;
            for (int i = 0; i < products.Count; i++)
            {
                if (products[i].Name == product)
                {
                    price = products[i].Price;
                }
            }
            int total = 0;
            for (int i = 0; i < orders.Count; i++)
            {
                if (orders[i].ProductName == product)
                {
                    total += orders[i] * price;
                }
            }
            return total;
        }
    }
}