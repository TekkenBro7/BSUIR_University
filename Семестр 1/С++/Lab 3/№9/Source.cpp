#include <iostream>

long double intPow(long double x, long double y)
{
	int i = 1.0;
	long double sum = x;
	if (y > 0)  // Cтепень больше 0
	{
		while (i < y)
		{
			sum *= x;
			i++;
		}
		return sum;
	}
	if (y == 0)  // Cтепень равна 0
	{
		sum = 1;
		return sum;
	}
	if (y < 0)  // Cтепень меньше 0
	{
		while (y < 0)
		{
			sum *= 1 / x;
			y++;
		}
		return sum;
	}
}

int main()
{
	long long a0, d, an, n, sum = 0.0;

	std::cout << "Write a0, d, an\n";
	std::cin >> a0 >> d >> an;
	n = (an - a0) / d;  // Кол-во членов прогрессии
	if ((an - a0) % d != 0 or n < 0)
	{
		std::cout << "No progression";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		sum += intPow(2.0, i) * intPow(-1.0, i) * (a0 + d * i);
	}
	std::cout << "Sum = " << sum;


	return 0;
}