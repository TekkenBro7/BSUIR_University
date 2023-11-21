#include <iostream>

using namespace std;
int main()
{
	int N, M, L = 0;
	cin >> N;
	int** mass = new int* [N];    // ќбъ€вление первого динамического массива
	for (int i = 0; i < N; i++)
	{
		mass[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> mass[i][j];
		}
	}
	cin >> M;
	int** mas = new int* [M];     // ќбъ€вление второго динамического массива
	for (int i = 0; i < N; i++)
	{
		mas[i] = new int[M];
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> mas[i][j];
		}
	}
	int** mass3 = new int* [N];   // ќбъ€вление третьего динамического массива
	for (int i = 0; i < N; i++)
	{
		mass3[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			mass3[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				mass3[i][j] += mass[i][k] * mas[k][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << mass3[i][j];
			if (i == L && j == M - 1)
			{
				continue;
			}
			std::cout << " ";
		}
		L++;
		if (i == N - 1)
		{
			continue;
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++)
	{
		delete[] mass[i];
	}
	for (int i = 0; i < M; i++)
	{
		delete[] mas[i];
	}
	for (int i = 0; i < N; i++)
	{
		delete[] mass3[i];
	}
	delete[] mass;
	delete[] mas;
	delete[] mass3;

	return 0;
}
