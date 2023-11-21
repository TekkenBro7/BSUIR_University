#define _CRT_SECURE_NO_WARNINGS 
#include<iostream> 
#include<iomanip> 
#include<stdio.h> 
#include<string> 

using namespace std;

class Student
{
private:
	char fullname[32] = "MAKS                           ";
	char address[16] = "Minsk          ";
	int math;
	int fis;
	int rus;
	double GPA;
	union
	{
		char allten[4];
		int tens;
	};
	void calculate_GPA()
	{
		GPA = (math + fis + rus) / 3.0;
	}
	void amount_ten()
	{
		int count = 0;
		if (math == 10)
			count++;
		if (fis == 10)
			count++;
		if (rus == 10)
			count++;
		tens = count;
	}
public:
	Student() {
		math = 9;
		fis = 9;
		rus = 9;
		GPA = 9;
		tens = 0;
	}
	void set_fullname(string str)
	{
		for (int i = 0; i < 31; i++)
		{
			if (str.size() > i)
				fullname[i] = str[i];
			else
				fullname[i] = ' ';
		}
	}
	string get_fullname()
	{
		string str = "";
		for (int i = 0; i < 31; i++)
			str += fullname[i];
		return str;
	}
	void set_address(string str)
	{
		for (int i = 0; i < 15; i++)
		{
			if (str.size() > i)
				address[i] = str[i];
			else
				address[i] = ' ';
		}
	}
	string get_address()
	{
		string str = "";
		for (int i = 0; i < 15; i++)
			str += address[i];
		return str;
	}
	void set_math(int ball)
	{
		math = ball;
		calculate_GPA();
		amount_ten();
	}
	int get_math()
	{
		return math;
	}
	void set_fis(int ball)
	{
		fis = ball;
		calculate_GPA();
		amount_ten();
	}
	int get_fis()
	{
		return fis;
	}
	void set_rus(int ball)
	{
		rus = ball;
		calculate_GPA();
		amount_ten();
	}
	int get_rus()
	{
		return rus;
	}
	double get_GPA()
	{
		return GPA;
	}
	void cout_union()
	{
		amount_ten();
		if (tens < 3)
			cout << tens;
		else
		{
			tens = 15033314;
			allten[3] = '\0';
			cout << allten;
		}
	}
};
long long intcheck(int low, int high);
void read_struct(FILE*& file, Student*& student, int& size);
void first_deal();
void cout_struct(Student*& student, int size);
Student* change(FILE* file, Student*& student, int size);
Student* add(FILE* file, Student*& student, int& size);
Student* del(FILE* file, Student*& student, int& size);
void function(FILE* file, Student*& student, int& size);


int main()
{
	setlocale(LC_ALL, "ru");
	printf("Ведомость абитуриентов содержит ФИО, адрес, оценки по трем предметам. Определить средний балл абитуриентов, проживающих в городе Минске\n");
	printf("Выполнил: Снежко Максим (группа 253505)\n");
	first_deal();
	system("cls");
	FILE* file;
	Student* student = nullptr;
	int size = 0, choose;
	fopen_s(&file, "FILE.bin", "rb+");  // Двоичный файл для чтения
	read_struct(file, student, size);
	while (true)
	{
		cout << "1. Вывести на экран\n";
		cout << "2. Добавить элемент\n";
		cout << "3. Удалить элемент\n";
		cout << "4. Изменить элемент\n";
		cout << "5. Вывести ответ\n";
		cout << "6. Закончить программу\n";
		cout << "\nВведите число: ";
		choose = intcheck(1, 6);

		if (choose == 1)
		{
			if (size == 0)
			{
				printf("Пусто\n");
			}
			else
			{
				cout_struct(student, size);
			}
		}
		if (choose == 2)
		{
			cout_struct(student, size);
			student = add(file, student, size);
			cout_struct(student, size);
		}
		if (choose == 3)
		{
			cout_struct(student, size);
			student = del(file, student, size);
			cout_struct(student, size);
		}
		if (choose == 4)
		{
			cout_struct(student, size);
			student = change(file, student, size);
			cout_struct(student, size);
		}
		if (choose == 5)
		{
			if (size == 0)
			{
				printf("Пусто\n");
			}
			else
			{
				function(file, student, size);
			}
		}
		if (choose == 6)
		{
			cout << "\nПрограмма завершена\n";
			fclose(file);
			delete[] student;
			return 0;
		}
	}
}

long long intcheck(int low, int high) {
	long long val = 0;
	bool flag, out = 1;
	int size;
	std::string line;
	do {
		flag = 0;
		std::getline(std::cin, line);
		size = line.size();
		if (line[0] == ' ')
		{
			printf("Некорректный ввод\n");
			printf("Попробуйте снова: ");
			flag = 1;
			continue;
		}
		if (line[0] == '-')
		{
			if (line[1] > '9' || line[1] < '0')
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
				flag = 1;
				continue;
			}
		}
		else
		{
			if (line[0] > '9' || line[0] < '0')
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
				flag = 1;
				continue;
			}
		}
		for (int i = 0; i < size; i++)
		{
			if (i == 0 && line[i] == '-')
			{
				out = 0;
				continue;
			}
			if (line[i] == ' ')
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
				flag = 1;
				break;
			}
			if ((line[i] <= '9' && line[i] >= '0') || line[i] == '.')
			{
				if (line[i] == '.')
				{
					if (i == size - 1)
					{
						printf("Некорректный ввод\n");
						printf("Попробуйте снова: ");
						flag = 1;
						break;
					}
					for (int j = i + 1; j < size; j++)
					{
						if (line[j] == ' ')
						{
							printf("Некорректный ввод\n");
							printf("Попробуйте снова: ");
							flag = 1;
							break;
						}
						if (line[j] != '0')
						{
							if (line[j] > '9' || line[j] < '0')
							{
								printf("Некорректный ввод\n");
								printf("Попробуйте снова: ");
								flag = 1;
								break;
							}
							printf("Некорректный ввод\n");
							printf("Попробуйте снова: ");
							flag = 1;
							break;
						}
					}
					if (flag)
					{
						break;
					}
					else
					{
						size = i;
						break;
					}
				}
			}
			else
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
				flag = 1;
				break;
			}
		}
		if (size > 18 && !flag)
		{
			printf("Некорректный ввод\n");
			printf("Попробуйте снова: ");
			flag = 1;
		}
	} while (flag);
	if (out)
	{
		for (int i = 0; i < size; i++)
		{
			val *= 10;
			val += line[i] - '0';
		}
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			val *= 10;
			val += line[i] - '0';
		}
		val *= -1;
	}
	if (val < low)
	{
		printf("Некорректный ввод\n");
		printf("Попробуйте снова: ");
		val = intcheck(low, high);
	}
	if (val > high)
	{
		printf("Некорректный ввод\n");
		printf("Попробуйте снова: ");
		val = intcheck(low, high);
	}
	return val;
}
void function(FILE* file, Student*& student, int& size)
{
	for (int i = 1; i < size; i++)
	{
		if (student[i].get_fullname() < student[i - 1].get_fullname())
		{
			for (int j = i; student[j].get_fullname() < student[j - 1].get_fullname() && j > 0; j--)
			{
				std::swap(student[j], student[j - 1]);
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (student[i].get_address() == "c.Minsk        ")
		{
			cout << "ФИО:  ";
			cout << student[i].get_fullname() << '\n';
			cout << "Адресс: " << student[i].get_address() << '\n';
			cout << "Балл по математике: " << student[i].get_math() << '\n';
			cout << "Балл по физике: " << student[i].get_fis() << '\n';
			cout << "Балл по русскому: " << student[i].get_rus() << '\n';
			cout << "Средний балл: " << std::setprecision(2) << student[i].get_GPA() << '\n';
		}
	}
	cout << '\n';
	read_struct(file, student, size);
}
void read_struct(FILE*& file, Student*& student, int& size)
{
	fseek(file, 0, SEEK_SET);
	char name[32];
	char house[16];
	string str;
	int score;
	fread(&size, sizeof(int), 1, file);
	student = new Student[size];
	for (int i = 0; i < size; i++)
	{
		str = "";
		fread(&name, sizeof(char), 32, file);
		for (int i = 0; i < 31; i++)
			str += name[i];
		student[i].set_fullname(str);
		fread(&house, sizeof(char), 16, file);
		str = "";
		for (int i = 0; i < 15; i++)
			str += house[i];
		student[i].set_address(str);
		fread(&score, sizeof(int), 1, file);
		student[i].set_math(score);
		fread(&score, sizeof(int), 1, file);
		student[i].set_fis(score);
		fread(&score, sizeof(int), 1, file);
		student[i].set_rus(score);
	}
}
void first_deal()
{
	int size;
	string ENTER;
	FILE* file = nullptr;
	cout << "Введите количество студентов: ";
	size = intcheck(1, 100);
	Student* student = new Student[size];
	for (int i = 0; i < size; i++)
	{
		int score;
		string str = "";
		while (true)
		{
			cout << "Введите ФИО: ";
			rewind(stdin);
			getline(cin, str);
			if (str.size() < 32)
			{
				break;
			}
			else
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
			}
		}
		student[i].set_fullname(str);
		str = "";
		while (1)
		{
			cout << "Введите адрес: ";
			rewind(stdin);
			getline(cin, str);
			if (str.size() < 16)
				break;
			else
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
			}
		}
		student[i].set_address(str);
		rewind(stdin);
		cout << "Введите балл по математике: ";
		score = intcheck(1, 10);
		student[i].set_math(score);
		cout << "Введите балл по физике: ";
		score = intcheck(1, 10);
		student[i].set_fis(score);
		cout << "Введите балл по русскому: ";
		score = intcheck(1, 10);
		student[i].set_rus(score);
	}
	file = fopen("FILE.bin", "wb+"); // Двоичный файл для записи
	string str = "";
	char to_str[32];
	to_str[31] = '\0';
	char to_str2[16];
	to_str2[15] = '\0';
	int score;
	double average;
	fwrite(&size, sizeof(int), 1, file);
	for (int i = 0; i < size; i++)
	{
		str = student[i].get_fullname();
		for (int i = 0; i < 31; i++)
			to_str[i] = str[i];
		fwrite(&to_str, sizeof(char), 32, file);
		str = "";
		str = student[i].get_address();
		for (int i = 0; i < 15; i++)
			to_str2[i] = str[i];
		fwrite(&to_str2, sizeof(char), 16, file);
		score = student[i].get_math();
		fwrite(&score, sizeof(int), 1, file);
		score = student[i].get_fis();
		fwrite(&score, sizeof(int), 1, file);
		score = student[i].get_rus();
		fwrite(&score, sizeof(int), 1, file);
	}
	fclose(file);
	delete[] student;
}
void cout_struct(Student*& student, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "ФИО: ";
		cout << student[i].get_fullname() << '\n';
		cout << "Адресс: " << student[i].get_address() << '\n';
		cout << "Балл по математике: " << student[i].get_math() << '\n';
		cout << "Балл по физике: " << student[i].get_fis() << '\n';
		cout << "Балл по русскому: " << student[i].get_rus() << '\n';
		cout << "Средний балл: " << std::setprecision(2) << student[i].get_GPA() << '\n';
	}
	cout << '\n';
}
Student* change(FILE* file, Student*& student, int size)
{
	int rem_i = -1;
	string str1, str2;
	Student* new_student = nullptr;
	while (true)
	{
		rewind(stdin);
		while (true)
		{
			cout << "Введите имя: ";
			getline(cin, str1);
			rewind(stdin);
			if (str1.size() < 32)
				break;
			else
			{
				printf("Некорректный ввод\n");
				printf("Попробуйте снова: ");
			}
		}
		while (str1.size() < 31)
			str1 += ' ';
		for (int i = 0; i < size; i++)
		{
			if (str1 == student[i].get_fullname())
				rem_i = i;
		}
		if (rem_i == -1)
		{
			cout << "Ошибка\n";
		}
		else
		{
			while (true)
			{
				long long choose;
				cout << "1. Поменять ФИО\n2. Поменять адресс\n3. Поменять балл по математике\n4. Поменять балл по физике\n5. Поменять балл по русскому\n 6. Выйти\n";
				cout << "Введите цифру: ";
				choose = intcheck(1, 6);
				char t[32], c[16];
				t[31] = '\0';
				c[15] = '\0';
				int score_math = -1, score_fis = -1, score_rus = -1;
				if (choose == 1)
				{
					rewind(stdin);
					while (true)
					{
						cout << "Введите ФИО: ";
						getline(cin, str1);
						rewind(stdin);
						if (str1.size() < 32)
							break;
						else
						{
							printf("Некорректный ввод\n");
							printf("Попробуйте снова: ");
						}
					}
					student[rem_i].set_fullname(str1);
					str1 = student[rem_i].get_fullname();
					for (int i = 0; i < 31; i++)
						t[i] = str1[i];
					fseek(file, rem_i * 60 + 4, SEEK_SET);
					fwrite(&t, sizeof(char), 32, file);
				}
				if (choose == 2)
				{
					rewind(stdin);
					while (1)
					{
						cout << "Введите адресс: ";
						getline(cin, str2);
						rewind(stdin);
						if (str2.size() < 16)
							break;
						else
						{
							printf("Некорректный ввод\n");
							printf("Попробуйте снова: ");
						}
					}
					student[rem_i].set_address(str2);
					str2 = student[rem_i].get_address();
					for (int i = 0; i < 15; i++)
						c[i] = str2[i];
					fseek(file, rem_i * 60 + 36, SEEK_SET);
					fwrite(&c, sizeof(char), 16, file);
				}
				if (choose == 3)
				{
					cout << "Введите балл по математике: ";
					score_math = intcheck(1, 10);
					student[rem_i].set_math(score_math);
					fseek(file, rem_i * 60 + 52, SEEK_SET);
					fwrite(&score_math, sizeof(int), 1, file);
				}
				if (choose == 4)
				{
					cout << "Введите балл по физике: ";
					score_fis = intcheck(1, 10);
					student[rem_i].set_fis(score_fis);
					fseek(file, rem_i * 60 + 56, SEEK_SET);
					fwrite(&score_fis, sizeof(int), 1, file);
				}
				if (choose == 5)
				{
					cout << "Введите балл по русскому: ";
					score_rus = intcheck(1, 10);
					student[rem_i].set_rus(score_rus);
					fseek(file, rem_i * 60 + 60, SEEK_SET);
					fwrite(&score_rus, sizeof(int), 1, file);
				}
				if (choose == 6)
				{
					cout << '\n' << "Успешно\n";
					delete[] student;
					read_struct(file, new_student, size);
					break;
				}
			}
			break;
		}
	}
	return new_student;
}
Student* add(FILE* file, Student*& student, int& size)
{
	string str1, str2;
	int amount, score_math, score_fis, score_rus;
	char t[32], c[16];
	t[31] = '\0';
	c[15] = '\0';
	cout << "Сколько добавить: ";
	cin >> amount;
	fseek(file, 0, SEEK_SET);
	size += amount;
	fwrite(&size, sizeof(int), 1, file);
	fseek(file, (size - amount) * 60 + 4, SEEK_SET);
	for (int i = 0; i < amount; i++)
	{
		while (1)
		{
			cout << "Введите ФИО: ";
			rewind(stdin);
			getline(cin, str1);
			if (str1.size() < 32)
				break;
			else
				printf("Некорректный ввод\n");
			printf("Попробуйте снова: ");
		}
		while (str1.size() < 31)
			str1 += ' ';
		for (int i = 0; i < 31; i++)
			t[i] = str1[i];
		fwrite(&t, sizeof(char), 32, file);
		while (1)
		{
			cout << "Введите адресс: ";
			rewind(stdin);
			getline(cin, str2);
			if (str2.size() < 16)
				break;
			else
				printf("Некорректный ввод\n");
			printf("Попробуйте снова: ");
		}
		while (str2.size() < 15)
			str2 += ' ';
		rewind(stdin);
		for (int i = 0; i < 15; i++)
			c[i] = str2[i];
		fwrite(&c, sizeof(char), 16, file);
		cout << "Введите балл по математике: ";
		score_math = intcheck(1, 10);
		fwrite(&score_math, sizeof(int), 1, file);
		cout << "Введите балл по физике: ";
		score_fis = intcheck(1, 10);
		fwrite(&score_fis, sizeof(int), 1, file);
		cout << "Введите балл по русскому: ";
		score_rus = intcheck(1, 10);
		fwrite(&score_rus, sizeof(int), 1, file);
	}
	delete[] student;
	Student* new_student = nullptr;
	read_struct(file, new_student, size);
	return new_student;
}
Student* del(FILE* file, Student*& student, int& size)
{
	int dop = -1;
	string str;
	while (1)
	{
		cout << "Введите ФИО, чтобы удалить: ";
		rewind(stdin);
		getline(cin, str);
		rewind(stdin);
		while (str.size() < 31)
			str += ' ';
		for (int i = 0; i < size; i++)
		{
			if (str == student[i].get_fullname())
				dop = i;
		}
		if (dop == -1)
		{
			printf("Некорректный ввод\n");
			printf("Попробуйте снова: ");
		}
		else
		{
			int count = 0;
			int score_math, score_fis, score_rus;
			char name[32], adr[16];
			name[31] = '\0';
			adr[15] = '\0';
			for (; count < size - dop; count++)
			{
				fseek(file, (count + dop + 1) * 60 + 4, SEEK_SET);
				fread(&name, sizeof(char), 32, file);
				fread(&adr, sizeof(char), 16, file);
				fread(&score_math, sizeof(int), 1, file);
				fread(&score_fis, sizeof(int), 1, file);
				fread(&score_rus, sizeof(int), 1, file);
				fseek(file, (count + dop) * 60 + 4, SEEK_SET);
				fwrite(&name, sizeof(char), 32, file);
				fwrite(&adr, sizeof(char), 16, file);
				fwrite(&score_math, sizeof(int), 1, file);
				fwrite(&score_fis, sizeof(int), 1, file);
				fwrite(&score_rus, sizeof(int), 1, file);
			}
			fseek(file, (count + dop - 1) * 60 + 4, SEEK_SET);
			for (int i = 0; i < 31; i++)
				name[i] = ' ';
			for (int i = 0; i < 15; i++)
				adr[i] = ' ';
			fwrite(&name, sizeof(char), 32, file);
			fwrite(&adr, sizeof(char), 16, file);
			int zero = 0;
			fwrite(&zero, sizeof(int), 1, file);
			fwrite(&zero, sizeof(int), 1, file);
			fwrite(&zero, sizeof(int), 1, file);
			break;
		}
	}
	size--;
	fseek(file, 0, SEEK_SET);
	fwrite(&size, sizeof(int), 1, file);
	cout << "\nВыполнено\n";
	delete[] student;
	Student* new_student = nullptr;
	read_struct(file, new_student, size);
	return new_student;
}