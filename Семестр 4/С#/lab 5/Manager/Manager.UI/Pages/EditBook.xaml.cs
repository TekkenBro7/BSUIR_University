using Manager.UI.ViewModels;

namespace Manager.UI.Pages;

public partial class EditBook : ContentPage
{
	private EditBookViewModel _viewModel;
	public EditBook(EditBookViewModel viewModel)
	{
		InitializeComponent();
		_viewModel = viewModel;
		BindingContext = _viewModel;
	}
}