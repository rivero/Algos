#pragma once
/*

// Given the root of a binary search tree and the lowest and highest boundaries as low and high, 
trim the tree so that all its elements lies in [low, high]. 
Trimming the tree should not change the relative structure of the elements that will remain in 
the tree (i.e., any node's descendant should remain a descendant). 
It can be proven that there is a unique answer.

// Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.


//Input: root = [1,0,2], low = 1, high = 2
//Output: [1,null,2]


//Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
//Output: [3,2,null,1]


  //    3              3
  // 0     4         2
  //   2           1
  // 1

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 104
// The value of each node in the tree is unique.
// root is guaranteed to be a valid binary search tree.
// 0 <= low <= high <= 104


A recursive function will test the values in the nodes. 
We keep a last valid node as part of the class (member). 
When we find a node that does not fall within the limits, 
we disconnect it. 
Meaning we test if there are other children that are valid. 
We connect the next valid child to the last valid node.

[binary search tree]<

      p
c1        c2 [X]
     c2_1[V]   c2_2[V] ?


      p
c1        c2_1 [X]
              c2_2[V] ? (if c2_1 is smaller than c2_2)

Following the BST rule then our rule above should satisfy the BST rule.

lo:1 hi:6.5

      4
   2     7[x]
       5    10

      4
    2   5

 example:
 3 is valid -> sotre it as last valid node
 4 is not valid -> test the children to find a next valid node. If found, connect the stored last valid node to the found valid child.

*/


/**
 * Definition for a binary tree node.
 */

 // low = 1, high = 3
    //   3              3       
   // 0     4         2
   //   2           1
   // 1

namespace RecursiveRabbitInterview
{
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	};

	class Solution
	{
		TreeNode* m_lastValid{ nullptr };
		int m_low{}, m_high{};
		void process(TreeNode* node)
		{
			if (!node)
				return;
			// val = 0
			if (node->val < m_low || node->val > m_high)
			{
				if (m_lastValid) // 3
				{
					int valLeft{}, valRight{};
					if (node->left)
					{
						valLeft = node->left->val;
					}
					if (node->right)
					{
						valRight = node->right->val;

					}

					if (valLeft < valRight)
					{
						m_lastValid->left = node->left; /// null
						m_lastValid->right = node->right; // null
					}
					else
					{
						m_lastValid->right = node->left;
						m_lastValid->left = node->right;
					}
				}
			}
			else
			{
				m_lastValid = node; // 3
			}
			process(node->left);
			process(node->right);
		}



	public:
		void preorder(TreeNode* node)
		{
			if (!node)
			{
				return;
			}
			cout << node->val << " ";
			preorder(node->left);
			preorder(node->right);
		}

		TreeNode* trimBST(TreeNode* root, int low, int high)
		{
			if (!root)
				return nullptr;
			m_low = low, m_high = high;
			process(root);
			return root;
		}
	};
	void process()
	{
		Solution sol;
		// low = 1, high = 3
   //   3              3       
  // 0     4         2
  //   2           1
  // 1

		auto root = new TreeNode(3);
		root->left = new TreeNode(0);
		root->right = new TreeNode(4);

		root->left->right = new TreeNode(2);
		root->left->right->left = new TreeNode(1);

		int low{ 1 }, high{ 3 };
		sol.preorder(root);
		cout << "\n";
		auto res = sol.trimBST(root, low, high);
		sol.preorder(res);
		cout << "\n";

	}
}