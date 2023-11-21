#include <iostream>

using namespace std;

class Vector
{
private:
	int* arr;
	int size = 0;
	int capacity = 0;

public:
	Vector()
	{
		arr = new int[1];
		capacity = 1;
	}

	~Vector() 
	{
		delete[] arr;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	int Capacity()
	{
		return capacity;
	}

	void addMemory()
	{
		capacity *= 2;
		int* tmp = arr;
		arr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = tmp[i];
		}
		delete[] tmp;
	}

	void push_back(const int& value)
	{
		if (size >= capacity)
		{
			addMemory();
		}
		arr[size++] = value;
	}

	void remove(int index) 
	{
		for (int i = index + 1; i < size; ++i) 
		{
			arr[i - 1] = arr[i];
		}
		--size;
	}

	void pop_back() 
	{
		if (size > 0) 
		{
			--size;
		}
	}

	int& operator[](int index) {
		return arr[index];
	}

	const int& operator[](int index) const {
		return arr[index];
	}

	int GetSize()
	{
		return size;
	}
};


int main()
{   
	Vector a;
	a.push_back(5);
	a.push_back(10);
	a.push_back(15);
	a.push_back(20);

	for (int i = 0; i < a.GetSize(); i++)
	cout << a[i] << " ";

}
