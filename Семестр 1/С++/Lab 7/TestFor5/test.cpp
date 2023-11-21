#include "pch.h"

long long chislo(long long n)
{
	return (n + 1) / 10;
}

TEST(TestCaseName1, TestName1) 
{
	long long n = 1;
	ASSERT_EQ(chislo(n), 0);
}

TEST(TestCaseName2, TestName2)
{
	long long n = 1000000000;
	ASSERT_EQ(chislo(n), 100000000);
}

TEST(TestCaseName3, TestName3)
{
	long long n = 880055535;
	ASSERT_EQ(chislo(n), 88005553);
}