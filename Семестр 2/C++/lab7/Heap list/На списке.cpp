#include <iostream>
#include "Header.h"

template<typename T>
class BinaryHeap_List
{
private:
	List<weak_ptr<T>> a;
public:
	void insert(const T& value)
	{
		shared_ptr<T> ptr(new T(value));
		weak_ptr<T> weak = ptr;
		a.push_back(weak);
		int dobav = a.GetSize() - 1;
		int parent = (dobav - 1) / 2;
		while (dobav > 0 && *a[parent].lock() < *a[dobav].lock())
		{
			std::swap(a[parent], a[dobav]);
			dobav = parent;
			parent = (dobav - 1) / 2;
		}
	}
	void print()
	{
		for (int i = 0; i < a.GetSize(); i++)
		{
			std::cout << *a[i].lock() << " ";
		}
		std::cout << '\n';
	}
	void print_Heap()
	{
		int i = 0;
		int k = 1;
		while (i < a.GetSize())
		{
			while ((i < k) && (i < a.GetSize()))
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
		return a.GetSize();
	}
	void removeMax()
	{
		if (a.GetSize() == 0)
		{
			return;
		}
		std::swap(a[0], a[a.GetSize() - 1]);
		a.pop_back();
		int currentIndex = 0;
		int childIndex = 1;
		while (childIndex < a.GetSize())
		{
			if (childIndex + 1 < a.GetSize() && *a[childIndex + 1].lock() > *a[childIndex].lock())
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
	BinaryHeap_List<int> a;
	a.insert(15);
	a.insert(233);
	a.insert(2);
	a.insert(56);
	a.insert(546);
	a.insert(1);
	a.insert(1000);
	Vector<int> b = { 1, 54, 6454, 11000, 52 };
	std::cout << a.getSize() << "\n\n";
	a.buildHead(b);
	a.removeMax();
	a.print_Heap();

	return 0;
}