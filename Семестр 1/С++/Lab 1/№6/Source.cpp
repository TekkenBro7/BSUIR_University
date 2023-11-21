#include <iostream>
#include <cmath>
#include <iso646.h>
int main() {
	double S, A, b, D, Y, K, C, Q, T, x, k{}, p, n, y, z, m, d, B, h;
	int variant;
	std::cout << "Select your variant" << std::endl;
	std::cin >> variant;
	switch (variant)
	{
	case 1:
		std::cout << "Write D, x" << std::endl;
		std::cin >> D >> x;
		b = x + D;
		A = D * x / b;
		S = (A * A + b * cos(x)) / (D * D * D + (A + D - b));
			std::cout << S << std::endl;
			if (D * D * D + (A + D - b) == 0)
			{
				std::cout << "Error";
				return 0;
			}
		break;

	case 2:
		std::cout << "Write x, p, K, D, C" << std::endl;
		std::cin >> x >> p >> K >> D >> C;
		A = x + sin(p);
		B = exp(k);
		Y = 1 + pow(K, 2) / (2 * A * B) - B + D * C;
		std::cout << Y;
		break;

	case 3:
		std::cout << "Write x, p, n, K, D" << std::endl;
		std::cin >> x >> p >> n >> K >> D;
		C = p-n;
		B = cos(x);
		Q = (B * B) / (K * D) + (B * C * C * C);
		std::cout << Q;
		break;

	case 4:
		std::cout << "Write x, y, z, K, C, D" << std::endl;
		std::cin >> x >> y >> z >> K >> C >> D;
		A = x - y;
		B = sqrt(z);
		T = cos(x) + (A * A) / (K - C * D) - B;
		std::cout << T;
		break;

	case 5:
		std::cout << "Write n, m, x, K" << std::endl;
		std::cin >> n >> m >> x >> K;
		A = fabs(n+m);
		D = tan(x);
		Y = 1.29 + (K / A) + D * D;
		std::cout << Y;
		break;

	case 6:
		std::cout << "Write x, y, C, A, K" << std::endl;
		std::cin >> x >> y >> C >> A >> K;
		D = fabs(C - A);
		A = x + y;
		S = 10.1 + (A / C) + (D / K * K);
		std::cout << S;
		break;

	case 7:
		std::cout << "Write x, p, h, K, C, D " << std::endl;
		std::cin >> x >> p >> h >> K >> C >> D;
		B = log(h);
		A = x - p;
		Y = 0.78 * B + (A * A * A) / (K * C * D);
		std::cout << Y;
		break;

	case 8:
		std::cout << "Write x, d, C, K " << std::endl;
		std::cin >> x >> d >> C >> K;
		B = x + exp(d);
		A = log10(x);
		Y = (A + B) - (C * C / K);
		std::cout << Y;
		break;

	case 9:
		std::cout << "Write x, z, p, K, C, D" << std::endl;
		std::cin >> x >> z >> p >> K >> C >> D;
		B = fabs(p - x);
		A = sin(x) - z;
		Y = (A + B) * (A + B) - (K / C * D);
		std::cout << Y;
		break;

	case 10:
		std::cout << "Write x, k, z, D, C" << std::endl;
		std::cin >> x >> k >> z >> D >> C;
		B = sqrt(z);
		A = log(x) - k;
		Y = D * D + (C * C / 0.75 * A) + B;
		std::cout << Y;
		break;

	default:
		std::cout << "Error, bad input";
		break;

	}
	return 0;
}