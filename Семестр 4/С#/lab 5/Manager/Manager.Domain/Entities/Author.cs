using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.Domain.Entities
{
    public class Author : Entity
    {
        public string? Country { get; set; }
        List<Book> books = new();
        public Author() { }
        public Author(string name, string country) : base(name) 
        {
            Country = country;
        }
    }
}
