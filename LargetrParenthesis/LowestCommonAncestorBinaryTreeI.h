#pragma once
/**
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q
as the lowest node in T that has both p and q as descendants
(where we allow a node to be a descendant of itself).”

Example 1:

			3
		  /	  \
		 5     1
		/ \   / \
	   6   2 0   8
		  / \
		 7   4

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

			3
		  /	  \
		 5     1
		/ \   / \
	   6   2 0   8
		  / \
		 7   4

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


Constraints:

	The number of nodes in the tree is in the range [2, 105].
	-10^9 <= TreeNode.val <= 10^9
	All TreeNode.val are unique.
	p != q
	p and q will exist in the tree.

Solution
NOTE that this API requires root.

The algorithm explores the tree recursively, checking if p and q are present in the left and right subtrees.

If both nodes are found in different subtrees, the current root is the LCA.
When we find the first p or q, we return the root to that node (which is also the ancestor of the other node).

Time complexity: O(n)
Space complexity: O(1) if not counting recursive stack frames else O(n)

*/
namespace LowestCommonAncestorBinaryTreeI
{
	struct TreeNode 
	{
		int val{};
		TreeNode* left{ nullptr };
		TreeNode* right{ nullptr };
	    TreeNode(int x) : val(x) {}
	};
	class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
		{
			if (!root)
				return root;
			
			if (root == p || root == q)
				return root;
			
			// value not found yet. Explore leafs
			auto l = lowestCommonAncestor(root->left, p, q); // left leaf
			auto r = lowestCommonAncestor(root->right, p, q); // right leaf
			
			if (l && r) // if both leafs are valid -> root is the LCA
				return root;
			
			return l ? l : r;
		}
	};

	void process()
	{
		cout << "LowestCommonAncestorBinaryTreeI\n";
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