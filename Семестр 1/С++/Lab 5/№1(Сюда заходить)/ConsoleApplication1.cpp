#include <iostream>
#include <cmath>

long long proverka();
long double* massive(long long);
long double* massive2(long double*, long long);
void destroyer1(long double*);

int main()
{
	int x = 1;
	setlocale(LC_ALL, "ru");
	printf("Составить программу вычисления значений элементов одномерного динамического массива c заданной формулой.\nСозданный массив и результат произведения вывести на экран.\nВыполнил: Снежко Максим Андреевич(группа 253505)\n");
	long long n;
	while (x == 1)
	{
		printf("Введите количество элементов массива: ");
		n = proverka();
		long double* arr;
		arr = massive(n);
		massive2(arr, n);
		destroyer1(arr);
		printf("Запустить программу по новой ? (0 - нет, 1 - да): ");
		while (!(std::cin >> x) || (std::cin.peek() != '\n') || (x != 0 && x != 1))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				std::cout << "Некорректный ввод\n";
				std::cout << "Попробуйте снова: ";
			}
		}
	}
	return 0;
}