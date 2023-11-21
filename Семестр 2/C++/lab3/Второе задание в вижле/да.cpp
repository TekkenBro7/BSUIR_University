#include <iostream>

using namespace std;

template <typename T1, typename T2>
struct Pair 
{
    T1 first;
    T2 second;

    Pair() {}
    Pair(const T1& f, const T2& s) : first(f), second(s) {}
};

template <typename T>
class Vector
{
private:
	T* arr;
	int Size;
	int Capacity;
public:
	class Iterator;
	class const_iterator;
	Vector(std::initializer_list<T> list) : Size(0), Capacity(list.size()), arr(new T[list.size()])
	{
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
	Vector(Vector&& other)
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
		/*
		*  Надо, если сlear очищать память
		if (arr == nullptr)
		{
			arr = new T[Capacity];
		}
		*/
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
		return std::numeric_limits<size_t>::max() / sizeof(T);
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
		/*
		for (size_t i = 0; i < Size; i++)
		{
			arr[i].~T();
		}
		Size = 0;
		Capacity = 5;
		delete[] arr;
		arr = nullptr;
		*/
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
			cout << "Выход за границы\n";
			return;
		}
		if (count < 0)
		{
			cout << "Не то значение\n";
			return;
		}
		for (int i = index + count; i < Size; i++)
		{
			arr[i - count] = arr[i];
		}
		Size -= count;
	}
	void insert(int index, int value)
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
			cout << "Некорретное количество";
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
			cout << arr[i] << " ";
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
	void resize(int n, int value = 0)
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
	void assign(Iterator& begin, Iterator& end)
	{
		if (begin > end)
		{
			return;
		}
		Iterator b = begin;
		Iterator e = end;
		int count = 0;
		for (b; b != e; b++)
		{
			count++;
		}
		if (count > Capacity)
		{
			reserve(100);
		}
		clear();
		Size = count;
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
	const const_iterator cbegin() const
	{
		return const_iterator(arr);
	}
	const const_iterator cend() const
	{
		return const_iterator(arr + Size);
	}
	class const_iterator
	{
	private:
		const T* current;
	public:
		const_iterator()
		{

		}
		const_iterator(T* it)
		{
			current = it;
		}
		const T& operator+ (int num)
		{
			return *(current + num);
		}
		const T& operator- (int num)
		{
			return *(current - num);
		}
		const T& operator= (const const_iterator& it) const
		{
			return current = it;
		}
		const T& operator++ (int)
		{
			return *current++;
		}
		const T& operator-- (int)
		{
			return *current--;
		}
		const T& operator++ ()
		{
			return *++current;
		}
		const T& operator-- ()
		{
			return *--current;
		}
		bool operator!= (const const_iterator& it)
		{
			return current != it.current;
		}
		bool operator== (const const_iterator& it)
		{
			return current == it.current;
		}
		bool operator> (const const_iterator& it)
		{
			return current > it.current;
		}
		bool operator< (const const_iterator& it)
		{
			return current < it.current;
		}
		const T& operator*() const
		{
			return *current;
		}
	};
	Iterator rbegin()
	{
		return (arr + Size - 1);
	}
	Iterator rend()
	{
		return (arr - 1);
	}
	Iterator begin()
	{
		return arr;
	}
	Iterator end()
	{
		return arr + Size;
	}
	class Iterator
	{
	private:
		T* cur;
	public:
		Iterator()
		{

		}
		Iterator(T* it)
		{
			cur = it;
		}
		T& operator+ (int num)
		{
			return *(cur + num);
		}
		T& operator- (int num)
		{
			return *(cur - num);
		}
		T& operator= (const Iterator& it) const
		{
			return cur = it;
		}
		T& operator++ (int)
		{
			return *cur++;
		}
		T& operator-- (int)
		{
			return *cur--;
		}
		T& operator++ ()
		{
			return *++cur;
		}
		T& operator-- ()
		{
			return *--cur;
		}
		bool operator!= (const Iterator& it)
		{
			return cur != it.cur;
		}
		bool operator== (const Iterator& it)
		{
			return cur == it.cur;
		}
		bool operator> (const Iterator& it)
		{
			return cur > it.cur;
		}
		bool operator< (const Iterator& it)
		{
			return cur < it.cur;
		}
		T& operator* ()
		{
			return *cur;
		}
	};
};

int main()
{
	setlocale(LC_ALL, "ru");
	Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vec(2);
	vec[0].first = Vector<int>(2);
	vec[0].first[0] = 1;
	vec[0].first[1] = 2;
	vec[1].first = Vector<int>(2);
	vec[1].first[0] = 5;
	vec[1].first[1] = 6;
	cout << "Первая матрица" << '\n';
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].first.size(); j++)
		{
			cout << vec[i].first[j] << "  ";
		}
		cout << '\n';
	}
	vec[0].second = Vector<Pair<int, double>>(2);
	vec[0].second[0] = Pair<int, double>(3, 0.1);
	vec[0].second[1] = Pair<int, double>(4, 0.2);
	vec[1].second = Vector<Pair<int, double>>(2);
	vec[1].second[0] = Pair<int, double>(7, 0.3);
	vec[1].second[1] = Pair<int, double>(8, 0.4);
	cout << "Вторая матрица" << '\n';
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].second.size(); j++)
		{
			cout << vec[i].second[j].first << " " << vec[i].second[j].second<< "   ";
		}
		cout << '\n';
	}
}

