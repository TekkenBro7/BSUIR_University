#include <iostream>
#include <cmath>

/*int factorial(int t)
{
	if (t == 0 || t == 1)
		return 1;
	else
		return t * factorial(t - 1);

} */

int main() {
	setlocale(LC_ALL, "ru");
	long double n, k, x, Y;
	std::cout << "Введите количество членов ряда n и количество повторений k" << '\n';
	std::cin >> n >> k;
	for (int i = 0; i < k; i++) {
		std::cout << "Введите x от 0.1 до 1" << '\n';
		std::cin >> x;
		if (x < 0.1 || x > 1) {
			std::cout << "Неправильный ввод";
			return 0;
		}
		Y = (exp(x) - exp(-x)) / 2;
		long double Znam = x;
		long double Chisl = 1;
		long double curNum = 2;
		long double S = Znam / Chisl;
		for (int t = 1; t <= n; t++) {
			Znam *= x * x;
			Chisl *= curNum * (curNum + 1);
			curNum += 2;
			S += Znam / Chisl;
		}
		std::cout << "Значение функции S " << S << '\n';
		std::cout << "Значение функции Y " << Y << '\n';
		std::cout << "Разность функицй Y и S " << fabs(Y - S) << '\n';
	}
	return 0;
}
