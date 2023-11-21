#include "pch.h"

long long amount0(long long** arr, long long n, long long k, long long amount)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (arr[i][j] == 0)
			{
				amount++;
			}
		}
	}
	return amount;
}

TEST(Test1, number1)
{
	long long n = 3, k = 3, amount = 0;
	long long** arr = new long long* [n];
	for (int i = 0; i < k; i++)
		arr[i] = new long long[k];
	arr[0][0] = 1; arr[0][1] = 0; arr[0][2] = 3;
	arr[1][0] = 4; arr[1][1] = 5; arr[1][2] = 6;
	arr[2][0] = 7; arr[2][1] = 8; arr[2][2] = 9;
	ASSERT_EQ(amount0(arr, n, k, amount), 1);
}

TEST(Test2, number2)
{
	long long n = 2, k = 2, amount = 0;
	long long** arr = new long long* [n];
	for (int i = 0; i < k; i++)
		arr[i] = new long long[k];
	arr[0][0] = 1; arr[0][1] = 3;
	arr[1][0] = 5; arr[1][1] = 11;
	ASSERT_EQ(amount0(arr, n, k, amount), 0);
}

TEST(Test3, number3)
{
	long long n = 3, k = 3, amount = 0;
	long long** arr = new long long* [n];
	for (int i = 0; i < k; i++)
		arr[i] = new long long[k];
	arr[0][0] = 3; arr[0][1] = 0; arr[0][2] = 12;
	arr[1][0] = 1; arr[1][1] = 5; arr[1][2] = 5;
	arr[2][0] = 0; arr[2][1] = 7; arr[2][2] = 9;
	ASSERT_EQ(amount0(arr, n, k, amount), 2);
}