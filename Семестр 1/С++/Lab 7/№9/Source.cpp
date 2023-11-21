#include <iostream>
#include <string>

int proverka()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0 || a > 240)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			printf("Некорректный ввод\n");
			printf("Попробуйте снова: ");
		}
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Вычислить отравленную бочку с помощью 5 slaves\n";
	std::cout << "Вычеслено Снежко Максимом (группа 253505)\n\n";
	int x = 1;
	while (x == 1)
	{
		std::cout << "Введите номер отравленной бочки(1 - 240): ";
		int otravlenaya;
		otravlenaya = proverka();
		std::cout << '\n';
		std::string troichka;
		int i = 0, Num;
		while (otravlenaya != 0)
		{
			troichka.resize(i + 1);
			Num = otravlenaya % 3 + 48;
			troichka[i] = Num;
			otravlenaya /= 3;
			i++;
		}
		std::reverse(troichka.begin(), troichka.end());
		int length = troichka.length();
		std::cout << "Переведем номер отравленной бочки в троичную систему: ";
		while (length < 5)
		{
			troichka.insert(0, 1, '0');
			length++;
		}
		for (int i = 0; i < length; i++)		// O(N)
		{
			std::cout << troichka[i];
		}
		std::cout << "\n\nПолучается, делим рабов в получанной системе счисления по разрядам, где первый разряд - первый раб, второй\nразряд - второй, и так далее.\n";
		std::cout << "0 - раб не умер\n1 - раб умер в первый день\n2 - раб умер во второй день\n";
		std::cout << "Например, возьмем первых пять бочек. 00001 - пятый раб умер в первый день, остальные живы, 00002 - пятый раб умер во\nвторой день, 00010 - второй раб умер в первый день, 00020 - четвертый раб умер во второй день, 00100 - третий раб умер в\nпервый день. И так до 240 включительно.";
		std::cout << "\n";
		std::cout << "В нашем случае:\n";
		for (int i = 0; i < length; i++)					// O(N)
		{
			if (troichka[i] == '0')
			{
				std::cout << i + 1 << "-й раб не умер\n";
			}
			if (troichka[i] == '1')
			{
				std::cout << i + 1 << "-й раб умер в первый день\n";
			}
			if (troichka[i] == '2')
			{
				std::cout << i + 1 << "-й раб умер во второй день\n";
			}
		}

		int t = length - 1;
		int sum = 0;
		int h = 0;
		while (t != -1)					// 0(N)
		{
			if (troichka[t] == '1')
			{
				sum += powl(3, h);
				h++;
				t--;
			}
			else if (troichka[t] == '2')
			{
				sum += 2 * powl(3, h);
				h++;
				t--;
			}
			else
			{
				h++;
				t--;
			}
		}
		std::cout << "\nТогда номер отравленной бочки: " << sum;
		std::cout << "\n\n";
		printf("\nЗапустить программу по новой? (0 - нет, 1 - да): ");
		while ((x != 0 && x != 1) || !(std::cin >> x) || (std::cin.peek() != '\n'))
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
