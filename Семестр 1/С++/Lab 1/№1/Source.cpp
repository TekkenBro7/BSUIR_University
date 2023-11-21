#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double x, a, b, c, n1, n2;
	cin >> x;
	cout << setprecision(5);
	a = x * x;
	b = 69 * a + 8;
	c = x * (23 * a + 32);
	cout << b + c << endl;
	cout << b - c;
	return 0;
}


