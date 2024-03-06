using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calculator.Pages.SQLite.Entities;
using SQLite;

namespace Calculator.Pages.SQLite.Services
{
    public class SQLiteService : IDbService
    {
        private SQLiteConnection Database;
        public static string DatabasePath => Path.Combine(FileSystem.AppDataDirectory, "SQLite.db");
        public IEnumerable<Author> GetAllAuthors()
        {
            return Database.Table<Author>().ToList();
        }
        public IEnumerable<Book> GetAuthorBooks(int id)
        {
            return Database.Table<Book>().Where(x => x.AuthorId == id).ToList();
        }
        public void Init()
        {
            Database = new SQLiteConnection(DatabasePath, SQLiteOpenFlags.Create | SQLiteOpenFlags.ReadWrite);
            if (Database == null)
                return;
            Database.DropTable<Author>();
            Database.DropTable<Book>();
            Database.CreateTable<Author>();
            Database.Insert(new Author { Name = "Лев Толстой", Country = "Россия" });
            Database.Insert(new Author { Name = "Якуб Колос", Country = "Беларусь" });
            Database.Insert(new Author { Name = "Уильям Шекспир", Country = "Англия" });
            Database.Insert(new Author { Name = "Федор Достоевский", Country = "Россия" });
            Database.Insert(new Author { Name = "Джордж Оруэлл", Country = "Великобритания" });
            Database.Insert(new Author { Name = "Агата Кристи", Country = "Великобритания" });
            Database.CreateTable<Book>();
            Database.Insert(new Book { Title = "Война и мир", Year = 1867, Genre = "Роман", AuthorId = 1});
            Database.Insert(new Book { Title = "Воскресенье", Year = 1899, Genre = "Роман", AuthorId = 1 });
            Database.Insert(new Book { Title = "Анна Карелина", Year = 1878, Genre = "Роман", AuthorId = 1 });
            Database.Insert(new Book { Title = "После бала", Year = 1911, Genre = "Фикшн", AuthorId = 1 });
            Database.Insert(new Book { Title = "Смерть Ивана Ильича", Year = 1886, Genre = "Новелла", AuthorId = 1 });

            Database.Insert(new Book { Title = "Новая земля", Year = 1955, Genre = "Поэма", AuthorId = 2 });
            Database.Insert(new Book { Title = "На росстанях", Year = 1955, Genre = "Роман", AuthorId = 2 });
            Database.Insert(new Book { Title = "Сымон-музыка", Year = 1925, Genre = "Поэзия", AuthorId = 2 });
            Database.Insert(new Book { Title = "Трясина", Year = 1965, Genre = "Проза", AuthorId = 2 });
            Database.Insert(new Book { Title = "В глубине Полесья", Year = 1927, Genre = "Роман", AuthorId = 2 });

            Database.Insert(new Book { Title = "Гамлет", Year = 1603, Genre = "Трагедия", AuthorId = 3 });
            Database.Insert(new Book { Title = "Ромео и Джульетта", Year = 1597, Genre = "Трагедия", AuthorId = 3 });
            Database.Insert(new Book { Title = "Отелло", Year = 1603, Genre = "Трагедия", AuthorId = 3 });
            Database.Insert(new Book { Title = "Макбет", Year = 1606, Genre = "Трагедия", AuthorId = 3 });
            Database.Insert(new Book { Title = "Король Лир", Year = 1606, Genre = "Трагедия", AuthorId = 3 });
            Database.Insert(new Book { Title = "Очарованный сон в летнюю ночь", Year = 1595, Genre = "Комедия", AuthorId = 3 });

            Database.Insert(new Book { Title = "Преступление и наказание", Year = 1866, Genre = "Роман", AuthorId = 4 });
            Database.Insert(new Book { Title = "Идиот", Year = 1869, Genre = "Роман", AuthorId = 4 });
            Database.Insert(new Book { Title = "Братья Карамазовы", Year = 1880, Genre = "Роман", AuthorId = 4 });
            Database.Insert(new Book { Title = "Бесы", Year = 1872, Genre = "Роман", AuthorId = 4 });
            Database.Insert(new Book { Title = "Игрок", Year = 1867, Genre = "Роман", AuthorId = 4 });
            Database.Insert(new Book { Title = "Записки из подполья", Year = 1864, Genre = "Роман", AuthorId = 4 });

            Database.Insert(new Book { Title = "1984", Year = 1949, Genre = "Роман", AuthorId = 5 });
            Database.Insert(new Book { Title = "Скотный двор", Year = 1945, Genre = "Сатира", AuthorId = 5 });
            Database.Insert(new Book { Title = "Скверный анекдот", Year = 1939, Genre = "Политический роман", AuthorId = 5 });
            Database.Insert(new Book { Title = "Смотритель", Year = 1933, Genre = "Роман", AuthorId = 5 });
            Database.Insert(new Book { Title = "Записки о палаче", Year = 1931, Genre = "Автобиография", AuthorId = 5 });
            Database.Insert(new Book { Title = "Маленький стражник", Year = 1936, Genre = "Роман", AuthorId = 5 });
            Database.Insert(new Book { Title = "Голая ветвь", Year = 1936, Genre = "Роман", AuthorId = 5 });

            Database.Insert(new Book { Title = "Десять негритят", Year = 1939, Genre = "Детектив", AuthorId = 6 });
            Database.Insert(new Book { Title = "Убийство в восточном экспрессе", Year = 1934, Genre = "Детектив", AuthorId = 6 });
            Database.Insert(new Book { Title = "Приключения мистера Куара", Year = 1936, Genre = "Детектив", AuthorId = 6 });
            Database.Insert(new Book { Title = "Загадка Эндхауза", Year = 1930, Genre = "Детектив", AuthorId = 6 });
            Database.Insert(new Book { Title = "Смерть на Ниле", Year = 1937, Genre = "Детектив", AuthorId = 6 });
            Database.Insert(new Book { Title = "Опасное задание", Year = 1932, Genre = "Детектив", AuthorId = 6 });
            Database.Insert(new Book { Title = "Таинственное происшествие в Стайлзе", Year = 1920, Genre = "Детектив", AuthorId = 6 });
        }
    }
}
