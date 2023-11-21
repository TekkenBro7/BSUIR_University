#include <iostream>

struct Node
{
	int key;
	Node* left;
	Node* right;
	int height;
	Node(int k)
	{
		key = k;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

class AVLTree
{
public:
	Node* root;
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
		std::cout << node->key << '\n';

		print_flowchart(node->left);
		tabs -= 5;
		return;
	}
	Node* rightRotate(Node* a)
	{
		Node* x = a->left;
		Node* y = x->right;
		x->right = a;
		a->left = y;
		a->height = max(height(a->left), height(a->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x;
	}
	Node* leftRotate(Node* a)
	{
		Node* x = a->right;
		Node* y = x->left;
		x->left = a;
		a->right = y;
		a->height = max(height(a->left), height(a->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x;
	}
	int getBalance(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return height(node->left) - height(node->right);
	}
public:
	AVLTree()
	{
		root = nullptr;
	}
	~AVLTree()
	{
		DestroyTree(root);
	}
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
	bool empty()
	{
		return root == nullptr;
	}
	int height(Node* a)
	{
		if (a == nullptr)
		{
			return 0;
		}
		return a->height;
	}
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	Node* search(Node* node, int key)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (key < node->key)
		{
			search(node->left, key);
		}
		else if (key > node->key)
		{
			search(node->right, key);
		}
		else
		{
			std::cout << node->key;
		}
		return node;
	}
/*
	Node* minValueNode(Node* node) {
		Node* current = node;

		while (current->left != nullptr)
			current = current->left;

		return current;
	}

	Node* deleteNode(Node* root, int key) {
		if (root == nullptr)
			return root;

		if (key < root->key)
			root->left = deleteNode(root->left, key);
		else if (key > root->key)
			root->right = deleteNode(root->right, key);
		else {
			if ((root->left == nullptr) || (root->right == nullptr)) {
				Node* temp = root->left ? root->left : root->right;

				if (temp == nullptr) {
					temp = root;
					root = nullptr;
				}
				else {
					*root = *temp;
				}

				delete temp;
			}
			else {
				Node* temp = minValueNode(root->right);

				root->key = temp->key;
				root->right = deleteNode(root->right, temp->key);
			}
		}

		if (root == nullptr)
			return root;

		root->height = 1 + max(height(root->left), height(root->right));

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);

		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);

		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}
	*/
	void print()
	{
		tabs = 0;
		print_flowchart(root);
		std::cout << '\n';
	}
	Node* insert(Node* node, int key)
	{
		if (node == nullptr)
		{
			return new Node(key);
		}
		if (key < node->key)
		{
			node->left = insert(node->left, key);
		}
		else if (key > node->key)
		{
			node->right = insert(node->right, key);
		}
		else
		{
			return node;
		}
		node->height = 1 + max(height(node->left), height(node->right));
		int balance = getBalance(node);
		if (balance > 1 && key < node->left->key)
		{
			return rightRotate(node);
		}
		if (balance < -1 && key > node->right->key)
		{
			return leftRotate(node);
		}
		if (balance > 1 && key > node->left->key) 
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		if (balance < -1 && key < node->right->key) 
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
};

int main()
{
	AVLTree tree;
	tree.root = tree.insert(tree.root, 10);
	tree.root = tree.insert(tree.root, 20);
	tree.root = tree.insert(tree.root, 39);
	tree.print();
	std::cout << "\n\n\n";
	tree.root = tree.insert(tree.root, 50);
	tree.root = tree.insert(tree.root, 60);

	tree.print();
	std::cout << "\n\n\n";
//	tree.root = tree.insert(tree.root, 50);
	tree.print();
	std::cout << "\n\n\n";
//	tree.root = tree.insert(tree.root, 70);
	tree.print();
	std::cout << "\n\n\n";
	tree.search(tree.root, 111);
	tree.search(tree.root, 10);

	std::cout << "\n\n\n";

//	tree.deleteNode(tree.root, 10);

	std::cout << "\n\n\n";
	tree.print();

	return 0;
}