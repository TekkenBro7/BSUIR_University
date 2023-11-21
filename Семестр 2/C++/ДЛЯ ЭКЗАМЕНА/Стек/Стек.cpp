#include <iostream>

struct Node 
{
    int data;
    Node* next;
};

class Stack 
{
private:
    Node* top;
public:
    Stack()
    {
        top = nullptr;
    }
    bool isEmpty() 
    {
        return top == nullptr;
    }
    void push(int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    void pop() 
    {
        if (isEmpty()) 
        {
            std::cout << "Стек пуст!" << '\n';
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek() 
    {
        if (isEmpty()) 
        {
            std::cout << "Стек пуст!" << '\n';
            return -1;
        }
        return top->data;
    }
};


int main() 
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Верхний элемент стека: " << stack.peek() << std::endl;
    stack.pop();
    stack.pop();
    std::cout << "Верхний элемент стека после удаления: " << stack.peek() << std::endl;

    return 0;
}
