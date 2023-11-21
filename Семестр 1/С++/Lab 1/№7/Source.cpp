#include <iostream>
#include <iomanip>
#include <cmath>
int main() {
	double x1, y1, x2, y2, x3, y3, d1, d2, d3, h1, h2, h3, P, p, S1, m1, m2, m3, b1, b2, b3, R, r, Cvp, Svp, Cop, Sop, S2, Rd1, Dd1, Rd2, Dd2, Rd3, Dd3, S3, pi = 3.141592653;
	std::cout << "Write x1, y1, x2, y2, x3, y3" << std::endl;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	std::cout << std::setprecision(5);

	// Sides
	d1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // First side
	d2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)); // Second side
	d3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)); // Third side

	// Area(Geron) P - perimetr  p - polyperimetr
	P = d1 + d2 + d3;
	p = P / 2;
	S1 = sqrt(p * (p - d1) * (p - d2) * (p - d3));

	// Heights
	h1 = 2 * S1 / d1;
	h2 = 2 * S1 / d2;
	h3 = 2 * S1 / d3;

	// Medians
	m1 = sqrt(2 * (d2 * d2 + d3 * d3) - d1 * d1) / 2;
	m2 = sqrt(2 * (d1 * d1 + d3 * d3) - d2 * d2) / 2;
	m3 = sqrt(2 * (d1 * d1 + d2 * d2) - d3 * d3) / 2;

	// Bisectors
	b1 = 2 * sqrt(d2 * d3 * p * (p - d1)) / (d2 + d3);
	b2 = 2 * sqrt(d1 * d3 * p * (p - d2)) / (d1 + d3);
	b3 = 2 * sqrt(d2 * d1 * p * (p - d3)) / (d2 + d1);

	// Radians and degrees
	Rd1 = acos((d3 * d3 + d1 * d1 - d2 * d2) / (2 * d3 * d1));
	Dd1 = Rd1 * 180 / pi;
	Rd2 = acos((d1 * d1 + d2 * d2 - d3 * d3) / (2 * d1 * d2));
	Dd2 = Rd2 * 180 / pi;
	Rd3 = acos((d2 * d2 + d3 * d3 - d1 * d1) / (2 * d2 * d3));
	Dd3 = Rd3 * 180 / pi;

	// Radius op and vp
	R = (d1 * d2 * d3) / (4 * sqrt(p * (p - d1) * (p - d2) * (p - d3)));
	r = S1 / p;

	// Length and area op and vp
	Cvp = 2 * pi * r;
	Svp = pi * r * r;
	Cop = 2 * pi * R;
	Sop = pi * R * R;

	// Area(h) (grad)
	S2 = d1 * h1 / 2;
	S3 = (d2 * d1 * d3) / (2 * 2 * R);
	// Cout sides
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;

	// Cout height
	std::cout << h1 << std::endl;
	std::cout << h2 << std::endl;
	std::cout << h3 << std::endl;

	// Ñout medians
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m3 << std::endl;

	// Cout bisectors
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	// Cout rad and grad
	std::cout << Rd1 << " ";
	std::cout << Dd1 << std::endl;
	std::cout << Rd2 << " ";
	std::cout << Dd2 << std::endl;
	std::cout << Rd3 << " ";
	std::cout << Dd3 << std::endl;

		// Cout radius op and vp
	std::cout << R << std::endl;
	std::cout << r << std::endl;

		// Cout length and area op and vp
	std::cout << Cvp << std::endl;
	std::cout << Svp << std::endl;
	std::cout << Cop << std::endl;
	std::cout << Sop << std::endl;

		// Cout area and perimeter
	std::cout << "Square of triangle = " << S1 << " or " << S2 << " or " << S3 << std::endl;
	std::cout << P;
	return 0;
}