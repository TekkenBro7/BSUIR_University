using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entity
{
    public class Product
    {
        public Product(string name, int price, bool sold)
        {
            Name = name;
            Price = price;
            Sold = sold;
        }
        public int Price { set; get; }
        public bool Sold { set; get; }
        public string Name { set; get; }
        public void Deconstruct(out string name, out int price, out bool sold)
        {
            name = Name;
            price = Price; 
            sold = false;
        }
    }

}
