#include <iostream> 

int main()
{
	setlocale(LC_ALL, "ru");
	printf("Ввести массив строк. Для каждой строки проверить, является она палиндромом или нет.\n");
	printf("Выполнил: Снежко Максим Андреевич(группа 253505)\n");
	while (true)
	{
		char str[81][81]{}, str2[81][81]{};
		long long i, t, j, n, k = 0, count[100]{}, N[255]{};
		std::cout << "Вводите строки через ENTER, чтобы перестать вводить, введите пустой ENTER: ";
		for (t = 0; t < 81; t++)
		{
			gets_s(str[t]);
			if (!*str[t])
			{
				break;
			}
		}
		for (int i = 0; i < t; i++)
		{
			n = strlen(str[i]);
			for (int k = 0; k < n; k++)
			{
				if (str[i][k] == ' ')
				{
					continue;
				}
				else
				{
					str2[i][k] = str[i][k];
				}
			}
		}
		for (int i = 0; i < t; i++)
		{
			N[i] = strlen(str[i]);
			count[i] = 0;
			for (int j = 0; j < N[i]; j++)
			{
				if (str2[i][j] == str2[i][N[i] - j - 1])
				{
					count[i]++;
				}

			}
		}
		for (int i = 0; i < t; i++)
		{
			std::cout << "Строка " << (i + 1);
			if (count[i] == N[i])
			{
				std::cout << " это палиндром\n";
			}
			else
			{
				std::cout << " это не палиндром\n";
			}
		}
		printf("\nЗапустить программу по новой? (0 - нет, любое число - да): ");
		/*
		while (!(std::cin >> x) || (std::cin.peek() != '\n') || (x != 0 && x != 1))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
			}
		}
		*/
		gets_s(str[0]);
		std::cout << '\n';
		if (str[0][0] == '0' && str[0][1] == '\0')
		{
			break;
		}
	}

	return 0;
}