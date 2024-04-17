using CommunityToolkit.Maui;
using Microsoft.Extensions.Logging;
using Manager.Aplication;
using Manager.Persistense;
using Manager.UI.Pages;
using Microsoft.Extensions.Configuration;
using System.Reflection;
using Manager.Persistense.Data;
using Microsoft.EntityFrameworkCore;
using Manager.UI.ViewModels;

namespace Manager.UI
{
    public static class MauiProgram
    {
        public static MauiApp CreateMauiApp()
        {
            string settingsStream = "Manager.UI.appsettings.json";
            var builder = MauiApp.CreateBuilder();
            var a = Assembly.GetExecutingAssembly();
            using var stream = a.GetManifestResourceStream(settingsStream);
            builder.Configuration.AddJsonStream(stream);         
            builder
                .UseMauiApp<App>()
                .UseMauiCommunityToolkit()
                .ConfigureFonts(fonts =>
                {
                    fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
                    fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
                });
            var connStr = builder.Configuration.GetConnectionString("SqliteConnection");
            string dataDirectory = FileSystem.Current.AppDataDirectory + "/";
            connStr = String.Format(connStr, dataDirectory);
            var options = new DbContextOptionsBuilder<AppDbContext>().UseSqlite(connStr).Options;
            builder.Services
                .AddApplication()
                .AddPersistence(options)
                .RegisterPages()
                .RegisterViewModels();
          //  DbInitializer
          //      .Initialize(builder.Services.BuildServiceProvider())
          //      .Wait();

#if DEBUG
            builder.Logging.AddDebug();
#endif

            return builder.Build();
        }
    }
}
