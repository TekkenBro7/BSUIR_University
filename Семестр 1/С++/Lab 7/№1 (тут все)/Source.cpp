#include <iostream>
#include <string>

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Перевод из прямого кода в дополнительный\n";
	std::cout << "Выполнил Снежко Максим (группа 253505)\n";
	int x = 1;
	while (x == 1)		
	{
		std::cout << "Введите число в прямом коде (0 и 1): ";
		std::string str;
		int length;
	//	rewind(stdin);
	//	getline(std::cin, str);
	//	int length = str.length();
		int ForProverka = 0;
		while (true)			 //	O(N^2)
		{
			rewind(stdin);
			getline(std::cin, str);
			length = str.length();
			ForProverka = 0;
			for (int i = 0; i < length; i++)           // O(N)
			{
				if (str[1] == ' ')
				{
					std::cout << "Вводиться только 0 или 1\n";
					std::cout << "Попробуйте снова:\n";
		//			std::cin.ignore(INT_MAX, '\n');
				}
				if (str[i] == '1' || str[i] == '0')    
				{
					ForProverka++;
				}
			}
			if (ForProverka == length)
			{
				break;
			}
			else
			{
				std::cout << "Вводиться только 0 или 1\n";
				std::cout << "Попробуйте снова:\n";
		//		std::cin.ignore(INT_MAX, '\n');
			}
		}
		std::cout << "\n\n";
		length = str.length();
				int j;
				if (length < 8)
				{
					j = 8 - length;
					str.insert(1, j, '0');              
				}
				if (length > 8 && length < 16)            
				{
					j = 16 - length;
					str.insert(1, j, '0');
				}
				if (length > 16 && length < 32)
				{
					j = 32 - length;
					str.insert(1, j, '0');
				}
				if (length > 32 && length < 64)
				{
					j = 64 - length;
					str.insert(1, j, '0');
				}
				length = str.length();
		
		if (str == "10000000")
		{
			std::cout << "Обратный код такой же, так как число положительное: 00000001";
			std::cout << "\nДополнительный код такой же, как и обратный, так как число положительное: 00000001" << '\n';
		}
		else if (str[0] == '0')
		{
			std::cout << "Обратный код такой же, так как число положительное: " << str;
			std::cout << "\nДополнительный код такой же, как и обратный, так как число положительное " << str << "\n\n";
		}
		else if (str[0] == '1')
		{
			std::cout << "Инверсируем из прямого кода кроме знакогово числа, так как число отрицательное "; // << s1;
			for (int i = 1; i < length; i++)  // O(N)
			{
				if (str[i] == '0')
				{
					str[i] = '1';
				}
				else if (str[i] == '1')
				{
					str[i] = '0';
				}
			}
			std::cout << str << '\n';

			if (str[length - 1] == '0')
			{
				str[length - 1] = '1';
				std::cout << "Дополнительный код числа: " << str;
			}

			else if (str[length - 1] == '1')
			{
				for (int i = length - 1; i > 0; i--)
				{
					if (str[i] == 50 || str[i] == 49)
					{
						str[i] = '0';
						if (str[i - 1] == '0')
						{
							str[i - 1] += 1;
							break;
						}
						str[i - 1] += 1;
					}

				}
				std::cout << "Дополнительный код числа: " << str;
			}
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