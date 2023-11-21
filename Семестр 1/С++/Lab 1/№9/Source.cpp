#include <iostream>
#include <safeint.h>
#include <climits>
int x, y;

int main() {
	std::cout << "Enter the first memory location ";
		std::cin >> x;
		std::cout << "Enter the second memory location ";
		std::cin >> y;
		if (x >= INT_MAX or y >= INT_MAX) {
		std::cout << "one of the variables is overflowing";
		return 0;
		}
		x = x xor y;
		y = y xor x;
		x = x xor y;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		return 0;
}