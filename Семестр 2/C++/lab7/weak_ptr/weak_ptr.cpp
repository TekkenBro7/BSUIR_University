#include <iostream>



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

int main()
{
	setlocale(LC_ALL, "ru");
	shared_ptr<int> sharedPtr(new int(100));
	std::cout << sharedPtr.use_count() << '\n';
	{
		weak_ptr<int> weakPtr(sharedPtr);
		std::cout << sharedPtr.use_count() << '\n';
		if (weakPtr.w_count != nullptr)
		{
			shared_ptr<int> lockedPtr = weakPtr.lock();
			if (lockedPtr)
			{
				std::cout << sharedPtr.use_count() << '\n';
				std::cout << lockedPtr.use_count() << '\n';
			}
		}
	}
	if (sharedPtr)
	{
		std::cout << sharedPtr.use_count() << std::endl;
	}
	shared_ptr<int> sharedPtr1(new int(42));
	shared_ptr<int> sharedPtr2(sharedPtr1);
	weak_ptr<int> weakPtr(sharedPtr1);
	sharedPtr1.reset();
	shared_ptr<int> lockedPtr = weakPtr.lock();
	if (lockedPtr)
	{
		std::cout << *lockedPtr << std::endl;
	}
}