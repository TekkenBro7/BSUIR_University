#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Human
{
	string surname;       // Фамилия
	string name;
	string patronymic;    // Отчество
	long double NomerOtdela;
	string dolznost;
	long double experience; // Стаж
};

// Number 1.1
Human* AddStruct(Human* obj, int& amount);
void showData(Human* Obj, int amount);

// Numver 1.2
Human* AddStruct2(Human* оbj, int& amount);
void showData2(Human* Obj, int& j);
void n2(Human* obj, int& count, int plus);

// Number 1.3
Human* AddStructForNumber3(Human* Obj, int amount);
void SetDataForNumber3(Human* Obj, int amount);

// Number3
void dw(Human* human, int& amount, int add, int i);
Human* Dobavlenie(Human* human, int& amount, int dobav);

// Number4
void otvet(Human* human, int& amount);

// Number5 
Human* Delete(Human* human, int& amount);

//Numver6
Human* change(Human* human, int& amount);

// Number7
void SWAP(Human* human, int i);
void SORT(Human* human, int& amount);

//Проверка на ввод
int checking();
long double proverka();
int kolvo();
int ProverkaDobavleniye();
string f(Human* human, int i);
string f1(Human* human);
int checking3();
int ProverkaFor5and3(int& amount);





int main()
{
	setlocale(LC_ALL, "ru");
	int count = 0, num{}, j{}, dobav = 0;
	Human* human = new Human[count];
	printf("Разработать программу, реализующую работу со структурами в консольном приложении.\n");
	printf("Информация о сотрудниках содержит ФИО, номер отдела, должность, стаж работы на предприятии.\nВывести список сотрудников заданного отдела, имеющих стаж работы на предприятии более 20 лет\n(Шейкер сортировка по возрастанию).\n");
	printf("Выполнил Снежко Максим (группа 253505)\n\n");
	while (true)
	{
		printf("Выберите действие:\n");
		printf("1. Записать структуры.\n");  // Cделано
		printf("2. Просмотр содержимого структуры.\n"); // Сделанно
		printf("3. Дополнения уже существующего массива структур новыми структурами.\n"); // Cделано
		printf("4. Ответ на задние(сотрудники с 20-им стажем).\n"); // Cделано
		printf("5. Изменение структуры.\n");   // Сделано
		printf("6. Удаления структуры.\n");   // Сделано
		printf("7. Отсортировать с помощью Шейкер сортировки по возрастанию.\n"); // Cделано
		printf("8. Выход из программы.\n\n"); // Сделано

		int nomer;
		nomer = checking();

		if (nomer == 1)
		{
			printf("1. Ввод заданного количества струкрут\n");
			printf("2. Ввод до появления структуры с заданным признаком\n");
			printf("3. Диалог с пользователем о необходимости продолжать ввод\n");
			num = checking();
			bool x = true;
			while (x)
			{
				if (num != 1 && num != 2 && num != 3)
				{
					printf("Такого варианта нет\nПовторите попытку: ");
					x = true;
				}
				else if (num == 1)
				{
					printf("Введите количество структур\n");
					count = kolvo();
					delete[] human;
					human = new Human[count];
					human = AddStruct(human, count);
					break;

				}
				else if (num == 2)
				{
					delete[] human;
					int j = 100;
					count = 0;
					human = new Human[j];
					human = AddStruct2(human, count);
					break;
				}
				else if (num == 3)
				{
					delete[] human;
					count = 0;
					human = new Human[count];
					int YesOrNot = 1;
					while (YesOrNot)
					{
						human = AddStructForNumber3(human, count);
						SetDataForNumber3(human, count);
						count++;
						cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
						while ((YesOrNot != 0 && YesOrNot != 1) || !(std::cin >> YesOrNot) || (std::cin.peek() != '\n'))
						{
							std::cin.clear();
							while (std::cin.get() != '\n');
							{
								printf("Некорректный ввод\n");
								printf("Попробуйте снова: ");
							}
						}
					}
					break;
				}
				num = checking();
			}
		}

		else if (nomer == 2)
		{
			if (count == 0)
			{
				printf("Структура пуста\n\n");
			}
			else
			{
				showData2(human, count);
			}
		}

		else if (nomer == 3)
		{
			printf("Введите, сколько структур вы хотите добавить: ");
			dobav;
			dobav = ProverkaDobavleniye();
			human = Dobavlenie(human, count, dobav);
		}

		else if (nomer == 4)
		{
			if (count == 0)
			{
				printf("Структура пуста\n\n");
			}
			else
			{
				otvet(human, count);
			}
		}

		else if (nomer == 5)
		{
			if (count == 0)
			{
				printf("Структура пуста\n\n");
			}
			else
			{
				human = change(human, count);
			}
		}

		else if (nomer == 6)
		{
			if (count == 0)
			{
				printf("Структура пуста, менять нечего\n\n");
			}
			else
			{
				human = Delete(human, count);
			}
		}

		else if (nomer == 7)
		{
			if (count == 0)
			{
				printf("Сортировать нечего\n\n");
			}
			else
			{
				SORT(human, count);
				printf("Cтруктура отсортирована\n\n");
			}
		}

		else if (nomer == 8)
		{
			printf("\nПрограмма завершена.\n\n");
			return 0;
		}
	}
}

// Number 1.1
Human* AddStruct(Human* obj, int& amount)
{
	obj = new Human[amount];
	for (int i = 0; i < amount; i++)
	{
		printf("Введите фамилию ");
		obj[i].surname = f(obj, i);
		printf("Введите имя: ");
		obj[i].name = f(obj, i);
		printf("Введите отчество: ");
		obj[i].patronymic = f(obj, i);
		printf("Введите номер отдела: ");
		obj[i].NomerOtdela = proverka();
		printf("Введите должность: ");
		obj[i].dolznost = f(obj, i);
		printf("Введите стаж работы: ");
		obj[i].experience = proverka();
		printf("\n");
	}
	return obj;
}

// Numver 1.2
Human* AddStruct2(Human* obj, int& amount)
{
	amount = 1;
	Human* structure = new Human[amount];
	string s1;
	long double k = 0;
	int vibor = 0;
	int plus = 0;
	int add = 0;
	printf("\nПо какому признаку будем смотреть?\n");
	printf("1. По фамилии\n");
	printf("2. По имени\n");
	printf("3. По отчеству\n");
	printf("4. По номеру отдела\n");
	printf("5. По должности\n");
	printf("6. По стажу\n");
	vibor = checking3();
	if (vibor == 1)
	{
		printf("Введите фамилию. Когда в структуре появится такой же признак, ввод закончится: ");
		s1 = f(obj, 0);
	}
	else if (vibor == 2)
	{
		printf("Введите имя. Когда в структуре появится такой же признак, ввод закончится: ");
		s1 = f(obj, 0);
	}
	else if (vibor == 3)
	{
		printf("Введите отчество. Когда в структуре появится такой же признак, ввод закончится: ");
		s1 = f(obj, 0);
	}
	else if (vibor == 4)
	{
		printf("Введите номер отдела. Когда в структуре появится такой же признак, ввод закончится: ");
		k = proverka();
	}
	else if (vibor == 5)
	{
		printf("Введите должность. Когда в структуре появится такой же признак, ввод закончится: ");
		s1 = f(obj, 0);
	}
	else if (vibor == 6)
	{
		printf("Введите стаж. Когда в структуре появится такой же признак, ввод закончится: ");
		k = proverka();
	}
	int again = 1;
	while (true)
	{
		n2(structure, amount, plus);
		if (vibor == 1)
		{
			if (s1 == structure[add].surname)
			{
				again = 0;
			}
		}
		else if (vibor == 2)
		{
			if (s1 == structure[add].name)
			{
				again = 0;
			}
		}
		else if (vibor == 3)
		{
			if (s1 == structure[add].patronymic)
			{
				again = 0;
			}
		}
		else if (vibor == 4)
		{
			if (k == structure[add].NomerOtdela)
			{
				again = 0;
			}
		}
		else if (vibor == 5)
		{
			if (s1 == structure[add].dolznost)
			{
				again = 0;
			}
		}
		else if (vibor == 6)
		{
			if (k == structure[add].experience)
			{
				again = 0;
			}
		}

		if (again == 1)
		{
			amount++;
			for (int i = 0; i < amount - 1; i++)
			{
				obj[i] = structure[i];
			}
			delete[] structure;

			structure = new Human[amount];
			for (int i = 0; i < amount - 1; i++)
			{
				structure[i] = obj[i];
			}
			delete[] obj;
			obj = new Human[amount];
			plus++;
			add++;
		}
		else
		{
			for (int i = 0; i < amount; i++)
			{
				obj[i] = structure[i];
			}
			delete[] structure;
			break;
		}
	}

	return obj;
}
void n2(Human* obj, int& count, int plus)
{
	for (int i = 0 + plus; i < count; i++)
	{
		printf("Введите фамилию ");
		obj[i].surname = f(obj, i);
		printf("Введите имя: ");
		obj[i].name = f(obj, i);
		printf("Введите отчество: ");
		obj[i].patronymic = f(obj, i);
		printf("Введите номер отдела: ");
		obj[i].NomerOtdela = proverka();
		printf("Введите должность: ");
		obj[i].dolznost = f(obj, i);
		printf("Введите стаж работы: ");
		obj[i].experience = proverka();
		printf("\n");
	}
}

// Number 1.3
Human* AddStructForNumber3(Human* obj, int amount)
{
	if (amount == 0)
	{
		obj = new Human[amount + 1];	// выделение памяти для первой структуры
	}
	else
	{
		Human* tempObj = new Human[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = obj[i];	    // копируем во временный объект
		}
		delete[] obj;

		obj = tempObj;
	}
	return obj;
}
void SetDataForNumber3(Human* obj, int amount)
{
	printf ("Введите фамилию: ");
	obj[amount].surname = f1(obj);
	printf("Введите имя: ");
	obj[amount].name = f1(obj);
	printf("Введите отчество: ");
	obj[amount].patronymic = f1(obj);
	printf("Введите номер отдела: ");
	obj[amount].NomerOtdela = proverka();
	printf("Введите должность: ");
	obj[amount].dolznost = f1(obj);
	printf("Введите стаж работы: ");
	obj[amount].experience = proverka();
	printf("\n");
}

// Number2
void showData2(Human* human, int& count)
{
	system("cls");
	cout << "Номер" << "     " << "Фамилия" << "           " << "Имя" << "         " << "Отчество" << "          " << "Номер отдела" << "             " << "Должность" << "          " << "Стаж работы(лет)\t" << '\n';
	printf("========================================================================================================================\n");
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << setw(16) << human[i].surname << setw(14) << human[i].name << setw(17) << human[i].patronymic << setw(22) << human[i].NomerOtdela << setw(22) << human[i].dolznost << setw(26) << human[i].experience << '\n';
	}
	printf("========================================================================================================================\n");
}

// Number3
Human* Dobavlenie(Human* human, int& amount, int dobav)
{
	Human* lox = new Human[amount + dobav];
	for (int i = 0; i < amount + dobav; i++)
	{
		if (i == amount)
		{
			dw(lox, amount, dobav, i);
			break;
		}
		lox[i] = human[i];
	}
	delete[] human;
	amount += dobav;
	human = new Human[amount];
	human = lox;

	return human;
}
void dw(Human* human, int& amount, int add, int i)
{
	for (int i = amount; i < amount + add; i++)
	{
		printf("Введите фамилию: ");
		human[i].surname = f(human, i);
		printf("Введите имя: ");
		human[i].name = f(human, i);
		printf("Введите отчество: ");
		human[i].patronymic = f(human, i);
		printf("Введите номер отдела: ");
		human[i].NomerOtdela = proverka();
		printf("Введите должность: ");
		human[i].dolznost = f(human, i);
		printf("Введите стаж работы: ");
		human[i].experience = proverka();
		printf("\n");

	}
}

// Number4
void otvet(Human* human, int& amount)
{
	for (int i = 0; i < amount; i++)
	{
		system("cls");
		cout << "Номер" << "     " << "Фамилия" << "           " << "Имя" << "         " << "Отчество" << "          " << "Номер отдела" << "             " << "Должность" << "          " << "Стаж работы(лет)\t" << '\n';
		printf("========================================================================================================================\n");
		if (human[i].experience > 20)
		{
			cout << i + 1 << setw(16) << human[i].surname << setw(14) << human[i].name << setw(17) << human[i].patronymic << setw(22) << human[i].NomerOtdela << setw(22) << human[i].dolznost << setw(26) << human[i].experience << '\n';
		}
	}
	printf("========================================================================================================================\n\n");
}

// Number5
Human* Delete(Human* human, int& amount)
{
	printf("\nВведите номер(по порядку) который хотите убрать: ");
	int n;
	n = ProverkaFor5and3(amount);
	Human* dop = new Human[amount - 1];
	int dopoln = 0;
	for (int i = 0; i < amount; i++)
	{
		if (i != n - 1 && i < amount)
		{
			dop[i + dopoln] = human[i];
		}
		else
		{
			dopoln = -1;
		}
	}
	delete[] human;
	amount--;
	human = new Human[amount];
	for (int i = 0; i < amount; i++)
	{
		human[i] = dop[i];
	}

	return human;
}

// Number6
Human* change(Human* human, int& amount)
{
	printf("\nВведите номер который надо изменить:");
	int n;
	n = ProverkaFor5and3(amount);

	for (int i = 0; i < amount; i++)
	{
		if (i == n - 1)
		{
			SetDataForNumber3(human, i);
			break;
		}
	}

	return human;
}

// Number 7 (Сортировка)
void SWAP(Human* human, int i)
{
	long double buff;
	buff = human[i].experience;
	human[i].experience = human[i - 1].experience;
	human[i - 1].experience = buff;

	string s;
	s = human[i].surname;
	human[i].surname = human[i - 1].surname;
	human[i - 1].surname = s;

	s = human[i].name;
	human[i].name = human[i - 1].name;
	human[i - 1].name = s;

	s = human[i].patronymic;
	human[i].patronymic = human[i - 1].patronymic;
	human[i - 1].patronymic = s;

	buff = human[i].NomerOtdela;
	human[i].NomerOtdela = human[i - 1].NomerOtdela;
	human[i - 1].NomerOtdela = buff;

	s = human[i].dolznost;
	human[i].dolznost = human[i - 1].dolznost;
	human[i - 1].dolznost = s;

}
void SORT(Human* human, int& amount)
{
	int leftMark = 1;
	int rightMark = amount - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (human[i - 1].experience > human[i].experience)
				SWAP(human, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (human[i - 1].experience > human[i].experience)
				SWAP(human, i);
		rightMark--;
	}

}

//Проверка на ввод
int checking()
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > 8)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "\nНеверный ввод\n";
			std::cout << "Попробуйте снова: ";
		}
	}
	return number;
}
long double proverka()
{
	long double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0 || a >= 9223372036854775807)
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
int kolvo()
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number >= INT_MAX)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "\nНеверный ввод\n";
			std::cout << "Попробуйте снова: ";
		}
	}
	return number;
}
int ProverkaDobavleniye()
{
	int number;
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 0 || number >= INT_MAX)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			printf("\nНеверный ввод\n");
			printf("Попробуйте снова: ");
		}
	}
	return number;
}
string f(Human* human, int i)
{
	string r;
	int length;
	int j = 0, check;
	while (true)
	{
		rewind(stdin);
		getline(std::cin, r);
		length = r.length();
		check = 1;
		while (j < length)
		{
			if (!isalpha(r[j]))
			{
				check = 0;
				break;
			}
			else if (isalpha(r[j + 1]) && r[j] == ' ')
			{
				check = 0;
				break;
			}
			else if (j == 0 && r[j] == '\n')
			{
				check = 0;
				break;
			}
			j++;
		}
		if (length == 0)
		{
			check = 0;
		}
		if (check == 1)
		{
			break;
		}

		std::cout << "Некорректный ввод, попробуйте снова!\n";

		rewind(stdin);
	}
	return r;

}
string f1(Human* human)
{
	string r;
	int length;
	int j = 0, check;
	while (true)
	{
		rewind(stdin);
		getline(std::cin, r);
		length = r.length();
		check = 1;
		while (j < length)
		{
			if (!isalpha(r[j]))
			{
				check = 0;
				break;
			}
			else if (isalpha(r[j + 1]) && r[j] == ' ')
			{
				check = 0;
				break;
			}
			else if (j == 0 && r[j] == '\n')
			{
				check = 0;
				break;
			}
			j++;
		}
		if (length == 0)
		{
			check = 0;
		}
		if (check == 1)
		{
			break;
		}

		std::cout << "Некорректный ввод, попробуйте снова!\n";

		rewind(stdin);
	}
	return r;

}
int checking3()
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > 6)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "\nНеверный ввод\n";
			std::cout << "Попробуйте снова: ";
		}
	}
	return number;
}
int ProverkaFor5and3(int& amount)
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > amount)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "\nНеверный ввод\n";
			std::cout << "Попробуйте снова: ";
		}
	}
	return number;
}