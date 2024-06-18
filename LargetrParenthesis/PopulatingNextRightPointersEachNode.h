#pragma once
namespace PopulatingNextRightPointersEachNode
{
	/*
	https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

	116. Populating Next Right Pointers in Each Node

	You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
	The binary tree has the following definition:

	Populate each next pointer to point to its next right node. If there is no next right node, the next pointer 
	should be set to NULL.

	Initially, all next pointers are set to NULL.



	Example 1:
	
	Input: root = [1,2,3,4,5,6,7]
	Output: [1,#,2,3,#,4,5,6,7,#]
	
	Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer 
	to point to its next right node, just like in Figure B. The serialized output is in level order as connected 
	by the next pointers, with '#' signifying the end of each level.
	
	Example 2:

	Input: root = []
	Output: []


	Constraints:

	The number of nodes in the tree is in the range [0, 2^12 - 1].
	-1000 <= Node.val <= 1000

	Follow-up:

	You may only use constant extra space.
	The recursive approach is fine. You may assume implicit stack space does not count as extra space for

	Solution
	https://leetcode.com/problems/populating-next-right-pointers-in-each-node/solutions/1653846/c-easy-to-solve-beginner-friendly-with-detailed-explanations-and-dry-run/

	Intuition:-

	We are given a prefect binary tree that means every parent has two children and all the leaves are on the same level .
	This question is an superior version of binary level order traversal .
	In level order traversal you will traverse each level of binary tree while outputting the data in that form . 
	So the only difference is that somehow we need to connect the previous levels rightmost node to the next level's 
	leftmost node and that's it .

	Algorithm:-

	Base case: if the root is null than return null
	Now to connect the left subtree of same level with right subtree of that level
	The only new line that differentiate from level order traversing is that we need to connect the rightmost node of a level 
	to the leftmost node of the next level.
	Now just repeat the steps over and over for every level of tree .

	*/

	struct Node 
	{
		int val{};
		Node* left {nullptr};
		Node* right{nullptr};
		Node* next {nullptr};
	};

	//Upvote and Comment 

	class SolutionRecursive 
	{
	public:
		Node* connect(Node* root) 
		{
			//base case
			if (!root) 
				return root;
			
			//connects the left subtree of same level with right subtree of that same level 
			if (root->left) 
				root->left->next = root->right;
			
			//connect the rightmost node of a level to the leftmost node of the next level.
			if (root->right && root->next) 
				root->right->next = root->next->left;
			
			//recursive calls for left and right subtrees.
			connect(root->left);
			connect(root->right);
			return root;
		}
	};

	//Upvote and Comment

	class SolutionIterative 
	{
	public:
		Node* connect(Node* root) 
		{
			//Initialize pointers
			Node* prev = root, * curr{ nullptr };
		
			while (prev) 
			{
				curr = prev;
				while (curr && curr->left) 
				{
					//connects the left subtree of same level with right subtree of that same level 
					curr->left->next = curr->right;
				
					//connect the rightmost node of a level to the leftmost node of the next level.
					if (curr->next) 
						curr->right->next = curr->next->left;
					
					curr = curr->next;
				}
				prev = prev->left;
			}
			return root;
		}
	};


	void process()
	{

	}
}