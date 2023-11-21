#ifndef QUEUE_H
#define QUEUE_H

#include <string>

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
struct Node
{
    T data;
    shared_ptr<Node<T>> next;
    shared_ptr<Node<T>> prev;
    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
    Node(const T& value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class Queue
{
public:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    int Size;
public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        Size = 0;
    }
    void push(const T& value)
    {
        shared_ptr<Node<T>> newNode(new Node<T>(value));
        if (head.get() == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        Size++;
    }
    void print()
    {
        auto cur = head;
        while (cur.get() != nullptr)
        {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << '\n';
    }

    void pop()
    {
        if (head.get() == nullptr)
        {
            return;
        }
        shared_ptr<Node<T>> oldHead = head;
        head = head->next;
        if (head.get() == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            head->prev = nullptr;
        }
        Size--;
    }
    int size()
    {
        return Size;
    }
    T& front()
    {
        return head->data;
    }
    T& back()
    {
        return tail->data;
    }
    bool empty()
    {
        return head.get() == nullptr;
    }
    T& operator[](const int index)
    {
        if (index >= 0 && index < Size)
        {
            int count = 0;
            auto current = head;
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
template <typename T>
class QueueSort : public Queue<T>
{
public:
    void sort()
    {
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            auto current = Queue<T>::head;
            while (current->next.get() != nullptr)
            {
                if (current->data > current->next->data)
                {
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        }
    }
};


#endif // QUEUE_H
