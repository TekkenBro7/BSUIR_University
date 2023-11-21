#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n, col, row, a, x, y;
	cin >> n;
	x = sqrt(n);
	y = sqrt(n + 1);
	a = n - x * x;
	if (a == 0)
	{
		row = sqrt(n) - 1;
		col = 0;
		cout << row << " " << col;
		return 0;
	}

	else if (y > x)
	{
		col = sqrt(n);
		row = 1;
		cout << col << " " << row;
		return 0;
	}
	else if ((a <= sqrt(n) + 1))
	{
		row = sqrt(n);
		col = n - powl(row, 2) - 1;
		cout << col << " " << row;
		return 0;
	}
	else
	{
		col = sqrt(n);
		row = n - powl(col, 2) - col;
		cout << col << " " << row;
	}
	return 0;
}