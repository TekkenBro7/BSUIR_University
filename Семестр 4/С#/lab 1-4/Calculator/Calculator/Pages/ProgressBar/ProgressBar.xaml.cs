namespace Calculator.Pages.ProgressBar;

public partial class ProgressBar : ContentPage
{
	public ProgressBar()
	{
		InitializeComponent();
	}
    private CancellationTokenSource? cancelTokenSource = null;
    private Task<double>? calcSinTask = null;
    async private void animateButton(Button button)
    {
        button.Scale = 0.9;
        await Task.Delay(100);
        button.Scale = 1;
    }
    private double CalculateIntegral()
    {
        double result = 0;
        MainThread.BeginInvokeOnMainThread(() =>
        {
            this.NameStepLabel.Text = "Вычисление";
        });
        int percent = 0;
        int lastPercent = 0;
        double step = 0.00000001;
        for (double i = 0; i < 1 + step; i += step)
        {
            if (cancelTokenSource.IsCancellationRequested) 
            {
                MainThread.BeginInvokeOnMainThread(() =>
                {
                    this.NameStepLabel.Text = "Задание отменено";
                });
                return 0;
            }
            result += step * Math.Sin(i);
            percent = (int)(i * 100);
            for (int j = 0; j < 50; j++) _ = 0 * 0;
            if (percent != lastPercent)
            {
                lastPercent = percent;
                MainThread.BeginInvokeOnMainThread(() =>
                {
                    progressBar.Progress = percent / 100.0;
                    this.progressLabel.Text = percent + "%";
                });
            }          
        }
        return result;
    }
    private async void OnStart(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        animateButton(button);
        if (calcSinTask?.Status != TaskStatus.Running) 
        {
            cancelTokenSource = new CancellationTokenSource();
            CancellationToken cancelToken = cancelTokenSource.Token;
            calcSinTask = Task.Run(() => CalculateIntegral(), cancelToken);
            double result = await calcSinTask;
            if (cancelToken.IsCancellationRequested) 
            {
                return;
            }
            this.NameStepLabel.Text = "Результат: " + result.ToString();
        }
    }
    private void OnCancel(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        animateButton(button);
        if (calcSinTask?.Status == TaskStatus.Running)
        {
            cancelTokenSource.Cancel();
            cancelTokenSource.Dispose();
        }
    }
}