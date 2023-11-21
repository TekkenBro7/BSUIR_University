#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	int variant;
	int n, sum = 0.0;
	std::cout << "Введите n" << '\n';
	std::cin >> n;
	std::cout << "Введите вариант (1 - цикл, 2 - без цикла)" << '\n';
	std::cin >> variant;
	switch (variant) {
	case 1:
		for (int i = 1; i < n; i++)
		{
			if (i % 2 == 0)
				sum = sum + i;
		}
		std::cout << sum;
		break;

	case 2:
		double S, Nomer;
		if (n % 2 == 0)
		{
			Nomer = n / 2 - 1;
			S = (2 + n - 2) / 2 * Nomer;
			std::cout << S;
		}
		if (n % 2 == 1)
		{
			Nomer = n / 2;
			S = (2 + n - 1) / 2 * Nomer;
			std::cout << S;
		}
		break;

	default:
		std::cout << "Нет такого варианта";

	}

	return 0;
}