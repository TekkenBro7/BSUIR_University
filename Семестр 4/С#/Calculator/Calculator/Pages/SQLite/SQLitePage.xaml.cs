using Calculator.Pages.SQLite.Entities;
using Calculator.Pages.SQLite.Services;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography.X509Certificates;

namespace Calculator;

public partial class SQLitePage : ContentPage
{
    public IDbService DbService { get; init; } // только в конструкторе
    public List<Book> BookList { get; set; }
    public List<Author> AuthorList { get; set; }
    public SQLitePage(IDbService dbService)
    {
        DbService = dbService;
        DbService.Init();
        BindingContext = this;
        InitializeComponent();
    }
    public void OnLoaded(object sender, EventArgs e)
    {
        AuthorList = DbService.GetAllAuthors().ToList();
        picker.ItemsSource = AuthorList;
    }
    void OnPickerSelectedIndexChanged(object sender, EventArgs e)
    {
        int selectedIndex = picker.SelectedIndex;
        BookList = DbService.GetAuthorBooks(selectedIndex + 1).ToList();
        collectionView.ItemsSource = BookList;
    }
}