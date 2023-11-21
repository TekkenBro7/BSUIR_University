#include <iostream>
#include <iomanip>
int main() {
	long double a, t, v0;
	std::cin >> a >> t >> v0;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << (v0 * t) + ((a * t * t) / 2);
	return 0;
}