#include <iostream>
#include <iomanip>
int main() {
	long double a1, a100;
	long long d, S;
	std::cin >> a1 >> a100;
	std::cout << std::setprecision(10);
	d = (a100 - a1) / 99;
	std::cout << d << std::endl;
	S = (2 * a1 + 69 * d) / 2 * 70;
	std::cout << S;
	return 0;
}