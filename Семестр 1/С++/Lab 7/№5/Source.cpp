#include <iostream>

long long chislo(long long n)
{
	return (n + 1) / 10;
}

int main()
{
	long long povtorenie, j = 0, n;
	std::cin >> povtorenie;
	while (j < povtorenie)
	{
		std::cin >> n;
		long long otver = chislo(n);
		std::cout << otver << '\n';
		j++;
	}
	return 0;
}