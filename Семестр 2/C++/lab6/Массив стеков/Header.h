#pragma once

template<typename T>
class Stack
{
private:
	T* arr;
	int size;

public:
	Stack()
	{
		arr = nullptr;
		size = 0;
	}
	~Stack()
	{
		if (size > 0)
		{
			delete[] arr;
		}
	}
	void push(T item)
	{
		T* a;
		a = arr;
		arr = new T[size + 1];
		size++;
		for (int i = 0; i < size - 1; i++)
		{
			arr[i] = a[i];
		}
		arr[size - 1] = item;
		if (size > 1)
		{
			delete[] a;
		}
	}
	void Print()
	{
		if (size == 0)
		{
			return;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << " ";
			}
		}
	}
	T pop()
	{
		if (size == 0)
		{
			return T();
		}
		size--;
		return arr[size];
	}
	T top()
	{
		if (size == 0)
		{
			return T();
		}
		return arr[size - 1];
	}
	T& operator[](int index)
	{
		return arr[index];
	}
	bool empty()
	{
		return size == 0;
	}
	int Size()
	{
		return size;
	}
};

template <typename T>
class iterator
{
private:
	T* ptr;
public:
	iterator()
	{
		ptr = nullptr;
	}
	iterator(T* p)
	{
		ptr = p;
	}
	bool operator==(const iterator& rhs) const
	{
		return ptr == rhs.ptr;
	}
	bool operator!=(const iterator& rhs) const
	{
		return !(*this == rhs);
	}
	bool operator >(const iterator& rhs) const
	{
		return (*this > rhs);
	}
	bool operator <(const iterator& rhs) const
	{
		return (*this < rhs);
	}
	bool operator >=(const iterator& rhs) const
	{
		return (*this >= rhs);
	}
	bool operator <=(const iterator& rhs) const
	{
		return (*this <= rhs);
	}
	const T& operator*()
	{
		return *ptr;
	}
	iterator& operator= (const iterator& other)
	{
		ptr = other.ptr;
		return  *this;
	}
	iterator& operator++()
	{
		++ptr;
		return *this;
	}
	iterator operator++(int)
	{
		iterator temp(*this);
		++* this;
		return temp;
	}
	iterator& operator--()
	{
		--ptr;
		return *this;
	}
	iterator operator--(int)
	{
		iterator temp(*this);
		--* this;
		return temp;
	}
	iterator operator+(int n)
	{
		return iterator(ptr + n);
	}
	iterator operator-(int n)
	{
		return iterator(ptr - n);
	}
	iterator operator*(int n)
	{
		return iterator(ptr * n);
	}
	const iterator<T> cend() const;
	const iterator<T> cbegin() const;
	iterator<T> begin();
	iterator<T> rbegin();
	iterator<T> rend();
	iterator<T> end() const;
};

template <typename T>
class Vector : public iterator<T>
{
private:
	T* arr;
	int Size;
	int Capacity;
public:
	const iterator<T> cend() const
	{
		return iterator<T>(arr + Size);
	};
	const iterator<T> cbegin() const
	{
		return iterator<T>(arr);
	};
	iterator<T>begin()
	{
		return iterator<T>(arr);
	};
	iterator<T> rbegin()
	{
		return iterator<T>(arr + Size - 1);
	};
	iterator<T> rend()
	{
		return iterator<T>(arr - 1);
	};
	iterator<T>end() const
	{
		return iterator<T>(arr + Size);
	};
	Vector(std::initializer_list<T> list)
	{
		Size = 0;
		Capacity = list.size();
		arr = new T[list.size()];
		for (const auto& element : list)
		{
			push_back(element);
		}
	}
	Vector()
	{
		Size = 0;
		Capacity = 5;
		arr = new T[Capacity];
	}
	Vector(int n)
	{
		arr = new T[n];
		Capacity = n + 1;
		Size = n;
	}
	Vector(const Vector& other)
	{
		Size = other.Size;
		Capacity = other.Capacity;
		arr = new T[other.Capacity];
		for (int i = 0; i < Size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	Vector(const Vector&& other)
	{
		arr = other.arr;
		Size = other.Size;
		Capacity = other.Capacity;
		other.arr = nullptr;
		other.Size = 0;
		other.Capacity = 0;
	}
	~Vector()
	{
		delete[] arr;
	}
	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			delete[] arr;
			Size = other.Size;
			Capacity = other.Capacity;
			arr = new T[Capacity];
			for (int i = 0; i < Size; i++)
			{
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}
	Vector& operator=(Vector&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = other.arr;
		Size = other.Size;
		Capacity = other.Capacity;
		other.arr = nullptr;
		other.Size = 0;
		other.Capacity = 0;

		return *this;
	}
	T& operator[](int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Vector is empty.");
		}
		else
		{
			return arr[index];
		}
	}
	void push_back(T value)
	{
		if (Size >= Capacity)
		{
			Capacity *= 2;
			T* tmp = arr;
			arr = new T[Capacity];
			for (int i = 0; i < Size; i++)
			{
				arr[i] = tmp[i];
			}
			delete[] tmp;
		}
		arr[Size] = value;
		Size++;
	}
	bool empty()
	{
		return Size == 0;
	}
	int size()
	{
		return Size;
	}
	int capacity()
	{
		return Capacity;
	}
	size_t max_size()
	{
		return (size_t)-1 / sizeof(T);
	}
	T& back()
	{
		if (Size == 0)
		{
			throw std::out_of_range("Vector is empty.");
		}
		else
		{
			return arr[Size - 1];
		}
	}
	T& front()
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty.");
		}
		else
		{
			return arr[0];
		}
	}
	T* data()
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty.");
		}
		else
		{
			return &arr[0];
		}
	}
	T& at(int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Vector is empty.");
		}
		else
		{
			return arr[index];
		}
	}
	void pop_back()
	{
		if (Size)
		{
			--Size;
		}
	}
	void clear()
	{
		Size = 0;
		Capacity = 2;
		delete[] arr;
		arr = new T[Capacity];
	}
	void erase(int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		for (int i = index; i < Size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		--Size;
	}
	void erase(int index, int count)
	{
		if (index < 0 || index >= Size || index + count >= Size)
		{
			std::cout << "Выход за границы\n";
			return;
		}
		if (count < 0)
		{
			std::cout << "Не то значение\n";
			return;
		}
		for (int i = index + count; i < Size; i++)
		{
			arr[i - count] = arr[i];
		}
		Size -= count;
	}
	void insert(int index, T value)
	{
		if (index < 0 || index > Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		if (Capacity < Size + 1)
		{
			reserve(Size + 1);
		}
		for (int i = Size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		Size++;
	}
	void insert(int index, int amount, T value)
	{
		if (amount <= 0)
		{
			std::cout << "Некорретное количество";
			return;
		}
		if (index < 0 || index > Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		if (Capacity < Size + amount)
		{
			reserve(Size + amount);
		}
		Size += amount;
		for (int i = Size - 1; i >= index + amount; i--)
		{
			arr[i] = arr[i - amount];
		}
		for (int i = index; i < index + amount; i++)
		{
			arr[i] = value;
		}
	}
	void insert(int index, Vector<T>& value)
	{
		if (index < 0 || index > Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		if (Capacity < Size + value.size())
		{
			reserve(Size + value.size());
		}
		Size += value.size();
		for (int i = Size - 1; i >= index + value.size(); i--)
		{
			arr[i] = arr[i - value.size()];
		}
		for (int i = index; i < index + value.size(); i++)
		{
			arr[i] = value[i - index];
		}
	}
	void sort()
	{
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = 0; j < Size - i - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
				{
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	void print()
	{
		for (int i = 0; i < Size; i++)
		{
			std::cout << arr[i] << " ";
		}
	}
	void swap(Vector& other)
	{
		std::swap(this->Capacity, other.Capacity);
		std::swap(this->Size, other.Size);
		std::swap(this->arr, other.arr);
	}
	void reserve(int new_capacity)
	{
		if (new_capacity <= Capacity)
		{
			return;
		}
		T* new_arr = new T[new_capacity];
		for (int i = 0; i < Size; i++)
		{
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		Capacity = new_capacity;
	}
	void resize(int n, T value = T())
	{
		if (n < Size)
		{
			Size = n;
		}
		else if (n > Capacity)
		{
			reserve(n);
			for (int i = Size; i < n; i++)
			{
				arr[i] = value;
			}
			Size = n;
		}
		else
		{
			for (int i = Size; i < n; i++)
			{
				arr[i] = value;
			}
			Size = n;
		}
	}
	void assign(int count, T values)
	{
		clear();
		reserve(count);
		for (int i = 0; i < count; i++)
		{
			push_back(values);
		}
	}
	void assign(int count, Vector<T>& values)
	{
		clear();
		reserve(count);
		for (int i = 0; i < count; i++)
		{
			push_back(values[i]);
		}
	}
	void assign(Vector<T>& values)
	{
		clear();
		reserve(values.Size);
		for (int i = 0; i < values.Size; i++)
		{
			push_back(values[i]);
		}
	}
	void emplace_back(T&& value)
	{
		if (Size == Capacity)
		{
			reserve(Capacity * 2);
		}
		arr[Size++] = std::move(value);
	}
	void emplace(int index, T&& value)
	{
		if (index < 0 || index > Size)
		{
			throw std::out_of_range("Out of ranfe.");
		}
		if (Size == Capacity)
		{
			reserve(Capacity * 2);
		}
		for (int i = Size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = std::move(value);
		Size++;
	}
};

template <typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
	Pair() {}
	Pair(const T1& f, const T2& s) : first(f), second(s) {}
};
