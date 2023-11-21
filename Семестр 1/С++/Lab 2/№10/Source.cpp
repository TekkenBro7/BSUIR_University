#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	long double x1, y1, r, x2, y2, R, L;
	std::cout << "Введите центр круга M1(x1; y2) и его радиус" << '\n';
	std::cin >> x1 >> y1 >> r;
	if (r <= 0) {
		std::cout << "Ошибка ввода";
		return 0;
	}
	std::cout << "Введите центр круга M2(x2; y2) и его радиус" << '\n';
	std::cin >> x2 >> y2 >> R;
	if (R <= 0) {
		std::cout << "Ошибка ввода";
		return 0;
	}
	L = sqrtl(powl(x1 - x2, 2) + powl(y1 - y2, 2));
	if (R >= L + r) {
		std::cout << "Да";
		return 0;
	}
	else if (r >= L + R) {
		std::cout << "Да, но справедливо обратное для двух фигур";
		return 0;
	}
	else if (L <= R + r) {
		std::cout << "Фигуры пересекаются";
		return 0;
	}
	else {
		std::cout << "Ни одно условие не выполнено";
		return 0;
	}
	return 0;
}