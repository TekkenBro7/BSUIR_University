
#include <iostream>
#include <cmath>
int main() {
	setlocale(LC_ALL, "ru");
	long double a, b, c, Y;
	int N;
	std::cout << "Write N" << '\n';
	std::cin >> N;
	switch (N)
	{
	case 2:
		std::cout << "Write a, b, c" << '\n';
		std::cin >> a >> b >> c;
		Y = b * c - a * a;
		std::cout << Y;
		break;

	case 56:
		std::cout << "Write b, c" << '\n';
		std::cin >> b >> c;
		Y = b * c;
		std::cout << Y;
		break;

	case 7:
		std::cout << "Write a, c" << '\n';
		std::cin >> a >> c;
		Y = a * a * a * a * a * a * a * c;
		std::cout << Y;
		break;

	case 3:
		std::cout << "Write a, b, c" << '\n';
		std::cin >> a >> b >> c;
		Y = a - b * c;
		std::cout << Y;
		break;

	default:
		std::cout << "Write a, b" << '\n';
		std::cin >> a >> b;
		Y = (a + b) * (a + b) * (a + b);
		std::cout << Y;
		break;

	}
		return 0;
}
