#include <iostream>


extern "C" __declspec(dllexport) long long proverka()
{
	long long a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
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
extern "C" __declspec(dllexport) long long proverka1()
{
	long double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
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
extern "C" __declspec(dllexport) void privetstvie()
{
	printf("Для заданного одномерного массива B из N элементов найти количество элементов массива, для которых выполняется условие\n(cosBi2>0)^(Bi<0). Рекурсивную функцию применять каждый раз отдельно для первой трети массива и для остальной части (2/3) массива. Рекурсивные вызовы заканчивать, когда останется только один или два элемента.\n");
	printf("Выполнил: Снежко Максим Андреевич(группа 253505)\n");
	printf("Введите количество элементов массива: ");
}
extern "C" __declspec(dllexport) long double* massive(long double* arr, long long N)
{
	printf("Введите элементы массива: ");

	for (int i = 0; i < N; i++)
		arr[i] = proverka1();

	return arr;

}
extern "C" __declspec(dllexport) void iznachalniy(long double* arr, long long N)
{
	printf("Изначальный массив\n\n");
	for (int i = 0; i < N; i++)
	{
		//	arr[i] = -rand();
		std::cout << arr[i] << " ";
	}
	printf("\n");

}
extern "C" __declspec(dllexport) long double summa(long long i, long double* arr, long long num)
{
	if (i == num - 1)
	{
		return 0;
	}
	else
	{
		if (cos(arr[i] * arr[i]) > 0 && arr[i] < 0)
		{
			return summa(i + 1, arr, num) + 1;
		}
		else
		{
			return summa(i + 1, arr, num);
		}
	}
}
extern "C" __declspec(dllexport) void other(long double* arr, long long N)
{
	long long sum1 = 0, sum2 = 0, T;
	T = N / 3;
	if (N < 3)
	{
		sum1 = summa(0, arr, N);
		std::cout << "\nКоличество: " << sum1;
	}
	else
	{

		sum1 = summa(0, arr, T);
		sum2 = summa(T + 1, arr, N);
		std::cout << '\n';
		std::cout << "\nКоличество: " << sum1 + sum2;
	}
}
extern "C" __declspec(dllexport) void destroyer(long double* arr)
{
	delete[] arr;
}