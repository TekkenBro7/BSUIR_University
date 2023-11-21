#include <iostream>
#include "Header.h"

class HashTable
{
private:
	int size;
	int count;
	Vector<Pair<std::string, int>> table;
	Vector<int> TableSize = { 16,64,128,2048 };
	const double A = (sqrt(5) - 1) / 2;
public:
	HashTable()
	{
		count = 0;
		size = 16;
		table.resize(size);
		for (int i = 0; i < size; i++)
		{
			table[i] = Pair<std::string, int>{ "", -1 };
		}
	}
	HashTable(int size)
	{
		this->size = TableSize[size];
		count = 0;
		table.resize(this->size);
		for (int i = 0; i < size; i++)
		{
			table[i] = Pair<std::string, int>{ "", -1 };
		}
	}
	bool isEmpty()
	{
		return count == 0;
	}
	int hashFunction(std::string key)
	{
		int sum = 0;
		for (int i = 0; i < key.size(); i++)
		{
			sum += key[i];
		}
		int a = size * fmod(sum * A, 1);
		return a;
	}
	void insert(std::string key, int value)
	{
		int index = abs(hashFunction(key)) % size;
		if (table[index].first == "")
		{
			table[index].first = key;
			table[index].second = value;
			count++;
		}
		else
		{
			while (table[index].first != "")
			{
				index = (index + 1) % size;
				if (table[index].first == key)
				{
					table[index].first = key;
					table[index].second = value;
					return;
				}
			}
			table[index].first = key;
			table[index].second = value;
			count++;
		}
	}
	void print()
	{
		for (int i = 0; i < table.size(); i++)
		{
			if (table[i].first == "")
			{
				std::cout << "-------\n";
			}
			else
			{
				std::cout << "Ключ: " << table[i].first << ", значение: " << table[i].second << '\n';
			}
		}
	}
	int find(std::string key)
	{
		int index = abs(hashFunction(key)) % size;
		int i = 0;
		while (index != size && table[index].first != "" && i < size)
		{
			if (table[index].first == key)
			{
				return table[index].second;
			}
			if (index == size)
			{
				index = -1;
			}
			index++;
			i++;
		}
		return -1;
	}
	void remove(std::string key)
	{
		int index = abs(hashFunction(key)) % size;
		int i = 0;
		while (table[index].first != "" && i < size)
		{
			if (table[index].first == key)
			{
				table[index].first = "";
				table[index].second = -1;
				count--;
			}
			index++;
			i++;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Введите индекс от 1 - 4(1 - 16, 2 - 64, 3 - 128, 4 - 2048\n";
	int x;
	std::cin >> x;	
	if (x != 1 && x != 2 && x != 3 && x != 4)
	{
		return 0;
	}
	else
	{
		x -= 1;
		HashTable a(x);
		a.insert("макс", 1);
		a.insert("саня", 2);
		a.insert("ваня", 3);
		a.insert("петя", 4);
		a.insert("никита", 5);
		a.insert("никита", 123);
		a.insert("гоша", 6);
		a.insert("матвей1", 7);
		a.insert("матвей2", 8);
		a.insert("матвей3", 9);
		a.insert("матвей4", 10);
		a.insert("матвей5", 11);
		a.insert("матвей6", 12);
		a.insert("матвей7", 13);
		a.insert("матвей8", 14);
		a.insert("матвей9", 15);
		a.insert("матвей10", 16);
		a.insert("матвей11", 17);
		a.insert("матвей555", 18);
		a.insert("матвей12", 19);
		a.insert("матвей13", 120);

		std::cout << a.find("матвей13") << '\n';

		a.print();
	}
}