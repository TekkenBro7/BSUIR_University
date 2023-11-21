#include <iostream>
#include <string>

void sum(std::string& str1, std::string& str2, long long length1, std::string& s3)
{
	length1 = str1.length();
	s3.resize(length1);
	int k = length1 - 1, inMind = 0;
	while (k > -1)         // O(N)
	{
		if (str1[k] == '0' && str2[k] == '0')
		{
			if (inMind == 0)
			{
				s3[k] = '0';
			}
			else
			{
				s3[k] = '1';
				inMind = 0;
			}
		}
		else if ((str1[k] == '0' && str2[k] == '1') || (str1[k] == '1' && str2[k] == '0'))
		{
			if (inMind == 0)
			{
				s3[k] = '1';
			}
			else
			{
				s3[k] = '0';
				inMind = 1;
			}
		}
		else
		{
			if (inMind == 0)
			{
				inMind = 1;
				s3[k] = '0';
			}
			else
			{
				s3[k] = '1';
				inMind = 1;
			}
		}
		k--;
	}
	std::cout << "Новое число в дополнительном коде: " << s3;


	if (s3[0] != '0')
	{
		long long index = -1;
		k = 0;
		while (k < length1)
		{
			index++;
			if (index == 0)
			{
				continue;
			}
			else if (s3[index] == '0')
			{
				s3[index] = '1';
			}
			else if (s3[index] == '1')
			{
				s3[index] = '0';
			}
			else
			{
				break;
			}
			k++;
		}
		if (inMind == 1 || inMind == 0)
		{
			index = length1;
			while (k > 0)
			{
				index--;
				if (index == 0)
				{

				}
				if (s3[index] == '0')
				{
					s3[index] = '1';
					break;
				}
				else if (s3[index] == '1')
				{
					s3[index] = '0';
				}
			}
		}

	}
	std::cout << "\n";
	std::cout << "После операций  сложения число в прямом коде: " << s3;


}

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Перевод из прямого кода в дополнительный\n";
	std::cout << "Выполнил Снежко Максим (группа 253505)\n";
	std::cout << "Осуществить сложение двоичных чисел, заданных в естественной форме.\nСложение выполните в дополнительном коде. Ответ выразите в естественной форме.";
	int x = 1;
	while (x == 1)
	{
		std::cout << "\nЗапишите первое и второе числа в естесвенном виде: ";
		std::string str1, str2, s3, st1, st2;
		long long length1, length2;
		rewind(stdin);
		getline(std::cin, str1);
		//std::cin >> str1;
		length1 = str1.length();
		int ForProverka = 0;
		while (true)            // O(N)
		{
			int p = 0;
			ForProverka = 0;
			for (int i = 0; i < length1; i++)
			{
				if (str1[i] >= '0' && str1[i] <= '9')
				{
					ForProverka++;
				}
				if (str1[i] == '-' && str1[i + 1] >= '0' && str1[i + 1] <= '9')
				{
					ForProverka++;
				}
			}
			if (str1[0] == '+' || str1[0] == '-' && str1[1] == ' ')
			{
				if(str1[0] == '+' || str1[0] == '-' && str1[1] == ' ')
				{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
			//	std::cin.ignore(INT_MAX, '\n');
				}
			}
			else if (str1[0] == '+' || str1[0] == '-' && str1[1] == ' ' && str1[3] >= '0' && str1[3] <= '9')
			{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
			//	std::cin.ignore(INT_MAX, '\n');
			}
			else if (ForProverka > 10)
			{
				std::cout << "Cлишком большое число\n";
				std::cout << "Попробуйте снова:\n";
			//	std::cin.ignore(INT_MAX, '\n');
			}
			else if (str1[0] == '0' && str1[1] >= '0' && str1[1] <= '9')
			{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
				std::cin.ignore(INT_MAX, '\n');
			}
			else if (ForProverka == length1)
			{
				break;
			}
			else
			{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
				std::cin.ignore(INT_MAX, '\n');
			}
			std::cin >> str1;
			length1 = str1.length();
		}
		rewind(stdin);
		getline(std::cin, str2);
		//std::cin >> str2;
		length2 = str2.length();
		while (true)      // O(N)
		{
			ForProverka = 0;
			for (int i = 0; i < length2; i++)
			{
				if (str2[i] >= '0' && str2[i] <= '9')
				{
					ForProverka++;
				}
				if (str2[i] == '-' && str2[i + 1] >= '0' && str2[i + 1] <= '9')
				{
					ForProverka++;
				}
			}
			if (str2[0] == '+' || str2[0] == '-' && str2[1] == ' ')
			{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
				std::cin.ignore(INT_MAX, '\n');
			}
			else if (str2[0] == '+' || str2[0] == '-' && str2[1] == ' ' && str2[3] >= '0' && str2[3] <= '9')
			{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
				std::cin.ignore(INT_MAX, '\n');
			}
			else if (ForProverka > 10)
			{
				std::cout << "Cлишком большое число\n";
				std::cout << "Попробуйте снова:\n";
				std::cin.ignore(INT_MAX, '\n');
			}
			else if (str2[0] == '0' && str2[1] >= '0' && str2[1] <= '9')
			{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
				std::cin.ignore(INT_MAX, '\n');
			}
			else if (ForProverka == length2)
			{
				break;
			}
			else
			{
				std::cout << "Неправильный ввод\n";
				std::cout << "Попробуйте снова:\n";
				std::cin.ignore(INT_MAX, '\n');
			}
			std::cin >> str2;
			length2 = str2.length();
		}
		std::cout << "\n";
		st1 = str1;
		st2 = str2;
		length1 = str1.length();
		length2 = str2.length();
		std::string sign1 = "0", sign2 = "0";

		// 23 - 59 - перевод в двоичку
		if (str1[0] == '-')
		{
			sign1 = "1";
		}
		if (str2[0] == '-')
		{
			sign2 = "1";
		}

		// Первое число
		int IntStr1 = std::stoi(str1);
		IntStr1 = fabs(IntStr1);
		int i = 0, Num1;
		while (IntStr1 != 0)
		{
			str1.resize(i + 1);
			Num1 = IntStr1 % 2 + 48;
			str1[i] = Num1;
			IntStr1 /= 2;
			i++;
		}
		std::reverse(str1.begin(), str1.end());
		str1.insert(0, sign1);
		length1 = str1.length();

		// Второе число
		int IntStr2 = std::stoi(str2);
		IntStr2 = fabs(IntStr2);
		int j = 0, Num2;
		while (IntStr2 != 0)
		{
			str2.resize(j + 1);
			Num2 = IntStr2 % 2 + 48;
			str2[j] = Num2;
			IntStr2 /= 2;
			j++;
		}
		std::reverse(str2.begin(), str2.end());
		str2.insert(0, sign2);
		length2 = str2.length();

		std::cout << "\n";
		std::cout << "Первое число в двоичном коде: " << str1 << '\n' << "Второе число в двоичном коде: " << str2;
		std::cout << "\n\n";
		std::cout << "Преобразуем числа для лучшего сложения" << '\n';

		if (length1 == length2)
		{
			str1.insert(1, "0");
			str2.insert(1, "0");
			std::cout << "Ваши числа в двоичной форме:\n" << "Первое число в двоичном коде: " << str1 << "\nВторое число в двоичном коде: " << str2 << '\n';
		}
		else if (length1 > length2)
		{
			str1.insert(1, "0");
			length1++;
			while (length1 > length2)
			{
				str2.insert(1, "0");
				length2 = str2.length();
			}
			std::cout << "Ваши числа в двоичной форме:\n" << "Первое число в двоичном коде: " << str1 << "\nВторое число в двоичном коде: " << str2 << '\n';
		}
		else
		{
			str2.insert(1, "0");
			length2++;
			while (length1 < length2)
			{
				str1.insert(1, "0");
				length1 = str1.length();
			}
			std::cout << "\nВаши числа в двоичной форме:\n" << "Первое число в двоичном коде: " << str1 << "\nВторое число в двоичном коде: " << str2 << '\n';
		}

		std::cout << '\n';
		std::cout << "Переведем первое число в дополнительный код" << '\n';

		if (str1 == "10000000")
		{
			std::cout << "Обратный код такой же, так как число положительное: 00000001";
			std::cout << "\nДополнительный код такой же, как и обратный, так как число положительное: 00000001" << '\n';
		}
		else if (str1[0] == '0')
		{
			std::cout << "Обратный код такой же, так как число положительное: " << str1;
			std::cout << "\nДополнительный код такой же, как и обратный, так как число положительное " << str1 << "\n\n";
		}
		else if (str1[0] == '1')
		{
			std::cout << "Инверсируем из прямого кода кроме знакогово числа, так как число отрицательное "; // << s1;
			for (int i = 1; i <= length1; i++)		// O(N)
			{
				if (str1[i] == '0')
				{
					str1[i] = '1';
				}
				else if (str1[i] == '1')
				{
					str1[i] = '0';
				}
			}
			std::cout << str1 << '\n';

			length1 = str1.length();

			if (str1[length1 - 1] == '0')
			{
				str1[length1 - 1] = '1';
				std::cout << "Дополнительный код числа: " << str1 << '\n';
			}

			else if (str1[length1 - 1] == '1')
			{
				for (int i = length1 - 1; i > 0; i--)		// O(N)
				{
					if (str1[i] == 50 || str1[i] == 49)
					{
						str1[i] = '0';
						if (str1[i - 1] == '0')
						{
							str1[i - 1] += 1;
							break;
						}
						str1[i - 1] += 1;
					}

				}
				std::cout << "Дополнительный код числа: " << str1 << '\n';
			}
		}

		std::cout << "\nПереведем второе число в дополнительный код" << "\n";

		if (str2 == "10000000")
		{
			std::cout << "Обратный код такой же, так как число положительное: 00000001" << '\n';
			std::cout << "\nДополнительный код такой же, как и обратный, так как число положительное: 00000001" << '\n';
		}
		else if (str2[0] == '0')
		{
			std::cout << "Обратный код такой же, так как число положительное: " << str2;
			std::cout << "\nДополнительный код такой же, как и обратный, так как число положительное " << str2 << "\n\n";
		}
		else if (str2[0] == '1')
		{
			std::cout << "Инверсируем из прямого кода кроме знакогово числа, так как число отрицательное "; // << s1;
			for (int i = 1; i <= length2; i++)
			{
				if (str2[i] == '0')
				{
					str2[i] = '1';
				}
				else if (str2[i] == '1')
				{
					str2[i] = '0';
				}
			}

			std::cout << str2 << '\n';
			length2 = str2.length();

			if (str2[length2 - 1] == '0')
			{
				str2[length2 - 1] = '1';
				std::cout << "Дополнительный код числа: " << str2 << '\n';
			}

			else if (str2[length2 - 1] == '1')
			{
				for (int i = length2 - 1; i > 0; i--)      // O(N)
				{
					if (str2[i] == 50 || str2[i] == 49)
					{
						str2[i] = '0';
						if (str2[i - 1] == '0')
						{
							str2[i - 1] += 1;
							break;
						}
						str2[i - 1] += 1;
					}

				}
				std::cout << "Дополнительный код числа: " << str2;
			}
		}
		s3.resize(length1);
		sum(str1, str2, length1, s3);
		// Сложение
		/*
		length1 = str1.length();
		s3.resize(length1);
		int k = length1 - 1, inMind = 0;
		while (k > -1)
		{
			if (str1[k] == '0' && str2[k] == '0')
			{
				if (inMind == 0)
				{
					s3[k] = '0';
				}
				else
				{
					s3[k] = '1';
					inMind = 0;
				}
			}
			else if ((str1[k] == '0' && str2[k] == '1') || (str1[k] == '1' && str2[k] == '0'))
			{
				if (inMind == 0)
				{
					s3[k] = '1';
				}
				else
				{
					s3[k] = '0';
					inMind = 1;
				}
			}
			else
			{
				if (inMind == 0)
				{
					inMind = 1;
					s3[k] = '0';
				}
				else
				{
					s3[k] = '1';
					inMind = 1;
				}
			}
			k--;
		}
		std::cout << "\nНовое число в дополнительном коде: " << s3;

		if (s3[0] != '0')
		{
			long long index = -1;
			k = 0;
			while (k < length1)
			{
				index++;
				if (index == 0)
				{
					continue;
				}
				else if (s3[index] == '0')
				{
					s3[index] = '1';
				}
				else if (s3[index] == '1')
				{
					s3[index] = '0';
				}
				else
				{
					break;
				}
				k++;
			}
			if (inMind == 1 || inMind == 0)
			{
				index = length1;
				while (k > 0)
				{
					index--;
					if (index == 0)
					{

					}
					if (s3[index] == '0')
					{
						s3[index] = '1';
						break;
					}
					else if (s3[index] == '1')
					{
						s3[index] = '0';
					}
				}
			}

		}
		std::cout << "\n\n";
		std::cout << "\n\n";
		std::cout << "После операций  сложения число в прямом коде: " << s3;
		*/
		int g = s3.length();
		int t = g - 1;
		int sum = 0;
		int h = 0;
		while (t != 0)
		{
			if (s3[t] == '1')
			{
				sum += powl(2, h);
				h++;
				t--;
			}
			else
			{
				h++;
				t--;
			}
		}
		int u = fabs(std::stoi(st1));
		int o = fabs(std::stoi(st2));
		std::cout << "\n\n";
		std::cout << "Сумма чисел: ";
		if (st1 != st2)
		{
			if (u == o)
			{
				sum = 0;
			}
		}
		if (sum == 0)
		{
			std::cout << sum;
		}
		else if (u > o && str1[0] == '1')
		{
			std::cout << "-" << sum;
		}
		else if (u < o && str2[0] == '1')
		{
			std::cout << "-" << sum;
		}
		else if (str1[0] == '1' && str2[0] == '1')
		{
			std::cout << "-" << sum;
		}
		else
		{
			std::cout << sum;
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

	return 0;

}