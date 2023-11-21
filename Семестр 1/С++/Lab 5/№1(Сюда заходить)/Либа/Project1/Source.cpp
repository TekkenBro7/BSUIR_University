#include <iostream>
#include <cmath>
using namespace std;

long long proverka() {
	long long a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			printf("Некорректный ввод\n");
			printf("Попробуйте снова: ");
		}
	}
	return a;
}
long double* massive(long long N)
{
	long double e = 2.7182818284590452353602874713527, pi = 3.1415926535897932384626433832795;
	long double* a = new long double[N];
	cout << "\n Изначальный вид массива:\n";
	for (int i = 0; i < N; i++)
	{
		a[i] = powl(e, ((-i / 2) - 2 * pi)) - atan(i + 0.1);
		cout << a[i] << "\n";
	}
	cout << "\n После преобразований:\n";
	return a;
}
long double* massive2(long double* a, long long N)
{
	for (int i = 0; i < N; i++)
	{
		if (a[i] < 0)
		{
			a[i] = a[i] + 0.5;
		}
		else if (a[i] > 0)
		{
			a[i] = 0.1;
		}
		cout << a[i] << "\n";
	}
	return a;
}
void destroyer1(long double* a)
{
	delete[]a;
}