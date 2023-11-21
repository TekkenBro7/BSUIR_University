#include <iostream>


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



int main()
{
	setlocale(LC_ALL, "ru");
	shared_ptr<int> p1(new int(42));

	std::cout << *p1 << "  " << p1.use_count() << "  " << p1.get() << "  " << (bool)p1 << "  " << p1.unique() << '\n';
	shared_ptr<int> p2 = p1;
	std::cout << *p1 << "  " << p1.use_count() << "  " << p1.unique() << '\n';
	std::cout << *p2 << "  " << p2.use_count() << '\n';
	*p1 = 13;
	std::cout << *p1 << "  " << p1.use_count() << '\n';
	std::cout << *p2 << "  " << p2.use_count() << '\n';
	p1.reset();
	std::cout << *p1 << "  " << p1.use_count() << '\n';
	std::cout << *p2 << "  " << p2.use_count() << '\n';
	shared_ptr<int> p3(new int(99));
	p2 = std::move(p3);
	std::cout << *p2 << "  " << p2.use_count() << '\n';
	std::cout << *p3 << "  " << p3.use_count() << '\n';

	return 0;
}
