#include <iostream>
#include "Header.h"
#include <initializer_list>

using namespace std;

struct HashFunctions
{
	int operator()(const double& key)
	{
		int hash = (int)key;
		return hash % 123;
	}
	int operator()(const string& key)
	{
		int hash = 0;
		for (int i = 0; i < key.size(); i++)
		{
			hash += hash * 1054 + key[i];
		}
		return hash;
	}
};

template<typename KeyType, typename ValueType, typename hash>
class unorder_map
{
private:
	int size;
	int count;
	hash hashFunction;
	Vector<ForwardList<Pair<KeyType, ValueType>>> table;
public:
	unorder_map()
	{
		count = 0;
		size = 5;
		table.resize(size);
	}
	unorder_map(int amount)
	{
		count = 0;
		size = amount;
		table.resize(size);
	}
	~unorder_map()
	{
		clear();
	}
	bool isEmpty()
	{
		return count == 0;
	}
	bool contains(KeyType key)
	{
		int index = abs(hashFunction(key)) % size;
		ValueType a = find(key);
		if (a)
		{
			return true;
		}
		return false;
	}
	int Size()
	{
		return size;
	}
	void rehash(int size)
	{
		if (this->size > size)
		{
			return;
		}
		Vector<ForwardList<Pair<KeyType, ValueType>>> table_new;
		table_new.resize(size);
		for (int i = 0; i < table.size(); i++)
		{
			for (const auto& element : table[i])
			{
				int index = abs(hashFunction(element.first)) % size;
				table_new[index].push_front(element);
			}
		}
		this->size = size;
		table = std::move(table_new);
	}
	void insert(KeyType key, ValueType value)
	{
		int x = size / 1.5;
		if (count >= x)
		{
			rehash(size * 2);
		}
		int index = abs(hashFunction(key)) % size;
		for (auto& element : table[index])
		{
			if (element.first == key)
			{
				element.second = value;
				return;
			}
		}
		Pair<KeyType, ValueType> values(key, value);
		table[index].push_front(values);
		count++;
	}
	void print()
	{
		for (const auto& list : table)
		{
			if (list.empty())
			{
				std::cout << "-------\n";
			}
			else
			{
				for (const auto& element : list)
				{
					std::cout << "Ключ: " << element.first << ", значение: " << element.second << '\n';
				}
			}
		}
	}
	ValueType find(KeyType key)
	{
		int index = abs(hashFunction(key)) % size;
		for (const auto& element : table[index])
		{
			if (element.first == key)
			{
				return element.second;
			}
		}
		return ValueType();
	}
	void remove(KeyType key)
	{
		int index = abs(hashFunction(key)) % size;
		auto& list = table[index];
		int zxc = 0;
		for (auto& element : table[index])
		{
			if (element.first == key)
			{
				table[index].removeAt(zxc);
				--count;
				return;
			}
			zxc;
		}
		return;
	}
	void clear()
	{
		for (int i = 0; i < table.size(); i++)
		{
			table[i].clearr();
		}
		count = 0;
	}
	ValueType& operator[](const KeyType& key)
	{
		int index = abs(hashFunction(key)) % size;
		for (auto element : table[index])
		{
			if (element.first == key)
			{
				return element.second;
			}
		}
		Pair<KeyType, ValueType> values(key, ValueType{});
		table[index].push_front(values);
		count++;
		return table[index].front().second;
	}
	const ValueType& operator[](const KeyType& key) const
	{
		int index = abs(hashFunction(key)) % size;
		for (const auto& element : table[index])
		{
			if (element.first == key)
			{
				return element.second;
			}
		}
		throw std::out_of_range("Ключ не найден");
	}
	ValueType& at(const KeyType& key)
	{
		int index = abs(hashFunction(key)) % size;
		for (auto& element : table[index])
		{
			if (element.first == key)
			{
				return element.second;
			}
		}
		throw std::out_of_range("Ключ не найден");
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	unorder_map<string, int, HashFunctions> a;
	a.insert("хук", 1337);
	a.insert("rwrrr", 1337);
	a.insert("ttt", 1);
	a.print();
	std::cout << "\n\n\n";
	a.insert("qqq", 2);
	a.insert("qqq", 123);
	a.print();
	cout << a.contains("хук") << '\n';
	cout << a.contains("Хук") << '\n';
	cout << a.find("хуй") << '\n';
	cout << a.find("Хуй") << '\n';
	a["213"] = 12344;
	a["213"] = 100;
	cout << a.find("хук") << '\n';
	std::cout << a.at("хук");
	//std::cout << a.at("ййцу");
	a.print();
	a.remove("qqq");
	cout << "\n\n\n";
	a.clear();
	a.print();
	
	return 0;
}