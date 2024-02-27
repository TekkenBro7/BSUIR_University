using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calculator.Pages.SQLite.Entities;


namespace Calculator.Pages.SQLite.Services
{
    public interface IDbService
    {
        IEnumerable<Author> GetAllAuthors();
        IEnumerable<Book> GetAuthorBooks(int id);
        void Init();
    }
}
