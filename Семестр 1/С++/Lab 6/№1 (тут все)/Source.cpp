#include <iostream>


int main()
{
	setlocale(LC_ALL, "ru");
	printf("Дана строка символов, состоящая из цифр, разделенных пробелами. Вывести четные числа этой строки.\n");
	printf("Выполнил: Снежко Максим Андреевич(группа 253505)\n");
	int x = 1;
	while (x == 1)
	{
		printf("Введите элементы массива: ");
		char arr[81]{};
		int ind = -1, n = 0;
		char string[100]{};
		char proverka;
		while (true)
		{
			bool goOut = 1, probelms = 1;
			for (int i = 0; i < 100; i++)
			{
				proverka = getchar();
				if (proverka == '\n' && i == 0 || proverka >= '9')
				{
					if (proverka >= '9')
					{
						std::cout << "В тексте нет слов(символов)\n";
						std::cout << "Попробуйте снова:\n";
						std::cin.ignore(INT_MAX, '\n');
					}
					goOut = 0;
				//	std::cout << "\nВ тексте нет слов \n";
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
					std::cout << "\nСтрока сосстоит из цифр, знаки неуместны!\n";
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
		n = strlen(string);
		printf("Четные числа массива: ");
		for (int i = 0; i < n; i++)     // считает до последнеего числа если они % 2 == 0
		{
			if (string[i] == ' ')
			{
				if (ind != -1 && arr[ind] % 2 == 0)
				{
					for (int j = 0; j <= ind; j++) {
						if (arr[j] >= '0' && arr[j] <= '9' || arr[j] == '-')
						{
							std::cout << arr[j];
						}
					}
					std::cout << " ";
				}
				ind = -1;
			}
			else
			{
				arr[++ind] = string[i];
			}
		}
		if (ind != -1 && arr[ind] % 2 == 0)           // считает последнее число если оно % 2 == 0
		{
			for (int j = 0; j <= ind; j++) {
				if (arr[j] >= '0' && arr[j] <= '9' || arr[j] == '-')
				{
					std::cout << arr[j];
				}
			}
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
}