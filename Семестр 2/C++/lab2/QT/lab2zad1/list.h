#ifndef LIST_H
#define LIST_H
#include <QString>

struct Node;
class List;


struct Node
{
public:
    Node(QString country, QString komanda, QString famil, QString nom, QString agee, QString rostt, QString vess)
    {
        this->country = country;
        this->komanda = komanda;
        this->fam = famil;
        this->nomer = nom;
        this->age = agee;
        this->rost = rostt;
        this->ves = vess;
        this->prev = this->next = nullptr;
    }
    Node* prev;
    Node* next;
    QString country;
    QString komanda;
    QString fam;
    QString nomer;
    QString age;
    QString rost;
    QString ves;
    QString GetCountru()
    {
        return this->country;
    }
    void setCountry(QString country)
    {
        this->country = country;
    }
    void setKomanda(QString komanda)
    {
        this->komanda = komanda;
    }
    void setFam(QString fam)
    {
        this->fam = fam;
    }
    void setNomer(QString nomer)
    {
        this->nomer = nomer;
    }
    void setAge(QString age)
    {
        this->age = age;
    }
    void setRost(QString rost)
    {
        this->rost = rost;
    }
    void setVes(QString ves)
    {
        this->ves = ves;
    }
};


class List
{
public:

    Node* head;
    Node* tail;
    int Size;

public:
    List();
    ~List();
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

    void EndDeleteNodeAtIndex(int index, int size)
    {
      if (tail == NULL)
      {
          return;
      }
      Node* currentNode = tail;
      int currentIndex = size;
      while (currentNode != NULL && currentIndex != index)
      {
        currentNode = currentNode->prev;
        currentIndex--;
      }
      if (currentNode == NULL)
      {
          return;
      }
      Node* prevNode = currentNode->next;
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
    Node* getAt(int index);
    Node* operator [](int index);
    bool isEmpty() const;
    int GetSize();
    void push_front(QString country, QString komanda, QString famil, QString nom, QString agee, QString rostt, QString vess);  // Добавляет элемент в начало
    void push_back(QString country, QString komanda, QString famil, QString nom, QString agee, QString rostt, QString vess);  // Добавить элемент в конец
    void display();  // Вывод списка на экран
    void pop_front();  // Удалить элемент сначала
    void clear();  // Удалить полностью список
    void pop_back() {
           if (tail != nullptr) {
               Node* nodeToDelete = tail;
               tail = tail->prev;

               if (tail != nullptr){
                   tail->next = nullptr;
               } else {
                   head = nullptr;
               }

               delete nodeToDelete;
           }
       }
};

#endif // LIST_H
