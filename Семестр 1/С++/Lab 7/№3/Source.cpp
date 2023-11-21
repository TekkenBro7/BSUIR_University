#include<iostream>
#include<string> 
#include <windows.h>

using namespace std;

string summa(string str1, string str2, string OsnovaniyeStr, int osnovaniye)
{
	string str3 = "0";
	int ostatok = 0, number;

	while (str1.size() < str2.size())	// O(n)
	{
		str1 = '0' + str1;
	}
	while (str2.size() < str1.size())	// O(n)
	{
		str2 = '0' + str2;
	}
	while (str3.size() < str1.size())	// O(n)
	{
		str3 = '0' + str3;
	}
	for (int i = str3.size() - 1; i >= 0; i--)	// O(n)
	{

	//	int u = OsnovaniyeStr.find(str1[i]);
	//	int o = OsnovaniyeStr.find(str2[i]);

		number = (OsnovaniyeStr.find(str1[i]) + OsnovaniyeStr.find(str2[i]) + ostatok);
		ostatok = number / osnovaniye;

	//	int n = num % osnovaniye;			// 123    123444		124122

		str3[i] = OsnovaniyeStr[number % osnovaniye];
	}
	if (ostatok == 1)
	{
		str3.insert(0, 1, OsnovaniyeStr[ostatok]);
	}

	return str3;
}
string raznost(string str1, string str2, string OsnovaniyeStr, int osnovaniye) 
{
	string str3 = "0", DopStr;
	int ostatok = 0, number;
	bool minus = 0;
	if (str1.size() < str2.size())
	{
		while (str1.size() < str2.size())	//0(n)
		{
			str1 = '0' + str1;
		}
	}
	if (str2.size() < str1.size())
	{
		while (str2.size() < str1.size())	//O(n)
		{
			str2 = '0' + str2;
		}
	}
	if (str2 > str1)
	{
		DopStr = str1;
		str1 = str2;
		str2 = DopStr;
		minus = 1;
	}

	while (str3.size() < str1.size())		// O(n) 
	{
		str3 = '0' + str3;
	}

	for (int i = str3.size() - 1; i >= 0; i--)		// O(n) 
	{
		number = OsnovaniyeStr.find(str1[i]) - OsnovaniyeStr.find(str2[i]) + ostatok;
		if (number < 0)
		{
			number += osnovaniye;
			ostatok = -1;
		}
		else
		{
			ostatok = 0;
		}
		str3[i] = OsnovaniyeStr[number];
	}

	while (str3[0] == '0' && str3.size() > 1)		// O(n)    удаление лишних нулей
	{
		str3.erase(0, 1);
	}
	if (minus == 1)     // - прибавляется в конце
	{
		str3 = '-' + str3;
	}

	return str3;
}
int check1() {
	string str;
	while (true)
	{
		cin >> str;
		if (str == "37" || str == "38" || str == "39")
		{
			std::cout << "\nНеверный ввод!\n";
			std::cout << "Попробуйте снова: ";
			continue;
		}
		if (str.size() == 1) 
		{
			if (str[0] > '0' && str[0] <= '9')
			{
				return stoi(str);
			}
			else
			{
				std::cout << "\nНеверный ввод!\n";
				std::cout << "Попробуйте снова: ";
				continue;
			}
		}
		else if (str.size() == 2)
		{
			if (str[0] >= '1' && str[0] <= '3' && str[1] >= '0' && str[1] <= '9') {
				return stoi(str);
			}
			else
			{
				std::cout << "\nНеверный ввод!\n";
				std::cout << "Попробуйте снова: ";
				continue;
			}
		}
		else
		{
			std::cout << "\nНеверный ввод!\n";
			std::cout << "Попробуйте снова: ";
			continue;
		}
	}
}
string check2(int osnovaniye)
{
	string base_str = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string proverka;
	while (true)
	{
		cin >> proverka;
		if (proverka[0] != '-')
		{
			int kolvo = 0;
			int dop = 0;
			for (int i = 0; i < proverka.size(); i++)	//O(n)
			{
				for (int q = 0; q < osnovaniye; q++)	//O(n)
				{
					if (proverka[i] == base_str[q])
					{
						kolvo++;
						break;
					}
				}
				if (kolvo == 0)
				{
					continue;
				}
				else
				{
					kolvo = 0;
					dop++;
				}
			}
			if (dop == proverka.size())
			{
				return proverka;
			}
			else
			{
				std::cout << "\nНеверный ввод!\n";
				std::cout << "Попробуйте снова: ";
			}
		}
		else
		{
			if (proverka.size() == 1 && proverka[0] == '-' || proverka.size() >= 2 && proverka[0] == '-' && proverka[1] == '0')
			{
				std::cout << "\nНеверный ввод!\n";
				std::cout << "Попробуйте снова: ";
				continue;
			}
			if (proverka.size() > 30)
			{
				std::cout << "\nНеверный ввод!\n";
				std::cout << "Попробуйте снова: ";
				continue;
			}
			int kol = 0;
			int lol = 0;
			for (int i = 1; i < proverka.size(); i++)	//O(n)
			{
				for (int q = 0; q < osnovaniye; q++)	//O(n)
				{
					if (proverka[i] == base_str[q])
					{
						kol++;
						break;
					}
				}
				if (kol == 0)
				{
					continue;
				}
				else
				{
					lol++;
				}
			}
			if (lol == proverka.size() - 1)
			{
				return proverka;
			}
			else
			{
				std::cout << "\nНеверный ввод!\n";
				std::cout << "Попробуйте снова: ";
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	cout << "Осуществить сложение и вычитание чисел в заданной системе счисления. В системах счисления больших десятичной\nиспользовать буквы по аналогии с шестнадцатеричной системой.\nРазработать функции для выполнения операции сложения и функции для выполнения операции вычитания.\n";
	cout << "Выполнил: Снежко Максим(группа 253505)\n\n";
	int x = 1;
	while (x)
	{
		int osnovaniye;
		string str1, str2, OsnovaniyeStr = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" }, sum, razn;
		cout << "Введите основание системы счисления (от 1 до 36), а за тем два числа: ";
		osnovaniye = check1();
		str1 = check2(osnovaniye);
		str2 = check2(osnovaniye);

		if (str1[0] != '-' && str2[0] != '-')                      // Если оба не отрицательные
		{
			sum = summa(str1, str2, OsnovaniyeStr, osnovaniye);
			cout << "\nСумма: " << sum;
			razn = raznost(str1, str2, OsnovaniyeStr, osnovaniye);
			cout << "\nРазность: " << razn;
		}

		else if (str1[0] == '-' && str2[0] != '-')					   // Если первый отрицательный   
		{
			str1.erase(0, 1);
			sum = raznost(str2, str1, OsnovaniyeStr, osnovaniye);
			cout << "\nСумма: " << sum;
			razn = summa(str1, str2, OsnovaniyeStr, osnovaniye);
			cout << "\nРазность: " << '-' + razn;
		}

		else if (str1[0] != '-' && str2[0] == '-')					   // Если второй отрицательный
		{
			str2.erase(0, 1);
			sum = raznost(str1, str2, OsnovaniyeStr, osnovaniye);
			cout << "\nСумма: " << sum;
			razn = summa(str1, str2, OsnovaniyeStr, osnovaniye);
			cout << "\nРазность: " << razn;
		}

		else if (str1[0] == '-' && str2[0] == '-')					   // Если оба отрицательные
		{
			str1.erase(0, 1);
			str2.erase(0, 1);
			sum = summa(str1, str2, OsnovaniyeStr, osnovaniye);
			cout << "\nСумма: " << '-' + sum;
			razn = raznost(str1, str2, OsnovaniyeStr, osnovaniye);
			if (razn[0] == '-')
			{
				razn.erase(0, 1);
			}
			else if (razn[0] != '-')
			{
				razn = '-' + razn;
			}
			else
			{
				razn = '0';
			}
			cout << "\nРазность: " << razn;
		}
		std::cout << "\n";
		printf("\nЗапустить программу по новой? (0 - нет, 1 - да): ");
		while (!(std::cin >> x) || (std::cin.peek() != '\n') || (x != 0 && x != 1))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
			}
		}
	}
}