#include <iostream>

int proverka() {
	int a;

	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	while (a <= 0)
	{
		std::cout << "Error" << '\n';
		std::cin >> a;
	}
	return a;
}
long double proverka1() {
	long double a;
	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(50000, '\n');

	}
	return a;
}
int proverka3()
{
	int a;

	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	while (a < 0 || a > 2)
	{
		std::cout << "Error" << '\n';
		std::cin >> a;
	}
	return a;

}

int main()
{
	setlocale(LC_ALL, "ru");
	int n, vibor{};
	srand(time(NULL));
	std::cout << "Ввести одномерный статистический массив из n элементов и определить, симметричен ли он, то есть читается ли он справа налево и слева направо" << '\n';
	std::cout << "Выполнил: Снежко Максим Андреевич(группа 253505)" << '\n';
	std::cout << "Вариант 10" << '\n';
	std::cout << "Введите количество элементов ";
	n = proverka();
	double a[1000]{};
	std::cout << "Нажмите 1, чтобы ввести элементы самому\nНажмите 2, чтобы ввести элементы через рандом\nНажмите 0, чтобы Завершить программу\n";
	vibor = proverka3();
	if (vibor == 0)
		exit(0);
	else if (vibor == 1)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << "Введите a[" << i << "]: ";
			a[i] = proverka1();
		}
	}
	else if (vibor == 2)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 10;
		}
	}

	for (int j = 0; j < n; j++)
	{
		std::cout << "a[" << j << "]: " << a[j] << '\n';
	}
	for (int i = 0; i < (n / 2); i++)
		if (a[i] != a[n - i - 1])
		{
			std::cout << "Не является симметричным" << '\n';
			return 0;
		}
	std::cout << "Является симметричным" << '\n';
	return 0;
}