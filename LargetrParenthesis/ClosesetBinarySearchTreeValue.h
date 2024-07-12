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
		int m_val{-1};
		double m_lastDifference{ std::numeric_limits<double>::max()};

		void bst(TreeNode* root, double target)
		{
			if (!root)
			{
				return;
			}
			bst(root->left, target);
			auto difference = abs(target - double(root->val));
			if (difference < m_lastDifference)
			{
				m_lastDifference = difference;
				m_val = root->val;
			}

			bst(root->right, target);

		}
	public:
		int closestValue(TreeNode* root, double target)
		{
			bst(root, target);
			return m_val;
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