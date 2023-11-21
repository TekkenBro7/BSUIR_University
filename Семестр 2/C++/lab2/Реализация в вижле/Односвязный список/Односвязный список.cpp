#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
	template<typename T>
	struct Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
public:
	List()
	{
		Size = 0;
		head = nullptr;
	}
	~List()
	{
		clear();
	}
	T search(T date)
	{
		Node<T>* current = head;
		while (current)
		{
			if (current->data == date)
			{
				return current->data;
			}
			current = current->pNext;
		}
		return T();
	}
	void pop_back()
	{
		removeAt(Size - 1);
	}
	void removeAt(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			Size--;
		}
	}
	void insert(T value, int index)
	{
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T>* newNode = new Node<T>(value, previous->pNext);
			previous->pNext = newNode;
			Size++;
	}
	void clear()
	{
		while (Size)
		{
			pop_front();
		}
	}
	void pop_front()
	{
		if (Size == 0)
		{
			cout << "Невозможно";
			return;
		}
		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}
	void push_back(const T& data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}
		Size++;
	}
	int GetSize()
	{
		return Size;
	}
	T& operator[](const int index)
	{
		int count = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (count == index)
			{
				return current->data;
			}
			current = current->pNext;
			count++;
		}
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	List<int> list;
	list.push_back(5);
	list.push_back(10);
	list.push_back(20);
	cout << list.GetSize() << '\n';
	cout << list[2] << '\n';
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i] << " ";
	}
	cout << '\n';
	list.pop_front();
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i] << " ";
	}
	cout << '\n';
//	list.push_front(50);
//	list.push_front(60);
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i] << " ";
	}
	cout << '\n';
	list.insert(100, 2);
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i] << " ";
	}
	list.removeAt(2);
	cout << '\n';
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i] << " ";
	}
	cout << '\n';
	list.pop_back();
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i] << " ";
	}
	list.search(50);
	list.clear();

	return 0;
}
