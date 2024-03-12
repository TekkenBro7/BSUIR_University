using Manager.Persistense.Data;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.Persistense.Repository
{
    public class FakeUnitOfWork : IUnitOfWork
    {
        private readonly Lazy<IRepository<Author>> _authorRepository;
        private readonly Lazy<IRepository<Book>> _bookRepository;
        public FakeUnitOfWork()
        {
            _authorRepository = new Lazy<IRepository<Author>>(() =>
            new FakeAuthorRepository());
            _bookRepository = new Lazy<IRepository<Book>>(() =>
            new FakeBookRepository());
        }
        public IRepository<Author> AuthorRepository => _authorRepository.Value;
        public IRepository<Book> BookRepository => _bookRepository.Value;
        public Task CreateDataBaseAsync() => throw new NotImplementedException();
        public Task DeleteDataBaseAsync() => throw new NotImplementedException();
        public Task SaveAllAsync() => throw new NotImplementedException();
    }
}
