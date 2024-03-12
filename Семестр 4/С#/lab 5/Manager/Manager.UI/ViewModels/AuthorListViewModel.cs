using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Manager.Aplication.AuthorUseCases.Queries;
using Manager.Aplication.BookUseCases.Queries;
using Manager.UI.Pages;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.UI.ViewModels
{
    public partial class AuthorListViewModel : ObservableObject
    {
        private readonly IMediator _mediator;
        public AuthorListViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }
        public ObservableCollection<Author> Authors { get; set; } = new();
        public ObservableCollection<Book> Books { get; set; } = new();

        // Выбранный в списке автор
        [ObservableProperty]
        Author selectedAuthor;

        // Команда обновления списка авторов
        [RelayCommand]
        async Task UpdateAuthorList() => await GetAuthors();

        // Команда обновления списка книг
        [RelayCommand]
        public async void UpdateBookList() => await GetBooks();

        [RelayCommand]
        async Task AddBook() => await GoToAddBookPage();

        [RelayCommand]
        async Task AddAuthor() => await GoToAddAuthorPage();

        [RelayCommand]
        async Task ShowDetails(Book book) => await GotoDetailsPage(book);

        async Task GoToAddAuthorPage()
        {
            await Shell.Current.GoToAsync(nameof(AddAuthor));
        }
        async Task GoToAddBookPage()
        {
            if (SelectedAuthor != null)
            {
                IDictionary<string, object> parametrs = new Dictionary<string, object>()
                {
                    {"Author", SelectedAuthor }
                };
                await Shell.Current.GoToAsync(nameof(AddBook), parametrs);
            }
        }
        public async Task GetAuthors()
        {
            var authors = await _mediator.Send(new GetAllAuthorsRequest());
            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                Authors.Clear();
                foreach (var author in authors)
                    Authors.Add(author);
            });
        }
        public async Task GetBooks()
        {
            if (SelectedAuthor != null)
            {
                var books = await _mediator.Send(new GetBooksByAuthorIdQuery(SelectedAuthor.Id));
                await MainThread.InvokeOnMainThreadAsync(() =>
                {
                    Books.Clear();
                    foreach (var book in books)
                        Books.Add(book);
                });
            }
        }
        private async Task GotoDetailsPage(Book book)
        {
            IDictionary<string, object> parametrs = new Dictionary<string, object>()
            {
                {"Book", book }
            };
            await Shell.Current.GoToAsync(nameof(BooksDetails), parametrs);
        }
    }
}
