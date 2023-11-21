#include <iostream>
#include <time.h>

int proverka() {
	int a;
	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	while (a <= 0)
	{
		std::cout << "Error" << '\n';
		std::cin >> a;
	}
	return a;
}
int proverka1() {
	int a;
	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	return a;
}
int proverka3()
{
	int a;

	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	while (a < 0 || a > 2)
	{
		std::cout << "Error" << '\n';
		std::cin >> a;
	}
	return a;

}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int  N, sum = 0, summ = 0, vibor;
	std::cout << "Память для массива выделить динамически. Дана целочисленная матрица порядка N. Найти сумму наименьших элементов ее нечетных строк и наибольших элементов ее четных строк" << '\n';
	std::cout << "Выполнил: Снежко Максим Андреевич(группа 253505)" << '\n';
	std::cout << "Вариант 10" << '\n';
	std::cout << "Введите порядок матрицы N: ";
	N = proverka();
	int** mass = new int* [N];
	for (int i = 0; i < N; i++)
	{
		mass[i] = new int[N];
	}
	std::cout << "Нажмите 1, чтобы ввести элементы самому\nНажмите 2, чтобы ввести элементы через рандом\nНажмите 0, чтобы Завершить программу\n";
	vibor = proverka3();
	if (vibor == 0)
		exit(0);
	else if (vibor == 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				mass[i][j] = proverka1();
			}
		}
	}
	else if (vibor == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				mass[i][j] = rand() % 10;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << mass[i][j] << '\t';
		}
		std::cout << '\n';
	}
	for (int i = 0; i < N; i += 2)
	{
		int min = mass[i][0];
		for (int j = 0; j < N; j++)
		{
			if (mass[i][j] < min)
			{
				min = mass[i][j];
			}
		}
		summ += min;
	}
	std::cout << '\n' << "Cумма наименьших элементов нечетных строк: " << summ << '\n';
	for (int i = 1; i < N; i += 2)
	{
		int max = mass[i][0];
		for (int j = 0; j < N; j++)
		{
			if (mass[i][j] > max)
			{
				max = mass[i][j];
			}
		}
		sum += max;
	}
	std::cout << "Cумма наибольших элементов четных строк: " << sum << '\n';
	for (int i = 0; i < N; i++)
		delete[] mass[i];
	return 0;
}