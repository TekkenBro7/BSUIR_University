#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	long double a, b, c, x, y;
	cout << "¬ведите a, b, c, x, y";
	cin >> a >> b >> c >> x >> y;
	if (a < 0 or b < 0 or c < 0 or x < 0 or y < 0) {
		cout << "Incorrect input";
		return 0;
	}
	if (x >= a and y >= b or x >= b and y >= a) {
		cout << "YES";
		return 0;
	}
	else if (x >= b and y >= c or x >= c and y >= b) {
		cout << "YES";
		return 0;
	}
	else if (x >= c and y >= a or x >= a and y >= c) {
		cout << "YES";
		return 0;
	}
	else cout << "NO";

	return 0;
}