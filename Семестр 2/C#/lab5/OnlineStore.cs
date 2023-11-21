using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Magazin
{
    class OnlineStore
    {
        private List<Product> products = new();
        private List<Order> orders = new();
        private List<Customer> customers = new();
        private enum OrderStatus
        {
            WAITING,
            COMPLETED
        };
        private class Product
        {
            public string Name;
            public double Price;
        }
        private class Order
        {
            public Customer Customers;
            public Product Products;
            public OrderStatus Status = OrderStatus.WAITING;
        }
        private class Customer
        {
            public string Name;
            public List<Order> orders = new();
        }
        public void AddProduct(string name, double price)
        {
            Product product = new();
            product.Name = name;
            product.Price = price;
            products.Add(product);
            Order order = new();
            order.Status = OrderStatus.WAITING;
            orders.Add(order);
            Console.WriteLine("Добавлен продукт " + product.Name + " c ценой " + product.Price + " и статус " + order.Status);
        }
        public void AddCustomer(string name)
        {
            Customer customer = new();
            customer.Name = name;
            customers.Add(customer);
        }
        public void BuyProduct(string customerName, string productName)
        {
            Customer customer = null;
            for (int i = 0; i < customers.Count; i++)
            {
                if (customers[i].Name == customerName)
                {
                    customer = customers[i];
                    break;
                }
            }
            if (customer == null)
            {
                Console.WriteLine("Клиент " + customerName + " не найден.");
                return;
            }
            Product product = new();
            for (int i = 0; i < products.Count; i++)
            {
                if (products[i].Name == productName)
                {
                    product = products[i];
                    break;
                }
            }
            if (product == null)
            {
                Console.WriteLine("Товар " + productName + " не " + "найден");
                return;
            }
            Order order = new() { Customers = customer, Products = product };
            orders.Add(order);
            customer.orders.Add(order);
            order.Status = OrderStatus.COMPLETED;
        }
        public void GetCustomerOrders(string customerName)
        {
            Customer customer = null;
            for (int i = 0; i < customers.Count; i++)
            {
                if (customers[i].Name == customerName)
                {
                    customer = customers[i];
                    break;
                }
            }
            if (customer != null)
            {
                Console.WriteLine("Список заказов для клиента " + customerName + ": ");
                for (int i = 0; i < orders.Count; i++)
                {
                    if (orders[i].Customers == customer)
                    {
                        Console.WriteLine("- " + orders[i].Products.Name + " " + orders[i].Status);
                    }
                }
            }
            else
            {
                Console.WriteLine("Клиент " + customerName + " не найден.");
            }
        }
        public void GetCustomerMoney(string customerName)
        {
            Customer customer = null;
            double MoneySpend = 0;
            for (int i = 0; i < customers.Count; i++)
            {
                if (customers[i].Name == customerName)
                {
                    customer = customers[i];
                    break;
                }
            }
            if (customer == null)
            {
                Console.WriteLine("Клиент " + customerName + " не найден.");
                return;
            }
            for (int i = 0; i < orders.Count; i++)
            {
                if (orders[i].Customers == customer)
                {
                    MoneySpend += orders[i].Products.Price;
                }
            }
            Console.WriteLine("Сумма заказов для клиента " + customerName + ": " + MoneySpend);
        }
    }
}