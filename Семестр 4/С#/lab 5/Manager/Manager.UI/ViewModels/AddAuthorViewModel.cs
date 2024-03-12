using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Manager.Aplication.AuthorUseCases.Commands;
using Manager.Domain.Abstractions;
using Manager.Persistense.Repository;
using Manager.UI.Pages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.UI.ViewModels
{
    public partial class AddAuthorViewModel : ObservableObject
    {
        private IMediator _mediator;

        public AddAuthorViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }

        [ObservableProperty]
        private string _nameAuthor;

        [ObservableProperty]
        private string _counryAuthor;

        [RelayCommand]
        async void AddAuthor() => await Add();

        public async Task Add()
        {
            if (_counryAuthor != null && _nameAuthor != null && _nameAuthor != "" && _counryAuthor != "")
            {
                var pos = new Author(_nameAuthor, _counryAuthor);
                await _mediator.Send(new AddAuthorCommand(_nameAuthor, _counryAuthor));
                await Shell.Current.GoToAsync("..");
            }
            else
            {
                await App.Current.MainPage.DisplayAlert("Ошибка", "Введите данные", "Ок");
            }
        }
    }
}
