#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>  

using namespace std;

class Date;
int checking3();
Date* FromFile(Date* information, int& size);
void showData(Date* information, int size);
int checking2();
int checking1();
int ProverkaFor5and3(int& amount);
void SetDataForNumber3(Date* obj, int amount);
Date* change(Date* human, int& amount);
void file1(Date* information, int& size);
void dw(Date* obj, int& amount, int add, int i);
Date* Dobavlenie(Date* human, int& amount, int dobav);
int proverka1();


class Date
{
public:
	string str;

	void NextDay(Date* information, int size)
	{
		cout << "Выберите дату с файла(номер): ";
		int r;
		while (!(std::cin >> r) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || r < 1 || r > size)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				std::cout << "\nНеверный ввод\n";
				std::cout << "Попробуйте снова: ";
			}
		}
		for (int x = 0; x < size; x++)
		{
			if (x == r - 1)
			{
				string s = "";
				s += information[x].str[0];
				s += information[x].str[1];
				int d = stoi(s);
				int j = d;
				if (information[x].str[2] != '.')
				{
					cout << "Ошибка даты";
					return;
				}
				s = "";
				s += information[x].str[3];
				s += information[x].str[4];
				int m = stoi(s);
				int k = m;
				if (information[x].str[5] != '.')
				{
					cout << "Ошибка даты";
					return;
				}
				s = "";
				for (int i = 6; information[x].str[i] != '\0'; i++)
				{
					s += information[x].str[i];
				}
				int year = stoi(s);
				int err = 0;
				string month[12] = { "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
				if (m < 1 || m > 12 || d < 1)
				{
					err = 1;
				}
				if (m == 2)
				{
					if (d > 28)
					{
						err = 1;
					}
					if (d == 28)
					{
						d = 1;
						m = 3;
					}
					else ++d;
				}
				else if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
				{
					if (d > 30)
					{
						err = 1;
					}
					if (d == 30)
					{
						d = 1;
						++m;
					}
					else ++d;
				}
				else
				{
					if (d > 31)
					{
						err = 1;
					}
					if (d == 31)
					{
						d = 1;
						++m;
						if (m == 13)
						{
							m = 1;
						}
					}
					else ++d;
				}
				if (j == 31 && k == 12)
				{
					cout << "01.01." << ++year;
					return;
				}
				if (err == 0)
				{
					cout << "Следующий день: " << d << "." << month[m - 1] << "." << year;
					return;
				}
				else
				{
					cout << "Неправильная дата";
					return;
				}
			}
		}
	}

	void PreviousDay(Date* information, int size)
	{
		cout << "Выберите дату с файла(номер): ";
		int r;
		while (!(std::cin >> r) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || r < 1 || r > size)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				std::cout << "\nНеверный ввод\n";
				std::cout << "Попробуйте снова: ";
			}
		}
		for (int x = 0; x < size; x++)
		{
			if (x == r - 1)
			{
				string s = "";
				s += information[x].str[0];
				s += information[x].str[1];
				int d = stoi(s);
				int j = d;
				if (information[x].str[2] != '.')
				{
					cout << "Ошибка даты";
					return;
				}
				s = "";
				s += information[x].str[3];
				s += information[x].str[4];
				int m = stoi(s);
				int k = m;
				if (information[x].str[5] != '.')
				{
					cout << "Ошибка даты";
					return;
				}
				s = "";
				for (int i = 6; information[x].str[i] != '\0'; i++)
				{
					s += information[x].str[i];
				}
				int year = stoi(s);
				int err = 0;
				string month[12] = { "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
				if (m < 1 || m > 12 || d < 1)
				{
					err = 1;
				}
				if (m == 2)
				{
					if (d > 28)
					{
						err = 1;
					}
					if (d == 28)
					{
						d = 1;
						m = 3;
					}
					else
					{
						--d;
					}
				}
				else if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
				{
					if (d > 30)
					{
						err = 1;
					}
					if (d == 30)
					{
						d = 1;
						--m;
					}
					else
					{
						--d;
					}
				}
				else
				{
					if (d > 31)
					{
						err = 1;
					}
					if (d == 31)
					{
						d = 1;
						--m;
						if (m == 13)
						{
							m = 1;
						}
					}
					else
					{
						--d;
					}
				}
				if (j == 1 && k == 1)
				{
					cout << "31.12." << --year;
					return;
				}
				if (err == 0)
				{
					cout << "Следующий день: " << d << "." << month[m - 1] << "." << year;
					return;
				}
				else
				{
					cout << "Неправильная дата";
					return;
				}
			}
		}
	}

	void DaysTillYourBithday(Date* information, int size)
	{
		cout << "Введите дату ДР в формате 'ДД ММ ГГГГ': " << '\n';
		tm first{}, second{};
		first.tm_mday = checking2();
		first.tm_mon = checking3();
		first.tm_year = checking1();
		first.tm_mon--;
		first.tm_year -= 1900;
		cout << "Выберите дату с файла(номер): ";
		int r;
		while (!(std::cin >> r) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || r < 1 || r > size)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				std::cout << "\nНеверный ввод\n";
				std::cout << "Попробуйте снова: ";
			}
		}
		for (int x = 0; x < size; x++)
		{
			if (x == r - 1)
			{
				string s = "";
				s += information[x].str[0];
				s += information[x].str[1];
				second.tm_mday = stoi(s);
				s = "";
				s += information[x].str[3];
				s += information[x].str[4];
				second.tm_mon = stoi(s);
				s = "";
				for (int i = 6; information[x].str[i] != '\0'; i++)
				{
					s += information[x].str[i];
				}
				second.tm_year = stoi(s);
				second.tm_mon--;
				second.tm_year -= 1900;

				int razn = fabs(second.tm_year - first.tm_year);
				if (razn > 2)
				{
					cout << "Зачем искать дату через большое количество времени?\n";
					return;
				}

				int difference = difftime(mktime(&second), mktime(&first));
				if (difference < 0)
				{
					difference *= -1;
					swap(first, second);
				}
				cout << "Дней между датами: " << fabs(difference / (60 * 60 * 24)) << '\n';
			}
			if (x == r - 1)
				break;
		}
	}

	void IsLeap(Date* information, int size)
	{
		string s = "";
		for (int x = 0; x < size; x++)
		{
			s = "";
			for (int i = 6; information[x].str[i] != '\0'; i++)
			{
				s += information[x].str[i];
			}
			int god = stoi(s);
			if (god % 4 == 0)
			{
				cout << "Год високосный\n";
			}
			else
			{
				cout << "Год не високосный\n";
			}
		}
	}





	void WeekNumber(Date* information, int size)
	{



	}

};

string DateCheck(Date* obj);


int main()
{
	setlocale(LC_ALL, "ru");
	int count = 0;
	Date* date{};
	date = FromFile(date, count);
	int number, dobav = 0;
	while (true)
	{
		cout << "Выберите, что хотите сделать:\n1. Посмотреть информацию\n2. Узнать следующий день даты\n3. Узнать, будет ли год високосныи или нет\n4. Номер недели в году для текущей даты\n5. Дней до дня рождения\n6. Узнать предыдущий день даты\n7. Изменить дату\n8. Добавить дату\n9. Узнать текущую дату\n10. Выйти\nВведите число: ";
		while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > 10)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				std::cout << "\nНеверный ввод\n";
				std::cout << "Попробуйте снова: ";
			}
		}
		if (number == 1)
		{
			showData(date, count);
		}
		else if (number == 2)
		{
			date->NextDay(date, count);
		}
		else if (number == 3)
		{
			date->IsLeap(date, count);
		}
		else if (number == 4)
		{
			date->WeekNumber(date, count);
		}
		else if (number == 5)
		{
			date->DaysTillYourBithday(date, count);
		}
		else if (number == 6)
		{
			date->PreviousDay(date, count);
		}
		else if (number == 7)
		{
			date = change(date, count);
			file1(date, count);
		}
		else if (number == 8)
		{
			printf("Введите, сколько дат вы хотите добавить: ");
			dobav;
			dobav = proverka1();
			date = Dobavlenie(date, count, dobav);
			file1(date, count);
		}
		else if (number == 9)
		{
			time_t seconds = time(NULL);
			tm* localTime = localtime(&seconds);
			cout << localTime->tm_mday << "." << 1 + localTime->tm_mon << "." << 1900 + localTime->tm_year;
		}
		else if (number == 10)
		{
			return 0;
		}
	}
}


void showData(Date* information, int size)
{
	system("cls");
	cout << "========================================================================================================================\n";
	for (int i = 0; i < size; i++)
	{
		cout << information[i].str << '\n';
	}
	cout << "========================================================================================================================\n";
}

Date* FromFile(Date* information, int& size)
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
	num_of_files /= 1;
	size = num_of_files;
	delete[] information;
	information = new Date[num_of_files];
	for (int i = 0; i < size; i++)
	{
		getline(file_start, information[i].str);
		int l = file_start.tellg(); // Возвращает позицию текущего символа во входном потоке.
		if (file_start.peek() == ' ' || file_start.peek() == '\0' || file_start.peek() == '\n')
		{
			l += 4;
		}
		file_start.seekg(l, std::ios_base::beg); // Устанавливает позицию следующего символа, который будет извлечен из входного потока.
	}
	file_start.close();

	return information;
}

int checking3()
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > 12)
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

int checking2()
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > 31)
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

int checking1()
{
	int number;
	printf("Введите число: ");
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1)
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

void SetDataForNumber3(Date* obj, int amount)
{
	cout << "Введите дату: ";
	obj->str = DateCheck(obj);
	printf("\n");
}

Date* change(Date* human, int& amount)
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

void file1(Date* information, int& size)
{
	std::ofstream EndFile;
	EndFile.open("file_end.txt", std::ios::out);
	for (int i = 0; i < size; i++)
	{
		EndFile << information[i].str << '\n';
	}
}

void dw(Date* obj, int& amount, int add, int i)
{
	for (int i = amount; i < amount + add; i++)
	{
		cout << "Введите дату: ";
		obj[i].str = DateCheck(obj);
		printf("\n");
	}
}

Date* Dobavlenie(Date* human, int& amount, int dobav)
{
	Date* lox = new Date[amount + dobav];
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
	human = new Date[amount];
	human = lox;

	return human;
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

string DateCheck(Date* obj)
{
	string str;
	int length;
	int j = 0, check;
	while (true)
	{
		check = 1;
		rewind(stdin);
		getline(cin, str);
		length = str.length();

		while (j < length)
		{
			if (length != 10)
			{
				check = 0;
				break;
			}
			if (!isdigit(str[j]) && str[j] != '.')
			{
				check = 0;
				break;
			}
			else if (isdigit(str[j + 1]) && str[j] == ' ')
			{
				check = 0;
				break;
			}
			else if (j == 0 && str[j] == '\n')
			{
				check = 0;
				break;
			}
			else if (str[2] != '.' && str[5] != '.')
			{
				check = 0;
				break;
			}
			//конкретно условия для даты
			if (str[0] > '3' || (str[0] <= '0' && str[1] <= '0'))
			{
				check = 0;
				break;
			}
			if (str[0] == '3' && str[1] > '1')
			{
				check = 0;
				break;
			}
			if (str[3] == '1' && str[4] > '2')
			{
				check = 0;
				break;
			}
			if (str[3] > '1' || (str[3] <= '0' && str[4] <= '0'))
			{
				check = 0;
				break;
			}
			if (str[6] == '1' && str[7] != '9')
			{
				check = 0;
				break;
			}
			if (str[6] == '2' && str[7] > '0')
			{
				check = 0;
				break;
			}
			if (str[6] > '2' || str[6] <= '0')
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

		printf("Неправильный ввод\nПовторите попытку\n");

		rewind(stdin);
	}
	return str;

}