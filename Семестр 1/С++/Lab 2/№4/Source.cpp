#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	long double X, Y;
	int variant;
	std::cout << "Выберите вариант" << '\n';
	std::cin >> variant;
	switch (variant) {
	case 1:
		std::cout << "Write X, Y" << '\n';
		std::cin >> X >> Y;
			X > Y ? (std::cout << "X is bigger than Y") : X < Y ? (std::cout << "Y is bigger than X") : (std::cout << "The numbers are similar");
			break;
		
	case 2:
		bool result;
		std::cout << "Write X, Y" << '\n';
		std::cin >> X >> Y;
		if (X >= Y) {
			result = true;
			std::cout << "X >= Y";
			return 0;
		}
		else {
			result = false;
			std::cout << "X < Y";
			return 0;
		}
		break;

	default:
		std::cout << "Error, bad input";
		break;

}
	return 0;
}
