#pragma once
/*
314. Binary Tree Vertical Order Traversal

Given the root of a binary tree, return the vertical order traversal of its nodes' values.
(i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Example 1:

			3
	9			20
			15		7

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:
		3
	9			8
4		01			7

Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]

Example 3:
		3
	9			8
4		01			7

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

struct BinaryTreeVerticalOrderTransversal : protected timeit
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

	map<int, vector<int> > m_map;
	int m_level{};
	void order(queue< const TreeNode* >& Q, int base)
	{
		if (Q.empty())
		{
			return;
		}
		auto current = Q.front();
		Q.pop();
		m_map[base].push_back(current->val);

		auto lc = base - 1;
		auto rc = base + 1;

		if (current->left)
		{
			Q.push(current->left);
			order(Q, lc);
		}
		if (current->right)
		{
			Q.push(current->right);
			order(Q, rc);
		}
	}
	vector<vector<int>> verticalOrder2(TreeNode* root)
	{
		if (root == nullptr)
			return {};

		queue< const TreeNode* > Q;
		Q.push(root);
		order(Q, 0);

		vector<vector<int>> res;
		for (const auto& [idx, vec] : m_map)
		{
			res.push_back(vec);
		}
		return res;
	}

	queue<pair<TreeNode*, int>> qu;
	map<int, vector<int>> verticalLevels;

	void order2()
	{
		if (qu.empty()) return;

		for (size_t i = 0; i < qu.size(); i++)
		{
			auto curr = qu.front(); qu.pop();
			TreeNode* currNode = curr.first;
			int level = curr.second;

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
		order2();
	}

	vector<vector<int>> verticalOrder(TreeNode* root)
	{
		vector<vector<int>> ans;
		if (!root) return ans;
		qu.push({ root, 0 });
		order2();

		for (const auto& entry : verticalLevels)
		{
			ans.push_back(entry.second);
		}

		return ans;
	}

	vector<vector<int>> verticalOrder3(TreeNode* root)
	{
		vector<vector<int>> ans;
		if (!root) return ans;
		qu.push({ root, 0 });
		while (!qu.empty())
		{
			int size = qu.size();

			for (int i = 0; i < size; i++)
			{
				auto curr = qu.front(); qu.pop();
				TreeNode* currNode = curr.first;
				int level = curr.second;

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
		}

		for (const auto& entry : verticalLevels)
		{
			ans.push_back(entry.second);
		}

		return ans;
	}
};
