using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab5.Domain
{
    public class Book
    {
        public string Name { get; set; }
        public string Author { get; set; }
        public int Year { get; set; }
        public Book(string name, string author, int year)
        {
            Name = name;
            Author = author;
            Year = year;
        }
        public Book() { }
    }
    public class BookDepository
    {
        public List<Book> Books { get; set; }
        public BookDepository()
        {
            Books = new List<Book>();
        }
        public BookDepository(List<Book> books)
        {
            Books = books;
        }
        public void AddBook(Book book)
        {
            Books.Add(book);
        }
    }
}
