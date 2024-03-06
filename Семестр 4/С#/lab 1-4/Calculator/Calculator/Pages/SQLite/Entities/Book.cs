using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace Calculator.Pages.SQLite.Entities
{
    [Table("Book")]
    public class Book
    {
        [PrimaryKey, AutoIncrement, Indexed]
        [Column("Id")]
        public int BookId { get; set; }
        [Unique]
        public string Title { get; set; }
        public int Year { get; set; }
        public string Genre { get; set; }
        [Indexed]
        public int AuthorId { get; set; }
    }
}
