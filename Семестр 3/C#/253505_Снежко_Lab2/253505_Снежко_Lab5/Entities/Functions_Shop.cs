using Collections;
using ProductRealization;
using OrderRealization;
using Shop;
using System;

namespace Functions
{
    public class ShopSystem
    {
        private MyCustomCollection<Product> products;
        private MyCustomCollection<Order> orders;
        public delegate void RegistationOrderMessage(string message);
        public event RegistationOrderMessage? RegistationOrderMessageEvent;
        public delegate void CustomerRegistationMessage(string message);
        public event CustomerRegistationMessage? CustomerRegistationMessageEvent;
        public delegate void ProductRegistationMessage(string message);
        public event ProductRegistationMessage? ProductRegistationMessageEvent;
        public ShopSystem()
        {
            products = new();
            orders = new();
        }
        public void AddProduct(string name, int price)
        {
            products.Add(new() { Name = name, Price = price });
            ProductRegistationMessageEvent?.Invoke($"Добавлен продукт {name} стоимостью {price}");
        }
        public void RegisterOrder(string customerName, string productName, int quantity)
        {
            Order order = new()
            {
                CustomerName = customerName,
                ProductName = productName,
                Quantity = quantity
            };
            if (!orders.Contains(customerName))
            {
                CustomerRegistationMessageEvent?.Invoke($"Добавлен пользователь {customerName}");
            }
            foreach (Product product in products)
            {
                if (productName == product.Name)
                {
                    orders.Add(order);
                    RegistationOrderMessageEvent?.Invoke($"Произошёл заказ на имя {customerName}");
                    return;
                }
            }
        }
        public void GetOrdersByCustomer(string customerName)
        {
            Console.WriteLine("Список заказов " + customerName + ": ");
            foreach (Order order in orders)
                if (order.CustomerName == customerName)
                {
                    Console.WriteLine("-" + order.ProductName + ", количество: " + order.Quantity);
                }
        }
        public int CalculateOrderTotal(string customerName)
        {
            int total = 0;
            foreach (Order order in orders)
            {
                if (order.CustomerName == customerName)
                {
                    foreach (Product product in products)
                    {
                        if (order.ProductName == product.Name)
                        {
                            total += order * product.Price;
                        }
                    }
                }
            }
            return total;
        }
        public int CalculateProductSalesTotal(string productName)
        {
            int price = 0;
            foreach (Product product in products)
            {
                if (product.Name == productName)
                {
                    price = product.Price;
                    break;
                }
            }
            int total = 0;
            foreach (Order order in orders)
            {
                if (order.ProductName == productName)
                {
                    total += order * price;
                }
            }
            return total;
        }
    }
}
