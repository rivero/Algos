#pragma once
/*
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/description/
* 
* Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q. 
If either node p or q does not exist in the tree, return null. 
All values of the nodes in the tree are unique.

According to the definition of LCA on Wikipedia: 
"The lowest common ancestor of two nodes p and q in a binary tree T is the lowest node that has 
both p and q as descendants (where we allow a node to be a descendant of itself)". 

A descendant of a node x is a node y that is on the path from node x to some leaf node.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5. A node can be a descendant of itself according to the definition of LCA.

Example 3:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
Output: null
Explanation: Node 10 does not exist in the tree, so return null.


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q

Solution
Solution
NOTE that this API requires root.

The algorithm explores the tree recursively, checking if p and q are present in the left and right subtrees.

We need to postorder the tree to find both p and q at the same time we test for values already.

If both nodes are found in different subtrees, the current root is the LCA.
When we find the first p or q, we return the root to that node (which is also the ancestor of the other node).

Time complexity: O(n)
Space complexity: O(1) if not counting recursive stack frames else O(n)

*/
namespace LowestCommonAncestorBinaryTreeII
{
	struct TreeNode
	{
		int val{};
		TreeNode* left{ nullptr };
		TreeNode* right{ nullptr };
		TreeNode(int x) : val(x) {}
	};

	class Solution 
	{
		bool p_found{}, q_found{};
		TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q)
		{
			if (!node)
				return node;

			auto l = dfs(node->left, p, q);
			auto r = dfs(node->right, p, q);

			if (node == p || node == q)
			{
				if (node == p)
					p_found = true;
				else
					q_found = true;
				return node;
			}

			if (l && r)
			{
				return node;
			}

			return l? l : r;
		}
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
		{
			auto res = dfs(root, p, q);

			if (p_found && q_found)
				return res;
			else
				return nullptr;
		}
	};
	void process()
	{
		cout << "LowestCommonAncestorBinaryTreeII\n";
		Solution sol;
		auto root = new TreeNode(3);
		root->left = new TreeNode(5);
		root->right = new TreeNode(1);
		root->left->left = new TreeNode(6);
		root->left->right = new TreeNode(2);
		root->left->right->left = new TreeNode(7);
		root->left->right->right = new TreeNode(4);
		root->right->left = new TreeNode(0);
		root->right->right = new TreeNode(8);

		auto res = sol.lowestCommonAncestor(root, root->left, root->right);

		cout << res->val << "\n";


	}
}