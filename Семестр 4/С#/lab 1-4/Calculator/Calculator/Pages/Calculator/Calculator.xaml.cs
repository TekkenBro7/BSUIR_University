namespace Calculator.Pages.Calculator;

public partial class Calculator : ContentPage
{
    public string operation;
    public string number;
    public bool is_input;
    public Calculator()
    {
        is_input = false;
        InitializeComponent();
    }
    async private void animateButton(Button button)
    {
        button.Scale = 0.9;
        await Task.Delay(100);
        button.Scale = 1;
    }
    private void OnSelectNumber(object sender, EventArgs e)
    {
        if (is_input)
        {
            this.resultText.Text = "0";
            is_input = false;
        }
        Button button = (Button)sender;
        if (this.resultText.Text == "0")
            this.resultText.Text = button.Text;
        else
            this.resultText.Text += button.Text;
        animateButton(button);
    }
    private void OnSelectResetNum(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        this.resultText.Text = "0";
        animateButton(button);
    }
    private void OnSel(object sender, EventArgs e)
    {
        
    }
    private void OnSelectResult(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        double num1, num2, res = 0;
        num1 = double.Parse(number);
        num2 = double.Parse(this.resultText.Text);
        switch (operation)
        {
            case "+":
                res = num1 + num2;
                break;
            case "-":
                res = num1 - num2;
                break;
            case "*":
                res = num1 * num2;
                break;
            case "/":
                if (num2 == 0)
                    DisplayAlert("Ошибка", "На ноль делить нельзя!", "Исправлюсь");
                else
                    res = num1 / num2;
                break;
        }
        is_input = true;
        operation = "=";
        this.resultText.Text = res.ToString();
        animateButton(button);
    }
    private void OnSelectOperation(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        operation = button.Text;
        number = this.resultText.Text;
        is_input = true;
        animateButton(button);
    }
    private void OnSelectSqrt(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        double num = double.Parse(this.resultText.Text);
        if (num < 0)
            DisplayAlert("Ошибка", "Корень из отрицательного числа!", "Исправлюсь");
        else
        {
            num = Math.Sqrt(num);
            this.resultText.Text = num.ToString();
        }
        animateButton(button);
    }
    private void OnSelectTwoDegree(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        double num = double.Parse(this.resultText.Text);
        num = Math.Pow(num, 2);
        this.resultText.Text = num.ToString();
        animateButton(button);
    }
    private void OnSelectMinusDegree(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        double num = double.Parse(this.resultText.Text);
        if (num == 0)
            DisplayAlert("Ошибка", "На ноль делить нельзя!", "Исправлюсь");
        else
            num = 1 / num;
        this.resultText.Text = num.ToString();

        animateButton(button);
    }
    private void OnSelectAreaCircle(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        double num = double.Parse(this.resultText.Text);
        num = Math.PI * Math.Pow(num, 2);
        this.resultText.Text = num.ToString();
        animateButton(button);
    }
    private void OnSelectMinus(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        double num = double.Parse(this.resultText.Text);
        num = -num;
        this.resultText.Text = num.ToString();
        animateButton(button);
    }
    private void OnSelectPlaceDot(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        if (!this.resultText.Text.Contains(","))
            this.resultText.Text += ",";
        animateButton(button);
    }
    private void OnSelectDeleteNum(object sender, EventArgs e)
    {
        Button button = (Button)sender;
        this.resultText.Text = this.resultText.Text.Remove(this.resultText.Text.Length - 1);
        if (this.resultText.Text == "")
            this.resultText.Text = "0";
        if (this.resultText.Text[this.resultText.Text.Length - 1] == ',')
            this.resultText.Text = this.resultText.Text.Remove(this.resultText.Text.Length - 1);
        animateButton(button);
    }
}