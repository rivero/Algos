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

1. **Algorithm Explanation**:
   - The `lowestCommonAncestor` function aims to find the lowest common ancestor (LCA) of two nodes, `p` and `q`, in a binary tree.
   - The algorithm follows these steps:
	 1. Define a helper function called `dfs` (depth-first search) that takes three parameters: 
	 the current `root`, and the target nodes `p` and `q`.
	 2. In the `dfs` function:
		- If the current `root` is null, return null.
		- Recursively call `dfs` on the left subtree (`root->left`) and the right subtree (`root->right`).
		- Check if the current `root` is equal to either `p` or `q`. If so:
		  - Update the corresponding flag (`p_found` or `q_found`) to indicate that the node has been found.
		  - Return the current `root`.
		- If both left and right subtrees (`l` and `r`) are not null, it means that `p` and `q` are found in different subtrees. In this case, the current `root` is the LCA.
		- Otherwise, return the non-null subtree (either `l` or `r`).
	 3. In the `lowestCommonAncestor` function:
		- Call `dfs` with the root of the tree and the target nodes `p` and `q`.
		- If both `p` and `q` are found (i.e., `p_found` and `q_found` are true), return the result of `dfs`.
		- Otherwise, return null.

2. **Complexities**:
   - Time Complexity: O(N), where N is the number of nodes in the binary tree.
	 - The algorithm traverses each node once during the depth-first search.
   - Space Complexity: O(H), where H is the height of the binary tree.
	 - The space is used for the recursive call stack during the depth-first search.

3. **Example**:
   - Given a binary tree:
	 ```
		 3
		/ \
	   5   1
	  / \ / \
	 6  2 0  8
	   / \
	  7   4
	 ```
	 - Nodes 5 and 1 have LCA = 3.
	 - Nodes 5 and 4 have LCA = 5.

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