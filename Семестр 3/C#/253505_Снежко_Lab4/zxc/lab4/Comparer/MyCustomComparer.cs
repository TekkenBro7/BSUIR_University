using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entity;

namespace Comparer
{
    public class MyCustomComparer : IComparer<Product>
    {
        public int Compare(Product? first, Product? second)
        {
            if (first == null || second == null)
            {
                throw new ArgumentNullException("Оба объекта должны быть не NULL.");
            }
            return string.Compare(first.Name, second.Name);
        }
    }
}
