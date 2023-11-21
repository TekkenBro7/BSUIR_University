#include <iostream>
#include "Header.h"

template<typename T>
class BinaryHeap_arr
{
private:
	Vector<weak_ptr<T>> a;
public:
	void insert(const T& value)
	{
		shared_ptr<T> ptr(new T(value));
		weak_ptr<T> weak = ptr;
		a.push_back(weak);
		int dobav = a.size() - 1;
		int parent = (dobav - 1) / 2;
		while (dobav > 0 && *a[parent].lock() < *a[dobav].lock())
		{
			std::swap(a[parent], a[dobav]);
			dobav = parent;
			parent = (dobav - 1) / 2;
		}
	}
	void print_Arr()
	{
		for (int i = 0; i < a.size(); i++)
		{
			std::cout << *a[i].lock() << " ";
		}
		std::cout << '\n';
	}
	void print_Heap()
	{
		int i = 0;
		int k = 1;
		while (i < a.size())
		{
			while ((i < k) && (i < a.size()))
			{
				std::cout << *a[i].lock() << " ";
				i++;
			}
			std::cout << '\n';
			k = k * 2 + 1;
		}
	}
	T getMax()
	{
		return *a[0].lock();
	}
	int getSize()
	{
		return a.size();
	}
	void removeMax()
	{
		if (a.size() == 0)
		{
			return;
		}
		std::swap(a[0], a[a.size() - 1]);
		a.pop_back();
		int currentIndex = 0;
		int childIndex = 1;
		while (childIndex < a.size())
		{
			if (childIndex + 1 < a.size() && *a[childIndex + 1].lock() > *a[childIndex].lock())
			{
				childIndex++;
			}
			if (*a[currentIndex].lock() < *a[childIndex].lock())
			{
				std::swap(a[currentIndex], a[childIndex]);
				currentIndex = childIndex;
				childIndex = 2 * currentIndex + 1;
			}
			else
			{
				break;
			}
		}
	}
	void buildHead(Vector<T>& other)
	{
		a.clear();
		for (int i = 0; i < other.size(); i++)
		{
			insert(other[i]);
		}
	}
};


int main()
{
	BinaryHeap_arr<int> a;
	a.insert(12);
	a.insert(51);
	a.insert(3);
	a.insert(1000);
	a.insert(1);
	a.insert(345);
	a.insert(-2);
	a.insert(5);
	a.insert(15);
	a.insert(23);
	a.print_Arr();
	std::cout << "\n\n";
	a.print_Heap();
	std::cout << "\n\n";
	std::cout << a.getMax();
	std::cout << "\n\n";
	a.removeMax();
	a.print_Heap();
	std::cout << "\n\n";
	Vector<int> b = { 123, 5435, 1337, 54, 44, 999 };
	a.buildHead(b);
	a.print_Heap();

	return 0;
}