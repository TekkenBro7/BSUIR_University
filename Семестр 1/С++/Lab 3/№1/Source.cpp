#include <iostream>
#include <iomanip>

int main() {
	int N=0.0;
	int i = 1, a, b;
	while (i <= 30)
	{
		if (i % 2 == 1) {
			a = i;
			b = i * i;
		}
		else if (i % 2 == 0) {
			a = i / 2;
			b = i * i * i;
		}
		N += (a - b) * (a - b);
			i++;
	}
	std::cout << N;
	return 0;
}