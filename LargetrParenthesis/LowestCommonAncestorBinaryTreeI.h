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

### Algorithm Explanation:

### Key Steps:
1. If the current node `root` is null, return `root` (base case).
2. If `root` is equal to either `p` or `q`, return `root` (one of the nodes is the ancestor of the other).
3. Recursively search the left subtree (`root->left`) for `p` and `q` (stored in `l`).
4. Recursively search the right subtree (`root->right`) for `p` and `q` (stored in `r`).
5. If both `l` and `r` are valid (i.e., not null), the current `root` is the LCA.
6. Otherwise, return the non-null value between `l` and `r`.

once we find other node, we return it, Because the other node is either under the found node or under the root of the found node.

### Time Complexity:
- The worst-case time complexity of this algorithm is O(n), where n is the number of nodes in the binary tree.
- In the worst case, we explore all nodes to find the LCA.

### Space Complexity:
- The space complexity is O(h), where h is the height of the binary tree.
- This accounts for the recursive call stack during traversal.

My explanation

We use a DFS approach were we search for the values in both trees.
If both left and right subtrees return non-null values, it means p and q are in different subtrees, 
	so the current node is the LCA.

If only one subtree returns a non-null value, return that subtree's root as the LCA. 
	This is because if the other three doesnt contain the value, then the not found value will be a descendant of the found node.
.	Because of the constraint "p and q will exist in the three"

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