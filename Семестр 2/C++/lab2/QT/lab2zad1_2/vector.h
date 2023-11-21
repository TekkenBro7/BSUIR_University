#ifndef VECTOR_H
#define VECTOR_H

#include <QString>

class Node;
class Vector;

class Node
{
public:
    QString group;
    QString marka;
    QString data;
    QString gotov;
    Node(QString group = "0", QString marka = "0", QString data = "0", QString gotov = "0")
    {
        this->group = group;
        this->marka = marka;
        this->data = data;
        this->gotov = gotov;
    }
    Node& operator=(Node& other)
    {
        group = other.group;
        marka = other.marka;
        data = other.data;
        gotov = other.gotov;

        return *this;
    }

    bool operator==(Node& other)
    {
        return ((group == other.group) && (marka ==  other.marka) && (data == other.data) && (gotov == other.gotov));
    }
    void setGroup(QString group)
    {
        this->group = group;
    }
    void setMarka(QString marka)
    {
        this->marka = marka;
    }
    void setData(QString data)
    {
        this->data = data;
    }
    void setGotov(QString gotov)
    {
        this->gotov = gotov;
    }

};



class Vector
{
private:
    int size;
    int capacity;
    Node* arr;

public:
    Vector()
    {
        size = 0;
        capacity = 5;
        arr = new Node[capacity];
    }
    ~Vector()
    {

    }
    void pushback(QString group = "0", QString marka = "0", QString data = "0", QString gotov = "0")
    {
        if (size < capacity)
        {
            arr[size].group = group;
            arr[size].marka = marka;
            arr[size].data = data;
            arr[size].gotov = gotov;
            size++;
        }
        else
        {
            capacity *= 2;
            Node* newarr = new Node[capacity];
            for (int i = 0; i < size; i++)
            {
                newarr[i] = arr[i];
            }
            newarr[size].group = group;
            newarr[size].marka = marka;
            newarr[size].data = data;
            newarr[size].gotov = gotov;
            size++;
            delete[] arr;
            arr = newarr;
        }
    }
    bool Empty()
    {
        return size == 0;
    }
    int Size()
    {
        return size;
    }
    int Capacity()
    {
        return capacity;
    }

    Vector(Vector& rhs) :size(rhs.size),
        capacity(rhs.capacity),
        arr(new Node[capacity])
    {
        for (int i = 0; i < rhs.Size(); ++i)
        {
            arr[i] = rhs.arr[i];
        }
    }
    void PopBack()
    {
        if (size == 0)
        {
            return;
        }
        else
        {
            --size;
        }
    }
    Node& operator[](int index)
    {
        return arr[index];
    }
    void Erase(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::exception("Out of range");
        }
        for (int i = index; i < size - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }
        --size;
    }
    void Clear() {
        size = 0;
    }

};




/*
class Vector
{
private:
    Node* arr;
    int size = 0;
    int capacity;

public:
    Vector()
    {
    //	arr = new int[1];
        size = 0;
    //    capacity = 1;
   //     arr = new Node[capacity];
    }


    void* operator new(std::size_t size)
    {

        return ::operator new(size);
    }
    void* operator new[](std::size_t size)
    {

        return ::operator new[](size);
    }



    ~Vector()
    {
        if (size != 0)
        delete[] arr;
    }


    Node& operator=(Node& other)
    {
        if (this != &other)
        {
            delete[] arr;
            arr = new int[other.capacity_];
            for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }





    bool isEmpty()
    {
        return size == 0;
    }

    int Capacity()
    {
        return capacity;
    }
/*
    void addMemory()
    {
        capacity *= 2;
        Node* tmp = arr;
        arr = new Node[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = tmp[i];
        }
        delete[] tmp;
    }
*/
/*
    void push_back(QString group, QString marka, QString data, QString gotov)
    {
  //      Node* i = new Node[capacity];
        Node* ptr = new Node(group, marka, data, gotov);



        int f = capacity;
        if (size >= capacity)
        {
    //		addMemory();
            size++;
        }
        else
        {
            arr[size] = *ptr;


     //   arr[size].group = group;
            arr[size].setGroup(group);

        arr[size].marka = marka;
        arr[size].data = data;
        arr[size].gotov = gotov;


        size++;
        }
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

    Node& operator[](int index)
    {
        return arr[index];
    }

    const Node& operator[](int index) const
    {
        return arr[index];
    }

    int GetSize()
    {
        return size;
    }
};
*/
#endif // VECTOR_H
