#include <iostream>

long long recursiya(long long n)
{
    if (n % 10 > 0)
    {
        return n % 10;
    }
    else if (n == 0)
    {
        return 0;
    }
    else
    {
        return recursiya(n / 10);
    }
}
long long summa(long long i, long long q)
{
    long long sum = 0;
    while (i <= q)
    {
        sum += recursiya(i);
        i++;
    }
    return sum;
}


int main()
{
    long long i = 0, q = 0, sum = 0;
    while (i >= 0 && q >= 0)
    {
        std::cin >> i >> q;
        if (i >= 0 && q >= 0)
        {
            std::cout << summa(i, q) << std::endl;
        }
    }
    return 0;
}