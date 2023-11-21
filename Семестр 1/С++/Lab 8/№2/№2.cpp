#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Human
{
	string country;
	string komanda;
	string fio;       // ФИО
	long double nomer;
	long double age;
	long double heigth;
	long double weigth;
};


// проверка на ввод
int checking();
long double proverka();
int proverka1();
int kolvo();
string check_name(Human* information, long long i, bool search);
string t(Human* human, int i);
string f(Human* human, int i);
string f1(Human* human);
string t1(Human* human);
int ProverkaFor5and3(int& amount);
int checking3();

// Number 1.1
Human* AddStruct(Human* obj, int& amount, int& min);

// Number 1.2
void n2(Human* obj, int& count, int plus, int& min);
Human* AddStruct2(Human* obj, int& amount, int& min);

// Number 1.3
Human* AddStructForNumber3(Human* obj, int amount);

// Просмотр
void showData2(Human* human, int& count);

// Добавление
Human* Dobavlenie(Human* human, int& amount, int dobav, int& min);
void dw(Human* obj, int& amount, int add, int i, int& min);

// Ответ
void otvet(Human* human, int& amount, int& min);

// Изменение
void SetDataForNumber3(Human* obj, int amount, int& min);
Human* change(Human* human, int& amount, int& min);

// Удаление
Human* Delete(Human* human, int& amount, int& min);

// С файлом
void zapis(Human* human, int& count);
void PrintInfo();

// Файл ответ
void zapis2(Human* human, int& count, int& min);
void PrintInfo2();

// Number 7 (Сортировка)
void SWAP(Human* human, int i)
{
	long double buff;
	buff = human[i].age;
	human[i].age = human[i - 1].age;
	human[i - 1].age = buff;

	string s;
	s = human[i].country;
	human[i].country = human[i - 1].country;
	human[i - 1].country = s;

	s = human[i].komanda;
	human[i].komanda = human[i - 1].komanda;
	human[i - 1].komanda = s;

	s = human[i].fio;
	human[i].fio = human[i - 1].fio;
	human[i - 1].fio = s;

	buff = human[i].nomer;
	human[i].nomer = human[i - 1].nomer;
	human[i - 1].nomer = buff;

	buff = human[i].heigth;
	human[i].heigth = human[i - 1].heigth;
	human[i - 1].heigth = buff;

	buff = human[i].weigth;
	human[i].weigth = human[i - 1].weigth;
	human[i - 1].weigth = buff;
}
void SORT(Human* human, int& amount)
{
	int leftMark = 1;
	int rightMark = amount - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (human[i - 1].age > human[i].age)
				SWAP(human, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (human[i - 1].age > human[i].age)
				SWAP(human, i);
		rightMark--;
	}

}

// Основной ФАЙЛ
void file1(Human* information, int& size);
Human* file_enter(int& size, Human* information);


int main()
{
	setlocale(LC_ALL, "ru");
	int count = 0, num{}, j{}, dobav = 0;
	int min = INT_MAX;
	Human* human = new Human[count];
	printf("Разработать программу, реализующую работу с файлами в консольном приложении.\n");
	printf("Информация об участниках спортивных соревнований содержит: наименование страны, название команды, Ф.И.О. игрока, игровой номер, возраст, рост, вес. Вывести информацию о самой молодой команде.\n");
	printf("Выполнил Снежко Максим (группа 253505)\n\n");
	while (true)
	{
		printf("Выберите действие:\n");
		printf("1. Записать структуры(и файла).\n");  // Cделано
		printf("2. Просмотр содержимого структуры.\n"); // Сделанно
		printf("3. Дополнения уже существующего массива структур новыми структурами.\n"); // Сделано
		printf("4. Ответ на задание (информация о самой молодой команде).\n"); // Cделано
		printf("5. Изменение структуры.\n");   // Сделано
		printf("6. Удаления структуры.\n");   //  Cделано
		printf("7. Вывод информации из файла.\n"); // Сделано
		printf("8. Запись в файл(ответ на задание)\n"); // Сделано
		printf("9. Вывод из файла(ответ на задание)\n"); // Сделано
		printf("10. Сортировка\n"); // Сделано
		printf("11. Выход из программы\n\n"); // Сделано

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
					human = AddStruct(human, count, min);
					zapis(human, count);
					file1(human, count);
					break;
				}
				else if (num == 2)
				{
					delete[] human;
					int j = 100;
					count = 0;
					human = new Human[j];
					human = AddStruct2(human, count, min);
					zapis(human, count);
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
						SetDataForNumber3(human, count, min);
						count++;
						zapis(human, count);
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
				cin >> num;
			}
		}

		else if (nomer == 2)
		{
			if (count == 0)
			{
				//printf("Структура пуста\n\n");
				human = file_enter(count, human);
				showData2(human, count);
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
			dobav = proverka1();
			human = Dobavlenie(human, count, dobav, min);
			zapis(human, count);
			zapis2(human, count, min);
			file1(human, count);
		}

		else if (nomer == 4)
		{
			if (count == 0)
			{
				printf("Структура пуста\n\n");
			}
			else
			{
				otvet(human, count, min);
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
				human = change(human, count, min);
				zapis(human, count);
				file1(human, count);
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
				human = Delete(human, count, min);
				zapis(human, count);
				file1(human, count);
			}
		}

		else if (nomer == 7)
		{
			//PrintInfo();
			file1(human, count);
		}

		else if (nomer == 8)
		{
			if (count == 0)
			{
				printf("Записано в файл, чтобы вывести, нажмите 9\n\n");
				human = file_enter(count, human);
				zapis2(human, count, min);
			}
			else
			{
				printf("Записано в файл, чтобы вывести, нажмите 9\n\n");
				zapis2(human, count, min);
			}
		}

		else if (nomer == 9)
		{
			PrintInfo2();
		}

		else if (nomer == 10)
		{
			if (count == 0)
			{
				printf("Сортировать нечего\n\n");
			}
			else
			{
				SORT(human, count);
				zapis(human, count);
				printf("Cтруктура отсортирована\n\n");
			}
		}

		else if (nomer == 11)
		{
			printf("\nПрограмма завершена.\n\n");
			return 0;
		}

		else if (nomer == 12)
		{

		}

	}

}


// Number 1.1
Human* AddStruct(Human* obj, int& amount, int& min)
{
	obj = new Human[amount];
	for (int i = 0; i < amount; i++)
	{
		cout << "Название страны: ";
		obj[i].country = f(obj, i);
		cout << "Название команды: ";
		obj[i].komanda = t(obj, i);
		cout << "Введите ФИО ";
		obj[i].fio = check_name(obj, i, false);
		cout << "Введите Номер игрока: ";
		obj[i].nomer = proverka1();
		cout << "Введите возраст(лет): ";
		obj[i].age = proverka();
		cout << "Введите рост(см): ";
		obj[i].heigth = proverka();
		cout << "Введите вес(кг): ";
		obj[i].weigth = proverka();
		printf("\n");
		if (obj[i].age < min)
		{
			min = obj[i].age;
		}
	}
	return obj;
}

// Number 1.2
void n2(Human* obj, int& count, int plus, int& min)
{
	for (int i = 0 + plus; i < count; i++)
	{
		cout << "Название страны: ";
		obj[i].country = f(obj, i);
		cout << "Название команды: ";
		obj[i].komanda = t(obj, i);
		cout << "Введите ФИО ";
		obj[i].fio = check_name(obj, i, false);
		cout << "Введите Номер игрока: ";
		obj[i].nomer = proverka1();
		cout << "Введите возраст(лет): ";
		obj[i].age = proverka();
		cout << "Введите рост(см): ";
		obj[i].heigth = proverka();
		cout << "Введите вес(кг): ";
		obj[i].weigth = proverka();
		printf("\n");
		if (obj[i].age < min)
		{
			min = obj[i].age;
		}
	}
}
Human* AddStruct2(Human* obj, int& amount, int& min)
{
	amount = 1;
	Human* structure = new Human[amount];
	string s1;
	long double k = 0;
	int vibor = 0;
	int plus = 0;
	int add = 0;
	printf("\nПо какому признаку будем смотреть?\n");
	printf("1. По стране\n");
	printf("2. По названию команда\n");
	printf("3. По ФИО\n");
	printf("4. По номеру игрока\n");
	printf("5. По возрасту\n");
	printf("6. По росту\n");
	printf("7. По весу\n");
	vibor = checking3();

	if (vibor == 1)
	{
		printf("Введите страну. Когда в структуре появится такой же признак, ввод закончится: ");
		s1 = f(obj, 0);
	}
	else if (vibor == 2)
	{
		printf("Введите название команды. Когда в структуре появится такой же признак, ввод закончится: ");
		s1 = t(obj, 0);
	}
	else if (vibor == 3)
	{
		printf("Введите ФИО. Когда в структуре появится такой же признак, ввод закончится: ");
		s1 = check_name(structure, 0, false);
	}
	else if (vibor == 4)
	{
		printf("Введите номер игрока. Когда в структуре появится такой же признак, ввод закончится: ");
		k = proverka1();
	}
	else if (vibor == 5)
	{
		printf("Введите возраст. Когда в структуре появится такой же признак, ввод закончится: ");
		k = proverka();
	}
	else if (vibor == 6)
	{
		printf("Введите рост. Когда в структуре появится такой же признак, ввод закончится: ");
		k = proverka();
	}
	else if (vibor == 7)
	{
		printf("Введите вес. Когда в структуре появится такой же признак, ввод закончится: ");
		k = proverka();
	}
	int again = 1;
	while (true)
	{
		n2(structure, amount, plus, min);
		if (vibor == 1)
		{
			if (s1 == structure[add].country)
			{
				again = 0;
			}
		}
		else if (vibor == 2)
		{
			if (s1 == structure[add].komanda)
			{
				again = 0;
			}
		}
		else if (vibor == 3)
		{
			if (s1 == structure[add].fio)
			{
				again = 0;
			}
		}
		else if (vibor == 4)
		{
			if (k == structure[add].nomer)
			{
				again = 0;
			}
		}
		else if (vibor == 5)
		{
			if (k == structure[add].age)
			{
				again = 0;
			}
		}
		else if (vibor == 6)
		{
			if (k == structure[add].heigth)
			{
				again = 0;
			}
		}
		else if (vibor == 7)
		{
			if (k == structure[add].weigth)
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

// Просмотр
void showData2(Human* human, int& count)
{
	system("cls");
	cout << "Номер" << "     " << "Название страны" << "     " << "Название команды" << "            " << "ФИО" << "           " << "Номер игрока" << "   " << "Возраст(лет)" << "   " << "Рост(см)" << "   " << "Вес(кг)" << '\n';
	cout << "========================================================================================================================" << '\n';
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << setw(24) << human[i].country << setw(21) << human[i].komanda << setw(16) << human[i].fio << setw(22) << human[i].nomer << setw(15) << human[i].age << setw(11) << human[i].heigth << setw(10) << human[i].weigth << '\n';
	}
	cout << "========================================================================================================================" << '\n';
}

// Добавление
Human* Dobavlenie(Human* human, int& amount, int dobav, int& min)
{
	Human* lox = new Human[amount + dobav];
	for (int i = 0; i < amount + dobav; i++)
	{
		if (i == amount)
		{
			dw(lox, amount, dobav, i, min);
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
void dw(Human* obj, int& amount, int add, int i, int& min)
{
	for (int i = amount; i < amount + add; i++)
	{
		cout << "Название страны: ";
		obj[i].country = f(obj, i);
		cout << "Название команды: ";
		obj[i].komanda = t(obj, i);
		cout << "Введите ФИО ";
		obj[i].fio = check_name(obj, i, false);
		cout << "Введите Номер игрока: ";
		obj[i].nomer = proverka1();
		cout << "Введите возраст(лет): ";
		obj[i].age = proverka();
		cout << "Введите рост(см): ";
		obj[i].heigth = proverka();
		cout << "Введите вес(кг): ";
		obj[i].weigth = proverka();
		printf("\n");
		if (obj[i].age < min)
		{
			min = obj[i].age;
		}
	}
}

// Ответ
void otvet(Human* human, int& amount, int& min)
{
	for (int i = 0; i < amount; i++)
	{
		if (human[i].age == min)
		{
			cout << "Номер" << "     " << "Название страны" << "     " << "Название команды" << "            " << "ФИО" << "           " << "Номер игрока" << "   " << "Возраст(лет)" << "   " << "Рост(см)" << "   " << "Вес(кг)" << '\n';
			cout << "========================================================================================================================" << '\n';
			cout << i + 1 << setw(24) << human[i].country << setw(21) << human[i].komanda << setw(16) << human[i].fio << setw(22) << human[i].nomer << setw(15) << human[i].age << setw(11) << human[i].heigth << setw(10) << human[i].weigth << '\n';
			cout << "========================================================================================================================" << '\n';
		}

	}
}

// Изменение
void SetDataForNumber3(Human* obj, int amount, int& min)
{
	min = INT_MAX;
	cout << "Название страны: ";
	obj[amount].country = f1(obj);
	cout << "Название команды: ";
	obj[amount].komanda = t1(obj);
	cout << "Введите ФИО ";
	obj[amount].fio = check_name(obj, 0, false);
	cout << "Введите Номер игрока: ";
	obj[amount].nomer = proverka1();
	cout << "Введите возраст(лет): ";
	obj[amount].age = proverka();
	cout << "Введите рост(см): ";
	obj[amount].heigth = proverka();
	cout << "Введите вес(кг): ";
	obj[amount].weigth = proverka();
	printf("\n");
	for (int i = 0; i < amount; i++)
	{
		if (obj[i].age < min)
		{
			min = obj[i].age;
		}
	}
}
Human* change(Human* human, int& amount, int& min)
{
	printf("\nВведите номер который надо изменить:");
	int n;
	n = ProverkaFor5and3(amount);

	for (int i = 0; i < amount; i++)
	{
		if (i == n - 1)
		{
			SetDataForNumber3(human, i, min);
			break;
		}
	}

	return human;
}

// Удаление
Human* Delete(Human* human, int& amount, int& min)
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
	min = INT_MAX;
	for (int i = 0; i < amount; i++)
	{
		if (human[i].age < min)
		{
			min = human[i].age;
		}
	}
	return human;
}


// C файлом
void zapis(Human* human, int& count)
{
	ofstream fout;
	fout.open("AllInfa.txt");
	fout << "\nВся информация:\n\n";
	for (int i = 0; i < count; i++)
	{
		fout << "Страна: ";
		fout << human[i].country;
		fout << '\n';
		fout << "Команда: ";
		fout << human[i].komanda;
		fout << '\n';
		fout << "ФИО: ";
		fout << human[i].fio;
		fout << '\n';
		fout << "Номер игрока: ";
		fout << human[i].nomer;
		fout << '\n';
		fout << "Возраст: ";
		fout << human[i].age;
		fout << '\n';
		fout << "Рост: ";
		fout << human[i].heigth;
		fout << '\n';
		fout << "Вес: ";
		fout << human[i].weigth;
		fout << '\n' << '\n';
	}
	fout.close();
}
void PrintInfo()
{
	ifstream fin;
	fin.open("AllInfa.txt");
	if (fin.is_open())
	{
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	else
	{
		cout << "Не открыт";
	}
}

// Файл ответ
void zapis2(Human* human, int& count, int& min)
{
	ofstream file;
	file.open("Otvet.txt");
	for (int i = 0; i < count; i++)
	{
		if (human[i].age < min)
		{
			min = human[i].age;
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (human[i].age == min)
		{
			file << "Страна: ";
			file << human[i].country;
			file << '\n';
			file << "Команда: ";
			file << human[i].komanda;
			file << '\n';
			file << "ФИО: ";
			file << human[i].fio;
			file << '\n';
			file << "Номер игрока: ";
			file << human[i].nomer;
			file << '\n';
			file << "Возраст: ";
			file << human[i].age;
			file << '\n';
			file << "Рост: ";
			file << human[i].heigth;
			file << '\n';
			file << "Вес: ";
			file << human[i].weigth;
			file << '\n' << '\n';
		}
	}
	file.close();
}
void PrintInfo2()
{
	ifstream th;
	th.open("Otvet.txt");
	if (th.is_open())
	{
		char yu;
		while (th.get(yu))
		{
			cout << yu;
		}
	}
	else
	{
		printf("Не открыт");
	}
}

// Основной ФАЙЛ
void file1(Human* information, int& size)
{
	std::ofstream EndFile;
	EndFile.open("file_end.txt", std::ios::out);
	for (int i = 0; i < size; i++)
	{
		EndFile << information[i].country << '\n';
		EndFile << information[i].komanda << '\n';
		EndFile << information[i].fio << '\n';
		EndFile << information[i].nomer << '\n';
		EndFile << information[i].age << '\n';
		EndFile << information[i].heigth << '\n';
		EndFile << information[i].weigth << '\n';
		EndFile << '\n';
	}
}
Human* file_enter(int& size, Human* information)
{
	std::ifstream file_start;
	file_start.open("file_end.txt", std::ios::in);

	std::string string;
	int num_of_files = 0;
	while (!file_start.eof())
	{
		std::getline(file_start, string);
		if (string != "\0")
		{
			num_of_files++;
		}
	}
	file_start.close();
	file_start.open("file_end.txt", std::ios::in);
	num_of_files /= 7;
	size = num_of_files;
	delete[] information;
	information = new Human[num_of_files];
	for (int i = 0; i < size; i++)
	{
		getline(file_start, information[i].country);
		getline(file_start, information[i].komanda);
		getline(file_start, information[i].fio);
		file_start >> information[i].nomer;
		file_start >> information[i].age;
		file_start >> information[i].heigth;
		file_start >> information[i].weigth;
		int l = file_start.tellg(); // Возвращает позицию текущего символа во входном потоке.
		if (file_start.peek() == ' ' || file_start.peek() == '\0' || file_start.peek() == '\n') // Eсли пустая
		{
			l += 4;
		}
		file_start.seekg(l, std::ios_base::beg); // Устанавливает позицию следующего символа, который будет извлечен из входного потока.
	}
	file_start.close();

	return information;
}


// проверка на ввод
int checking()
{
	int number;
	std::cout << "Введите число: ";
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > 12)
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
int proverka1()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0 || a >= INT_MAX)
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
	std::cout << "Введите число: ";
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
string check_name(Human* information, long long i, bool search)
{
	std::string name_of_student;
	while (true)
	{
		rewind(stdin);
		bool check = 1, space_in_a_row = 0, not_enough_names = 0;
		int times = 0, space = 0, names = 0;
		name_of_student;

		if (!search)
		{
			std::cout << "Введите ФИО студента под номером " << i + 1 << "\n";
			getline(std::cin, name_of_student);
			information[i].fio = name_of_student;
		}
		else
		{
			getline(std::cin, name_of_student);
			information[i].fio = name_of_student;
		}

		long long dlina = information[i].fio.length();
		name_of_student = information[i].fio;

		while (times < dlina)
		{
			space_in_a_row = 0;
			not_enough_names = 0;
			if (!isalpha(name_of_student[times]) && times == 0)

			{
				check = 0;
				break;
			}

			if (!isalpha(name_of_student[times]) && name_of_student[times] != ' ')
			{
				check = 0;
				break;
			}

			if (name_of_student[times] == ' ' && name_of_student[times + 1] == ' ')
			{
				check = 0;
				space_in_a_row = 1;
				break;
			}

			if (name_of_student[times] == ' ')
			{
				space++;
			}

			times++;

			if (times == dlina && space != 2)
			{
				check = 0;
				not_enough_names = 1;
				break;
			}

			if (!isalpha(name_of_student[dlina - 1]))
			{
				check = 0;
				not_enough_names = 1;
				break;
			}
		}
		if (check)
		{
			break;
		}
		std::cout << "Некорректный ввод, попробуйте снова!\a\n";

		if (space_in_a_row)
		{
			std::cout << "Между фамилией именем и отчеством должен быть только 1 пробел!\n";
		}

		if (not_enough_names)
		{
			std::cout << "Надо обязательно писать и имя, и фамилию, и отчество!(последним символом не может быть пробел)\n";
		}

		information[i].fio.erase(0, dlina);
		rewind(stdin);
	}
	return name_of_student;
}
string t(Human* human, int i)
{
	string r;
	rewind(stdin);
	getline(std::cin, r);
	return r;
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
string t1(Human* human)
{
	string r;
	rewind(stdin);
	getline(std::cin, r);
	return r;
}
int ProverkaFor5and3(int& amount)
{
	int number;
	std::cout << "Введите число: ";
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
int checking3()
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > 7)
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