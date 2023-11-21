#ifndef STACK_H
#define STACK_H

#include <QString>

class Stack
{
private:
    QString* arr;
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
    void push(QString item)
    {
        QString* a;
        a = arr;
        arr = new QString[size + 1];
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
    QString pop()
    {
        if (size == 0)
        {
            return 0;
        }
        size--;
        return arr[size];
    }
    QString top()
    {
        if (size == 0)
        {
            return 0;
        }
        return arr[size - 1];
    }

    bool empty()
    {
        return size == 0;
    }
};




/*
class Stack1
{
private:
    double* arr;
public:
    int size;

public:
    Stack1()
    {
        arr = nullptr;
        size = 0;
    }
    ~Stack1()
    {
        if (size > 0)
        {
            delete[] arr;
        }
    }
    void push(double item)
    {
        double* a;
        a = arr;
        arr = new double[size + 1];
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
    int pop()
    {
        if (size == 0)
        {
            return 0;
        }
        size--;
        return arr[size];
    }
    int top()
    {
        if (size == 0)
        {
            return 0;
        }
        return arr[size - 1];
    }

    bool Empty()
    {
        return size == 0;
    }
};

*/
#endif // STACK_H
