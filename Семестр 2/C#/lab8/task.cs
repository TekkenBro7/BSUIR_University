using System.Collections.Specialized;
using static System.Formats.Asn1.AsnWriter;
using Magazin;

namespace lab8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Store store = new();
            store.AddNoDiscount("123", 12);
            store.AddAbsDiscount("zzz", 100, 90);
            store.AddAbsDiscount("qqq", 1001, 35);
            store.FindCheapestProduct();
            store.GetAllProducts();
            Console.ReadKey();
        }
    }
}