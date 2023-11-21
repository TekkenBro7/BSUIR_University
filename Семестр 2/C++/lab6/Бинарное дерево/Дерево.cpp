#include <iostream>
#include "cpp.h"
#include "vector.h"

struct Node
{
	std::string famil;
	int data;
	Node* left;
	Node* right;
	Node(std::string people, int value)
	{
		data = value;
		famil = people;
		left = nullptr;
		right = nullptr;
	}
};

class Tree
{
private:
	void DestroyTree(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		DestroyTree(node->left);
		DestroyTree(node->right);
		delete node;
	}
	// Функция для вывода информации в прямом порядке (префиксной форме)
	void prefix(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		std::cout << node->data << " " << node->famil << '\n';
		prefix(node->left);
		prefix(node->right);
	}
	// Функция для вывода информации в обратном порядке (постфиксной форме)
	void postfix(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		postfix(node->left);
		postfix(node->right);
		std::cout << node->data << " " << node->famil << '\n';
	}
	// Функция для вывода информации в порядке возрастания ключей (инфиксной форме)
	void infix(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		infix(node->left);
		std::cout << node->data << " " << node->famil << '\n';
		infix(node->right);
	}
	// Схематично вывести дерево
	int tabs = 0;
	void print_flowchart(Node* node)
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
		std::cout << node->data << " " << node->famil << '\n';
		print_flowchart(node->left);
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
	void insert(std::string people, int value)
	{
		Node* new_node = new Node(people, value);
		if (root == nullptr)
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
	void pring_prefix()
	{
		prefix(root);
		std::cout << '\n';
	}
	// Функция для вывода информации в обратном порядке (постфиксной форме)
	void print_postfix()
	{
		postfix(root);
		std::cout << '\n';
	}
	// Функция для вывода информации в порядке возрастания ключей (инфиксной форме)
	void print_infix()
	{
		infix(root);
		std::cout << '\n';
	}
	bool empty()
	{
		return root == nullptr;
	}
	void print()
	{
		tabs = 0;
		print_flowchart(root);
		std::cout << '\n';
	}
	Node* search(Node* node, int key)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (key < node->data)
		{
			search(node->left, key);
		}
		else if (key > node->data)
		{
			search(node->right, key);
		}
		else
		{
			std::cout << node->data << "  " << node->famil;
		}
		return node;
	}
	Node* DelNode(Node* node)
	{
		Node* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
	Node* deleteNode(Node* node, int key, std::string = "0")
	{
		if (node == nullptr)
		{
			return node;
		}
		if (key < node->data)
		{
			deleteNode(node->left, key);
		}
		else if (key > node->data)
		{
			deleteNode(node->right, key);
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
		Vector<Node*> nodes;
		push_in_arr(root, nodes);
		root = buildBalancedTree(nodes, 0, nodes.size() - 1);
	}
	Node* buildBalancedTree(Vector<Node*>& nodes, int start, int end)
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
	void push_in_arr(Node* node, Vector<Node*>& nodes)
	{
		if (node == nullptr)
		{
			return;
		}
		push_in_arr(node->left, nodes);
		nodes.push_back(node);
		push_in_arr(node->right, nodes);
	}
	void BFS(Node* root) 
	{
		if (root == nullptr) 
		{
			return;
		}
		Queue<Node*> a;
		a.push(root);
		while (!a.empty())
		{
			Node* current = a.front();
			a.pop();
			std::cout << "Ключ: " << current->data << ", Значение: " << current->famil << '\n';
			if (current->left != nullptr)
			{
				a.push(current->left);
			}
			if (current->right != nullptr)
			{
				a.push(current->right);
			}
		}
	}
};

class TreeTask : public Tree
{
public:
	int maxDepth(Node* node)
	{
		if (node == nullptr)
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

int main()
{
	setlocale(LC_ALL, "ru");
	TreeTask a;
	a.insert("111", 1);
	a.insert("000", 0);
	a.insert("222", 2);
	a.insert("555", 5);
	a.insert("-222", -2);
	a.insert("-111", -1);
	a.insert("-123", 0);
	a.insert("333", 3);
	a.insert("444", 4);
	a.insert("111", 1);
	a.insert("-333", -3);
	a.insert("-444", -4);
	a.insert("-444", -500);
	a.print();
	a.search(a.root, 5);
	a.print();
	a.deleteNode(a.root, 1);
//	a.balanceTree();
	a.print();
	std::cout << "\n\n" << a.maxDepth(a.root) << "\n\n";
	a.pring_prefix();
	a.print_infix();
	a.print_postfix();
	a.BFS(a.root);

	std::cout << "\n\n\n";
	
	return 0;
}