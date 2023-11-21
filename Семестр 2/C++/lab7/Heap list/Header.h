#pragma once

template<typename T>
class List
{
private:
	template<typename T>
	struct Node
	{
	public:
		T data;
		Node* prev;
		Node* next;

		Node(T data = T())
		{
			this->data = data;
			this->prev = this->next = nullptr;
		}
	};
	Node<T>* head;
	Node<T>* tail;
	int Size;
public:
	List()
	{
		Size = 0;
		head = tail = nullptr;
	}
	~List()
	{
		clear();
	}
	bool isEmpty() const
	{
		return head == nullptr;
	}
	int GetSize()
	{
		return Size;
	}
	void push_front(T data)
	{
		Node<T>* ptr = new Node<T>(data);
		if (isEmpty())
		{
			head = tail = ptr;
		}
		else
		{
			ptr->next = head;
			head->prev = ptr;
			head = ptr;
		}
		Size++;
	}
	void push_back(T data)
	{
		Node<T>* ptr = new Node<T>(data);
		if (isEmpty())
		{
			head = tail = ptr;
			Size++;
		}
		else
		{
			ptr->prev = tail;
			tail->next = ptr;
			tail = ptr;
			Size++;
		}
	}
	void display()
	{
		if (isEmpty())
		{
			std::cout << "Cписок пуст\n";
		}
		else
		{
			Node<T>* current = head;
			while (current != nullptr)
			{
				std::cout << current->data << " ";
				current = current->next;
			}
		}
	}
	void pop_back()
	{
		if (isEmpty())
		{
			std::cout << "Удалять нечего\n";
		}
		else
		{
			Node<T>* ptr = tail;
			tail = tail->prev;
			if (tail != nullptr)
			{
				tail->next = nullptr;
			}
			else
			{
				tail = nullptr;
			}
			delete ptr;
			Size--;
		}
	}
	void pop_front()
	{
		if (isEmpty())
		{
			std::cout << "Удалять нечего\n";
		}
		else
		{
			Node<T>* ptr = head;
			head = head->next;
			if (head != nullptr)
			{
				head->prev = nullptr;
			}
			else
			{
				tail = nullptr;
			}
			delete ptr;
			Size--;
		}
	}
	void clear()
	{
		while (Size)
		{
			pop_front();
		}
	}
	T& operator[](int index) 
	{
		Node<T>* currNode = head;
		int currIndex = 0;
		while (currNode != nullptr) 
		{
			if (currIndex == index) 
			{
				return currNode->data;
			}
			currNode = currNode->next;
			currIndex++;
		}
		throw std::out_of_range("Index out of range");
	}
	void insertAtPosition(T data, int position)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		if (position == 1)
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}
		Node<T>* temp = head;
		for (int i = 1; i < position - 1 && temp != NULL; i++)
		{
			temp = temp->next;
		}
		if (temp == NULL)
		{
			std::cout << "Invalid position" << '\n';
			return;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		/*
		if (temp->next != NULL)
		{
		temp->next->prev = newNode;
		}
		*/
		temp->next = newNode;

	}
	/*

	Удаление по индкексу

	 void NachDeleteNodeAtIndex(int index)
	{
	  if (head == NULL)
	  {
		  return;
	  }
	  Node* currentNode = head;
	  int currentIndex = 0;
	  while (currentNode != NULL && currentIndex != index)
	  {
		currentNode = currentNode->next;
		currentIndex++;
	  }
	  if (currentNode == NULL)
	  {
		  return;
	  }
	  Node* prevNode = currentNode->prev;
	  Node* nextNode = currentNode->next;

	  if (prevNode != NULL)
	  {
		prevNode->next = nextNode;
	  }
	  else
	  {
		head = nextNode;
	  }
	  if (nextNode != NULL)
	  {
		nextNode->prev = prevNode;
	  }

	  delete currentNode;
	}

	*/
};

template<typename T>
class weak_ptr;

template<typename T>
class shared_ptr
{
public:
	T* ptr;
	int* count;
	friend class weak_ptr<T>;
public:
	shared_ptr()
	{
		ptr = nullptr;
		count = nullptr;
	}
	shared_ptr(T* ptr)
	{
		this->ptr = ptr;
		count = new int(1);
	}
	shared_ptr(shared_ptr<T>& other)
	{
		ptr = other.ptr;
		count = other.count;
		++(*count);
	}
	shared_ptr(shared_ptr<T>&& other)
	{
		ptr = other.ptr;
		count = other.count;
		other.ptr = nullptr;
		other.count = nullptr;
	}
	shared_ptr(const weak_ptr<T>& other)
	{
		ptr = other.w_ptr;
		count = other.w_count;
		if (count)
		{
			(*count)++;
		}
	}
	shared_ptr<T>& operator=(weak_ptr<T>& other)
	{
		release();
		ptr = other.w_ptr;
		count = other.w_count;
		if (count)
		{
			(*count)++;
		}
		return *this;
	}
	~shared_ptr()
	{
		release();
	}
	shared_ptr<T>& operator=(shared_ptr<T>& other)
	{
		if (this != &other)
		{
			if (count)
			{
				if (*count == 1)
				{
					delete count;
					delete ptr;
				}
				else
				{
					(*count)--;
				}
			}
			ptr = other.ptr;
			count = other.count;
			(*count)++;
		}
		return *this;
	}
	shared_ptr<T>& operator=(shared_ptr<T>&& other) noexcept
	{
		if (this != &other)
		{
			reset();
			ptr = other.ptr;
			count = other.count;
			other.ptr = nullptr;
			other.count = nullptr;
		}
		return *this;
	}
	void reset()
	{
		if (count)
		{
			if (*count == 1)
			{
				delete ptr;
				delete count;
			}
			else
			{
				(*count)--;
			}
		}
		ptr = nullptr;
		count = nullptr;
	}
	void swap(shared_ptr<T>& other)
	{
		std::swap(ptr, other.ptr);
		std::swap(count, other.count);
	}
	T& operator*() const
	{
		if (ptr != nullptr)
		{
			return *ptr;
		}
	}
	T* operator->() const
	{
		return ptr;
	}
	T* get() const
	{
		return ptr;
	}
	explicit operator bool() const
	{
		return ptr != nullptr;
	}
	int use_count() const
	{
		return count ? *count : 0;
	}
	bool unique() const
	{
		return *count == 1;
	}
private:
	void release()
	{
		if (count)
		{
			if (*count == 1)
			{
				delete count;
				delete ptr;
			}
			else
			{
				(*count)--;
			}
		}
	}
};

template<typename T>
class weak_ptr
{
public:
	T* w_ptr;
	int* w_count;
	friend class shared_ptr<T>;
public:
	weak_ptr()
	{
		w_ptr = nullptr;
		w_count = nullptr;
	}
	weak_ptr(const shared_ptr<T>& other)
	{
		w_ptr = other.ptr;
		w_count = other.count;
		if (w_count)
		{
			(*w_count)++;
		}
	}
	weak_ptr(const weak_ptr<T>& other)
	{
		w_ptr = other.w_ptr;
		w_count = other.w_count;
		if (w_count)
		{
			(*w_count)++;
		}
	}
	~weak_ptr()
	{
		release();
	}
	weak_ptr<T>& operator=(const shared_ptr<T>& other)
	{
		release();
		w_ptr = other.w_ptr;
		w_count = other.w_count;
		if (w_count)
		{
			(*w_count)++;
		}
		return *this;
	}
	weak_ptr<T>& operator=(const weak_ptr<T>& other)
	{
		release();
		w_ptr = other.w_ptr;
		w_count = other.w_count;
		if (w_count)
		{
			(*w_count)++;
		}
		return *this;
	}
	void release()
	{
		if (w_count)
		{
			if (*w_count == 1)
			{
				delete w_count;
				delete w_ptr;
			}
			else
			{
				(*w_count)--;
			}
		}
	}
	shared_ptr<T> lock()
	{
		return shared_ptr<T>(*this);
	}
	bool equals(weak_ptr other)
	{
		return w_ptr == other.w_ptr;
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