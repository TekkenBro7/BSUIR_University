#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Реформа английского языка\n";
	cout << "Выполнил: Снежко Максив (группа 253505)\n";
	std::string povtor;
	do
	{
		string mainstring, dopstring;
		cout << "Введите текст: ";
		while (true)
		{
			getline(cin, mainstring);
			if ((mainstring[0] == '\n') || (mainstring[0] == '\0'))
			{
				break;
			}
			std::cout << "Текст до: " << mainstring;
			string str = "ksKsfFzZuUiI";
			long long size = mainstring.size();
			for (int i = 0; i < size; i++)
			{
				// замены с перед e, i, y и в других случаях
				dopstring = mainstring[i];

				if (mainstring[i] == 'c')
				{
					if (mainstring[i + 1] == 'e' || mainstring[i + 1] == 'i' || mainstring[i + 1] == 'y' || mainstring[i + 1] == 'E' || mainstring[i + 1] == 'I' || mainstring[i + 1] == 'Y')
					{
						mainstring[i] = 's';
					}
					else
					{
						mainstring[i] = 'k';
					}
				}

				// замена С
				if (mainstring[i] == 'C')
				{
					if (mainstring[i + 1] == 'e' || mainstring[i + 1] == 'i' || mainstring[i + 1] == 'y' || mainstring[i + 1] == 'E' || mainstring[i + 1] == 'I' || mainstring[i + 1] == 'Y')
					{
						mainstring[i] = 'S';
					}
					else
					{
						mainstring[i] = 'K';
					}
				}

				// замена q на k, а qu на kv
				if (mainstring[i] == 'q')
				{
					if (mainstring[i + 1] == 'u' || mainstring[i + 1] == 'U')
					{
						mainstring[i] = 'k';
						mainstring[i + 1] = 'v';
					}
					else if (mainstring[i + 1] != 'u')
					{
						mainstring[i] = 'k';
					}
				}

				// замена Q на К
				if (mainstring[i] == 'Q')
				{
					if (mainstring[i + 1] == 'u')
					{
						mainstring[i] = 'K';
						mainstring[i + 1] = 'v';
					}
					else if (mainstring[i + 1] == 'U')
					{
						mainstring[i] = 'K';
						mainstring[i + 1] = 'V';
					}
					else if (mainstring[i + 1] != 'u' || mainstring[i + 1] != 'U')
					{
						mainstring[i] = 'K';
					}
				}

				// Замена x на ks
				if (mainstring[i] == 'x')
				{
					size++;
					mainstring.insert(i + 1, str, 0, 2);
					mainstring.erase(i, 1);
				}

				// Замена Х нА KS
				else if (mainstring[i] == 'X')
				{
					size++;
					mainstring.insert(i + 1, str, 2, 2);
					mainstring.erase(i, 1);
				}

				// Замена w на v
				if (mainstring[i] == 'w')
				{
					mainstring[i] = 'v';
				}

				// Замена X на V
				if (mainstring[i] == 'X')
				{
					mainstring[i] = 'V';
				}


				// th на z
				if (mainstring[i] == 't' && mainstring[i + 1] == 'h' || mainstring[i] == 't' && mainstring[i + 1] == 'H')
				{
					size--;
					mainstring.insert(i + 2, str, 6, 1);
					mainstring.erase(i, 2);
				}

				// TH на Z
				if (mainstring[i] == 'T' && mainstring[i + 1] == 'H' || mainstring[i] == 'T' && mainstring[i + 1] == 'h')
				{
					size--;
					mainstring.insert(i + 2, str, 7, 1);
					mainstring.erase(i, 2);
				}

				// ph на f
				if (mainstring[i] == 'p' && mainstring[i + 1] == 'h' || mainstring[i] == 'p' && mainstring[i + 1] == 'H')
				{
					size--;
					mainstring.insert(i + 2, str, 4, 1);
					mainstring.erase(i, 2);
				}

				// PH на F
				if (mainstring[i] == 'P' && mainstring[i + 1] == 'H' || mainstring[i] == 'P' && mainstring[i + 1] == 'h')
				{
					size--;
					mainstring.insert(i + 2, str, 5, 1);
					mainstring.erase(i, 2);
				}

				// you и oo на u
				if (mainstring[i] == 'y' && mainstring[i + 1] == 'o' && mainstring[i + 2] == 'u' || mainstring[i] == 'o' && mainstring[i + 1] == 'o')
				{
					if (mainstring[i] == 'y' && mainstring[i + 1] == 'o' && mainstring[i + 2] == 'u')
					{
						size -= 2;
						mainstring.insert(i + 3, str, 8, 1);
						mainstring.erase(i, 3);
					}
					else
					{
						size--;
						mainstring.insert(i + 2, str, 8, 1);
						mainstring.erase(i, 2);
					}
				}

				// YOU и OO на U
				if (mainstring[i] == 'Y' && mainstring[i + 1] == 'O' && mainstring[i + 2] == 'U' || mainstring[i] == 'O' && mainstring[i + 1] == 'O')
				{
					if (mainstring[i] == 'Y' && mainstring[i + 1] == 'O' && mainstring[i + 2] == 'U' || mainstring[i] == 'Y' && mainstring[i + 1] == 'o' && mainstring[i + 2] == 'u')
					{
						size -= 2;
						mainstring.insert(i + 3, str, 9, 1);
						mainstring.erase(i, 3);
					}
					else
					{
						size--;
						mainstring.insert(i + 2, str, 9, 1);
						mainstring.erase(i, 2);
					}
				}

				// ee на i
				if (mainstring[i] == 'e' && mainstring[i + 1] == 'e' || mainstring[i] == 'e' && mainstring[i + 1] == 'E')
				{
					size--;
					mainstring.insert(i + 2, str, 10, 1);
					mainstring.erase(i, 2);
				}

				// EE на I
				if (mainstring[i] == 'E' && mainstring[i + 1] == 'E' || mainstring[i] == 'E' && mainstring[i + 1] == 'e')
				{
					size--;
					mainstring.insert(i + 2, str, 10, 1);
					mainstring.erase(i, 2);
				}
			}
			string str1 = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxZz";	
			int length = mainstring.size();
			for (int i = 0; i < length; i++) {
				int a = 0, b = i + 1;
				while ((int)mainstring[i] == (int)mainstring[b] || (int)mainstring[i] == (int)mainstring[b] - 32 || (int)mainstring[i] - 32 == (int)mainstring[b]) 
				{
					a++;
					b++;
				}
				if (a) {
					mainstring.replace(i, a + 1, 1, mainstring[i]);
					length -= a;
				}
			}
			std::cout << "\nТекст после: " << mainstring << "\n";
			std::cout << "Для повторного ввода значений введите что угодно,для выхода введите 0: ";
			std::cin >> povtor;
			if (povtor == "0")
			{
				return 0;
			}
		}
	} while (povtor != "0");

	return 0;
}




//ThthththththththththththththththThtH





/*
			int povtorenie{};
			do
			{
				povtorenie = 0;
				int length = mainstring.size();
				for (int j = 0; j < length; j++)
				{
					if (mainstring[j] == 'a' || mainstring[j] == 'A' || mainstring[j] == 'E' || mainstring[j] == 'e' || mainstring[j] == 'o' || mainstring[j] == 'O' || mainstring[j] == 'i' || mainstring[j] == 'I' || mainstring[j] == 'y' || mainstring[j] == 'Y' || mainstring[j] == 'u' || mainstring[j] == 'U')
					{
						break;
					}
					if ((str1.find(mainstring) == string::npos) && (toupper(mainstring[j]) == toupper(mainstring[j + 1])))
					{
						(mainstring).erase(j + 1, 1);
						j--;
						length--;
						povtorenie = 1;
					}
				}
			} while (povtorenie == 1);
			*/