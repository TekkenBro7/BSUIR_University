using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace Calculator.Pages.SQLite.Entities
{
    [Table("Author")]
    public class Author
    {
        [PrimaryKey, AutoIncrement, Indexed]
        public int Id { get; set; }
        [Unique]
        public string Name { get; set; }
        public string Country { get; set; }
    }
}
