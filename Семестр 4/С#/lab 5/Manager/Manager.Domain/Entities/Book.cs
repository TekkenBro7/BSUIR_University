using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.Domain.Entities
{
    public class Book : Entity
    {
        public Book() { }
        public Book(string name, double rating, string genre, int year, int? authorId = 0) : base(name)
        {
            Rating = rating;
            Genre = genre;
            Year = year;
            AuthorId = authorId.Value;
        }
        public int Year { get; set; }
        public string Genre { get; set; }
        public double Rating { get; set; }
        public int AuthorId { get; set; }
        public void AddToAuthor(int authorId)
        {
            if (authorId <= 0) return;
                AuthorId = authorId;
        }
    }
}
