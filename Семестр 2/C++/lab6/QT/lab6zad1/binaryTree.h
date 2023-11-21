#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QString>
#include <QMessageBox>

struct Node
{
    QString famil;
    int data;
    Node* left;
    Node* right;
    Node(QString people, int value)
    {
        data = value;
        famil = people;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
protected:
    int tabs = 0;
    void DestroyTree(Node* node)
    {
        if (node == NULL)
        {
            return;
        }
        DestroyTree(node->left);
        DestroyTree(node->right);
        delete node;
    }
    // Функция для вывода информации в прямом порядке (префиксной форме)
    void prefix(Node* node, QString& s)
    {
        if (node == NULL)
        {
            return;
        }
        s += QString::number(node->data);
        s += " ";
        s += node->famil;
        s += '\n';
        prefix(node->left, s);
        prefix(node->right, s);
    }
    // Функция для вывода информации в обратном порядке (постфиксной форме)
    void postfix(Node* node, QString& s)
    {
        if (node == NULL)
        {
            return;
        }
        postfix(node->left, s);
        postfix(node->right, s);
        s += QString::number(node->data);
        s += " ";
        s += node->famil;
        s += '\n';
    }
    // Функция для вывода информации в порядке возрастания ключей (инфиксной форме)
    void infix(Node* node, QString& s)
    {
        if (node == NULL)
        {
            return;
        }
        infix(node->left, s);
        s += QString::number(node->data);
        s += " ";
        s += node->famil;
        s += '\n';
        infix(node->right, s);
    }
    // Схематично вывести дерево
    void print_flowchart(Node* node, QString& s)
    {
        if (node == nullptr)
        {
            return;
        }
        tabs += 5;
        print_flowchart(node->right, s);
        for (int i = 0; i < tabs; i++)
        {
            s += "  ";
        }
        s += QString::number(node->data);
        s += " ";
        s += node->famil;
        s += '\n';
        print_flowchart(node->left, s);
        tabs -= 5;
        return;
    }
public:
    Node* root;
    Tree()
    {
        root = nullptr;
    }
    ~Tree()
    {
        DestroyTree(root);
    }
    void insert(QString people, int value)
    {
        Node* new_node = new Node(people, value);
        if (root == NULL)
        {
            root = new_node;
            return;
        }
        Node* current = root;
        while (true)
        {
            if (value < current->data)
            {
                if (current->left == nullptr)
                {
                    current->left = new_node;
                    return;
                }
                current = current->left;
            }
            else if (value == current->data)
            {
                return;
            }
            else
            {
                if (current->right == nullptr)
                {
                    current->right = new_node;
                    return;
                }
                current = current->right;
            }
        }
    }
    // Функция для вывода информации в прямом порядке (префиксной форме)
    QString print_prefix(QString& s)
    {
        prefix(root, s);
        return s;
    }
    // Функция для вывода информации в обратном порядке (постфиксной форме)
    QString print_postfix(QString& s)
    {
        postfix(root, s);
        return s;
    }
    // Функция для вывода информации в порядке возрастания ключей (инфиксной форме)
    QString print_infix(QString& s)
    {
        infix(root, s);
        return s;
    }
    bool empty()
    {
        return root == nullptr;
    }
    QString print(QString& s)
    {
        tabs = 0;
        print_flowchart(root, s);
        return s;
    }
    Node* searchNode(Node* node, int key)
    {
        if (node == nullptr || node->data == key)
        {
           return node;
        }
        else if (key < node->data)
        {
            return searchNode(node->left, key);
        }
        else
        {
            return searchNode(node->right, key);
        }
    }
    QString search(int key)
    {
        Node *node = searchNode(root, key);
        if (node == nullptr)
        {
            QString str = "";
            return str;
        }
        else
        {
            QString str = "";
            str += QString::number(node->data);
            str += " ";
            str += node->famil;
            return str;
        }
    }
    Node* DelNode(Node* node)
    {
        Node* current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    Node* deleteNode(Node* node, int key, QString = "0")
    {
        if (node == nullptr)
        {
            return node;
        }
        if (key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node* temp = DelNode(node->right);
                node->data = temp->data;
                node->famil = temp->famil;
                node->right = deleteNode(node->right, temp->data, temp->famil);
            }
        }
        return node;
    }
    void balanceTree()
    {
        std::vector<Node*> nodes;
        push_in_arr(root, nodes);
        root = buildBalancedTree(nodes, 0, nodes.size() - 1);
    }
    Node* buildBalancedTree(std::vector<Node*>& nodes, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;
        Node* root = nodes[mid];
        root->left = buildBalancedTree(nodes, start, mid - 1);
        root->right = buildBalancedTree(nodes, mid + 1, end);
        return root;
    }
    void push_in_arr(Node* node, std::vector<Node*>& nodes)
    {
        if (node == nullptr)
        {
            return;
        }
        push_in_arr(node->left, nodes);
        nodes.push_back(node);
        push_in_arr(node->right, nodes);
    }
};

class TreeTask : public Tree
{
public:
    int maxDepth(Node* node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            int leftDepth = maxDepth(node->left);
            int rightDepth = maxDepth(node->right);
            if (leftDepth > rightDepth)
            {
                return (leftDepth + 1);
            }
            else
            {
                return (rightDepth + 1);
            }
        }
    }

};

#endif // BINARYTREE_H
