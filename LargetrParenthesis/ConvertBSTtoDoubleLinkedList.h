#pragma once
namespace BTreeToDLink
{
    /*
    * 
	* 
    https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/
    426. Convert Binary Search Tree to Sorted Doubly Linked List
	
    Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

    You can think of the left and right pointers as synonymous to the predecessor 
    and successor pointers in a doubly-linked list. 
    
    For a circular doubly linked list, the predecessor of the first element is the last element, 
    and the successor of the last element is the first element.

    We want to do the transformation in place. 
    
    After the transformation, 
    the left pointer of the tree node should point to its predecessor, 
    and the right pointer should point to its successor. 
    
    You should return the pointer to the smallest element of the linked list.

    Example 1:

                4
               / \
              2   5
             / \
            1   3

    Input: root = [4,2,5,1,3]
    Output: [1,2,3,4,5]
    Explanation: The figure below shows the transformed BST. 
    The solid line indicates the successor relationship, 
    while the dashed line means the predecessor relationship.

        ->1<->2<->3<->4<->5<-
        |-------------------|

    Example 2:

    Input: root = [2,1,3]
    Output: [1,2,3]


    Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
    All the values of the tree are unique.

    Solution

	### Algorithm Explanation:
	The given algorithm converts a binary tree into a doubly linked list (DLL) 
	while maintaining the same order as the in-order traversal of the tree. Here are the key steps:

	1. **In-Order Traversal with Set:**
	   - The algorithm starts by performing an in-order traversal of the binary tree.
	   - During traversal, it inserts each node into a set (m_set) as a pair (value, Node*).
	   - The set ensures that the nodes are sorted based on their values.

	2. **Building the Doubly Linked List:**
	   - After completing the traversal, the algorithm iterates through the set.
	   - It connects adjacent nodes in the set to create the doubly linked list.
	   - The left pointer of a node points to the previous node, and the right pointer points to the next node.

	3. **Adjusting the Head and Tail:**
	   - Finally, the algorithm adjusts the head and tail of the doubly linked list.
	   - The head is set to the first node in the set (which corresponds to the smallest value).
	   - The tail is set to the last node in the set (which corresponds to the largest value).

	### Time Complexity:
	- The time complexity of the algorithm depends on the in-order traversal, which visits each node once.
	- Therefore, the time complexity is **O(N)**, where **N** is the number of nodes in the binary tree.

	### Space Complexity:
	- The space complexity is determined by the set (m_set) used to store the nodes.
	- Since the set contains all nodes, the space complexity is also **O(N)**.

	In summary, this algorithm efficiently converts a binary tree to a doubly linked list 
	while maintaining the order of in-order traversal. 

*/
	class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
	};


	class Solution
	{
		set< pair<int, Node*> > valueNode;
		void process(Node* node)
		{
			// base case
			if (!node) return;

			process(node->left);
			valueNode.insert({ node->val, node });
			process(node->right);
		}
	public:
		Node* treeToDoublyList(Node* root)
		{
			if (!root) return root;

			process(root);

			for (auto nextIt = next(valueNode.begin()); nextIt != valueNode.end(); ++nextIt)
			{
				auto& [prevVal, prevNode] = *prev(nextIt);
				auto& [nextVal, nextNode] = *nextIt;
				prevNode->right = nextNode;
				nextNode->left = prevNode;
			}
			auto [val, start] = *valueNode.begin();
			auto [val2, finish] = *(prev(valueNode.end()));
			start->left = finish;
			finish->right = start;
			root = start;
			return root;
		}
	};
	void process()
	{
        auto root = new Node(4);
        root->left = new Node(2);
        root->right = new Node(5);
		root->left->left = new Node(1);
		root->left->right = new Node(3);
        Solution sol;
        root = sol.treeToDoublyList(root);
        root = sol.treeToDoublyList(nullptr);
	}
}