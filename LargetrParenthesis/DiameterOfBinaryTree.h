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
 *
  This algorithm does the following
  - Recursively reaches the bottom
  - as it goes back in the tree, it increments by one the counter which is the height.
  - It adds the values of the left and right leaves
  - the maximum distance is given by the max of the previous and new accumulated

  */

namespace DiameterOfBinaryTree
{
	struct Solution : public timeit
	{
		struct TreeNode {
			int val{};
			TreeNode* left{ nullptr };
			TreeNode* right{ nullptr };
			TreeNode() = default;
			TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
			TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		};
		int diameterOfBinaryTree(TreeNode* root)
		{
			int diameter = 0;
			helper("root", root, diameter);
			return diameter;
		}
	private:
		int helper(const char* const txt, TreeNode* node, int& diameter)
		{
			// terminate
			if (!node)
				return 0;

			// enumerate
			int left = helper("left", node->left, diameter);
			int right = helper("right", node->right, diameter);

			// update the diameter
			diameter = max(diameter, left + right);

			//cout << txt << " (" << node->val << ")";
			//cout << "\tdiameter: " << diameter;
			//cout << " left: " << left;
			//cout << " right: " << right;
			//cout << "\n";

			// return the distance between the farest leaf and the current `node`
			return 1 + max(left, right);
		}
	};

	void process()
	{
		{
			Solution b;
			auto root = new Solution::TreeNode(1);
			root->left = new Solution::TreeNode(2);
			root->right = new Solution::TreeNode(3);
			root->left->left = new Solution::TreeNode(4);
			root->left->right = new Solution::TreeNode(5);
			int val = b.diameterOfBinaryTree(root);
			assert(val == 3);
			cout << "result: " << val << "\n";

		}
		{
			Solution b;
			auto root = new Solution::TreeNode(1);
			root->left = new Solution::TreeNode(2);
			int val = b.diameterOfBinaryTree(root);
			assert(val == 1);
			cout << "result: " << val << "\n";

		}

	}
}
