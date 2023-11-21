#ifndef DEQUE_H
#define DEQUE_H

const int size_Block = 8;

template <typename T>
class Deque
{
private:
    struct BlockMemory
    {
        T* arr;
        BlockMemory* next;
        BlockMemory* prev;
        BlockMemory()
        {
            arr = new T[size_Block];
            next = nullptr;
            prev = nullptr;
        }
    };
    BlockMemory* head;
    BlockMemory* tail;
    int head_index;
    int tail_index;
    int size;
public:
    Deque()
    {
        head = nullptr;
        tail = nullptr;
        head_index = 0;
        tail_index = 0;
        size = 0;
    }
    ~Deque()
    {
        clear();
    }
    void clear()
    {
        while (size != 0)
        {
            pop_back();
        }
    }
    bool empty()
    {
        return size == 0;
    }
    int Size()
    {
        return size;
    }
    T& operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            int block_number = (head_index + index) / size_Block;
            int block_index = (head_index + index) % size_Block;
            BlockMemory* current = head;
            for (int i = 0; i < block_number; i++)
            {
                current = current->next;
            }
            return current->arr[block_index];
        }
    }
    void push_back(const T& value)
    {
        if (empty())
        {
            head = new BlockMemory();
            tail = head;
            head_index = 0;
            tail_index = 0;
            size = 1;
            head->arr[0] = value;
        }
        else
        {
            if (tail_index == size_Block - 1)
            {
                BlockMemory* new_block = new BlockMemory();
                new_block->prev = tail;
                tail->next = new_block;
                tail = new_block;
                tail_index = 0;
                size++;
                tail->arr[0] = value;
            }
            else
            {
                tail_index++;
                size++;
                tail->arr[tail_index] = value;
            }
        }
    }
    void push_front(const T& value)
    {
        if (empty())
        {
            head = new BlockMemory();
            tail = head;
            head_index = 0;
            tail_index = 0;
            size = 1;
            head->arr[0] = value;
        }
        else
        {
            if (head_index == 0)
            {
                BlockMemory* new_block = new BlockMemory();
                new_block->next = head;
                head->prev = new_block;
                head = new_block;
                head_index = size_Block - 1;
                size++;
                head->arr[head_index] = value;
            }
            else
            {
                head_index--;
                size++;
                head->arr[head_index] = value;
            }
        }
    }
    void pop_back()
    {
        if (!empty())
        {
            if (size == 1)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                head_index = 0;
                tail_index = 0;
                size = 0;
            }
            else
            {
                if (tail_index == 0)
                {
                    BlockMemory* temp = tail;
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete temp;
                    tail_index = size_Block - 1;
                    size--;
                }
                else
                {
                    tail_index--;
                    size--;
                }
            }
        }
    }
    void pop_front()
    {
        if (!empty())
        {
            if (size == 1)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                head_index = 0;
                tail_index = 0;
                size = 0;
            }
            else
            {
                if (head_index == size_Block - 1)
                {
                    BlockMemory* temp = head;
                    head = head->next;
                    head->prev = nullptr;
                    delete temp;
                    head_index = 0;
                    size--;
                }
                else
                {
                    head_index++;
                    size--;
                }
            }
        }
    }
    void resize(int new_size, const T& value = T())
    {
        int dop_size = abs(size - new_size);
        if (new_size > size)
        {
            for (int i = 0; i < dop_size; i++)
            {
                push_back(value);
            }
        }
        else if (new_size < size)
        {
            for (int i = 0; i < dop_size; i++)
            {
                pop_back();
            }
        }
    }
    class iterator
    {
    private:
        BlockMemory* block;
        int index;
        friend class Deque;
    public:
        iterator()
        {
            block = nullptr;
            index = 0;
        }
        iterator(BlockMemory* block, int index)
        {
            this->block = block;
            this->index = index;
        }
        T& operator*()
        {
            return block->arr[index];
        }
        iterator& operator++()
        {
            if (block != nullptr)
            {
                if (index == size_Block - 1)
                {
                    block = block->next;
                    index = 0;
                }
                else
                {
                    index++;
                }
                return *this;
            }
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        iterator& operator--()
        {
            if (block == nullptr)
            {
                if (index == 0)
                {
                    block = block->prev;
                    index = size_Block - 1;
                }
                else
                {
                    index--;
                }
                return *this;
            }
        }
        iterator operator--(int)
        {
            iterator temp = *this;
            --(*this);
            return temp;
        }
        bool operator==(const iterator& other)
        {
            return block == other.block && index == other.index;
        }
        bool operator!=(const iterator& other)
        {
            return !(*this == other);
        }
        bool operator >(const iterator& other)
        {
            return (*this > other);
        }
        bool operator <(const iterator& other)
        {
            return (*this < other);
        }
    };
    iterator begin()
    {
        return iterator(head, head_index);
    }
    iterator end()
    {
        return iterator(tail, tail_index + 1);
    }
};


#endif // DEQUE_H
