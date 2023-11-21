#include <iostream>
#include <iomanip>
int main() {
	long double b1, q = 1;
	std::cin >> b1;
		std::cout << std::setprecision(8);
		q /= 1001;
		std::cout << b1 / (1 - q);
	return 0;
}