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

			queue<TreeNode*>q;
			vector<vector<int>>ans;

			q.push(root);

			while (!q.empty()) 
			{
				vector<int>level;
				int n = q.size();
				
				for (int i = 0; i < n; i++) 
				{
					level.push_back(q.front()->val);
					if (q.front()->left) q.push(q.front()->left);
					if (q.front()->right) q.push(q.front()->right);
					q.pop();
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