using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Magazin
{
    interface IPrice
    {
        double GetPrice(double price);
    }
    class Product
    {
        private double Price;
        private string Name;
        public IPrice PriceStrategy;
        public Product(string Name, double Price, IPrice priceStrategy)
        {
            this.Price = Price;
            this.Name = Name;
            PriceStrategy = priceStrategy;
        }
        public double GetPrice()
        {
            return PriceStrategy.GetPrice(Price);
        }
        public void SetPrice(double Price)
        {
            this.Price = Price;
        }
        public string GetName()
        {
            return Name;
        }
        public void SetName(string Name)
        {
            this.Name = Name;
        }
    }
    class DiscountOnProduct : IPrice
    {
        private double Discount;
        private double Price;
        public DiscountOnProduct(double price, double discount)
        {
            if (discount > 100 || discount < 0)
            {
                throw new Exception("Такой скидки быть не может");
            }
            Discount = discount;
            Price = GetPrice(price);
        }
        public double GetPrice(double price)
        {
            return price * (1 - Discount / 100);
        }
    }
    class NoDiscount : IPrice
    {
        private double Price;
        public NoDiscount(double price)
        {
            Price = GetPrice(price);
        }
        public double GetPrice(double price)
        {
            return price;
        }
    }
    class Store
    {
        private List<Product> products = new();
        public void AddAbsDiscount(string name, double price, double discount)
        {
            Product product = new(name, price, new DiscountOnProduct(price, discount));
            product.SetPrice(product.PriceStrategy.GetPrice(price));
            products.Add(product);
        }
        public void AddNoDiscount(string name, double price)
        {
            Product product = new Product(name, price, new NoDiscount(price));
            products.Add(product);
        }
        public void FindCheapestProduct()
        {
            if (products.Count == 0)
            {
                Console.WriteLine("Список товаров пуст");
                return;
            }
            Product cheapestProduct = products[0];
            foreach (Product product in products)
            {
                if (product.GetPrice() < cheapestProduct.GetPrice())
                {
                    cheapestProduct = product;
                }
            }
            Console.WriteLine($"Самый дешевый продукт: {cheapestProduct.GetName()} с ценой {cheapestProduct.GetPrice()}");
        }
        public void GetAllProducts()
        {
            if (products.Count == 0)
            {
                Console.WriteLine("Список товаров пуст");
                return;
            }
            Console.WriteLine("Список товаров: ");
            foreach (Product product in products)
            {
                Console.WriteLine($"- Продукт {product.GetName()} c ценой {product.GetPrice()}");
            }
        }
    }
}
