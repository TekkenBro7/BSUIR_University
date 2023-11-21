#pragma once


template<typename T>
class My_shared_ptr
{
private:
	T* ptr;
	int* count;
public:
	My_shared_ptr()
	{
		ptr = nullptr;
		count = nullptr;
	}
	My_shared_ptr(T* ptr)
	{
		this->ptr = ptr;
		count = new int(1);
	}
	My_shared_ptr(My_shared_ptr<T>& other)
	{
		ptr = other.ptr;
		count = other.count;
		++(*count);
	}
	My_shared_ptr(My_shared_ptr<T>&& other)
	{
		ptr = other.ptr;
		count = other.count;
		other.ptr = nullptr;
		other.count = nullptr;
	}
	~My_shared_ptr()
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
	My_shared_ptr<T>& operator=(My_shared_ptr<T>& other)
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
	My_shared_ptr<T>& operator=(My_shared_ptr<T>&& other) noexcept
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
	void swap(My_shared_ptr<T>& other)
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

