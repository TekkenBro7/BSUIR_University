#pragma once

template<typename T>
class shared_ptr
{
private:
	T* ptr;
	int* count;
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
	~shared_ptr()
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
};


template <typename T>
struct Node1
{
	T data;
	shared_ptr<Node1<T>> next1;
	shared_ptr<Node1<T>> prev1;
	Node1()
	{
		next1 = nullptr;
		prev1 = nullptr;
	}
	Node1(const T& value)
	{
		data = value;
		next1 = nullptr;
		prev1 = nullptr;
	}
};

template <typename T>
class Queue
{
public:
	shared_ptr<Node1<T>> head1;
	shared_ptr<Node1<T>> tail1;
	int Size;
public:
	Queue()
	{
		head1 = nullptr;
		tail1 = nullptr;
		Size = 0;
	}
	void push(const T& value)
	{
		shared_ptr<Node1<T>> newNode(new Node1<T>(value));
		if (head1.get() == nullptr)
		{
			head1 = newNode;
			tail1 = newNode;
		}
		else
		{
			newNode->prev1 = tail1;
			tail1->next1 = newNode;
			tail1 = newNode;
		}
		Size++;
	}
	void print()
	{
		auto cur = head1;
		while (cur.get() != nullptr)
		{
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << '\n';
	}
	void pop()
	{
		if (head1.get() == nullptr)
		{
			return;
		}
		shared_ptr<Node1<T>> oldHead = head1;
		head1 = head1->next1;
		if (head1.get() == nullptr)
		{
			tail1 = nullptr;
		}
		else
		{
			head1->prev1 = nullptr;
		}
		Size--;
	}
	int size()
	{
		return Size;
	}
	T& front()
	{
		return head1->data;
	}
	T& back()
	{
		return tail1->data;
	}
	bool empty()
	{
		return head1.get() == nullptr;
	}
	T& operator[](const int index)
	{
		if (index >= 0 && index < Size)
		{
			int count = 0;
			auto current = head1;
			while (current.get() != nullptr)
			{
				if (count == index)
				{
					return current->data;
				}
				current = current->next;
				count++;
			}
		}
	}

};


