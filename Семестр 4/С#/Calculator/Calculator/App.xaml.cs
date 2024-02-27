namespace Calculator
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();

            MainPage = new AppShell();
        }
        protected override Window CreateWindow(IActivationState activationState)
        {
            Window window = base.CreateWindow(activationState);
            const int newWidth = 440;
            const int newHeight = 550;
            window.Width = newWidth;
            window.Height = newHeight;
            window.MinimumHeight = newHeight;
            window.MinimumWidth = newWidth;

            return window;
        }
    }
}
