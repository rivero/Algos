#pragma once
/**
 *
 * https://leetcode.com/problems/diameter-of-binary-tree
 543. Diameter of Binary Tree

 Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



Example 1:
			  1
		2			3
	4		5
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

Solution
Compute the number of edges of left and right leafs. Add them up and return the max + 1
Recursively compute the height (number of edges) of the left subtree (left).
Recursively compute the height of the right subtree (right).
Update the diameter by considering the sum of left and right heights.
Return the distance between the farthest leaf and the current node (1 + max(left, right)).

Time Complexity:
The algorithm visits each node once, so the time complexity is O(N), where N is the number of nodes in the tree.

Space Complexity:
The space complexity is determined by the recursive call stack.
In the worst case (a skewed tree), the maximum depth of the call stack is O(N).
Thus, the space complexity is O(N).

  */

namespace DiameterOfBinaryTree
{
	struct TreeNode
	{
		int val{};
		TreeNode* left{ nullptr };
		TreeNode* right{ nullptr };
		TreeNode() = default;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};

	struct Solution : public timeit
	{
		int diameterOfBinaryTree(TreeNode* root)
		{
			int diameter = 0;
			helper(root, diameter);
			return diameter;
		}
	private:
		int helper(TreeNode* node, int& diameter)
		{
			if (!node)
				return 0;

			auto left = helper(node->left, diameter);
			auto right = helper(node->right, diameter);

			diameter = max(diameter, left + right);

			return 1 + max(left, right);
		}
	};

	void process()
	{
		{
			Solution b;
			auto root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(3);
			root->left->left = new TreeNode(4);
			root->left->right = new TreeNode(5);
			int val = b.diameterOfBinaryTree(root);
			assert(val == 3);
			cout << "result: " << val << "\n";

		}
		{
			Solution b;
			auto root = new TreeNode(1);
			root->left = new TreeNode(2);
			int val = b.diameterOfBinaryTree(root);
			assert(val == 1);
			cout << "result: " << val << "\n";

		}

	}
}
