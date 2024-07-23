#pragma once
/*
https://leetcode.com/problems/binary-tree-level-order-traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

*/
namespace BinaryTreeLevelOrderTransversal
{

	struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	class Solution
	{
	public:
		vector<vector<int>> levelOrder(TreeNode* root)
		{
			if (!root)
				return {};

			queue<TreeNode*> q;
			vector<vector<int>> ans;

			q.push(root);

			while (!q.empty())
			{
				int levelSize = q.size(); // Number of nodes at the current level
				vector<int> level;

				for (int i = 0; i < levelSize; i++)
				{
					auto curr = q.front(); q.pop();

					level.push_back(curr->val);

					if (curr->left)
						q.push(curr->left);
					if (curr->right)
						q.push(curr->right);
				}

				ans.push_back(level);
			}

			return ans;
		}
	};
	void process()
	{

	}
}