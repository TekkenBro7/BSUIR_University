#include <iostream>
#include <iomanip>

long double Mypow(double a, double b)
{
    int i = 1.0;
    double sum = a;
    if (b > 0)
    {
        while (i < b)
        {
            sum *= a;
            i++;
        }
        return sum;
    }
    if (b == 0)
    {
        sum = 1;
        return sum;
    }
    sum = 1;
    if (b < 0)
    {
        while (b < 0)
        {
            sum *= 1 / a;
            b++;
        }
        return sum;
    }
}
long double Mymodule(long double a)
{
    if (a < 0)
    {
        return a *= -1;
    }
    if (a >= 0)
    {
        return a;
    }
}
long double Myfact(long double x)
{
    long double sum = 1;
    if (x == 0 || x == 1)
    {
        return sum = 1;
    }
    for (int i = 1; i <= x; i++)
    {
        sum *= i;
    }
    return sum;
}
long double Mysin(long double x)
{
    long double result = 0.0;
    long double pi = 3.141592653589793238462643383279502884197169L;;
    if (x > 1e13)
    {
        x /= 1e9;
        x = ((x / (2 * pi)) - long long(x / (2 * pi))) * 2 * pi;
        x *= 1e9;
    }
    x = ((x / (2 * pi)) - long long(x / (2 * pi))) * 2 * pi;
    for (int n = 0; n <= 100; n++)
    {
        result += Mypow(-1, n) * Mypow(x, (2 * n + 1)) / Myfact(2 * n + 1);
    }
    return result;
}
long double Mycos(long double x)
{
    long double result = 0.0, n = 0.0;
    long double pi = 3.141592653589793238462643383279502884197169L;;
    if (x > 1e13)
    {
        x /= 1e9;
        x = ((x / (2 * pi)) - long long(x / (2 * pi))) * 2 * pi;
        x *= 1e9;
    }
    x = ((x / (2 * pi)) - long long(x / (2 * pi))) * 2 * pi;
    for (int n = 0; n <= 100; n++)
    {
        result += Mypow(-1, n) * Mypow(x, (2 * n)) / Myfact(2 * n);
    }
    return result;
}
long double Myln(long double x)
{
    long double ln = 0.0, x1, b = 0, i = 0, j, l = 0;
    x = Mymodule(x);
    if (x <= 1e-4)
    {
        x = 1 / x;
        b = 1;
    }
    if (x > 1)
    {
        x1 = x;
        while (x1 >= 10)
        {
            x1 /= 10;
            i++;
        }
        if (x >= 1e4)
        {
            l = 1;
            j = i / 4.0;
            x = 1e4;
        }
        x = x / (x - 1);
        for (int n = 1; n <= 95000; n++)
        {
            ln += 1.0 / (n * Mypow(Mymodule(x), n));
        }
        if (l == 1)
        {
            ln *= j;
        }
        if (b == 1)
        {
            ln = -ln;
        }
        return ln;
    }
    else if (x <= 1)
    {
        for (int n = 1; n <= 10000; n++)
        {
            ln += Mypow(-1.0, n + 1.0) * (Mypow(Mymodule(x), n) / n);
        }
        return ln;
    }
}

int main()
{
    long double a, b, c, x;
    std::cout << "x = ";
    std::cin >> x;
    if (x == 0)
    {
        a = Mysin(x);
        b = Mycos(x);

        std::cout << '\n' << "sin(x) = " << a << '\n';
        std::cout << "cos(x) = " << b << '\n';
        
        if (a < b)
            std::cout << "sin(x) - min = " << a;
        else
            std::cout << "cos(x) - min = " << b;
    }
    std::cout << std::setprecision(50);
    a = Mysin(x);
    b = Mycos(x);
    c = Myln(x);
    std::cout << '\n' << "sin(x) = " << a << '\n';
    std::cout << "cos(x) = " << b << '\n';
    std::cout << "ln(x) = " << c << '\n' << '\n';
    if (a < b && a < c)
        std::cout << "sin(x) - min = " << a; 
    else if (b < a && b < c)
        std::cout << "cos(x) - min = " << b;
    else
        std::cout << "ln(x) - min = " << c;
}











/*

    if (x == 0)
    {
        a = Mysin(x);
        b = Mycos(x);

        std::cout << '\n' << "sin(x) = " << a << '\n';
        std::cout << "cos(x) = " << b << '\n';

        if (a < b)
            std::cout << "sin(x) - min = " << a;
        else
            std::cout << "cos(x) - min = " << b;
    }

*/