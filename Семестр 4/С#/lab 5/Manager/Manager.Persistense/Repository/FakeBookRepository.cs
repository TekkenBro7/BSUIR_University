using Manager.Domain.Entities;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Manager.Persistense.Repository
{
    public class FakeBookRepository : IRepository<Book>
    {
        List<Book> _books;
        public FakeBookRepository()
        {
            _books = new List<Book>()
            {
                new Book { Id = 1, Name = "Война и мир", Year = 1867, Genre = "Роман", AuthorId = 1, Rating = 5.0},
                new Book { Id = 2, Name = "Воскресенье", Year = 1899, Genre = "Роман", AuthorId = 1, Rating = 4.9 },
                new Book { Id = 3, Name = "Анна Карелина", Year = 1878, Genre = "Роман", AuthorId = 1, Rating = 4.8 },
                new Book { Id = 4, Name = "После бала", Year = 1911, Genre = "Фикшн", AuthorId = 1, Rating = 4.7 },
                new Book { Id = 5, Name = "Смерть Ивана Ильича", Year = 1886, Genre = "Новелла", AuthorId = 1, Rating = 4.6 },

                new Book { Id = 6, Name = "Новая земля", Year = 1955, Genre = "Поэма", AuthorId = 2, Rating = 4.5},
                new Book { Id = 7, Name = "На росстанях", Year = 1955, Genre = "Роман", AuthorId = 2, Rating = 4.4},
                new Book { Id = 8, Name = "Сымон-музыка", Year = 1925, Genre = "Поэзия", AuthorId = 2, Rating = 4.3},
                new Book { Id = 9, Name = "Трясина", Year = 1965, Genre = "Проза", AuthorId = 2, Rating = 4.2},
                new Book { Id = 10, Name = "В глубине Полесья", Year = 1927, Genre = "Роман", AuthorId = 2, Rating = 4.1},

                new Book { Id = 11, Name = "Гамлет", Year = 1603, Genre = "Трагедия", AuthorId = 3, Rating = 4.0},
                new Book { Id = 12, Name = "Ромео и Джульетта", Year = 1597, Genre = "Трагедия", AuthorId = 3, Rating = 3.9},
                new Book { Id = 13, Name = "Отелло", Year = 1603, Genre = "Трагедия", AuthorId = 3, Rating = 3.8},
                new Book { Id = 14, Name = "Макбет", Year = 1606, Genre = "Трагедия", AuthorId = 3, Rating = 3.7},
                new Book { Id = 15, Name = "Король Лир", Year = 1606, Genre = "Трагедия", AuthorId = 3, Rating = 3.6}
            };
        }
        public Task AddAsync(Book entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
        public Task DeleteAsync(Book entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
        public Task<Book> FirstOrDefaultAsync(Expression<Func<Book, bool>> filter, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
        public Task<Book> GetByIdAsync(int id, CancellationToken cencellationToken = default, params Expression<Func<Book, object>>[] includesProperties)
        {
            throw new NotImplementedException();
        }
        public async Task<IReadOnlyList<Book>> ListAllAsync(CancellationToken cancellationToken = default)
        {
            // throw new NotImplementedException();
            return await Task.Run(() => _books);
        }
        public async Task<IReadOnlyList<Book>> ListAsync(Expression<Func<Book, bool>> filter, CancellationToken cancellationToken = default, params Expression<Func<Book, object>>[]? includesProperties)
        {
            var data = _books.AsQueryable();
            return data.Where(filter).ToList();
        }
        public Task UpdateAsync(Book entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
    }
}
