#pragma once
/*
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii
* 
1650. Lowest Common Ancestor of a Binary Tree III

Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
	public int val;
	public Node left;
	public Node right;
	public Node parent;
}
According to the definition of LCA on Wikipedia:
"The lowest common ancestor of two nodes p and q in a tree T
is the lowest node that has both p and q as descendants
(where we allow a node to be a descendant of itself)."

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
Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself
according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q

p and q exist in the tree.

Solution

The algorithm simulates moving up the tree from both nodes until they meet at the LCA.
If one node reaches the root before the other, it resets itself to the other pointer.
The iteration continues but one of the pointers is ahead in the iteration.
slowly they both will catch up to their ancestor.

Example 1:

			3
		  /	  \
		 5     1
		/ \   / \
	   6   2 0   8
		  / \
		 7   4

		 p = 4, q = 8 Output = 3

		 Values	Iterations
											Magic here too
												*
		 P = p		4	2	5	3		null	8	(<- we catch up in the same level here)	1 3
		 Q = q		8	1	3	null	4		2	(<- we catch up in the same level here)	5 3
		                                ^													  ^ found LCA
									  Magic here
								Reset to other pointer
		When magic happens, then one of the pointers is ahead in the iteration than the other. 
		Slowly but surely they will catch up with each other and when they are the same the LCA was found

2. **Explanation**:
   - The algorithm starts with `P` and `Q` pointing to the input nodes `p` and `q`.
   - In each iteration, it checks whether `P` and `Q` are equal. If they are, it means they have met at the LCA.
   - Otherwise, it updates `P` and `Q` as follows:
	 - If `P` is `nullptr`, it sets `P` to `q`.
	 - If `Q` is `nullptr`, it sets `Q` to `p`.
   - The loop continues until `P` and `Q` meet (i.e., `P == Q`).

3. **Complexities**:
   - **Time Complexity**: The while loop runs until `P` and `Q` meet, which takes at most `O(h)` iterations, where `h` is the height 
   of the tree. 
   In a balanced binary tree, `h` is approximately `log(n)` (where `n` is the number of nodes). 
   Thus, the time complexity is `O(log(n))`.
   
   - **Space Complexity**: The algorithm uses only a constant amount of extra space (for `P` and `Q`). 
   Hence, the space complexity is `O(1)`.

*/
#define PRINTV
namespace LowestCommonAncestorBinaryTreeIII
{
	class Node {
	public:
		int val{};
		Node(int v, Node* par = nullptr) : val(v), parent(par) 
		{
			if (!parent)
			{
				parent = this;
			}
		}
		Node* left{ nullptr };
		Node* right{ nullptr };
		Node* parent{ nullptr };
	};
	//It is just a variation of Intersection of LinkedList!
	class Solution {
	public:
		Node* lowestCommonAncestor(Node* p, Node* q) 
		{
			auto P = p;
			auto Q = q;
#ifdef PRINTV
			cout << "\nBegin a:\t" << P->val << "\tb:\t" << Q->val << "\n";
#endif // PRINTV
			while (P != Q)
			{
				P = P == nullptr ? q : P->parent;
				Q = Q == nullptr ? p : Q->parent;
#ifdef PRINTV
			cout << "\nEnd   a:\t" << P->val << "\tb:\t" << Q->val << "\n";
#endif // PRINTV
			}
			return P;
		}
	};	
	void process()
	{
		cout << "LowestCommonAncestorBinaryTreeIII\n";
		Solution sol;
		auto root = new Node(3);
		root->left = new Node(5, root);
		root->right = new Node(1, root);
		root->left->left = new Node(6, root->left);
		root->left->right = new Node(2, root->left);
		root->left->right->left = new Node(7, root->left->right);
		root->left->right->right = new Node(4, root->left->right);
		root->right->left = new Node(0, root->right);
		root->right->right = new Node(8, root->right);

		auto res = sol.lowestCommonAncestor(root->left, root->right);

		cout << res->val << "\n";

		res = sol.lowestCommonAncestor(root->left, root->left->right->right);
		cout << res->val << "\n";

	}
}
