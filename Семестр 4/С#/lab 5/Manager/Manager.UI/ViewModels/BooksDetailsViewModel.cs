using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Manager.UI.Pages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.UI.ViewModels
{
    [QueryProperty(nameof(Book), nameof(Book))]
    public partial class BooksDetailsViewModel : ObservableObject
    {
        [ObservableProperty]
        Book book;

        [RelayCommand]
        async void Edit() => await GotoEditObjectPage();

        public async Task GotoEditObjectPage()
        {
            IDictionary<string, object> parametrs = new Dictionary<string, object>()
            {
                { "Book", Book }
            };
            await Shell.Current.GoToAsync(nameof(EditBook), parametrs);
        }
    }
}
