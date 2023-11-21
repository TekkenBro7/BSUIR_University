#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	long double R, P, r, Q, S, Q;
	std::cout << "Введите радиус шара, сторону ромба, его угол" << '\n';
	std::cin >> R >> P >> Q;
	if (R <= 0 || P <= 0 || sin(Q) == 1.0 || 0 >= sin(Q) ) {
		std::cout << "Ошибка ввода";
		return 0;
	}
	S = P * P * sin(Q);
	r = S / 2 * P;
	if (r >= R)
		std::cout << "Сможет";
	else
		std::cout << "Не сможет";

	return 0;
}