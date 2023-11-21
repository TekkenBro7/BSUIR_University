#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	long double A = 0.0, M = 20.0, B, H, y, x;
	const long double pi = 3.141592653589793;
	int i = 0;
	B = pi / 2.0;
	H = (B - A) / M;
	x = A + i * H;
	for (; x >= A && x < B; i++)
	{
		x = A + i * H;
		y = sinl(x) - cosl(x);
		std::cout << y << '\n';
	}
	return 0;
}