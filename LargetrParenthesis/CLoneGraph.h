#pragma once
/*
https://leetcode.com/problems/clone-graph

133. Clone Graph
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
	public int val;
	public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val == 1, the second node with val == 2, and so on. 
The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. 
Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. 
You must return the copy of the given node as a reference to the cloned graph.

Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

Example 2:
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Example 3:
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.


Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

Solution

Certainly! Let's dive into the provided algorithm for deep copying a graph and discuss its complexities.

1. **Algorithm Description**:
   - The given `Solution` class provides a method `cloneGraph` that takes a graph represented by a `Node*` (with neighbors) 
   and returns a deep copy of the graph.
   - The algorithm uses depth-first search (DFS) to traverse the original graph and create a copy.

2. **Explanation**:
   - The algorithm proceeds as follows:
	 1. Initialize an unordered map `mp` to store the mapping between original nodes and their corresponding clones.
	 2. Define a helper function `dfs` that takes a `Node*` (representing the current node in the original graph) and returns 
	 its clone.
	 3. In the `dfs` function:
		- Create a new node `clone` with the same value as the original node.
		- Store the mapping between the original node and its clone in the `mp` map.
		- Initialize an empty vector `pals` to store the cloned neighbors.
		- For each neighbor `n` of the original node:
		  - If `n` has already been cloned (i.e., exists in `mp`), add its clone to `pals`.
		  - Otherwise, recursively call `dfs(n)` to clone `n` and add its clone to `pals`.
		- Set the neighbors of `clone` to the cloned neighbors stored in `pals`.
		- Return the `clone`.
	 4. In the `cloneGraph` function:
		- Handle edge cases:
		  - If the input `node` is `nullptr`, return `nullptr`.
		  - If the input node has no neighbors (i.e., isolated node), create a new node with the same value and return it.
		- Otherwise, call `dfs(node)` to clone the entire graph.

3. **Complexities**:
   - **Time Complexity**:
	 - The algorithm traverses each node once (via DFS).
	 - For each node, the time spent on cloning its neighbors is proportional to the number of neighbors.
	 - In total, the time complexity is linear: `O(V + E)`, where `V` is the number of nodes (vertices) and `E` is the number 
	 of edges.
   - **Space Complexity**:
	 - The space complexity is determined by the additional memory used for the map `mp` and the recursive call stack during DFS.
	 - In the worst case, when all nodes are unique and interconnected, the space complexity is also linear: `O(V + E)`.

4. **Example**:
   - Suppose we have the following graph:
	 ```
	 1 -- 2
	 |    |
	 4 -- 3
	 ```
   - The algorithm creates clones as follows:
	 - Clone of node 1 (with value 1) has neighbors 2 and 4.
	 - Clone of node 2 (with value 2) has neighbors 1 and 3.
	 - Clone of node 3 (with value 3) has neighbors 2 and 4.
	 - Clone of node 4 (with value 4) has neighbors 1 and 3.

*/
namespace CloneGraph
{
	struct Node
	{
		int val{};
		vector<Node*> neighbors{};
		Node(int _val) : val(_val) {}
		Node(int _val, vector<Node*> _neighbors) 
		{
			val = _val;
			neighbors = _neighbors;
		}
	};

	class Solution
	{
		unordered_map<Node*, Node*> mp;
		Node* dfs(Node* node)
		{
			auto clone = new Node(node->val);
			mp[node] = clone; // to avoid re-cloning
			vector<Node*> pals;
			for (auto& n : node->neighbors)
			{
				if (mp.count(n) > 0) // neighbor already cloned
					pals.push_back(mp[n]);
				else // neighbor not yet cloned
					pals.push_back(dfs(n));
			}
			clone->neighbors = pals;
			return clone;
		}
	public:
		Node* cloneGraph(Node* node)
		{
			if (!node) return node;

			if (node->neighbors.empty())
				return new Node(node->val);

			return dfs(node);
		}
	};

	void process()
	{

	}
}
