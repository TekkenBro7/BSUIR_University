using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Collections;
using Magazin;
namespace Shop
{
    internal interface IShopSystem
    {
        void AddProduct(string name, int price);
        void RegisterOrder(string customerLastName, string productName, int quantity);
        void GetOrdersByCustomer(string customerLastName);
        int CalculateOrderTotal(string customerName);
        int CalculateProductSalesTotal(string productName);
    }
}
