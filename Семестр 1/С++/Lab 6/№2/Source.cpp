#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "ru");
	printf("В тексте найти и вывести на экран слова максимальной и минимальной длины.\n");
	printf("Выполнил: Снежко Максим Андреевич(группа 253505)\n");
	int x = 1;
	while (x == 1)
	{
		/*
		char arr[81];
		std::cout << "Введите слова: ";
		std::cin.getline(arr, 80);
		*/
		char string[100];
		char proverka;
		long long minDlina = 0, index = 1;
		std::cout << "Введите слова:\n";
		while (true)
		{
			bool goOut = 1, probelms = 1;
			for (int i = 0; i < 100; i++)
			{
				proverka = getchar();
				if (proverka == '\n' && i == 0 || proverka <= '9' && proverka >= '0')
				{
					if (proverka <= '9' && proverka >= '0')
					{
						std::cout << "В тексте нет цифр\n";
						std::cout << "Попробуйте снова:\n";
						std::cin.ignore(INT_MAX, '\n');
					}
					goOut = 0;
				//	std::cout << "\nffffВ тексте нет цифр\n";
				//	std::cout << "Попробуйте снова:\n";
					std::cin.clear();
				//	std::cin.ignore(INT_MAX, '\n');
					break;

				}

				if (proverka == '\n')
				{
					string[i] = '\0';
					break;
				}

				if (probelms && proverka == ' ')
				{
					// i--;
					continue;
				}
				else
				{
					probelms = false;
				}
				string[i] = proverka;

				if (ispunct(proverka))  // Проверка на разные знаки
				{
					std::cout << "\nСтрока сосстоит из слов и цифр, знаки неуместны!\n";
					std::cout << "Попробуйте снова:\n";
					rewind(stdin);
					goOut = 0;
					for (int i = 0; i < 100; i++)
					{
						string[i] = '\0';
					}
					break;
				}
			}
			if (goOut == 1)
			{
				break;
			}
		}
		char* NUL = NULL;
		char* slovo = strtok_s(string, " ", &NUL);
		char* wordmax = NULL;
		char* wordmin = NULL;
		long long length = strlen(slovo), count = 0, minLen = 10000, maxLen = 0;
		char mas[100];
		while (slovo != NULL) // пока есть слова
		{
			length = strlen(slovo);
			if (maxLen < length)
			{
				maxLen = length;
				wordmax = slovo;
			}
			std::cout << '\n';
			if (minLen >= length)
			{
				minLen = length;
				wordmin = slovo;
			}
			count++;
			slovo = strtok_s(NULL, " ", &NUL);  //следующее слово
		}
		if (count == 1)
		{
			std::cout << "В тексте одно слово: " << wordmax;
		}
		else
		{
			std::cout << "Самое длинное слово: " << wordmax << '\n' << "Самое короткое слово: " << wordmin;
		}
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
}s