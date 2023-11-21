#include <list.h>
#include <mainwindow.h>

List::List()
{
    Size = 0;
    head = tail = nullptr;
}

List::~List()
{
    clear();
}

Node* List::getAt(int index)
{
    Node* prt = head;
    int n = 0;
    while (n != index)
    {
        if (prt == nullptr)
        {
            return prt;
        }
        prt = prt->next;
        n++;
    }
    return prt;
}

Node* List::operator [](int index)
{
    return getAt(index);
}

void List::clear()
{
    while (Size)
    {
        pop_front();
    }
}

void List::pop_front()
{
    if (head == nullptr) return;
    Node* ptr = head->next;
    if (ptr != nullptr)
    {
        ptr->prev = nullptr;
    }
    else
    {
        tail = ptr;
    }
//    delete head;
    head = ptr;
    Size--;
   }

    /*
    if (isEmpty())
    {
    //    std::cout << "Удалять нечего\n";
        return;
    }
    else
    {
        Node* ptr = head;
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
    */


void List::push_back(QString country, QString komanda, QString famil, QString nom, QString agee, QString rostt, QString vess)
{
    Node* ptr = new Node(country, komanda, famil, nom, agee, rostt, vess);
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


bool List::isEmpty() const
{
    return head == nullptr;
}

int List::GetSize()
{
    return Size;
}


void List::push_front(QString country, QString komanda, QString famil, QString nom, QString agee, QString rostt, QString vess)
{
    Node* ptr = new Node(country, komanda, famil, nom, agee, rostt, vess);
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

void List::display()
{
    if (isEmpty())
    {
//        std::cout << "Cписок пуст\n";
    }
    else
    {
        Node* current = head;
        while (current != nullptr)
        {
            current = current->next;
        }
    }
}
