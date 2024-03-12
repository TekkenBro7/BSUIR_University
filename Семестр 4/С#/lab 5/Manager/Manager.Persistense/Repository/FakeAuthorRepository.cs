using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Manager.Persistense.Repository
{
    public class FakeAuthorRepository : IRepository<Author>
    {
        List<Author> _authors;
        public FakeAuthorRepository() 
        {
            _authors = new List<Author>()
            {
                new Author { Name = "Лев Толстой", Country = "Россия", Id = 1 },
                new Author { Name = "Якуб Колос", Country = "Беларусь", Id = 2 },
                new Author { Name = "Уильям Шекспир", Country = "Англия", Id = 3 },
            };
        }
        public Task AddAsync(Author entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
        public Task DeleteAsync(Author entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
        public Task<Author> FirstOrDefaultAsync(Expression<Func<Author, bool>> filter, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
        public Task<Author> GetByIdAsync(int id, CancellationToken cencellationToken = default, params Expression<Func<Author, object>>[] includesProperties)
        {
            throw new NotImplementedException();
        }
        public async Task<IReadOnlyList<Author>> ListAllAsync(CancellationToken cancellationToken = default)
        {
            return await Task.Run(() => _authors);
        }
        public Task<IReadOnlyList<Author>> ListAsync(Expression<Func<Author, bool>> filter, CancellationToken cancellationToken = default, params Expression<Func<Author, object>>[]? includesProperties)
        {
            throw new NotImplementedException();
        }
        public Task UpdateAsync(Author entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
    }
}
