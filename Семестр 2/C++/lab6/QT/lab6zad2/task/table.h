#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <QString>
#include <string>

template<typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
    MyPair()
    {

    }
    MyPair(const T1& f, const T2& s)
    {
        first = f;
        second = s;
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
    T& operator*()
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
    Vector(std::initializer_list<T> values)
    {
        int amount = 0;
        for (auto& goThrough : values)
        {
            amount++;
        }
        arr = new T[amount];
        int through = 0;
        for (auto& goThrough : values)
        {
            arr[through] = goThrough;
            through++;
        }

        Size = amount;
        Capacity = amount;
    };
    const iterator<T> cend() const
    {
        return iterator<T>(arr + Capacity);
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
    /*
    Vector(std::initializer_list<T> list) : Size(0), Capacity(list.size()), arr(new T[list.size()])
    {
        for (const auto& element : list)
        {
            push_back(element);
        }
    }
    */
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
        //other.arr = nullptr;
        //other.Size = 0;
        //other.Capacity = 0;
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
            //throw std::out_of_range("Vector is empty.");
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
            //throw std::out_of_range("Vector is empty.");
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
            //throw std::out_of_range("Vector is empty.");
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
            //throw std::out_of_range("Vector is empty.");
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
            //throw std::out_of_range("Vector is empty.");
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
            //throw std::out_of_range("Out of ranfe.");
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
            //std::cout << "Выход за границы\n";
            return;
        }
        if (count < 0)
        {
            //std::cout << "Не то значение\n";
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
            //throw std::out_of_range("Out of ranfe.");
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
            //std::cout << "Некорретное количество";
            return;
        }
        if (index < 0 || index > Size)
        {
            //throw std::out_of_range("Out of ranfe.");
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
            //throw std::out_of_range("Out of ranfe.");
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
                int n = arr[j];
                int k = arr[j+1];
                if (arr[j] > arr[j + 1])
                {
                    //swap(arr[j], arr[j + 1]);
                    T f;
                    f = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = f;
                }
            }
        }
    }
    void print()
    {
        for (int i = 0; i < Size; i++)
        {
            //std::cout << arr[i] << " ";
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
    void assign(iterator<T>& begin, iterator<T>& end)
    {
        if (begin > end)
        {
            return;
        }
        iterator<T> b = begin;
        iterator<T> e = end;
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
        arr[Size++] = move(value);
    }
    void emplace(int index, T&& value)
    {
        if (index < 0 || index > Size)
        {
            //throw std::out_of_range("Out of ranfe.");
        }
        if (Size == Capacity)
        {
            reserve(Capacity * 2);
        }
        for (int i = Size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = move(value);
        Size++;
    }

    T* Insert(int index, std::initializer_list<T> list)
    {
        if (index < 0 || index > Size)
        {
            return NULL;
        }
        int amount = 0;
        for (auto& goThrough : list)
        {
            ++amount;
        }
        if (amount + Size > Capacity)
        {
            reserve((amount + Size) * 2);
        }
        T* listElements = new T[amount];
        T* rightElementsOfCurrent = new T[Size - index];
        T* leftElementsOfCurrent = new T[index];
        int id = 0;
        for (auto& goThrough : list)
        {
            listElements[id] = goThrough;
            id++;
        }
        for (int i = 0; i < Size; i++)
        {
            if (i < index)leftElementsOfCurrent[i] = arr[i];
            if (i >= index)rightElementsOfCurrent[i - 1] = arr[i];
        }
        Size += amount;
        T* helper = new T[Size];
        for (int i = 0; i < Size; i++)
        {
            if (i < index)
            {
                helper[i] = leftElementsOfCurrent[i];
            }
            if (i >= index && i < amount + index)
            {
            helper[i] = listElements[i - index];
            }
            if (i >= index + amount)
            {
                helper[i] = rightElementsOfCurrent[i - amount - 1];
            }
        }
        delete[] arr;
        arr = new T[Size];

        for (int i = 0; i < Size; i++)
        {
            arr[i] = helper[i];
        }
    }
};

class MyHashTable
{
private:
    int size;
    int count;
    Vector<MyPair<std::string, int>> table;
    Vector<int> TableSize = { 16,64,128,2048 };
    const double A = (sqrt(5) - 1) / 2;
public:
    MyHashTable()
    {
        count = 0;
        size = 16;
        table.resize(size);
    }
    MyHashTable(int size)
    {
        this->size = TableSize[size];
        count = 0;
        table.resize(this->size);
        for (int i = 0; i < size; i++)
        {
            table[i] = MyPair<std::string, int>{ "", -1 };
        }
    }
    bool isEmpty()
    {
        return count == 0;
    }
    int HashFunction1(std::string key)
    {
        return 1;
    }
    int hashFunction(std::string key)
    {
        int sum = 0;
        for (int i = 0; i < key.size(); i++)
        {
            sum += key[i];
        }
        int a = size * fmod(sum * A, 1);
        return a;
    }
    void insert(std::string key, int value)
    {

        int index = abs(hashFunction(key));
        if (index != 0)
            index = index  % size;
        if (table[index].second == -1)
        {
            table[index].first = key;
            table[index].second = value;
            count++;
        }
        else
        {
            while (table[index].first != "")
            {
                if (table[index].second == value)
                {
                    table[index].second = value;
                }
                index = (index + 1) % size;
                if (table[index].first == key)
                {
                    table[index].first = key;
                    table[index].second = value;
                    return;
                }
            }
            table[index].first = key;
            table[index].second = value;
            count++;
        }
    }
    void print()
    {
        for (int i = 0; i < table.size(); i++)
        {
            if (table[i].first == "")
            {
                std::cout << "-------\n";
            }
            else
            {
                std::cout << "Ключ: " << table[i].first << ", значение: " << table[i].second << '\n';
            }
        }
    }
    int find(std::string key)
    {
        int index = abs(hashFunction(key)) % size;
        int i = 0;
        while (index != size && table[index].first != "" && i < size)
        {
            if (table[index].first == key)
            {
                return table[index].second;
            }
            if (index == size)
            {
                index = -1;
            }
            index++;
            i++;
        }
        return -1;
    }
    void remove(std::string key)
    {
        int index = abs(hashFunction(key)) % size;
        int i = 0;
        while (table[index].first != "" && i < size)
        {
            if (table[index].first == key)
            {
                table[index].first = "";
                table[index].second = -1;
                count--;
            }
            index++;
            i++;
        }
    }
    void insert1(const std::string& key, int value)
    {

        int index = HashFunction1(key);
        if (index != 0)
            index = index  % size;
        if (table[index].second == -1)
        {
            table[index].first = key;
            table[index].second = value;
            count++;
        }
        else
        {
            while (table[index].first != "")
            {
                index = (index + 1) % size;
                if (table[index].first == key)
                {
                    table[index].first = key;
                    table[index].second = value;
                    return;
                }
            }
            table[index].first = key;
            table[index].second = value;
            count++;
        }
    }
    int find1(const std::string& key)
    {
        int index = HashFunction1(key);
        int i = 0;
        while (index != size && table[index].first != "" && i < size)
        {
            if (table[index].first == key)
            {
                return table[index].second;
            }
            if (index == size)
            {
                index = -1;
            }
            index++;
            i++;
        }
        return -1;
    }
};

#endif // TABLE_H
