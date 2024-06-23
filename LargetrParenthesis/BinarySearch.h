#pragma once
namespace BinarySearch
{
	// A binary tree node has data, pointer to left child
	// and a pointer to right child
	template <typename T>
	struct Node {
		T data;
		Node(int d) : data(d)
		{
			std::cout << data << " ";
		}
		~Node()
		{
			std::cout << data << " ";
		}

		struct Node* left{ nullptr }, * right{ nullptr };

		static Node* newNode(T data)
		{
			return new Node<T>(data);
		}

		static void DeleteTree(Node* node)
		{
			if (node->left)
			{
				DeleteTree(node->left);
				delete node->left;
			}
			if (node->right)
			{
				DeleteTree(node->right);
				delete node->right;
			}
		}
	};

	template <typename T>
	struct DeptFirst : public timeit
	{
		DeptFirst()
		{
			std::cout << "\n\nDepth first Search\n";
		}
		// Given a binary tree, print its nodes in Preorder
		void printPreOrder(const Node<T>* node)
		{
			if (node == nullptr)
				return;

			// First print the data of node
			std::cout << node->data << " ";

			// then recur on left child
			printPreOrder(node->left);

			// Now recur on right child
			printPreOrder(node->right);
		}

		// Given a binary tree, print its nodes in inorder
		void printInorder(const Node<T>* node)
		{
			if (node == nullptr)
				return;

			// First recur on left child
			printInorder(node->left);

			// Then print the data of node
			std::cout << node->data << " ";

			// Now recur on right child
			printInorder(node->right);
		}

		// Given a binary tree, print its nodes in Postrder
		void printPostOrder(const Node<T>* node)
		{
			if (node == nullptr)
				return;

			// First recur on left child
			printPostOrder(node->left);
			// Then recur on right child
			printPostOrder(node->right);
			// Finally print the data of node
			std::cout << node->data << " ";

		}
	};

	/*
	Time complexity
	O(n) linear
	Space complexity
	number of nodes = space complexity.

	one node pop one pushed - best case O(1)
	perfect tree - worst case O(n)

	*/
	template <typename T>
	struct BreadthFirst : public timeit
	{
		BreadthFirst()
		{
			std::cout << "\n\nBreadth first Search\n";
		}
		void printLevel(const Node<T>* root)
		{
			if (root == nullptr)
				return;

			std::queue< const Node<T>* > Q;
			Q.push(root);
			int col_counter{};

			while (!Q.empty())
			{
				auto current = Q.front();
				std::cout << current->data << " ";
				if (current->left)
					Q.push(current->left);
				if (current->right)
					Q.push(current->right);
				Q.pop();
			}

		}

	};
	struct Nooby : protected timeit
	{
		static void know_algos()
		{
			std::cout << "\nknow algos\n";
			std::cout << "find positive using lambda ";
			const std::vector<int> vec{ -1,-3, -5, 8, 15, -1 };
			printv(vec);
			auto is_positive = [](int x) { return (x > 0); };
			auto first_pos = find_if(vec.begin(), vec.end(), is_positive);
			std::cout << *first_pos << "\n";
		}
		void struct_bindings()
		{
			static std::unordered_map<std::string, std::string> colors
			{
				{"RED", "#FF000"},
				{"GREEN", "#00FF00"},
				{"BLUE", "#0000FF"}
			};

			for (const auto& [name, number] : colors)
			{
				std::cout << "name " << name << " number " << number << "\n";
			}

			struct S
			{
				int a;
				std::string s;
				S() : a(100), s("Name") {}
			};
			S s;

			const auto [number, name] = s;
			std::cout << " name " << name << " number " << number << "\n";
		}
	};

	Node<int>* createInts()
	{
		auto root = Node<int>::newNode(1);

		root->left = Node<int>::newNode(2);
		root->right = Node<int>::newNode(3);

		root->left->left = Node<int>::newNode(4);
		root->left->right = Node<int>::newNode(5);

		root->right->left = Node<int>::newNode(6);
		root->right->right = Node<int>::newNode(7);
		return root;
	}

	Node<char>* createChars()
	{
		auto root = Node<char>::newNode('F');

		root->left = Node<char>::newNode('D');
		root->right = Node<char>::newNode('J');

		root->left->left = Node<char>::newNode('B');
		root->left->right = Node<char>::newNode('E');
		root->left->left->left = Node<char>::newNode('A');
		root->left->left->right = Node<char>::newNode('C');

		root->right->left = Node<char>::newNode('G');
		root->right->left->right = Node<char>::newNode('I');
		root->right->left->right->left = Node<char>::newNode('H');
		root->right->right = Node<char>::newNode('K');
		return root;
	}

	Node<int>* createCharsBTVOT()
	{
		auto root = Node<int>::newNode(3);

		root->left = Node<int>::newNode(9);
		root->right = Node<int>::newNode(20);

		root->right->left = Node<int>::newNode(15);
		root->right->right = Node<int>::newNode(7);
		return root;
	}

	void process()
	{
		cout << "\nBinarySearch\n";
		if (true)
		{
			cout << "\nInts\t";
			auto root = createInts();

			DeptFirst<int> d;
			// Function call
			cout << "\nPreorder traversal of binary tree is\t";
			d.printPreOrder(root);

			cout << "\nInorder traversal of binary tree is\t";
			d.printInorder(root);

			cout << "\nPostorder traversal of binary tree is\t";
			d.printPostOrder(root);

			cout << "\nDestructing\t";
			Node<int>::DeleteTree(root);
			delete root;
		}
		if (true)
		{
			cout << "\nCharacters\t";
			auto root = createChars();

			DeptFirst<char> d;
			// Function call
			cout << "\nPreorder traversal of binary tree is\t";
			d.printPreOrder(root);

			cout << "\nInorder traversal of binary tree is\t";
			d.printInorder(root);

			cout << "\nPostorder traversal of binary tree is\t";
			d.printPostOrder(root);

			cout << "\nDestructing\t";
			Node<char>::DeleteTree(root);
			delete root;
			cout << endl;
		}
		if (false)
		{
			cout << "\nConstructing char\t";
			auto root = createChars();

			BreadthFirst<char> b;
			cout << "\nPrinting\t";
			b.printLevel(root);

			cout << "\nDestructing\t";
			Node<char>::DeleteTree(root);
			delete root;
			cout << endl;
		}

		if (false)
		{
			cout << "\nConstructing BTVOT\t";
			auto root = createCharsBTVOT();

			BreadthFirst<int> b;
			cout << "\nPrinting\t";
			b.printLevel(root);

			cout << "\nDestructing\t";
			Node<int>::DeleteTree(root);
			delete root;
			cout << endl;
		}
		if (false)
		{
			Nooby n;
			n.know_algos();
			n.struct_bindings();
		}

	}
}
