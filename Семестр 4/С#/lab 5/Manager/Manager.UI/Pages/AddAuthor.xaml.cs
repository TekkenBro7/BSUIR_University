using Manager.UI.ViewModels;

namespace Manager.UI.Pages;

public partial class AddAuthor : ContentPage
{
	private AddAuthorViewModel _viewModel;
	public AddAuthor(AddAuthorViewModel viewModel)
	{
		InitializeComponent();
		_viewModel = viewModel;
		BindingContext = _viewModel;
	}
}