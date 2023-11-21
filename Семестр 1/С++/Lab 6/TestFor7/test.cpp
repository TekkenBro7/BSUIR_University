#include "pch.h"

long long answ(std::string arr)
{
	int n = arr.size();
	int mid = n / 2;
	int count = 0;
	int count1 = 0;
	if (n == 1)
	{
		return -1;
	}
	else if (n == 2 && arr[0] == arr[1])
	{
		return -1;
	}
	for (int i = 0; i <= mid; i++)
	{
		if (arr[i] == arr[n - i - 1])
		{
			count++;
		}
	}
	if (count == mid)
	{
		return n;
	}

	for (int i = 0; i <= mid; i++)
	{
		if (arr[i] == arr[n - i - 1])
		{
			count = 1;
		}
		if (arr[0] != arr[n - 1])
		{
			return n;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count1++;
		}
	}
	if (count1 == n - 1)
	{
		return -1;
	}
	if (count == 1)
	{
		return n - 1;
	}
	if (count == 0)
	{
		return n;
	}
}

TEST(TestCaseName1, TestName1)
{
	std::string arr = "qqq";
	ASSERT_EQ(answ(arr), -1);
}
TEST(TestCaseName2, TestName2)
{
	std::string arr = "aba";
	ASSERT_EQ(answ(arr), 2);
}
TEST(TestCaseName3, TestName3)
{
	std::string arr = "avcdg";
	ASSERT_EQ(answ(arr), 5);
}