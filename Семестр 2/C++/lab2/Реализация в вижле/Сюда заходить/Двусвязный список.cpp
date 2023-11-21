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
		T data;
		Node* prev;
		Node* next;
		Node(T data = T())
		{
			this->data = data;
			this->prev = this->next = nullptr;
		}
	};
	Node<T>* head;
	Node<T>* tail;
	int Size;



public:
	List();
	~List();
	bool isEmpty() const;
	int GetSize();
	void push_front(T data);  // Добавляет элемент в начало
	void push_back(T data);  // Добавить элемент в конец
	void display();  // Вывод списка на экран
	void pop_back();  // Удалить элемент в конце
	void pop_front();  // Удалить элемент сначала
	void clear();  // Удалить полностью список
	void insertAtPosition(T data, int position) 
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;
		if (head == NULL) 
		{
			head = newNode;
			return;
		}
		if (position == 1) 
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}
		Node<T>* temp = head;
		for (int i = 1; i < position - 1 && temp != NULL; i++) 
		{
			temp = temp->next;
		}
		if (temp == NULL) 
		{
			cout << "Invalid position" << endl;
			return;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		/*
		if (temp->next != NULL) 
		{
		temp->next->prev = newNode;
		}
		*/
		temp->next = newNode;

	}
	/*
	
	Удаление по индкексу

	 void NachDeleteNodeAtIndex(int index)
	{
	  if (head == NULL)
	  {
		  return;
	  }
	  Node* currentNode = head;
	  int currentIndex = 0;
	  while (currentNode != NULL && currentIndex != index)
	  {
		currentNode = currentNode->next;
		currentIndex++;
	  }
	  if (currentNode == NULL)
	  {
		  return;
	  }
	  Node* prevNode = currentNode->prev;
	  Node* nextNode = currentNode->next;

	  if (prevNode != NULL)
	  {
		prevNode->next = nextNode;
	  }
	  else
	  {
		head = nextNode;
	  }
	  if (nextNode != NULL)
	  {
		nextNode->prev = prevNode;
	  }

	  delete currentNode;
	}
		
	*/
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = tail = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_back()
{
	if (isEmpty())
	{
		std::cout << "Удалять нечего\n";
	}
	else
	{
		Node<T>* ptr = tail;
		tail = tail->prev;
		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete ptr;
		Size--;
	}
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (isEmpty())
	{
		std::cout << "Удалять нечего\n";
	}
	else
	{
		Node<T>* ptr = head;
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete ptr;
		Size--;
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* ptr = new Node<T>(data);
	if (isEmpty())
	{
		head = tail = ptr;
	}
	else
	{
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
		Size++;
	}
}

template<typename T>
bool List<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
int List<T>::GetSize()
{
	return Size;
}

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* ptr = new Node<T>(data);
	if (isEmpty())
	{
		head = tail = ptr;
	}
	else
	{
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
	Size++;
}

template<typename T>
void List<T>::display()
{
	if (isEmpty())
	{
		std::cout << "Cписок пуст\n";
	}
	else
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
	}
}




int main()
{
	setlocale(LC_ALL, "ru");
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_back(5);
	list.display();
	std::cout << '\n';

//	list.insertAtPosition(10, 4);

	list.display();
	std::cout << '\n';

	list.pop_back();
//	list.pop_front();
	list.display();

	return 0;
}

