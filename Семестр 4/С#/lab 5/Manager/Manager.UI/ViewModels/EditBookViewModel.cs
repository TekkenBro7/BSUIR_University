using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Manager.Aplication.AuthorUseCases.Queries;
using Manager.Aplication.BookUseCases.Commands;
using Manager.Domain.Abstractions;
using Manager.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.UI.ViewModels
{
    [QueryProperty(nameof(Book), nameof(Book))]
    public partial class EditBookViewModel : ObservableObject
    {
        IMediator _mediator;
        public EditBookViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }
        public ObservableCollection<Author> _authors { get; set; } = new();

        [ObservableProperty]
        Author selectedAuthor;

        [ObservableProperty]
        Book book;

        [RelayCommand]
        async void EditBook() => await Edit();

        [RelayCommand]
        async void UpdateAuthorsList() => await GetAllAuthors();

        [RelayCommand]
        async void ChooseImage() => await LoadImage();

        public async Task Edit()
        {
            if (selectedAuthor != null)
            {
                Book.AuthorId = selectedAuthor.Id;
            }
            await _mediator.Send(new EditBookCommand(Book));
            await Shell.Current.GoToAsync("../..");
        }

        public async Task GetAllAuthors()
        {
            var authors = await _mediator.Send(new GetAllAuthorsRequest());
            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                _authors.Clear();
                foreach (var author in authors)
                    _authors.Add(author);
            });
        }

        public async Task LoadImage()
        {
            var options = new PickOptions
            {
                PickerTitle = "Выберите фотографию",
                FileTypes = FilePickerFileType.Images
            };
            var result = await FilePicker.Default.PickAsync(options);
            if (result != null && Book != null)
            {
                // Генерация имени файла
                string targetFileName = "image";
                string file = Book.Id.ToString();
                targetFileName += file;
                int dotIndex = result.FileName.LastIndexOf('.');
                string fileFormat = result.FileName.Substring(dotIndex);
                targetFileName += fileFormat;

                // Генерация пути  
                string targetFile = Path.Combine(FileSystem.Current.AppDataDirectory, targetFileName); //"C:\\Manager\\Manager.UI\\Resources\\Images"

                // Копирование изображения в директорию
                using var stream = await result.OpenReadAsync();
                using FileStream outputStream = File.OpenWrite(targetFile);
                await stream.CopyToAsync(outputStream);
            }
        }
    }
}
