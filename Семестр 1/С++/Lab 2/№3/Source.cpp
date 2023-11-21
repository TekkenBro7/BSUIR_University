#include <iostream>
using namespace std;

int main() {
	double X, Y, A, B, C, K;
	cout << "Write X, Y, A, B, C, K" << '\n';
	cin >> X >> Y >> A >> B >> C >> K;
	if (X < Y) {
		cout << "0 " << Y << '\n';
	}
	else if (X > Y) {
		cout << X << " 0" << '\n';
	}
	else {
		cout << "0 0" << '\n';
	}
	if (A > B && A > C) {
		cout << A - K <<" " << B << " " << C;
	}
	if (B > A && B > C) {
		cout << A << " " << B - K << " " << C;
	}
	if (C > B && C > A) {
		cout << A  << " " << B << " " << C - K;
	}

	return 0;
}
