#include<iostream>
#include<iomanip>

using namespace std;

long long proverka() {
	long long a;
	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	while (a <= 0 || a == 2)
	{
		std::cout << "Данного квадрата не существует, введите заного" << '\n';
		std::cin >> a;
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	long long n;
	std::cout << "Магический квадрат" << '\n';
	std::cout << "Выполнил: Снежко Максим Андреевич(группа 253505)" << '\n';
	cout << "Введите порядок квадрата: ";
	n = proverka();
	long long constanta;
	constanta = n * (n * n + 1) / 2;
	std::cout << "Магическая константа: " << constanta << '\n';
	long long** arr = (long long**)calloc(n, sizeof(long long*));;
	for (int i = 0; i < n; i++) {
		arr[i] = (long long*)calloc(n, sizeof(long long));
	}
	if (n % 2 == 1)
	{
		std::cout << "Квадрат порядка одинарной четности" << '\n' << '\n';
		long long x = 0, y = n / 2;
		arr[x][y] = 1;

		for (int i = 2; i <= n * n; i++)
		{

			if (x == 0 && y == n - 1)
			{
				x++;
			}
			else if (x == 0 && y != n - 1)
			{
				x = n - 1;
				y++;
			}
			else if (x != 0 && y == n - 1)
			{
				x--;
				y = 0;
			}
			else if (arr[x - 1][y + 1] != 0)
			{
				x++;
			}
			else
			{
				x--;
				y++;
			}
			arr[x][y] = i;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << " ";
			cout << "\n";
		}
	}
	else if (n % 2 == 0 && n % 4 != 0)
	{
		std::cout << "Квадрат порядка двойной четности" << '\n' << '\n';
		long long x = 0, y = n / 4;

		// 1 квадрат 
		arr[x][y] = 1;
		for (long long i = 2; i <= n * n / 4; i++)
		{
			if (x == 0 && y == n / 2 - 1)
			{
				x++;
			}
			else if (x == 0 && y < n / 2)
			{
				x = n / 2 - 1;
				y++;
			}
			else if (y == n / 2 - 1 && x != 0 && x < n / 2)
			{
				y = 0;
				x--;
			}
			else if (arr[x - 1][y + 1] != 0)
			{
				x++;
			}
			else
			{
				x--;
				y++;
			}
			arr[x][y] = i;
		}

		// 2 квадрат
		x = 0, y = 3 * n / 4;
		arr[x][y] = 1 + n * n / 2;
		for (long long i = 2 + n * n / 2; i <= 3 * n * n / 4; i++)
		{
			if (x == 0 && y == n - 1)
			{
				x++;
			}
			else if (x == 0 && y != n - 1 && y >= n / 2)
			{
				x = n / 2 - 1;
				y++;

			}
			else if (y == n - 1 && x != 0 && x < n / 2)
			{
				y = n / 2;
				x--;
			}
			else if (arr[x - 1][y + 1] != 0)
			{
				x++;
			}
			else
			{
				x--;
				y++;
			}
			arr[x][y] = i;
		}

		// 3 квадрат
		x = n / 2, y = n / 4;
		arr[x][y] = 1 + 3 * n * n / 4;
		for (long long i = 2 + 3 * n * n / 4; i <= n * n; i++)
		{
			if (x == n / 2 && y == n / 2 - 1)
			{
				x++;
			}
			else if (x == n / 2 && y < n / 2)
			{
				x = n - 1;
				y++;
			}
			else if (y == n / 2 - 1 && x > n / 2)
			{
				y = 0;
				x--;
			}
			else if (arr[x - 1][y + 1] != 0)
			{
				x++;
			}
			else
			{
				x--;
				y++;
			}
			arr[x][y] = i;
		}

		//4 квадрат
		x = n / 2, y = 3 * n / 4;
		arr[x][y] = 1 + n * n / 4;
		for (long long i = 2 + n * n / 4; i <= n * n / 2; i++)
		{
			if (x == n / 2 && y == n - 1)
			{
				x++;
			}
			else if (x == n / 2 && y != n - 1 && y >= n / 2)
			{
				x = n - 1;
				y++;
			}
			else if (y == n - 1 && x > n / 2)
			{
				y = n / 2;
				x--;
			}
			else if (arr[x - 1][y + 1] != 0)
			{
				x++;
			}
			else
			{
				x--;
				y++;
			}
			arr[x][y] = i;
		}
		long long* dop1 = (long long*)malloc(n * sizeof(long long));    //Доп массив для перестановски(главная диагональ)
		for (int i = 0; i <= n / 4; i++)
		{
			dop1[i] = arr[i][i];
			arr[i][i] = arr[n / 2 + i][i];
			arr[n / 2 + i][i] = dop1[i];
		}
		long long* dop2 = (long long*)malloc(n * sizeof(long long));    //Доп массив для перестановски(Побочная тип)
		for (int i = n / 4 + 1; i < n / 2; i++)
		{
			for (int j = n / 4 - 1; j >= 0; j--)
			{
				dop2[j] = arr[i][j];
				arr[i][j] = arr[n - 1 - j][j];
				arr[n - 1 - j][j] = dop2[j];
			}
		}
		for (long long i = 0; i < n; i++)
		{
			for (long long j = 0; j < n; j++)
				cout << arr[i][j] << "\t";
			cout << "\n";
		}
		free(dop1);
		free(dop2);
	}

	else if (n % 4 == 0)
	{
		std::cout << "Квадрат нечетного порядка" << '\n' << '\n';
		int da = n / 4;
		int nomer = 0, nom = 0;

		for (int i = 0; i < da; i++)
			for (int j = 0; j < da; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					arr[4 * i + k][(j * 4) + k] = 0;
					arr[(i + 1) * 4 - k - 1][(j * 4) + k] = 0;
				}
			}
		for (int i = n - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--)
			{
				nomer++;
				if (arr[i][j] == 0)
					arr[i][j] = nomer;
			}
		for (int i = 0; i < da; i++)
			for (int j = 0; j < da; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					arr[4 * i + k][(j * 4) + k] = 0;
					arr[(i + 1) * 4 - k - 1][(j * 4) + k] = 0;
				}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				nom++;
				if (arr[i][j] == 0)
					arr[i][j] = nom;
			}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << " ";
			cout << "\n";
		}

	}
	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

	return 0;
}