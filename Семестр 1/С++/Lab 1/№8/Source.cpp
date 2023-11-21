#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	int h1, min1, h2, min2, minS, minE, minA, h3, min3;
	std::cout << "Write h1, min1, h2, min2" << std::endl;
	std::cin >> h1 >> min1 >> h2 >> min2;
	if (h1 >= 24 or h1 < 0 or h2 >= 24 or h2 < 0)
	{
		std::cout << "Error";
		return 0;
	}
	if (min1 >= 60 or min1 < 0 or min2 >= 60 or min2 < 0)
	{
		std::cout << "Error";
		return 0;
	}
	if (h1 > h2)
	{
		minS = h1 * 60 + min1; // Min start
		minE = h2 * 60 + min2; // Min end
		minA = 1440 - abs(minE - minS); // All min worked
		h3 = minA / 60;
		min3 = minA - h3 * 60;
		std::cout << "Time - " << h3 << " " << min3;
	}
	else {


		minS = h1 * 60 + min1; // Min start
		minE = h2 * 60 + min2; // Min end
		minA = abs(minE - minS); // All min worked
		h3 = minA / 60;
		min3 = minA - h3 * 60;
		std::cout << "Time - " << h3 << " " << min3;
	}
	return 0;
}