#include <iostream>
#include <string>

using namespace std;


template<typename T>
class Stack
{
private:
    T* arr;
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
    void push(T item)
    {
        T* a;
        a = arr;
        arr = new T[size + 1];
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
    void Print()
    {
        if (size == 0)
        {
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
    char pop()
    {
        if (size == 0)
        {
            return 0;
        }
        size--;
        return arr[size];
    }
    char top()
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



class Stack1
{
private:
    int* arr;
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
    void push(int item)
    {
        int* a;
        a = arr;
        arr = new int[size + 1];
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

int main()
{
    setlocale(LC_ALL, "ru");
    Stack<char> a;
    a.push('(');
    a.push(')');
    a.push('[');
    a.Print();

    cout << "\n";
    a.pop();
        a.Print();

      cout << '\n' <<  a.top();

      cout << "\n";
      cout << "\n";
      cout << "\n";

      Stack<char> b;
      Stack1 c;
      string str;
      cin >> str;

      for (int i = 0; i < str.size(); i++)
      {
          if (str[i] == '(' || str[i] == '[' || str[i] == '{')
          {
              b.push(str[i]);
              c.push(i);
          }
          else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
          {
              if (b.Empty() || str[i] == ')' && b.top() != '(' || str[i] == ']' && b.top() != '[' || str[i] == '}' && b.top() != '{')
              {
                  cout << "\nОшибка на индексе " << i << '\n';
                  return 0;
              }
              b.pop();
          }
      }
      while (c.size > 1)
      {
          c.pop();
      }
      if (!b.Empty())
      {
          cout << "На индексе " << c.pop();
          return 0;
      }
      cout << "успешно";
}


