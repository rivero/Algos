#pragma once
/*
* https://leetcode.com/problems/range-sum-of-bst/

* 938. Range Sum of BST
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

Certainly! Let's break down the code snippet and discuss why it uses a preorder traversal.

1. **Code Explanation**:
	- The given code defines a class `Solution` with a member variable `m_sum` (initialized to 0) and a member function `rangeSumBST`.
	- The purpose of `rangeSumBST` is to calculate the sum of values within a binary search tree (BST) that fall within a given range `[low, high]`.
	- The function takes three parameters:
		- `root`: A pointer to the root node of the BST.
		- `low`: The lower bound of the range.
		- `high`: The upper bound of the range.
	- The function recursively traverses the BST and accumulates the sum of values that satisfy the range condition.

2. **Preorder Traversal**:
	- The traversal strategy used in this code is **preorder**.
	- In a **preorder traversal**, the order of visiting nodes is as follows:
		1. Visit the root node.
		2. Recur on the left subtree.
		3. Recur on the right subtree.
	- This means that the root node is processed first, followed by its left subtree, and then its right subtree.

3. **Why Preorder?**:
	- The choice of preorder traversal is related to the problem requirements:
		- We need to find the sum of values within the specified range.
		- By visiting the root first, we can check whether the root's value falls within the range and accumulate it if it does.
		- Then, we continue recursively with the left and right subtrees.
	- Using preorder ensures that we process nodes in the correct order to accumulate the sum efficiently.

4. **Base Case and Recursion**:
	- The base case for recursion is when `root` is `nullptr`.
	- If `root` is not `nullptr`, we check whether its value is within the range `[low, high]`.
	- If so, we add its value to `m_sum`.
	- Then, we recursively call `rangeSumBST` on the left and right subtrees.

In summary, this code snippet calculates the sum of values within the specified range in a BST using a preorder traversal approach.

It accumulates the sum by FIRST checking each node's value against the range and recursing through the tree.
   */
namespace RangeSumOfBST
{
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
