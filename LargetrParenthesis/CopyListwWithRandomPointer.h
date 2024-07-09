#pragma once
namespace CopyListwWithRandomPointer
{
	/*
	https://leetcode.com/problems/copy-list-with-random-pointer/description/
	138. Copy List with Random Pointer

	A linked list of length n is given such that each node contains an additional random pointer, 
	which could point to any node in the list, or null.

	** Construct a deep copy of the list. 
	
		The deep copy should consist of exactly n brand new nodes, where each new node has its value 
		set to the value of its corresponding original node. 
	
		Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers 
		in the original list and copied list represent the same list state. 
	
		None of the pointers in the new list should point to nodes in the original list.

	For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the 
	corresponding two nodes x and y in the copied list, x.random --> y.

	Return the head of the copied linked list.

	The linked list is represented in the input/output as a list of n nodes. Each node is represented as a 
	pair of [val, random_index] where:

		- val: an integer representing Node.val
		- random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if 
		it does not point to any node.
	
	* Your code will only be given the head of the original linked list.

	Example 1:
	Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
	Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

	Example 2:
	Input: head = [[1,1],[2,1]]
	Output: [[1,1],[2,1]]

	Example 3:
	Input: head = [[3,null],[3,0],[3,null]]
	Output: [[3,null],[3,0],[3,null]]

	Constraints:

	0 <= n <= 1000
	-10^4 <= Node.val <= 10^4
	Node.random is null or is pointing to some node in the linked list.

	Solution1

	Two pases

	First pass will store the nodes and next in a a hash

	Second pass will make new nodes and establish the links

	Solution 2

1. **Function Description:**
   - The `copyRandomList` function takes a pointer to the head of a special linked list (where each node has an additional `random` pointer) and returns a deep copy of the list.
   - Each node in the copied list has the same value as the original node, and the `random` pointer points to the corresponding node in the copied list.

2. **Algorithm Overview:**
   - We use a recursive approach to create the deep copy.
   - We maintain a `clone` map (or hash table) to store the mapping between original nodes and their corresponding copied nodes.
   - If the current node is already in the `clone` map, we return the corresponding copied node.
   - Otherwise, we create a new node with the same value as the original node and add it to the `clone` map.
   - Recursively copy the `random` and `next` pointers for the current node.

3. **Complexity Analysis:**
   - Let `N` be the number of nodes in the original linked list.
   - **Time Complexity**: The recursive function visits each node once, so the time complexity is O(N).
   - **Space Complexity**:
	 - The `clone` map stores at most `N` nodes, so the space complexity is O(N) due to the map.
	 - Additionally, the recursive call stack contributes to the space complexity, but it is also O(N) 
	 in the worst case (for a skewed linked list).
	
	*/

	// Definition for a Node.
	struct Node
	{
		int val{};
		Node* next{ nullptr };
		Node* random{ nullptr };
		Node(int _val) : val(_val) {}
	};

	void printm(map<Node*, Node*> oldToCopy)
	{
		for (auto& [key, value] : oldToCopy)
		{
			cout << key->val << ":" << value->val << " ";
		}
		cout << "\n";
	}

#define PRINTV
    class Solution 
	{
    public:
        Node* copyRandomList(Node* head) 
		{
			map<Node*, Node*> oldToCopy{ {nullptr,nullptr} };
			auto cur = head;
			while (cur)
			{
				auto copy = new Node(cur->val);
				oldToCopy[cur] = copy;
				cur = cur->next;
			}
			cur = head;
			while (cur)
			{
				auto copy = oldToCopy[cur];
				copy->next = oldToCopy[cur->next];
				copy->random = oldToCopy[cur->random];
				cur = cur->next;
			}
			return oldToCopy[head];
		}
	};

	struct Solution2 
	{
		unordered_map<Node*, Node*> clone;

		Node* copyRandomList(Node* node) 
		{
			if (!node) 
				return nullptr;

			if (clone.find(node) != clone.end()) 
				return clone[node];

			clone[node] = new Node(node->val);
			clone[node]->random = copyRandomList(node->random);
			clone[node]->next = copyRandomList(node->next);

			return clone[node];
		}
	};

	void process()
	{

	}
}