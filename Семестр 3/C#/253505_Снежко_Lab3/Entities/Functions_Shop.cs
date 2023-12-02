using Shop;
using System;
using System.Collections.Generic;
using Generic.Math;
using System.Numerics;
using System.Linq;
using System.Diagnostics;
using System.Collections;

namespace Functions
{
    internal class Customer
    {
        public string Name { get; set; }
    }
    internal class Order
    {
        public string CustomerName { get; set; }
        public string ProductName { get; set; }
        public int Quantity { get; set; }
    }

    public class ShopSystem
    {
        private Dictionary<string, double> products;
        private List<Order> orders;
        private List<Customer> customers;
        public delegate void ShopMessages(string message);
        public event ShopMessages? RegistationCustomerMessageEvent;
        public event ShopMessages? RegistationOrderMessageEvent;
        public event ShopMessages? ProductRegistationMessageEvent;
        public ShopSystem()
        {
            products = new();
            orders = new();
            customers = new();
        }
        public void AddProduct(string name, double price)
        {
            if (!products.ContainsKey(name))
            {
                products.Add(name, price);
                ProductRegistationMessageEvent?.Invoke($"Добавлен продукт {name} стоимостью {price}");
            }
            else
            {
                throw new InvalidOperationException("Продукт с таким именем уже существует");
            }
        }
        public void RegisterOrder(string customerName, string productName, int quantity)
        {
            if (!customers.Any(c => c.Name == customerName))
            {
                customers.Add(new() { Name = customerName });
                RegistationCustomerMessageEvent?.Invoke($"Добавлен в базу человек с именем {customerName}");
            }
            Order order = new()
            {
                CustomerName = customerName,
                ProductName = productName,
                Quantity = quantity
            };
            foreach (var product in products)
            {
                if (productName == product.Key)
                {
                    orders.Add(order);
                    RegistationOrderMessageEvent?.Invoke($"Произошёл заказ на имя {customerName}");
                    return;
                }
            }
            throw new InvalidOperationException("Продукта с таким именем не существует");
        }
        public List<string> GetSortedProductsByPrice()
        {
            return (from product in products orderby product.Value select product.Key).ToList();
        }
        public double GetSumOfAllProducts()
        {
            return (from product in products select product.Value).Sum();
        }
        public double GetSumOfAllSales()
        {
            return orders.Join(products, order => order.ProductName, product => product.Key, (order, product) => order.Quantity * product.Value).Sum();
        }
        public string GetClientNameWithMaxPayment()
        {
            return orders.GroupBy(order => order.CustomerName)
                .Select(group => new 
                {
                    CustomerName = group.Key,
                    TotalCost = group.Sum(order => order.Quantity * products[order.ProductName])
                })
                .OrderByDescending(customer => customer.TotalCost)
                .First().CustomerName;         
        }
        public int GetClientCountGreaterSum(double sum)
        {
            var сlients = orders.GroupBy(order => order.CustomerName).Select(group => new
            {
                CustomerName = group.Key,
                TotalCost = group.Sum(order => order.Quantity * products[order.ProductName])
            });
            return сlients.Aggregate(0, (count, client) => client.TotalCost > sum ? count + 1 : count);
        }
        public List<double> GetCustomerExpenses(string ClientName)
        {
            var list_of_items = orders
                .Where(order => order.CustomerName == ClientName)
                .GroupBy(order => order.ProductName)
                .Select(group => group.Sum(order => order.Quantity * products[order.ProductName]))
                .ToList();
            return list_of_items;
        }
    }
}
