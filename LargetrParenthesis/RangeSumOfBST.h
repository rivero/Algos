#pragma once
namespace RangeSumOfBST
{
	/*
Given the root node of a binary search tree and two integers low and high,
return the sum of values of all nodes with a value in the inclusive range [low, high].

Example 1
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

			  10
		5			15
	3		7	null	18

Definition for a binary tree node.
   */
	struct TreeNode
	{
		int val{};
		TreeNode* left{ nullptr };
		TreeNode* right{ nullptr };
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	};
	struct Solution : public timeit 
	{
		int m_sum{};

		void preorder(TreeNode* root, int low, int high)
		{
			if (root)
			{
				if (root->val >= low && root->val <= high)
					m_sum += root->val;
				preorder(root->left, low, high);
				preorder(root->right, low, high);
			}
		}

		int rangeSumBST(TreeNode* root, int low, int high)
		{
			preorder(root, low, high);
			return m_sum;
		}
	};

	int process()
	{
		cout << "RangeSumOfBST\n";
		auto root = new TreeNode(10);

		root->left = new TreeNode(5);
		root->left->left = new TreeNode(3);
		root->left->right = new TreeNode(7);

		root->right = new TreeNode(15);
		root->right->right = new TreeNode(18);
		Solution sol;
		return sol.rangeSumBST(root, 7, 15);
	}

}
