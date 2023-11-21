#include <iostream>
#include <iomanip>
#include <math.h>
int main() {
	int h;
	double g = 9.8;
	std::cin >> h;
	std::cout << std::setprecision(5) << std::fixed;
	std::cout << sqrt(2 * h / g);
	return 0;
}