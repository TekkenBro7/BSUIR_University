#include <iostream>

int main() {
	double d, e = 0.001, sum = 0.0;
 	int n = 1;
	do {
		d = powl((double)1 / 2, n) + powl((double)1 / 3, n);
		sum += d;
		n++;
	} 
	while (abs(d) >= e);
	std::cout << sum;

	return 0;

}