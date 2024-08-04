#pragma once
namespace ConvertBSTtoDoubleLinkedList
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

	## Algorithm Explanation

	**Problem:** Convert a binary tree to a doubly linked list in-place.

	**Approach:**

	1. **In-order traversal:** Perform a modified in-order traversal of the binary tree.
	2. **Link nodes:** During the traversal, link the current node to the previous node.
	3. **Update head and tail:** Maintain pointers to the head and tail of the doubly linked list.
	4. **Circular link:** Connect the head and tail to form a circular doubly linked list.

	**Code Breakdown:**

	* **`prev` pointer:** Tracks the previously visited node during in-order traversal.
	* **`head` pointer:** Points to the head of the doubly linked list.
	* **`helper` function:**
	  * Recursively traverses the left subtree.
	  * Links the current node to the previous node if `prev` is not null.
	  * Updates the `head` pointer if this is the first node.
	  * Sets the current node as the `prev` for the next iteration.
	  * Recursively traverses the right subtree.
	* **`treeToDoublyList` function:**
	  * Initializes `prev` and `head` pointers.
	  * Calls the `helper` function to perform in-order traversal and linking.
	  * Creates a circular doubly linked list by connecting the head and tail.
	  * Returns the head of the doubly linked list.

	**Time Complexity:** O(N), where N is the number of nodes in the tree. This is because each node is visited exactly once during 
	the in-order traversal.

	**Space Complexity:** O(1), as the algorithm uses only constant extra space for the `prev` and `head` pointers.

	**Key Points:**

	* The in-order traversal ensures that nodes are linked in ascending order.
	* The `prev` pointer efficiently maintains the link to the previous node.
	* The `head` pointer keeps track of the starting node for the doubly linked list.

	Time complexity: O(N), where N is the number of nodes in the tree. 
	Space complexity: O(1) as it doesn't use any extra data structures apart from constant variables.

	## Understanding the Algorithm Through an Example

### Input Tree:

```
	 4
	/ \
   2   5
  / \
 1   3
```

### Step-by-Step Breakdown:

**1. Initial State:**
* `prev` is null
* `head` is null

**2. Recursive calls:**
* `helper(4)`:
  * `helper(2)`:
	* `helper(1)`:
	  * `prev` is null, so `head` becomes 1
	  * `prev` becomes 1
	* `helper(3)`:
	  * `prev` is 1, so link 1 -> 3 and 3 -> 1
	  * `prev` becomes 3
	* `prev` is 3, so link 2 -> 3 and 3 -> 2
  * `prev` becomes 2
  * `helper(5)`:
	* `prev` is 2, so link 2 -> 5 and 5 -> 2
  * `prev` becomes 5
* `prev` is 5, so link 4 -> 5 and 5 -> 4

**3. Circular Link:**
* `head->left = prev`: Link the first node (head) to the last node (prev)
* `prev->right = head`: Link the last node (prev) to the first node (head)

### Final Doubly Linked List:
```
1 <-> 2 <-> 3 <-> 4 <-> 5
```

**Explanation:**
* The `helper` function performs an in-order traversal of the tree.
* During the traversal, it links each node to its previous node using the `prev` pointer.
* The `head` pointer keeps track of the first node in the list.
* After the traversal, the `head` and `prev` pointers are linked to form a circular doubly linked list.

This step-by-step breakdown illustrates how the algorithm constructs the doubly linked list by traversing the binary tree and 
linking nodes accordingly.

**Would you like to explore other examples or modifications to the code?**

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


	class Solutionbefore
	{
		set< pair<int, Node*> > valueNode;
		void buildSet(Node* node)
		{
			// base case
			if (!node) return;

			buildSet(node->left);
			valueNode.insert({ node->val, node });
			buildSet(node->right);
		}
	public:
		Node* treeToDoublyList(Node* root)
		{
			if (!root) return root;

			buildSet(root);

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

	class Solution
	{
	public:
		Node* prev = nullptr;
		Node* head = nullptr;

		void helper(Node* node)
		{
			if (!node) return;

			helper(node->left);
			if (prev)
			{
				prev->right = node;
				node->left = prev;
			}
			else
			{
				head = node;
			}
			prev = node;
			helper(node->right);
		}

		Node* treeToDoublyList(Node* root)
		{
			if (!root) return nullptr;
			helper(root);
			head->left = prev;
			prev->right = head;
			return head;
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