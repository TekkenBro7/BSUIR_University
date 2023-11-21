#include <iostream>
#include <iomanip>
int main() {
	double a, b, c, d, Z;
	std::cin >> a >> b >> c >> d;
	std::cout << std::setprecision(19);
	if (c == 0) {
		std::cout << "ERROR";
		return 0;
	}
	if (c >= d && a < d || c < d && a >= d) {
		if (c >= d && a < d) {
			Z = a + b / c;
			std::cout << Z;
		}
		
			if (c < d && a >= d) {
				Z = a - b / c;
				std::cout << Z;
			}
	}
	else {
	std::cout << "0";
	}

	return 0;
}

