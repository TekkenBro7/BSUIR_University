#include <iostream>
int main()
{
	int rows, cols;
	std::cin >> rows >> cols;
	int** arrA = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arrA[i] = new int[cols];
	}
	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			std::cin >> arrA[j][k];
		}
	}
	int** arrB = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arrB[i] = new int[cols];
	}
	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			arrB[j][k] = arrA[j][k];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k <= i; k++)
			{
				for (int b = 0; b <= j; b++)
				{
					if (arrA[k][b] > arrB[i][j])
					{
						arrB[i][j] = arrA[k][b];
					}
				}
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arrB[i][j] << " ";
		}
		std::cout << '\n';
	}
	for (int i = 0; i < rows; i++)
		delete[] arrA[i];
	for (int i = 0; i < rows; i++)
		delete[] arrB[i];
	delete[] arrA;
	delete[] arrB;

	return 0;
}