using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using Generic.Math;

namespace OrderRealization 
{
    internal class Order : IMultiplyOperators<Order, int, int>
    {
        public string CustomerName { get; set; }
        public string ProductName { get; set; }
        public int Quantity { get; set; }
        public static int operator *(Order left, int right)
        {
            return left.Quantity * right;
        }
    }
}
