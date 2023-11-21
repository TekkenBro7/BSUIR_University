#include <iostream>
#include <cmath>

long long recursiya(long long k, long long n, long long m)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 != 0)
    {
        return (k * recursiya((k * k) % m, n / 2, m)) % m;
    }
    else
    {
        return recursiya((k * k) % m, n / 2, m) % m;
    }
}

int main()
{
    long long k, n, t, m, i = 0;
    while (true)
    {
        std::cin >> k >> n >> t;
        if (k == 0 && n == 0 && t == 0)
            break;
        m = powl(10, t);
        k %= m;
        std::cout << "Case #" << i + 1 << ": " << recursiya(k, n, m) << '\n';
        i++;
    }
    return 0;
}