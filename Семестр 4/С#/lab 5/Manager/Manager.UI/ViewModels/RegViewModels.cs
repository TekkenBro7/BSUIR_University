using Manager.UI.Pages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.UI.ViewModels
{
    public static class DependencyInjection
    {
        public static IServiceCollection RegisterPages(this IServiceCollection services)
        {
            services.
                AddTransient<AuthorList>()
                .AddTransient<BooksDetails>()
                .AddTransient<EditBook>()
                .AddTransient<AddAuthor>()
                .AddTransient<AddBook>();
            return services;
        }
        public static IServiceCollection RegisterViewModels(this IServiceCollection services)
        {
            services.
                AddTransient<AuthorListViewModel>()
                .AddTransient<BooksDetailsViewModel>()
                .AddTransient<EditBookViewModel>()
                .AddTransient<AddAuthorViewModel>()
                .AddTransient<AddBookViewModel>();
            return services;
        }
    }
}
