#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL, "ru");
	long double chast;
	long double s, minx, miny, step, length = 1.0;
	std::cout << "Введите на сколько частей поделить отрезок" << '\n';
	std::cin >> chast;
	if (chast <= 0) {
		std::cout << "Неправильный ввод";
		return 0;
	}
	minx = 2;
	miny = cosl(4.0) / sinl(4.0) - (1.0 / 5.0);
	step = length / chast; // шаг
	for (double x = 2.0; x <= 3.0; x += step)
	{
		s = fabs(cosl(2.0 * x) / sinl(2.0 * x) - (1.0 / (1.0 + x * x)));
			if (fabsl(s) < miny)
			{
				miny = fabsl(s);
				minx = x;
			}
	}
	std::cout << minx;

	return 0;
}