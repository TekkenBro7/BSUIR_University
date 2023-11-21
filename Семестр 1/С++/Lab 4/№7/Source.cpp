#include <iostream>

using namespace std;

int main()
{
	double* a = new double[1000];
	int n = 0, q = 0;
	while (cin >> n) {
		a[q] = n;
		q++;
	}
	int min = 1000;
	int max = -1000;
	int imax = 0;
	int imin = 0;
	for (int i = 0; i < q; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			imin = i;
		}
		if (a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	}
	imin += 1;
	imax += 1;
	if (imax > imin)
		for (imin; imin < imax - 1; imin++)
			a[imin] = 0;
	else
		for (imax; imax < imin - 1; imax++)
			a[imax] = 0;
	std::cout << '\n';
	int count = 0;
	bool delzero = false;
	for (int i = 0; i < q; i++) {
		if (a[i] == 0) {
			count++;
		}
	}
	if (count > q / 2) {
		delzero = true;
	}
	for (int j = 0; j < q; j++) {
		if (a[j] == 0 && delzero == true) {
			continue;
		}
		std::cout << a[j] << " ";
	}
	delete[] a;

	return 0;
}