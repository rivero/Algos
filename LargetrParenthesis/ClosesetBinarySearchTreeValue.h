#pragma once
namespace ClosesetBinarySearchTreeValue
{
	/*
	https://leetcode.com/problems/closest-binary-search-tree-value/

	270. Closest Binary Search Tree Value
	Easy
	Topics
	Companies
	Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target. 

	If there are multiple answers, print the smallest.



	Example 1:


	Input: root = [4,2,5,1,3], target = 3.714286
	Output: 4
	Example 2:

	Input: root = [1], target = 4.428571
	Output: 1


	Constraints:

	The number of nodes in the tree is in the range [1, 104].
	0 <= Node.val <= 109
	-109 <= target <= 109
	
	Solution:

	**Method `bst` (Binary Search Tree Traversal):**
	   - This method performs an in-order traversal of a binary search tree (BST) rooted at `root`.
		 - Recurse on the left subtree (`root->left`).
		 - Calculate the absolute difference between the target value and the current node's value.
		 - If this difference is smaller than the previously recorded difference (`m_lastDifference`), 
		   update `m_lastDifference` and `m_val`.
		 - Recurse on the right subtree (`root->right`).

	In summary, this code snippet defines a class that finds the closest value to a given target in a binary search tree. 
	The `bst` method recursively traverses the tree, updating the closest value as it goes. 
	The `closestValue` method initializes the traversal and returns the result.


	**Time Complexity**:
	- The `closestValue` method performs an in-order traversal of the binary search tree (BST).
	- In the worst case, it visits every node in the BST once.
	- Therefore, the time complexity of the `closestValue` method is **O(n)**, where **n** is the number of nodes in the BST¹.
	
	**Space Complexity**:
	- The space complexity is determined by the recursive call stack during the traversal.
	- In the worst case, the maximum depth of the recursion is equal to the height of the BST.
	- If the BST is balanced, the height is **O(log n)** (where **n** is the number of nodes).
	- However, if the BST is skewed (e.g., a linked list), the height can be **O(n)**.
	- Therefore, the space complexity of the `closestValue` method is **O(n)** in the worst case¹.

	*/

	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	};

	class Solution
	{
		int val{ -1 };
		double lastdiff = numeric_limits<double>::max();
		void searchValue(TreeNode* node, double target)
		{
			if (!node) return;
			searchValue(node->left, target);
			auto diff = abs(target - double(node->val));
			if (diff < lastdiff)
			{
				lastdiff = diff;
				val = node->val;
			}

			searchValue(node->right, target);
		}
	public:
		int closestValue(TreeNode* root, double target)
		{
			searchValue(root, target);
			return val;
		}
	};

	void process()
	{
		{
			auto root = new TreeNode(4);
			root->left = new TreeNode(2);
			root->right = new TreeNode(5);
			root->left->left = new TreeNode(1);
			root->left->right = new TreeNode(3);
			Solution sol;
			cout << sol.closestValue(root, 3.7142860) << "\n";

		}
		{
			auto root = new TreeNode(1);
			Solution sol;
			cout << sol.closestValue(root, 4.428571) << "\n";

		}
		{
			auto root = new TreeNode(1);
			root->right = new TreeNode(2);

			Solution sol;
			cout << sol.closestValue(root, 3.428571) << "\n";

		}
		{
			auto root = new TreeNode(4);
			root->left = new TreeNode(2);
			root->right = new TreeNode(5);
			root->left->left = new TreeNode(1);
			root->left->right = new TreeNode(3);
			Solution sol;
			cout << sol.closestValue(root, 3.5) << "\n";

		}
		{
			auto root = new TreeNode(4);
			root->left = new TreeNode(3);
			Solution sol;
			cout << sol.closestValue(root, 3.5) << "\n";

		}
	}
}