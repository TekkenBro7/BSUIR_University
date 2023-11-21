#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL, "ru");
	long double a, b, z, y, x, f;

	std::cout << "Введите а, b, z" << '\n';
	std::cin >> a >> b >> z;
	int fuctrion;
	std::cout << "Введите функцию" << '\n';
	std::cin >> fuctrion;
	switch (fuctrion) {
	case 1:
		std::cout << "Функия f(x) = 2x" << '\n';
		if (z < -1) {
			std::cout << "При z < -1 имеем" << '\n';
			x = -z / 3;
			f = 2 * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		else {
			std::cout << "При z >= -1 имеем" << '\n';
			x = fabs(z);
			f = 2 * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		break;
	case 2:
		std::cout << "Функия f(x) = x^3" << '\n';
		if (z < -1) {
			std::cout << "При z < -1 имеем" << '\n';
			x = -z / 3;
			f = x * x * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		else {
			std::cout << "При z >= -1 имеем" << '\n';
			x = fabs(z);
			f = x * x * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		break;
	case 3:
		std::cout << "Функия f(x) = x/3" << '\n';
		if (z < -1) {
			std::cout << "При z < -1 имеем" << '\n';
			x = -z / 3;
			f = x / 3;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		else {
			std::cout << "При z >= -1 имеем" << '\n';
			x = fabs(z);
			f = x / 3;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		break;
	default:
		std::cout << "Неверный ввод";
		break;
	}

	return 0;
}