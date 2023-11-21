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
int mins()
{
	char a;
	bool g = true;
	while (g)
	{
		std::cout << "Элемент: ";
		g = false;
		std::cin >> a;
		if (a != '.' && a != '*' || std::cin.peek() != '\n')
		{
			g = true;
			std::cout << "Неверный ввод, повторите попытку!\n";

			std::cin.clear();
			std::cin.ignore(9000, '\n');
		}
	}
	return a;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	std::cout << "На вход подаётся поле для игры в сапер размером n*m символов, где символ '.' означает пустое место, а символ '*' - бомбу. Требуется дополнить это поле числами, как в оригинальной игре." << '\n';
	std::cout << "Выполнил: Снежко Максим Андреевич(группа 253505)" << '\n';
	std::cout << "Введите размер поля(сначала строки, потом столбцы): ";
	int rows, cols, random, vibor;
	rows = proverka();
	cols = proverka();
	

	
	char** arr = new char* [rows];    // Объявление первого динамического массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[cols];
	}
	
	
	/*char** arr = (char**)malloc(rows * sizeof(char*));
	for (int i = 0; i < rows; i++) 
	{
		arr[i] = (char*)malloc(cols * sizeof(char));
	}
	*/

	std::cout << "Нажмите 1, чтобы ввести элементы самому\nНажмите 2, чтобы ввести элементы через рандом\nНажмите 0, чтобы Завершить программу\n";
	vibor = proverka3();
	if (vibor == 0)
		exit(0);
	else if (vibor == 1)
	{
		std::cout << "Введите . если это пустая клетка или * если это мина.\n";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = mins();
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] == '*')
				{
					if (i + 1 != rows && arr[i + 1][j] == '*')
						continue;
					if (i + 1 != rows)
						arr[i + 1][j] = '1';

					if(i - 1 >= 0 && arr[i - 1][j] == '*')
						continue;

					if (i - 1 >= 0)
						arr[i - 1][j] = '1';

						if (j + 1!= cols && arr[i][j + 1] == '*')
							continue;
						if (j + 1 != cols)
							arr[i][j + 1] = '1';

							if (j - 1 >= 0 && arr[i][j - 1] == '*')
								continue;
							if (j - 1 >= 0)
								arr[i][j - 1] = '1';
				}
				else
					arr[i][j] = '.';
			}
		}
	}
	else if (vibor == 2)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				random = rand() % 10;
				if (random == 0)
				{
					arr[i][j] = '*';
					if (arr[i][j] == '*')
					{
						if (i + 1 != rows && arr[i + 1][j] == '*')
							continue;
						if (i + 1 != rows)
							arr[i + 1][j] = '1';

						if (i - 1 >= 0 && arr[i - 1][j] == '*')
							continue;

						if (i - 1 >= 0)
							arr[i - 1][j] = '1';

						if (j + 1 != cols && arr[i][j + 1] == '*')
							continue;
						if (j + 1 != cols)
							arr[i][j + 1] = '1';

						if (j - 1 >= 0 && arr[i][j - 1] == '*')
							continue;
						if (j - 1 >= 0)
							arr[i][j - 1] = '1';
					}
					else
						arr[i][j] = '.';
				}
			}
		}
	}
	int d = '0';
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] != '*')
			{
				d = 0;
				if (i - 1 >= 0 && arr[i - 1][j] == '*')
				{
					d++;
				}
				if (i + 1 != rows && arr[i + 1][j] == '*')
				{
					d++;
				}
				if (j - 1 >= 0 && arr[i][j - 1] == '*')
				{
					d++;
				}
				if (j + 1 != cols && arr[i][j + 1] == '*')
				{
					d++;
				}
				if ((i - 1 >= 0) && (j - 1 >= 0) && arr[i - 1][j - 1] == '*')
				{
					d++;
				}
				if ((i + 1 != rows) && (j + 1 != cols) && arr[i + 1][j + 1] == '*')
				{
					d++;
				}
				if ((j - 1 >= 0) && (i + 1 != rows) && arr[i + 1][j - 1] == '*')
				{
					d++;
				}
				if ((j + 1 != cols) && (i - 1 >= 0) && arr[i - 1][j + 1] == '*')
				{
					d++;
				}
				if (d == 0) arr[i][j] = '.';
				else arr[i][j] = '0' + d;
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}

	/*for (int i = 0; i < rows; i++)
		free(arr[i]);
	free(arr);
	*/
	
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
		
	return 0;
}


/*


for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			random = rand() % 10;
			if (random == 0)
			{
				arr[i][j] = '*';
				if (arr[i][j] == '*')
				{
					if (i - 1 >= 0)
						arr[i - 1][j] = '1';

					if (i + 1 != rows)
						arr[i + 1][j] = '1';

					if (j - 1 >= 0)
						arr[i][j - 1] = '1';

					if (j + 1 != cols)
						arr[i][j + 1] = '1';
				}
			}
			else
			{
				arr[i][j] = '.';
			}
		}
	}


*/