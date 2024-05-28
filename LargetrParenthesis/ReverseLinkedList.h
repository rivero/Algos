#pragma once

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []

 */
struct ReverseLinkedList : public timeit
{
	struct ListNode
	{
		int val{};
		ListNode* next{ nullptr };
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* reverseList(ListNode* head)
	{
		ListNode* prev{ nullptr };
		ListNode* curr = head;
		ListNode* forward{ nullptr };
		reverse(curr, forward, prev);
		return prev;
	}

	void reverse(ListNode*& curr, ListNode*& forward, ListNode*& prev)
	{
		if (!curr)
			return;

		forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;
		reverse(curr, forward, prev);
	}

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
};
