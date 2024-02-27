using Microsoft.Extensions.DependencyInjection;
using Calculator.Pages.CurrencyConverter.Services;
using Microsoft.Extensions.Logging;
using Calculator.Pages.SQLite.Services;
using Calculator.Pages.CurrencyConverter;

using Microsoft.Extensions;

namespace Calculator
{
    public static class MauiProgram
    {
        public static MauiApp CreateMauiApp()
        {
            var builder = MauiApp.CreateBuilder();
            builder
                .UseMauiApp<App>()
                .ConfigureFonts(fonts =>
                {
                    fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
                    fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
                });
            builder.Services.AddTransient<IDbService, SQLiteService>();
            builder.Services.AddSingleton<SQLitePage>();
            builder.Services.AddHttpClient<IRateService, RateService>(opt => opt.BaseAddress = new Uri("https://www.nbrb.by/api/exrates/rates"));
            builder.Services.AddSingleton<CurrencyConverter>();

#if DEBUG
            builder.Logging.AddDebug();
#endif

            return builder.Build();
        }
    }
}
