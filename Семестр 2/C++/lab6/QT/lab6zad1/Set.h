#ifndef SET_H
#define SET_H

#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct Node
{
    int key;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        height = 0;
    }
};

template<typename T>
class Set
{
private:
    list<Node<T>*> tree_list;
    int tabs = 0;
    void print_flowchart(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        tabs += 5;
        print_flowchart(node->right);
        for (int i = 0; i < tabs; i++)
        {
            std::cout << "  ";
        }
        std::cout << node->key << '\n';
        print_flowchart(node->left);
        tabs -= 5;
        return;
    }
    Node<T>* getRoot()
    {
        return root;
    }
    int GetBalance(Node<T>* node)
    {
        return (GetHeight(node->right) - GetHeight(node->left));
    }
    int GetHeight(Node<T>* node)
    {
        return ((node == nullptr) ? -1 : node->height);
    }
    void heightBalance(Node<T>* node)
    {
        int lefft = -1, rigght = -1;
        if (node->left)
        {
            lefft = node->left->height;
        }
        if (node->right)
        {
            rigght = node->right->height;
        }
        node->height = max(lefft, rigght) + 1;
    }
    void treeFix(Node<T>* node)
    {
        if (GetBalance(node) == 2)  //правое поддерево сильнее, чем левое на 2
        {
            if (GetBalance(node->right) < 0)
            {
                RightRotate(node->right);
            }
            LeftRotate(node);
            heightBalance(node);
        }
        else if (GetBalance(node) == -2) //левое поддерево сильнее, чем правое на 2
        {
            if (GetBalance(node->left) > 0)
            {
                LeftRotate(node->left);
            }
            RightRotate(node);
            heightBalance(node);
        }
    }
    void balance(Node<T>* node)
    {
        if (node == root)
        {
            treeFix(root);
        }
        else
        {
            while (node != nullptr)
            {
                heightBalance(node);
                node = node->parent;
                if (node)
                {
                    treeFix(node);
                }
            }
        }
    }

    void LeftRotate(Node<T>* node)
    {
        T tmp = 0;
        Node<T>* new_node = new Node<T>(tmp);
        if (node->right->left)
        {
            new_node->right = node->right->left;
        }
        new_node->left = node->left;
        new_node->key = node->key;
        node->key = node->right->key;
        node->left = new_node;
        if (new_node->left)
        {
            new_node->left->parent = new_node;
        }
        if (new_node->right)
        {
            new_node->right->parent = new_node;
        }
        new_node->parent = node;
        if (node->right->right)
        {
            node->right = node->right->right;
        }
        else
        {
            node->right = nullptr;
        }
        if (node->right)
        {
            node->right->parent = node;
        }
        heightBalance(node->left);
        if (node->right)
        {
            heightBalance(node->right);
        }
        heightBalance(node);
    }
    void RightRotate(Node<T>* node)
    {
        T tmp = 0;
        Node< T>* new_node = new Node< T>(tmp);
        if (node->left->right)
        {
            new_node->left = node->left->right;
        }
        new_node->right = node->right;
        new_node->key = node->key;
        node->key = node->left->key;
        node->right = new_node;
        if (new_node->left)
        {
            new_node->left->parent = new_node;
        }
        if (new_node->right)
        {
            new_node->right->parent = new_node;
        }
        new_node->parent = node;
        if (node->left->left)
        {
            node->left = node->left->left;
        }
        else
        {
            node->left = nullptr;
        }
        if (node->left)
        {
            node->left->parent = node;
        }
        heightBalance(node->right);
        if (node->left)
        {
            heightBalance(node->left);
        }
        heightBalance(node);
    }

    void RemoveNode(Node<T>* parrent, Node<T>* curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        if (curr->left == nullptr && curr->right == nullptr)
        {
            if (parrent->key == curr->key)
            {
                root = nullptr;
            }
            else if (parrent->right == curr)
            {
                parrent->right = nullptr;
            }
            else
            {
                parrent->left = nullptr;
            }
            balance(parrent);
        }
        else if (curr->left != nullptr && curr->right == nullptr)
        {
            T sp = curr->key;
            curr->key = curr->left->key;
            curr->left->key = sp;
            RemoveNode(curr, curr->left);
        }
        else if (curr->left == nullptr && curr->right != nullptr)
        {
            T sp = curr->key;
            curr->key = curr->right->key;
            curr->right->key = sp;
            RemoveNode(curr, curr->right);
        }
        else
        {
            Node<T>* temp = curr->right;
            int flag = 0;
            while (temp->left)
            {
                flag = 1;
                parrent = temp;
                temp = temp->left;
            }
            if (!flag)
            {
                parrent = curr;
            }
            T sp = curr->key;
            curr->key = temp->key;
            temp->key = sp;
            RemoveNode(parrent, temp);
        }
    }
public:
    Node<T>* root;
    Set()
    {
        root = nullptr;
    }
    class Iterator
    {
    private:
        Node<T>* curr_node;
        Node<T>* root;
    public:
        Iterator(Node<T>* root, Node<T>* node)
        {
            curr_node = root;
            this->root = node;
        }
        Iterator& operator=(const Iterator& other)
        {
            this->root = other.root;
            this->curr_node = other.curr_node;
            return *this;
        }
        bool operator==(const Iterator& other)
        {
            return curr_node == other.curr_node;
        }
        bool operator!=(const Iterator& other)
        {
            return !(curr_node == other.curr_node);
        }
        T& operator*()
        {
            return curr_node->key;
        }
        Iterator& operator++()
        {
            if (curr_node == nullptr)
            {
                curr_node = root;
                if (curr_node == nullptr)
                {
                    return *this;
                }
                while (curr_node->left != nullptr)
                {
                    curr_node = curr_node->left;
                }
            }
            else if (curr_node->right != nullptr)
            {
                curr_node = curr_node->right;
                while (curr_node->left != nullptr)
                {
                    curr_node = curr_node->left;
                }
            }
            else
            {
                Node<T>* p = curr_node->parent;
                while (p != nullptr && curr_node == p->right)
                {
                    curr_node = p;
                    p = p->parent;
                }
                curr_node = p;
            }
            return *this;
        }
        Iterator& operator--()
        {
            if (curr_node == nullptr)
            {
                curr_node = root;
                if (curr_node == nullptr)
                {
                    return *this;
                }
                while (curr_node->right != nullptr)
                {
                    curr_node = curr_node->right;
                }
            }
            else if (curr_node->left != nullptr)
            {
                curr_node = curr_node->left;
                while (curr_node->right != nullptr)
                {
                    curr_node = curr_node->right;
                }
            }
            else
            {
                Node<T>* p = curr_node->parent;
                while (p != nullptr && curr_node == p->left)
                {
                    curr_node = p;
                    p = p->parent;
                }
                curr_node = p;
            }
            return *this;
        }
    };
    Iterator begin()
    {
        Node<T>* node = Set<T>::root;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return Iterator(node, Set<T>::root);
    }
    Iterator end()
    {
        return Iterator(nullptr, Set<T>::root);
    }
    class IteratorList
    {
    private:
        list<Node<T>> tree_list;
        typename list<Node<T>*>::iterator it;
    public:
        IteratorList(const list<Node<T>>& other, bool begin)
        {
            tree_list = other;
            if (begin)
            {
                it = tree_list.begin();
            }
            else
            {
                it = tree_list.end();
            }
        }
        list<Node<T> > getList()
        {
            return tree_list;
        }
        T operator*()
        {
            return *it;
        }
        IteratorList& operator++()
        {
            ++it;
            return *this;
        }
        IteratorList& operator--()
        {
            --it;
            return *this;
        }
    };
    void prefix(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->key << " ";
        prefix(node->left);
        prefix(node->right);
    }
    void postfix(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        postfix(node->left);
        postfix(node->right);
        std::cout << node->key << " ";
    }
    void infix(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        infix(node->left);
        std::cout << node->key << " ";
        infix(node->right);
    }
    void insert(T key)
    {
        if (root == nullptr)
        {
            root = new Node<T>(key);
            root->height = 0;
            root->parent = nullptr;
        }
        else
        {
            Node<T>* new_root = getRoot();
            Node<T>* new_node = new Node<T>(key);
            while (new_root != nullptr)
            {
                if (new_root->key == key)
                {
                    new_root->key = key;
                    return;
                }
                if (new_root->key > key)
                {
                    if (new_root->left == nullptr)
                    {
                        new_root->left = new_node;
                        new_node->height = 0;
                        new_node->parent = new_root;
                        break;
                    }
                    else
                    {
                        new_root = new_root->left;
                    }
                }
                else
                {
                    if (new_root->right == nullptr)
                    {
                        new_root->right = new_node;
                        new_node->height = 0;
                        new_node->parent = new_root;
                        break;
                    }
                    else
                    {
                        new_root = new_root->right;
                    }
                }
            }
            balance(new_node);
        }
    }
    void print()
    {
        tabs = 0;
        print_flowchart(root);
        std::cout << '\n';
    }
    void remove(T key)
    {
        Node<T>* tmp = root;
        Node<T>* parent = tmp;
        if (tmp == nullptr)
        {
            return;
        }
        while (tmp)
        {
            if (key == tmp->key)
            {
                RemoveNode(parent, tmp);
                break;
            }
            else if (key < tmp->key)
            {
                parent = tmp;
                tmp = tmp->left;
            }
            else
            {
                parent = tmp;
                tmp = tmp->right;
            }
        }
        return;
    }
    Node<T>* search(T key)
    {
        Node<T>* tmp = getRoot();
        if (tmp == nullptr)
        {
            return nullptr;
        }
        while (tmp)
        {
            if (key == tmp->key)
            {
                return tmp;
            }
            else if (key < tmp->key)
            {
                tmp = tmp->left;
            }
            else
            {
                tmp = tmp->right;
            }
        }
        return nullptr;
    }
    T operator[](T key)
    {
        if (search(key))
        {
            return search(key)->key;
        }
        else
        {
            throw "Не найдено";
        }
    }
};

#endif // SET_H
