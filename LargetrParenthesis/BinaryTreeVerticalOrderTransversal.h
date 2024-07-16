#pragma once
/*
* 
* https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/
* 
314. Binary Tree Vertical Order Traversal

Given the root of a binary tree, return the vertical order traversal of its nodes' values.
(i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Example 1:

	  3
	 / \
	9	20
	   /  \
	  15   7

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:
		3
	9			8
4		0,1       7

Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]

Example 3:
		3
	9			8
4		0,1			7

	5			2
Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
/*
* 314. Binary tree Vertical order transversal
*
Given the root of a binary tree, return the vertical order traversal of its nodes' values.
(i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.



Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

	3
9		20
	 15   7

Example 2:
Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
		3
	9		8
4	   0 1   7

Example 3:
Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#define PRINTV
namespace BinaryTreeVerticalOrderTransversal
{
	struct TreeNode
	{
		int val{};
		TreeNode* left{ nullptr };
		TreeNode* right{ nullptr };
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	};

	struct Solution : private timeit
	{
		queue<pair<TreeNode*, int>> qu;
		map<int, vector<int>> verticalLevels;
		/*
		scans a queue which contains nodes and levels. Starts at root, 0.
		as it goes it adds to it the current level's left and right if they exist.
		for left child the level is level - 1.
		for right child is level + 1.
		*/
		void createLevels()
		{
			if (qu.empty()) 
				return;

			for (size_t i = 0; i < qu.size(); i++) 
			{
				auto [currNode, level] = qu.front(); qu.pop();

				verticalLevels[level].push_back(currNode->val);

				if (currNode->left)
				{
					qu.push({ currNode->left, level - 1 });
				}
				if (currNode->right)
				{
					qu.push({ currNode->right, level + 1 });
				}
			}
#ifdef PRINTV
			cout << "\n";
			for (auto [level, valuesVec]: verticalLevels)
			{
				cout << level << ":\t";
				printv(valuesVec);
			}
#endif
			createLevels();
		}

		vector<vector<int>> verticalOrder(TreeNode* root)
		{
			vector<vector<int>> ans;
			if (!root) 
				return ans;

			qu.push({ root, 0 });

			createLevels();
			// Once the vertical levels are built add them to the required resulting vector of vector of ints
			for (const auto& [level, valuesVec] : verticalLevels)
			{
				ans.push_back(valuesVec);
			}

			return ans;
		}

	};

	void process()
	{
		cout << "BinaryTreeVerticalOrderTransversal\n";
		if (true)
		{
			/*
			* 
					  3
					 / \
					9	20
					   /  \
					  15   7

			Input [3,9,20,null,null,15,7]
			Output [[9],[3,15],[20],[7]]
			*/
			auto root = new TreeNode(3);

			root->left = new TreeNode(9);
			root->right = new TreeNode(20);

			root->right->left = new TreeNode(15);
			root->right->right = new TreeNode(7);

			Solution b;
			auto res = b.verticalOrder(root);
			for (auto elem : res)
			{
				cout << "[";
				printv(elem, false);
				cout << "],";
			}
			cout << "\n";

		}
		if (true)
		{
			auto root = new TreeNode(3);

			root->left = new TreeNode(9);
			root->right = new TreeNode(8);

			root->left->left = new TreeNode(4);
			root->left->right = new TreeNode(0);

			root->right->left = new TreeNode(1);
			root->right->right = new TreeNode(7);

			Solution b;
			auto res = b.verticalOrder(root);

			for (auto elem : res)
			{
				cout << "[";
				printv(elem, false);
				cout << "],";
			}
			cout << "\n";

		}
		if (true)
		{
			auto root = new TreeNode(3);

			root->left = new TreeNode(9);
			root->right = new TreeNode(8);

			root->left->left = new TreeNode(4);
			root->left->right = new TreeNode(0);

			root->right->left = new TreeNode(1);
			root->right->right = new TreeNode(7);

			root->left->right->left = new TreeNode(5);
			root->left->right->right = new TreeNode(2);

			Solution b;
			auto res = b.verticalOrder(root);

			for (auto elem : res)
			{
				cout << "[";
				printv(elem, false);
				cout << "],";
			}
			cout << "\n";

		}

	}
}
