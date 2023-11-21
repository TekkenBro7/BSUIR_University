#include <iostream>
#include "Header.h"

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
protected:
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

int main()
{
	QueueSort<int> a;
	a.push(423);
	a.push(12);
	a.push(655);
	a.push(3);
	a.print();
	a.sort();
	a.print();
	a.pop();
	a.print();
	a.pop();
	a.print();
	a.pop();
	a.print();
	a.pop();
	std::cout << a.size();

	return 0;
}


