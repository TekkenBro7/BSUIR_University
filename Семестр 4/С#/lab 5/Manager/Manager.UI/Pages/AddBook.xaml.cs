using Manager.UI.ViewModels;

namespace Manager.UI.Pages;

public partial class AddBook : ContentPage
{
	private AddBookViewModel _viewModel;
	public AddBook(AddBookViewModel viewModel)
	{
		InitializeComponent();
		_viewModel = viewModel;
		BindingContext = _viewModel;
	}
}