#pragma once

/*
* https://leetcode.com/problems/reverse-linked-list/description/
* 
* 206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []
## Algorithm Explanation and Complexity

### Algorithm Explanation
The provided code reverses a singly linked list iteratively.

* **Three pointers:** `prev`, `curr`, and `next` are used to keep track of nodes during the reversal process.
* **Iterative process:**
	* `next` stores the next node to be processed.
	* The `next` pointer of the current node (`curr`) is reversed to point to the previous node (`prev`).
	* The `prev` and `curr` pointers are updated to move to the next node.
* **Return value:** The function returns the `prev` pointer, which becomes the new head of the reversed list.

### Time Complexity
The time complexity of the `reverseList` function is **O(n)**, where n is the number of nodes in the linked list. Each node is 
visited exactly once, and constant time operations are performed at each node.

### Space Complexity
The space complexity of the `reverseList` function is **O(1)** as it uses a constant amount of extra space for the three pointers 
`prev`, `curr`, and `next`, regardless of the input size.

**In summary:** The provided code efficiently reverses a singly linked list in linear time and constant space.

## Tabular Example of Linked List Reversal

**Understanding the Problem:**
* We have a singly linked list.
* We want to reverse the order of the nodes in the list.

**Algorithm:**
* Use three pointers: `prev`, `curr`, and `next`.
* Iterate through the list, reversing the links between nodes.

**Tabular Representation:**

| Iteration | prev					| curr					| next			   |
|---		|---					|---					|---			   |
| 1			| null					| 1 -> 2 -> 3 -> 4 -> 5 | 2 -> 3 -> 4 -> 5 |
| 2			| 1						| 2 -> 3 -> 4 -> 5		| 3 -> 4 -> 5	   |
| 3			| 2						| 3 -> 4 -> 5			| 4 -> 5		   |
| 4			| 3						| 4 -> 5				| 5				   |
| 5			| 4						| 5						| null			   |
| 6			| 5						| null					| null			   |

**Explanation:**

* Initially, `prev` is null, `curr` points to the head of the list, and `next` points to the second node.
* In each iteration:
	* `next` stores the next node to be processed.
	* The `next` pointer of the current node (`curr`) is reversed to point to the previous node (`prev`).
	* The `prev` and `curr` pointers are updated for the next iteration.

**After the final iteration:**
* The `prev` pointer points to the last node, which becomes the new head of the reversed list.

**Visual Representation:**
```
Original: 1 -> 2 -> 3 -> 4 -> 5
Reversed: 5 -> 4 -> 3 -> 2 -> 1
```

This table demonstrates how the pointers change during each iteration of the `reverse` function, resulting in a reversed linked list.

**Would you like to see a visual representation of this process?**

 */
namespace ReverseLinkedList
{
	struct ListNode
	{
		int val{};
		ListNode* next{ nullptr };
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	class Solution
	{
		void reverse(ListNode*& curr, ListNode*& next, ListNode*& prev)
		{
			if (!curr)
				return;

			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			reverse(curr, next, prev);
		}
	public:
		ListNode* reverseList(ListNode* head)
		{
			ListNode* prev{ nullptr };
			ListNode* curr = head;
			ListNode* forward{ nullptr };
			reverse(curr, forward, prev);
			return prev;
		}


	};

	ListNode* reverseListPrint(ListNode* head)
	{
		ListNode* prev{ nullptr };
		ListNode* curr = head;
		while (curr)
		{
			cout << " curr " << curr->val << " ";

			ListNode* forward = curr->next;
			if (forward)
			{
				cout << " forward " << forward->val << " ";
			}


			curr->next = prev;
			prev = curr;

			cout << " prev " << prev->val << " ";
			if (curr->next)
			{
				cout << "curr->next " << curr->next->val;
			}

			curr = forward;

			if (curr)
			{
				cout << " after curr = forward : curr " << curr->val;
			}
			cout << "\n";
		}
		return prev;
	}
	void printList(ListNode* head)
	{
		if (head)
		{
			cout << head->val << " ";
			printList(head->next);
		}

	}

	void process()
	{
		auto head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = new ListNode(5);
		Solution r;
		printList(head);
		cout << "\n";

		auto newHead = r.reverseList(head);
		printList(newHead);
		cout << "\n";

	}
}