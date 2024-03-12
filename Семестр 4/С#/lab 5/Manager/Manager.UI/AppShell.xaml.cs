using Manager.UI.Pages;

namespace Manager.UI
{
    public partial class AppShell : Shell
    {
        public AppShell()
        {
            Routing.RegisterRoute(nameof(BooksDetails), typeof(BooksDetails));
            Routing.RegisterRoute(nameof(EditBook), typeof(EditBook));
            Routing.RegisterRoute(nameof(AddBook), typeof(AddBook));
            Routing.RegisterRoute(nameof(AddAuthor), typeof(AddAuthor));

            InitializeComponent();
        }
    }
}
