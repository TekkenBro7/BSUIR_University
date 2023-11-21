#include <iostream>
#include "Header.h"

class HashTable
{
protected:
	int size;
	Vector<Stack<Pair<int, std::string>>> table;
	const double A = (sqrt(5) - 1) / 2;
	int hashFunction(int key)
	{
		int x = key / 2 + 1;
		int a = size * fmod((key * x) * A, 1);
		return a;
	}
public:
	HashTable(int tableSize)
	{
		size = tableSize;
		table.resize(size);
	}
	void insert(int key, std::string value)
	{
		int index = abs(hashFunction(key) % size);
		Pair<int, std::string> temp(key, value);
		table[index].push(temp);
	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Стек " << i + 1 << ": " << '\n';
			int k = 0;
			while (k != table[i].Size())
			{
				std::cout << "Ключ: " << table[i][k].first << " " << "значение: " << table[i][k].second << '\n';
				k++;
			}
			std::cout << '\n';
		}
	}
	void deleteAll()
	{
		for (int i = 0; i < table.size(); i++)
		{
			Stack<Pair<int, std::string>> temp;
			while (!table[i].empty())
			{
				table[i].pop();
			}
		}
	}
	std::string Find(int key)
	{
		int index = abs(hashFunction(key) % size);
		for (int i = 0; i < size; i++)
		{
			int k = 0;
			while (k != table[i].Size())
			{
				if (table[index][k].first == key)
				{
					return table[i][k].second;
				}
				k++;
			}			
		}
		return "";
	}
};

class HashTableTask : public HashTable
{
public:
	HashTableTask(int s) : HashTable(s) {}
	void deleteNegative()
	{
		for (int i = 0; i < table.size(); i++)
		{
			Stack<Pair<int, std::string>> temp;
			while (!table[i].empty())
			{
				if (table[i].top().first >= 0)
				{
					temp.push(table[i].top());
				}
				table[i].pop();
			}
			while (!temp.empty())
			{
				table[i].push(temp.top());
				temp.pop();
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	HashTableTask a(5);
	a.insert(1, "1");
	a.insert(2, "2");
	a.insert(3, "3");
	a.insert(4, "4");
	a.insert(5, "5");
	a.insert(-1, "-1");
	a.insert(-2, "-2");
	a.insert(-3, "-3");
	a.insert(-4, "-4");
	a.insert(-5, "-5");
	a.display();
	std::cout << "\n\n";
	std::cout << a.Find(2);
	std::cout << "\n\n";
	a.deleteNegative();
	a.display();

	return 0;
}