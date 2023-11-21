#include <iostream>

template<typename T>
class unique_ptr;

class deliver
{
public:
	template<typename T>
	void operator()(T* ptr)
	{
		delete ptr;
    }
};

template<typename T>
class unique_ptr : public deliver
{
private:
	T* ptr;
public:
	operator bool() const
	{
		return ptr != nullptr;
	}
	unique_ptr(T* pointer = nullptr)
	{
		ptr = pointer;
	}
	~unique_ptr()
	{
	//	deliver del;
	//	del(ptr);
		delete ptr;
	}
	unique_ptr(unique_ptr&& x)
	{
		ptr = x.ptr;
		x.ptr = nullptr;
	}
	unique_ptr& operator=(unique_ptr&& x)
	{
		if (&x == this)
		{
			return *this;
		}
		delete ptr;
		ptr = x.ptr;
		x.ptr = nullptr;
		return *this;
	}
	// Запрещаем любое копирование
	unique_ptr(const unique_ptr& x) = delete;
	unique_ptr& operator=(unique_ptr& a) = delete;
	void swap(unique_ptr& other)
	{
		std::swap(ptr, other.ptr);
	}
	// Освобождает умный указатель
	T* release()
	{
		T* tmp = ptr;
		ptr = nullptr;
		return tmp;
	}
	// Затирает данные
	void reset(T* data = nullptr)
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = data;
		}
	}
	T& operator*() const
	{
		return *ptr;
	}
	T* operator->() const
	{
		return ptr;
	}
	bool isNull() const
	{
		return ptr == nullptr;
	}
	T* get() const
	{
		return ptr;
	}
	template<typename Arg1, typename... Args>
	static unique_ptr<T> make_unique(Arg1&& arg1, Args&&... args)
	{
		return unique_ptr<T>(new T(std::forward<Arg1>(arg1), std::forward<Args>(args)...));
	}
};

template<typename T>
class Item
{
public:
	T val;
	int v;
	Item(T value, int a)
	{
		val = value;
		v = a;
	}
	Item()
	{
		std::cout << "\nСоздан";
	}
	int a()
	{
		return v;
	}
	~Item()
	{
		std::cout << "\nУдалён\n";
	}
	friend std::ostream& operator<<(std::ostream& out, const Item& object)
	{
		out << object.val << " " << object.v;
		return out;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	unique_ptr<Item<std::string>> ptr(new Item<std::string>("1233", 555));
	auto a = unique_ptr<Item<std::string>>::make_unique("zxc", 123);
	//auto b = std::move(a);
	
	//unique_ptr<Item<std::string>> bb(std::move(b));

	//bb = b;
	
//	a.release();

	std::cout << a->v << '\n';
	std::cout << a.get();
	std::cout << (bool)a;

	auto c = unique_ptr<Item<std::string>>::make_unique("qqq", 111);
	/*
	auto f2 = std::make_unique<Item<int>[]>(5);
	std::cout << f2[0] << '\n';

	int* p = new int(5);
	unique_ptr<int>b(p);
	std::cout << '\n' << b.isNull();
	std::cout << '\n' << *b;
	std::cout << '\n' << b.isNull();
	*/
	//	unique_ptr<Item> ptr2 = std::move(a);
	//	std::cout << a.isNull() << '\n';
	//	std::cout << ptr2.isNull() << '\n';
	//	std::cout << '\n' << b.isNull() << '\n';
}