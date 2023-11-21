#include <iostream>
#include <iomanip>

using namespace std;

const int n = 5;

double* gauss1(double A[n][n], double* b, int n)  // схема единстенного деления
{
	double* x = new double[n];
	for (int i = 0; i < n; i++)  // прямой ход, приведение к верхетреугольному виду
	{
		if (A[i][i] != 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				double q = A[j][i] / A[i][i];  // получаем q
				for (int k = i; k < n; k++)  // вычитаем i-ую строку умноженную на q из последующих строк
				{
					if (k == i)
					{
						A[j][k] = 0;  // исключение погрешности для нулевых элементов
					}
					else
					{
						A[j][k] -= q * A[i][k];
					}
				}
				b[j] -= q * b[i];
			}
		}
		else
		{
			cout << "Нельзя решить систему данным методом: ведущий элемент стал равен 0\n";
			return x;
		}
	}
	for (int i = n - 1; i >= 0; i--)  // обратный ход, получение решений уравнений
	{
		for (int j = n - 1; j > i; j--)
		{
			b[i] -= x[j] * A[i][j];
		}
		x[i] = b[i] / A[i][i];
	}
	return x;
}
double* gauss2(double A[n][n], double* b, int n)
{
	double* x = new double[n];
	for (int i = 0; i < n; i++)  //прямой ход, приведение к верхетреугольному виду
	{
		int max = abs(A[i][i]);
		int maxIndex = i;
		for (int j = i + 1; j < n; j++)  //поиск наибольшего главного элемента в столбце
		{
			if (abs(A[j][i]) > max)
			{
				maxIndex = j;
				max = abs(A[j][i]);
			}
		}
		for (int j = 0; j < n; j++)  //перестановка уравнения с наибольшим главным элементом 
		{
			swap(A[i][j], A[maxIndex][j]);
		}
		swap(b[i], b[maxIndex]);
		if (A[i][i] != 0)		// аналогично первой схеме решения
		{
			for (int j = i + 1; j < n; j++)
			{
				double q = A[j][i] / A[i][i];
				for (int k = i; k < n; k++)
				{
					if (k == i)
					{
						A[j][k] = 0;
					}
					else
					{
						A[j][k] -= q * A[i][k];
					}
				}
				b[j] -= q * b[i];
			}
		}
		else
		{
			cout << "Нельзя решить систему данным методом: ведущий элемент стал равен 0\n";
			return x;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			b[i] -= x[j] * A[i][j];
		}
		x[i] = b[i] / A[i][i];
	}
	return x;
}
double* gauss3(double A[n][n], double* b, int n) 
{
	double* x = new double[n];

	for (int i = 0; i < n; i++)  //прямой ход
	{
		double max = abs(A[i][0]);
		int maxIndexX = i;
		int maxIndexY = 0;
		for (int j = i; j < n; j++)  //поиск наибольшего элемента в матрице под текущей строкой
		{
			for (int k = 0; k < n; k++)
			{
				if (abs(A[j][k]) > max)
				{
					maxIndexX = j;
					maxIndexY = k;
					max = abs(A[j][k]);
				}
			}
		}
		for (int j = 0; j < n; j++)  //перестановка уравнения с наибольшим главным элементом
		{
			swap(A[i][j], A[maxIndexX][j]);
		}
		swap(b[i], b[maxIndexX]);
		if (A[i][maxIndexY] != 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				double q = A[j][maxIndexY] / A[i][maxIndexY];  //получаем q
				for (int k = 0; k < n; k++)  //вычитаем i-ую строку умноженную на q из последующих строк
				{
					if (k == maxIndexY)
					{
						A[j][k] = 0;  //исключение погрешности для нулевых элементов
					}
					else
					{
						A[j][k] -= q * A[i][k];
					}
				}
				b[j] -= q * b[i];
			}
		}
		else
		{
			cout << "Нельзя решить систему данным методом: элементы в оставшихся строках стали нулевыми (система не имеет единственное решение)\n";
			return x;
		}
	}
	bool* xFound = new bool[n];
	for (int i = 0; i < n; i++) 
	{
		xFound[i] = 0;
	}
	for (int i = n - 1; i >= 0; i--)  //обратный ход, получение решений уравнений
	{                   
		int curX;
		for (int j = 0; j < n; j++) 
		{
			if (A[i][j] != 0 && xFound[j] == 0) 
			{
				curX = j;
			}
			if (A[i][j] != 0 && xFound[j] == 1) 
			{
				b[i] -= x[j] * A[i][j];
			}
		}
		x[curX] = b[i] / A[i][curX];
		xFound[curX] = 1;
	}
	return x;
}


int main()
{
	setlocale(LC_ALL, "ru");
	std::cout.precision(4);	// Устанавливает точность
	std::cout.setf(std::ios::fixed, std::ios::floatfield); // Все последующие числа с плавающей точкой будут выводиться с фиксированным числом знаков после запятой
	double b[n] = { 4.2, 4.2, 4.2, 4.2, 4.2 };

	cout << 0.0392 << '\n';
	cout << -0.0780 << '\n';
	cout << 0.1915 << '\n';
	cout << 0.1511 << '\n';
	cout << 0.2926 << '\n' << '\n';

	double C[n][n] = { {0.2,0,0.2,0,0},
						{0,0.2,0,0.2,0},
						{0.2,0,0.2,0,0.2},
						{0,0.2,0,0.2,0},
						{0,0,0.2,0,0.2} };

	double D[n][n] = { {2.33,0.81,0.67,0.92,-0.53},
						{-0.53,2.33,0.81,0.67,0.92},
						{0.92,-0.53,2.33,0.81,0.67},
						{0.67,0.92,-0.53,2.33,0.81},
						{0.81,0.67,0.92,-0.53,2.33} };

	double A[n][n]{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 27 * C[i][j] + D[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "\n\n";
	int choise;
	while (true)
	{
		cout << "1. Метод Гаусса (схема единственного деления)\n";
		cout << "2. Метод Гаусса (схема частичного выбора)\n";
		cout << "3. Метод Гаусса (схема полного выбора)\n";
		cout << "4. Выход\n";
		cin >> choise;
		system("cls"); // Очистка экрана консоли
		if (choise == 1)
		{
			double* x = gauss1(A, b, n);
			for (int i = 0; i < n; i++)
			{
				cout << x[i] << "\n";
			}
			return 0;
		}
		else if (choise == 2)
		{
			double* x = gauss2(A, b, n);
			for (int i = 0; i < n; i++)
			{
				cout << x[i] << "\n";
			}
			return 0;
		}
		else if (choise == 3)
		{
			double* x = gauss3(A, b, n);
			for (int i = 0; i < n; i++)
			{
				cout << x[i] << "\n";
			}
			return 0;
		}
		else if (choise == 4)
		{
			return 0;
		}
	}
}
