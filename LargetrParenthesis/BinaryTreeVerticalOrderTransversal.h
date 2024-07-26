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


1. **Algorithm Explanation**:
   - The given code defines a class `Solution` that aims to find the vertical order traversal of a binary tree.
   - The goal is to group nodes based on their vertical positions in the tree.
   - The algorithm uses a queue-based approach to traverse the tree level by level, maintaining the vertical levels.
   - Here are the key steps:
	 - Initialize an empty queue (`qu`) to store pairs of nodes and their corresponding vertical levels.
	 - Initialize an empty map (`verticalLevels`) to store nodes grouped by their vertical levels.
	 - Start by pushing the root node and its level (which is 0) into the queue.
	 - The `createLevels` function processes the queue:
	   - While the queue is not empty:
		 - Dequeue a pair `(currNode, level)` from the front of the queue.
		 - Add the value of `currNode` to the `verticalLevels` map at the specified `level`.
		 - If `currNode` has a left child, enqueue it with `level - 1`.
		 - If `currNode` has a right child, enqueue it with `level + 1`.
	 - The `verticalOrder` function initializes an empty result vector (`ans`).
	 - It pushes the root node and its level (0) into the queue.
	 - Calls `createLevels` to build the vertical levels.
	 - Finally, it constructs the result by adding the values from `verticalLevels` to `ans`.

2. **Complexities**:
   - **Time Complexity**: The algorithm traverses the entire tree once, visiting each node exactly once. Therefore, the time complexity is O(N), where N is the number of nodes in the tree.
   - **Space Complexity**:
	 - The space complexity includes the memory used for the queue (`qu`) and the map (`verticalLevels`).
	 - In the worst case, the queue can store all nodes (O(N)), and the map can store all distinct vertical levels (O(N)).
	 - Overall space complexity remains O(N).

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
