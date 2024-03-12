using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Manager.Aplication.BookUseCases.Commands;
using Manager.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.UI.ViewModels
{
    [QueryProperty(nameof(Author), nameof(Author))]
    public partial class AddBookViewModel : ObservableObject
    {
        private IMediator _mediator;

        public AddBookViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }

        [ObservableProperty]
        Author _author;

        [ObservableProperty]
        private string _bookName;

        [ObservableProperty]
        private string _bookYear;

        [ObservableProperty]
        private string _bookRating;

        [ObservableProperty]
        private string _bookGenre;

        [RelayCommand]
        async void AddBook() => AddNewBook();

        public async Task AddNewBook()
        {
            if (_author != null && int.TryParse(_bookYear, out int year) && double.TryParse(_bookRating, out double rating) && _bookGenre != "" && _bookName != "" && Convert.ToInt32(_bookYear) > 0)
            {
                if (double.TryParse(_bookRating, out double rate))
                {
                    if (rate < 0 || rate > 5)
                        await App.Current.MainPage.DisplayAlert("Ошибка", "Значение рейтинга должно быть от 0 до 5", "Ок");
                    else
                    {
                        await _mediator.Send(new AddBookCommand(_bookName, _bookGenre, year, rating, _author.Id));
                        await Shell.Current.GoToAsync("..");
                    }
                }
            }
            else
            {
                await App.Current.MainPage.DisplayAlert("Ошибка", "Заполните все поля", "Ок");
            }
        }
    }
}
