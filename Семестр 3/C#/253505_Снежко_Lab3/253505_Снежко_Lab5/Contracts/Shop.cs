using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Functions;
namespace Shop
{
    internal interface IShopSystem
    {
        void AddProduct(string name, double price);
        void RegisterOrder(string customerLastName, string productName, int quantity);

    }
}
