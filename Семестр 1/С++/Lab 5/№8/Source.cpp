#include <iostream>

long long del(long long n)
{
	long long x = (n + 1) / 2;
	if (n == 0)
		return 0;
	else
		return x * x + del(n / 2);
}

int main()
{
	long long n, col, a;
	std::cin >> col;
	for (int i = 0; i < col; i++)
	{
		std::cin >> n;
		a = del(n);
		std::cout << a << '\n';
	}
	return 0;
}