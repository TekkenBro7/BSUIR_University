#include "pch.h"
#include <string>

long long answ(std::string arr)
{
	long long chislitel = 1, n = arr.size();
	for (int i = 1; i <= arr.size(); i++)
	{
		chislitel *= i;
	}
	for (int i = 0; i < n; i++)
	{
		long long count = 1;
		for (int k = i + 1; k < n; k++)
		{
			if (arr[i] == arr[k])
			{
				count++;
			}
		}
		chislitel /= count;
	}

	return chislitel;
}

TEST(TestCaseName1, TestName1)
{
	std::string arr = "SOLO";
	ASSERT_EQ(answ(arr), 12);
}
TEST(TestCaseName2, TestName2)
{
	std::string arr = "SSOOOLL";
	ASSERT_EQ(answ(arr), 210);
}
TEST(TestCaseName3, TestNam3)
{
	std::string arr = "QWERTTYTT";
	ASSERT_EQ(answ(arr), 15120);
}