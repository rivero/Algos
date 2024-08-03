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

## Algorithm Explanation

**Problem:** Given a binary tree, return a list of its nodes' values ordered from left to right by their level.

**Approach:**

1. **Initialize data structures:** Use a queue to store nodes and their corresponding levels, and a map to store nodes by their 
vertical level.
2. **Create levels:**
   * Enqueue the root node with level 0.
   * While the queue is not empty:
	 * Dequeue the front node and its level.
	 * Add the node's value to the `verticalLevels` map at the current level.
	 * Enqueue the left child with level - 1 if it exists.
	 * Enqueue the right child with level + 1 if it exists.
3. **Construct result:** Iterate through the `verticalLevels` map and add the values for each level to the result vector.

**Time Complexity:** O(N)
* Each node is visited and enqueued/dequeued once, where N is the number of nodes in the tree.

**Space Complexity:** O(N)
* The queue can hold at most N nodes in the worst case (a completely skewed tree).
* The `verticalLevels` map can store up to N key-value pairs.

## Breakdown of Code

* **`createLevels` function:**
  * Performs a level-order traversal of the tree while keeping track of node levels.
  * Populates the `verticalLevels` map with nodes at their respective vertical levels.
* **`verticalOrder` function:**
  * Initializes the result vector.
  * Calls `createLevels` to populate the `verticalLevels` map.
  * Converts the map to a vector of vectors and returns it.

**Key Points:**

* The use of a queue enables level-order traversal.
* The `verticalLevels` map efficiently stores nodes based on their vertical position.
* The code provides a clear and concise implementation of the vertical order traversal.

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
