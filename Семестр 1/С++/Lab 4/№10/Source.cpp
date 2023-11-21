#include <iostream>

using namespace std;

long long a[100], b[100], c[500];

long long dlinka()
{
    long long n, k;
    cin >> n;
    k = n - 1;
    if (n % 2 == 0)
        n /= 2;
    else k /= 2;
    for (int i = 0; n > 0; i++, n /= 10)
    {
        a[i] = n % 10;
    }
    for (int i = 0; k > 0; i++, k /= 10)
    {
        b[i] = k % 10;
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    c[0]++;
    for (int i = 0; i < 50; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    bool x = false;
    for (int i = 100; i >= 0; i--)
    {
        if (c[i]) x = true;
        if (x) cout << c[i];
    }
    cout << '\n';
}

int main()
{
    long long n;
   n = dlinka();

   return 0;
    
}