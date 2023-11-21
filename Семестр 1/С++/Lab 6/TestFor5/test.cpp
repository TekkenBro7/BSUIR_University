#include "pch.h"


long long answ(long long AllLength, long long m, std::string string1, std::string string2)
{
	std::string string3, string4;
	long long answer = 0;
	long long length = string1.length() + string2.length();  // Размер длины суффикса и префикса
	long  long raznost = AllLength - length;

	if (length < AllLength)           // Если сумма длин суффикса и постфикса меньше всей длины
	{

		answer = 1;
		for (int i = 0; i < (raznost) % m; i++)
		{
			answer *= 26;        // Количетсов неизвестных символов которых может быть
			answer %= m;
		}
		if (string1 != string2)
		{
			answer *= 2;         // Допустим, cup может пусть суффиксом или префиксом
		}
		answer %= m;
	}
	else if (length > AllLength)
	{
		long long pos;
		string3 = string1;
		string4 = string2;
		for (int i = 0; i < string3.length(); i = 0)
		{
			pos = string4.find(string3, 0);
			if (pos == 0)
			{
				string4.erase(pos, string3.length());     // Если найдем общее между строк, то удалить общее
				break;
			}
			else
			{
				string3.erase(0, 1);                      // Иначе обрезать лево
			}
		}
		string3 = string1 + string4;
		if (string3.length() <= AllLength)
		{
			answer++;
		}
		string4 = string2;
		for (int i = 0; i < string4.length(); i = 0)
		{
			pos = string1.find(string4, 0);              // Это для обратного случая decup, потом codec
			if (pos == 0)
			{
				string1.erase(pos, string4.length());
				break;
			}
			else string4.erase(0, 1);
		}
		string4 = string1 + string2;
		if (string4.length() <= AllLength)
		{
			answer++;
		}
	}
	else if (length == AllLength)            // Если длина префикса и суффикса равна всей длине
	{
		answer = 1;
	}

	return answer;
}

TEST(TestCaseName1, TestName1) 
{
	long long AllLength = 14;
	long long m = 1000;
	std::string string1 = "cup";
	std::string string2 = "russia";
	ASSERT_EQ(answ(AllLength, m, string1, string2), 752);
}

TEST(TestCaseName2, TestName2)
{
	long long AllLength = 7;
	long long m = 123;
	std::string string1 = "russian";
	std::string string2 = "codecap";
	ASSERT_EQ(answ(AllLength, m, string1, string2), 0);
}

TEST(TestCaseName3, TestName3)
{
	long long AllLength = 7;
	long long m = 15;
	std::string string1 = "codec";
	std::string string2 = "decup";
	ASSERT_EQ(answ(AllLength, m, string1, string2), 1);
}