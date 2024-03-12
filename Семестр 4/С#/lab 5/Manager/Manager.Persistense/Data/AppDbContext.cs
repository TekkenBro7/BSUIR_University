using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Storage;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.Persistense.Data
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> context) : base(context)
        {
            Database.EnsureCreated(); // Создание базы данных, если она не существует
        }
        public DbSet<Book> Books { get; set; }
        public DbSet<Author> Author { get; set; }
    }
}
