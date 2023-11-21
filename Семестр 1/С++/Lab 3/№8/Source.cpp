#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int length, x, a, k, s;
	cin >> x;

	for (int i = 1; i < x; i++) {
		a = 1;
		length = 0;
		s = 0;

		while (i / a != 0) {
			length++;
			a *= 10;
		}
		
		for (int j = 0; j < length; j++) {
			 k = i % (int) pow(10, j+1) / (int) pow(10, j);
			 s += (int)powl(k, length);
		}

		if (s == i) cout << s << endl;
	}

	return 0;
}