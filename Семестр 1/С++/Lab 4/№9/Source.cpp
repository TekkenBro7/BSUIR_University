#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
	long double a;
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
	int size, diagonal_1 = 0, diagonal_2 = 0, diagonal_3 = 0, diagonal_4 = 0, ben = 0, vibor;
	setlocale(LC_ALL, "ru");
	std::cout << "Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел. Необходимо определить диагональ с\nнаибольшей суммой чисел.\n";
	std::cout << "Выполнил: Снежко Максим Андреевич(группа 253505)" << '\n';
	std::cout << "Введите размер массив" << " ";
	size = proverka();
	long*** arr = NULL;
	arr = (long***)malloc(size * sizeof(long**));
	for (int i = 0; i < size; i++)
		arr[i] = (long**)malloc(size * sizeof(long*));
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = (long*)malloc(size * sizeof(long));

	std::cout << "Нажмите 1, чтобы ввести элементы самому\nНажмите 2, чтобы ввести элементы через рандом\nНажмите 0, чтобы Завершить программу\n";
	vibor = proverka3();
	if (vibor == 0)
		exit(0);
	else if (vibor == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					arr[i][j][k] = proverka1();
				}
			}
		}
	}
	else if (vibor == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					arr[i][j][k] = rand() % 10;
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		diagonal_1 += arr[i][i][i];
		diagonal_2 += arr[size - i - 1][i][i];
		diagonal_3 += arr[i][size - i - 1][i];
		diagonal_4 += arr[i][i][size - i - 1];
	}
	std::cout << "d1 = " << diagonal_1 << '\n' <<
		"d2 = " << diagonal_2 << '\n' <<
		"d3 = " << diagonal_3 << '\n' <<
		"d4 = " << diagonal_4 << '\n';
	if (diagonal_1 > diagonal_2 && diagonal_1 > diagonal_3 && diagonal_1 > diagonal_4)
		std::cout << "Наибольшая диагональ = " << diagonal_1;
	else if (diagonal_2 > diagonal_1 && diagonal_2 > diagonal_3 && diagonal_2 > diagonal_4)
		std::cout << "Наибольшая диагональ = " << diagonal_2;
	else if (diagonal_3 > diagonal_1 && diagonal_3 > diagonal_2 && diagonal_3 > diagonal_4)
		std::cout << "Наибольшая диагональ = " << diagonal_3;
	else if (diagonal_4 > diagonal_1 && diagonal_4 > diagonal_2 && diagonal_4 > diagonal_3)
		std::cout << "Наибольшая диагональ = " << diagonal_4;
	else
		std::cout << "Наибольшая диагональ = " << diagonal_4;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			free(arr[i][j]);
	for (int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
	return 0;
}









/*  int*** arr = (int***)malloc(size * sizeof(int**));
for (int i = 0; i < size; i++)
{
	arr[i] = (int**)malloc(size * sizeof(int*));
	for (int j = 0; j < size; j++)
	{
		arr[i][j] = (int*)malloc(size * sizeof(int));
	}
}


int*** arr = new int** [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int* [size];
		for (int j = 0; j < size; j++)
			arr[i][j] = new int[size];
	}











for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			free(arr[i][j]);
			free(arr[i]);
		}
	}
	free(arr);




		for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			delete[] arr[i][j];
		delete[] arr[i];
	}
	delete[] arr;




*/