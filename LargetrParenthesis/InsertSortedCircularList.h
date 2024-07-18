#pragma once
namespace InsertSortedCircularList
{
	/*
	* 
	* https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/description/
	
	708. Insert into a Sorted Circular Linked List
	
	Given a Circular Linked List node, which is sorted in non-descending order, 
	write a function to insert a value insertVal into the list such that it 
	remains a sorted circular list. 
	The given node can be a reference to any single node in the list and may not 
	necessarily be the smallest value in the circular list.

	If there are multiple suitable places for insertion, 
	you may choose any place to insert the new value. 

	After the insertion, the circular list should remain sorted.

	If the list is empty (i.e., the given node is null), 
	you should create a new single circular list and return the reference to that single node. 
	
	Otherwise, you should return the originally given node.


	Example 1:

		1 -->|
		^    |
		|    |
		     |
		4<---3 head

	Input: head = [3,4,1], insertVal = 2
	Output: [3,4,1,2]
	Explanation: In the figure above, there is a sorted circular list of three elements. 
	You are given a reference to the node with value 3, and we need to insert 2 into the list. 
	The new node should be inserted between node 1 and node 3. 
	After the insertion, the list should look like this, and we should still return node 3.

		1 -->2
		^    |
		|    |
			 |
		4<---3 head


	Example 2:

	Input: head = [], insertVal = 1
	Output: [1]
	Explanation: The list is empty (given head is null). 
	We create a new single circular list and return the reference to that single node.

	Example 3:

	Input: head = [1], insertVal = 0
	Output: [1,0]


	Constraints:

	The number of nodes in the list is in the range [0, 5 * 10^4].
	-10^6 <= Node.val, insertVal <= 10^6

1. **Base Case (Empty List):**
   - If the input `head` is `nullptr` (i.e., the list is empty), create a new node with the value `insertVal`.
   - Set its `next` pointer to itself (since it's the only node in the list).
   - Return this new node as the new head of the list.

2. **Iterating Through the List:**
   - Initialize a pointer `cur` to the `head`.
   - While `cur->next` is not equal to the original `head` (i.e., we haven't completed a full loop through the circular list):
	 - Get the values of the current node (`curVal`) and the next node (`nextVal`).
	 - Check if the current node's value is greater than the next node's value:
	   - If so, we've reached the end of the sorted portion of the list.
	   - Check if the `insertVal` should be inserted between the current and next nodes:
		 - If `(curVal <= insertVal && insertVal <= nextVal)`, we found the proper position to insert the value.
		 - Otherwise, continue iterating.
	 - If the current node's value is not greater than the next node's value:
	   - Check if the `insertVal` should be inserted between the current and next nodes:
		 - If `(curVal > nextVal && (curVal <= insertVal || insertVal <= nextVal))`, we found the proper position to insert the value.
		 - Otherwise, continue iterating.

3. **Insertion:**
   - Create a new node with the value `insertVal` and set its `next` pointer to `cur->next`.
   - Update `cur->next` to point to the new node.
   - Return the original `head`.

This algorithm maintains the sorted order of the circular linked list while inserting the new value. 
The time complexity is O(N), where N is the number of nodes in the list, since we iterate through the entire list once. 
The space complexity is O(1) because we don't use any additional data structures. 😊👍
	*/

	struct Node 
	{
		int val{};
		Node* next{ nullptr };

		Node() = default;

		Node(int _val) 
		{
			val = _val;
			next = NULL;
		}

		Node(int _val, Node* _next) 
		{
			val = _val;
			next = _next;
		}
	};

	/*
	Concise C++ one-pass traversal with explanation and comments

	zzg_zzm
	2377
	821
	May 15, 2020
	C++
	Since the circular list is sorted, image the values are v[1] <= v[2] <= ... <= v[n]. 
	There are two cases to insert a new value insertVal into the curcular list:

	insertVal is inside some sub-interval [v[i], v[i+1]], so position after v[i] is the insertion point.
	insertVal is outside the range (v[1], v[N]), so position after v[N] is the insertion point.

	We will traverse through the circular list and compare the value of 
	current node cur->val and next node cur->next->val to check if we 
	have encountered either case and then insert a new node at position cur->next.

	*/
	class Solution 
	{
	public:
		Node* insert(Node* head, int insertVal) 
		{
			if (!head) 
			{
				// create a single node circular list
				auto inserted_node = new Node(insertVal);
				inserted_node->next = inserted_node;
				return inserted_node;
			}

			auto cur = head;

			// loop list to find insertion position: cur->next
			for (; cur->next != head; cur = cur->next) 
			{
				auto curVal = cur->val;
				auto nextVal = cur->next->val;

				// curVal is max (nextVal is min), and insertVal is outside (min, max)
				// This condition handles the case where curVal is the maximum value in 
				//		the list, and insertVal falls outside the range [curVal, nextVal]
				if (curVal > nextVal && (curVal <= insertVal || insertVal <= nextVal))
					break;

				// insertVal is inside [curVal, nextVal]
				//  This condition handles the case where insertVal should be inserted between cur and cur->next.
				if (curVal <= insertVal && insertVal <= nextVal) 
					break;
			}

			// insert a new node
			auto inserted_node = new Node(insertVal, cur->next);
			cur->next = inserted_node;

			return head;
		}
	};

	void printcl(Node* head)
	{
		auto start = head;
		do
		{
			cout << start->val << " ";
			start = start->next;
		} while (start && start != head);
		cout << "\n";
	}

	void process()
	{
		auto head = new Node(3);
		head->next = new Node(4);
		head->next->next = new Node(1);
		head->next->next->next = head;
		Solution sol;
		head = sol.insert(head, 2);
		printcl(head);

		head = nullptr;
		head = sol.insert(head, 1);
		printcl(head);

		head = new Node(1);
		head->next = head;
		head = sol.insert(head, 0);
		printcl(head);

		head = new Node(3);
		head->next = new Node(3);
		head->next->next = new Node(3);
		head->next->next->next = head;
		head = sol.insert(head, 0);
		printcl(head);

		head = new Node(1);
		head->next = new Node(3);
		head->next->next = new Node(5);
		head->next->next->next = head;
		head = sol.insert(head, 0);
		printcl(head);
	}
}