#include <iostream>
#include <cmath>
#include <Windows.h>


int main()
{
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef long long(*Proverka)();
	Proverka proverka;
	proverka = (Proverka)GetProcAddress(load, "proverka");

	typedef long long(*Proverka1)();
	Proverka1 proverka1;
	proverka1 = (Proverka1)GetProcAddress(load, "proverka1");

	typedef void (*Privetstvie)();
	Privetstvie privetstvie;
	privetstvie = (Privetstvie)GetProcAddress(load, "privetstvie");

	typedef long double* (*Massive)(long double*, long long);
	Massive massive;
	massive = (Massive)GetProcAddress(load, "massive");

	typedef void (*Iznachalniy)(long double*, long long);
	Iznachalniy iznachalniy;
	iznachalniy = (Iznachalniy)GetProcAddress(load, "iznachalniy");

	typedef long double (*Summa)(long long, long double*, long long);
	Summa summa;
	summa = (Summa)GetProcAddress(load, "summa");

	typedef void (*Other)(long double*, long long);
	Other other;
	other = (Other)GetProcAddress(load, "other");

	typedef void (*Destroyer)(long double*);
	Destroyer destroyer;
	destroyer = (Destroyer)GetProcAddress(load, "destroyer");

	setlocale(LC_ALL, "ru");
	privetstvie();
	int x = 1;
	while (x == 1)
	{
		printf("Введите количество элементов массива: ");
		long long N, T, sum1 = 0, sum2 = 0;
		N = proverka();
		long double* arr = new long double[N];
		T = N / 3;
		massive(arr, N);
		iznachalniy(arr, N);
		other(arr, N);
		destroyer(arr);
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

	FreeLibrary(load);

}