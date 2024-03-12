using Manager.UI.ViewModels;

namespace Manager.UI.Pages;

public partial class BooksDetails : ContentPage
{
	private BooksDetailsViewModel _detailsViewModel;
	public BooksDetails(BooksDetailsViewModel detailsViewModel)
	{
		InitializeComponent();
		_detailsViewModel = detailsViewModel;
		BindingContext = _detailsViewModel;
	}
}