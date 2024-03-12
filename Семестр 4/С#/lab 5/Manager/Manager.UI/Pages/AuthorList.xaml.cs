using Manager.UI.ViewModels;

namespace Manager.UI.Pages;

public partial class AuthorList : ContentPage
{
    private AuthorListViewModel _viewModel;
    public AuthorList(AuthorListViewModel viewModel)
    {
        InitializeComponent();
        _viewModel = viewModel;
        BindingContext = _viewModel;
    }
}

