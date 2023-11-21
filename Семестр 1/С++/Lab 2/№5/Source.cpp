#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	long double K, X, Y;
	cin >> K >> X >> Y;
	cout << setprecision(22);
	if (K > 0) {
		if (X <= K && X > 0 && Y > K) {         // ябепус бмхг
			cout << fabs(Y - K);
			return 0;
		}
		else if (X <= K && X > 0 && Y < 0) {        // ямхгс ббепу
			cout << fabs(Y);
			return 0;
		}
		else if (X == K && Y == K or X == 0 && Y == 0) { // мю йбюдпюре
			cout << "0";
			return 0;
		}
		else if (X <= K && X < 0 && Y > 0) {            // якебю мюопюбн
			cout << fabs(X);
			return 0;
		}
		else if (X >= K && Y <= K && Y > 0) {  // яопюбю бкебн
			cout << fabs(X - K);
			return 0;
		}
		else if (X == 0 && Y > 0 && Y > K) {   // ябепус бмхг
			cout << Y - K;
			return 0;
		}
		else if (X == 0 && Y < 0 && Y < K) {            // ямхгс ббепу
			cout << fabs(Y);
			return 0;
		}
		else if (X > K && X > 0 && Y > K && Y > 0) {     // охтюцнп яопюбю ббепу   FDFDFFDFFD
			cout << sqrt((X - K) * (X - K) + (Y - K) * (Y - K));
			return 0;
		}
		else if (X > K && X > 0 && Y < K && Y < 0) {    // охтюцнп яопюбю бмхг
			cout << sqrt((X - K) * (X - K) + Y * Y);
			return 0;
		}
		else if (X < K && X < 0 && Y < K && Y < 0) {    // охтюцнп ямхгс якебю
			cout << sqrt(X * X + Y * Y);
			return 0;
		}
		else if (X < K && X < 0 && Y > K && Y > 0) {    // охтюцнп ябепгс якебю
			cout << sqrt(X * X + (Y - K) * (Y - K));
			return 0;
		}
		else if (X < K && Y < K && X > 0 && Y > 0 && ((K - X == 1) || (K - Y == 1))) {  // бмсрпх
			cout << "1";
			return 0;
		}

		else if (X < K && Y < K && X > 0 && Y > 0 && (K - X) < (K - Y)) {  // бмсрпх
			cout << Y;
			return 0;
		}
		else if (X < K && Y < K && X > 0 && Y > 0 && (K - Y) < (K - X)) {  // бмсрпх
			cout << X;
			return 0;
		}
		else if (X == 0 && Y <= K && Y > 0) {  // бмсрпх
			cout << "0";
			return 0;
		}
		else if (Y == 0 && X <= K && X > 0) {  // бмсрпх
			cout << "0";
			return 0;
		}

	}


	if (K < 0) {

		if (X < 0 && Y > 0 && X >= K) {         // ябепус бмхг
			cout << fabs(Y);
			return 0;
		}
		else if (X < 0 && Y < 0 && X >= K && Y < K) {        // ямхгс ббепу
			cout << fabs(Y - K);
			return 0;
		}
		else if (X == K && Y == K or X == 0 && Y == 0) { // мю йбюдпюре
			cout << "0";
			return 0;
		}
		else if (X < 0 && Y < 0 && Y >= K && X < K) {            // якебю мюопюбн
			cout << fabs(X - K);
			return 0;
		}
		else if (X > 0 && Y < 0 && Y >= K) {  // яопюбю бкебн
			cout << fabs(X);
			return 0;
		}
		else if (X > 0 && Y > 0 && Y > K && Y > 0) {     // охтюцнп яопюбю ббепу
			cout << sqrt(X * X + Y * Y);
			return 0;
		}
		else if (X > 0 && Y < 0 && Y < K) {    // охтюцнп яопюбю бмхг
			cout << sqrt(X * X + (Y - K) * (Y - K));
			return 0;
		}
		else if (X < 0 && Y < 0 && X < K && Y < K) {    // охтюцнп ямхгс якебю
			cout << sqrt((X - K) * (X - K) + (Y - K) * (Y - K));
			return 0;
		}
		else if (X < 0 && Y > 0 && X < K) {    // охтюцнп ябепгс якебю
			cout << sqrt((X - K) * (X - K) + Y * Y);
			return 0;
		}
		else if (X == 0 && Y < K && Y < 0) {  // Cмхгс ббепу
			cout << fabs(Y - K);
			return 0;
		}
		else if (X == 0 && Y > 0) {       // Cбепус бмхг
			cout << Y;
			return 0;
		}
		else if (Y == 0 && X < K && X < 0) {   // ямхгс ббепу
			cout << fabs(X - K);
			return 0;
		}
		else if (Y == 0 && X > 0) {  // яопюбю бкебн
			cout << X;
			return 0;
		}
		else if (X > K && Y > K && X < 0 && Y < 0 && ((-K - X == 1) || (-K - Y == 1))) {  // бмсрпх
			cout << "1";
			return 0;
		}
		else if (X > K && Y > K && X < 0 && Y < 0 && fabs(X - K) < fabs(Y - K)) {  // бмсрпх
			cout << fabs(X - K);
			return 0;
		}
		else if (X > K && Y > K && X < 0 && Y < 0 && fabs(Y - K) < fabs(X - K)) {  // бмсрпх
			cout << fabs(Y - K);
			return 0;
		}
		else if (X == 0 && Y >= K && Y < 0) {  // бмсрпх
			cout << "0";
			return 0;
		}
		else if (Y == 0 && X >= K && X < 0) {  // бмсрпх
			cout << 0;
		}

	}

	return 0;
}