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

Look recursively for the first node that contains either p or q. Once it is found, return.
Then choose the other leaf and look recursively for the other value (p or q).

If not found we know that the other value (p or q) must exist under the leaf where we found
the first value.

Return that node's value.

*/
namespace LowestCommonAncestorBinaryTreeWithRoot
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
			if (!root) // if root is null return (also base case for recursion)
				return root;
			
			if (root == p || root == q) // if we found either p or q return: the node must be the lowest common ancestor
				return root;
			
			// value not found yet. Explore leafs
			auto l = lowestCommonAncestor(root->left, p, q); // left leaf
			auto r = lowestCommonAncestor(root->right, p, q); // right leaf
			
			if (l && r) // if both leafs are valid -> root is the LCA
				return root;
			
			if (l) // ... otherwise test left leaf
				return l;
			
			if (r)  // ...then right leaf
				return r;
			
			return nullptr; // tree ends here
		}
	};

	void process()
	{
		cout << "LowestCommonAncestorBinaryTreeWithRoot\n";
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