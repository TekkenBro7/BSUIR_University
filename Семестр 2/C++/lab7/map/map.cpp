#include <iostream>
#include <list>
#include "Header.h"

using namespace std;

template <typename T1, typename T2>
struct Node_map
{
	Node_map(pair<T1, T2> pair_main)
	{
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		height = 0;
		this->pair_main.first = pair_main.first;
		this->pair_main.second = pair_main.second;
	}
	pair<T1, T2> pair_main;
	My_shared_ptr<Node_map<T1, T2>> left;
	My_shared_ptr<Node_map<T1, T2>> right;
	My_shared_ptr<Node_map<T1, T2>> parent;
	//	Node_map* left;
	//	Node_map* right;
	//	Node_map* parent;
	int height;
};

template <typename T1, typename T2>
class Map
{
private:
	My_shared_ptr<Node_map<T1, T2>> root;
	//	Node_map<T1, T2>* root;
	list<My_shared_ptr<Node_map<T1, T2>>> tree_list;
	//	list<Node_map<T1, T2>*> tree_list;
	int tabs = 0;
	void print_flowchart(My_shared_ptr<Node_map<T1, T2>> node)
	{
		if (node.get() == nullptr)
		{
			return;
		}
		tabs += 5;
		print_flowchart(node->right);
		for (int i = 0; i < tabs; i++)
		{
			std::cout << "  ";
		}
		std::cout << node->pair_main.second << '\n';
		print_flowchart(node->left);
		tabs -= 5;
		return;
	}
	void prefix(My_shared_ptr<Node_map<T1, T2>> node)
	{
		if (node == nullptr)
		{
			return;
		}
		std::cout << node->pair_main.second << " ";
		prefix(node->left);
		prefix(node->right);
	}
	void postfix(My_shared_ptr<Node_map<T1, T2>> node)
	{
		if (node == nullptr)
		{
			return;
		}
		postfix(node->left);
		postfix(node->right);
		std::cout << node->pair_main.second << " ";
	}
	void infix(My_shared_ptr<Node_map<T1, T2>> node)
	{
		if (node == nullptr)
		{
			return;
		}
		infix(node->left);
		std::cout << node->pair_main.second << " ";
		infix(node->right);
	}
public:
	void print()
	{
		tabs = 0;
		print_flowchart(root);
		std::cout << '\n';
	}
	Map()
	{
		root = nullptr;
	}
	My_shared_ptr<Node_map<T1, T2>> getRoot()
	{
		return root.get();
	}
	int GetHeight(My_shared_ptr<Node_map<T1, T2>> tmp)
	{
		return ((tmp.get() == nullptr) ? -1 : tmp->height);
	}
	int GetBalance(My_shared_ptr<Node_map<T1, T2>> temp)
	{
		return (GetHeight(temp->right) - GetHeight(temp->left));
	}
	void insert(pair<T1, T2> node)
	{
		if (root.get() == nullptr)
		{
			auto root (new Node_map<T1, T2>(node));
			//	root = new Node_map<T1, T2>(node);
			root->height = 0;
			root->parent = nullptr;
		}

		else
		{
			My_shared_ptr<Node_map<T1, T2>> curr_root = getRoot();
			My_shared_ptr<Node_map<T1, T2>> new_node(new Node_map<T1, T2>(node));
			while (curr_root.get() != nullptr)
			{
				if (curr_root->pair_main.first == node.first)
				{
					curr_root->pair_main.second = node.second;
					return;
				}
				if (curr_root->pair_main.first > node.first)
				{
					if (curr_root->left.get() == nullptr)
					{
						curr_root->left = new_node;
						new_node->height = 0;
						new_node->parent = curr_root;
						break;
					}
					else
					{
						curr_root = curr_root->left;
					}
				}
				else
				{
					if (curr_root->right.get() == nullptr)
					{
						curr_root->right = new_node;
						new_node->height = 0;
						new_node->parent = curr_root;
						break;
					}
					else
					{
						curr_root = curr_root->right;
					}
				}
			}
			balance(new_node);
		}
	}
	void heightBalance(My_shared_ptr<Node_map<T1, T2>> node)
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
	void treeFix(My_shared_ptr<Node_map<T1, T2>> node)
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
	void balance(My_shared_ptr<Node_map<T1, T2>> node)
	{
		if (node.get() == root.get())
		{
			treeFix(root);
		}
		else
		{
			while (node.get() != nullptr)
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
	void LeftRotate(My_shared_ptr<Node_map<T1, T2>> node)
	{
		pair<T1, T2> temp{ T1(), T2() };
		auto new_node(new Node_map<T1, T2>(temp));
		if (node->right->left)
		{
			new_node->right = node->right->left;
		}
		new_node->left = node->left;
		new_node->pair_main.first = node->pair_main.first;
		new_node->pair_main.second = node->pair_main.second;
		node->pair_main.second = node->right->pair_main.second;
		node->pair_main.first = node->right->pair_main.first;
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
	void RightRotate(My_shared_ptr<Node_map<T1, T2>> node)
	{
		pair<T1, T2> tmp{ T1(), T2() };
		auto new_node(new Node_map<T1, T2>(tmp));
		if (node->left->right)
		{
			new_node->left = node->left->right;
		}
		new_node->right = node->right;
		new_node->pair_main.first = node->pair_main.first;
		new_node->pair_main.second = node->pair_main.second;
		node->pair_main.second = node->left->pair_main.second;
		node->pair_main.first = node->left->pair_main.first;
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

	void removeNode(My_shared_ptr<Node_map<T1, T2>> parrent, My_shared_ptr<Node_map<T1, T2>> curr, T1 key)
	{
		if (curr.get() == nullptr)
		{
			return;
		}
		if (curr->pair_main.first == key)
		{
			if (curr->left.get() == nullptr && curr->right.get() == nullptr)
			{
				if (parrent->pair_main.first == curr->pair_main.first)
				{
					root = nullptr;
				}
				else if (parrent->right.get() == curr.get())
				{
					parrent->right = nullptr;
				}
				else
				{
					parrent->left = nullptr;
				}
				heightBalance(parrent);
			}
			else if (curr->left.get() != nullptr && curr->right.get() == nullptr)
			{
				T1 sp = curr->pair_main.first;
				curr->pair_main.first = curr->left->pair_main.first;
				curr->left->pair_main.first = sp;
				removeNode(curr, curr->left, key);
			}
			else if (curr->left.get() == nullptr && curr->right.get() != nullptr)
			{
				T1 sp = curr->pair_main.first;
				curr->pair_main.first = curr->right->pair_main.first;
				curr->right->pair_main.first = sp;
				removeNode(curr, curr->right, key);
			}
			else
			{
				auto temp = curr->right;
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
				T1 sp = curr->pair_main.first;
				curr->pair_main.first = temp->pair_main.first;
				temp->pair_main.first = sp;
				T2 sp2 = curr->pair_main.second;
				curr->pair_main.second = temp->pair_main.second;
				temp->pair_main.second = sp2;
				removeNode(parrent, temp, temp->pair_main.first);
			}
		}
	}
	void remove(T1 key)
	{
		auto node = root;
		auto parrent = node;
		//	Node_map<T1, T2>* node = root;
		//	Node_map<T1, T2>* parrent = node;
		while (node)
		{
			if (key == node->pair_main.first)
			{
				removeNode(parrent, node, key);
				balance(parrent);
				break;
			}
			else if (key < node->pair_main.first)
			{
				parrent = node;
				node = node->left;
			}
			else
			{
				parrent = node;
				node = node->right;
			}
		}
	}


	My_shared_ptr<Node_map<T1, T2>> search(T1 key)
	{
		auto node = getRoot();
		if (node == nullptr)
		{
			return nullptr;
		}
		while (node)
		{
			if (key == node->pair_main.first)
			{
				return node;
			}
			else if (key < node->pair_main.first)
			{
				node = node->left;
			}
			else
			{
				node = node->right;
			}
		}
		return nullptr;
	}
	T1& operator[](T1 key)
	{
		if (search(key))
		{
			return search(key)->pair_main.second;
		}
		else
		{
			throw "Не найдено";
		}
	}
	/*
	class Iterator_map
	{
	private:
		Node_map<T1, T2>* curr_node;
		Node_map<T1, T2>* root;

	public:
		Iterator_map(Node_map<T1, T2>* root, Node_map<T1, T2>* node)
		{
			curr_node = root;
			root = node;
		}
		Iterator_map& operator=(const Iterator_map& other)
		{
			this->root = other.root;
			this->curr_node = other.curr_node;
			return *this;
		}
		bool operator==(const Iterator_map& other)
		{
			return curr_node == other.curr_node;
		}
		bool operator!=(const Iterator_map& other)
		{
			return !(curr_node == other.curr_node);
		}
		pair<T1, T2>& operator*()
		{
			return curr_node->pair_main;
		}
		Iterator_map& operator++()
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
				Node_map<T1, T2>* pair_main = curr_node->parent;
				while (pair_main != nullptr && curr_node == pair_main->right)
				{
					curr_node = pair_main;
					pair_main = pair_main->parent;
				}
				curr_node = pair_main;
			}
			return *this;
		}
		Iterator_map& operator--()
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
				Node_map<T1, T2>* pair_main = curr_node->parent;
				while (pair_main != nullptr && curr_node == pair_main->left)
				{
					curr_node = pair_main;
					pair_main = pair_main->parent;
				}

				curr_node = pair_main;
			}
			return *this;
		}
	};
	Iterator_map begin()
	{
		Node_map<T1, T2>* node = Map<T1, T2>::root;
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return Iterator_map(node, Map<T1, T2>::root);
	}
	Iterator_map end()
	{
		return Iterator_map(nullptr, Map<T1, T2>::root);
	}
	class IteratorList_map
	{
	private:
		list<Node_map<T1, T2>> tree_list;
		typename list<Node_map<T1, T2>*>::iterator it;
	public:
		IteratorList_map(const list<Node_map<T1, T2>>& other, bool begin)
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
		list<Node_map<T1, T2>> getList()
		{
			return tree_list;
		}
		pair<T1, T2> operator*()
		{
			return (*it)->pair_main;
		}
		IteratorList_map& operator++()
		{
			++it;
			return *this;
		}
		IteratorList_map& operator--()
		{
			--it;
			return *this;
		}
	};
	*/
};


int main()
{
	Map<int, string> a;
	a.insert(make_pair(1, "q"));
	a.print();
	a.insert(make_pair(2, "w"));
	a.insert(make_pair(6, "e"));
	a.insert(make_pair(4, "r"));
	a.insert(make_pair(5, "a"));

	
	a.remove(2);
	a.print();

	return 0;
}