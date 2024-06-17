#pragma once
/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

863. All Nodes Distance K in Binary Tree
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the 
values of all nodes that have a distance k from the target node.

You can return the answer in any order.



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []


Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

Solution:

Transform the tree in a graph

create a list of nodes that can be visited from each node.
from there explore the number k of nodes that we can reach using that list.

time complexity : 
	building a graph. Go over entirely of our tree: O(n)
	parse queue to process the whole graph: O(n)
	Total: O(n) + O(n) -> O(2n) -> O(n)
space complexity: O(n) + O(n) -> O(2n) -> O9n)


*/
namespace AllNodesInDistanceKInBinaryTree
{

	struct TreeNode 
	{
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
#define PRINTV

	void convertBinaryTreeToUndirectedGraph(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
		if (!root)
		{
			return;
		}

		if (parent)
		{
			graph[root].push_back(parent);
			graph[parent].push_back(root);
		}

		convertBinaryTreeToUndirectedGraph(root->left, root, graph);
		convertBinaryTreeToUndirectedGraph(root->right, root, graph);
	}
	class SolutionCOPIED
	{
	public:

		vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
		{			
			if (k == 0)
				return {target->val};

			if (!root || !target)
				return {};
			
			unordered_map<TreeNode*, vector<TreeNode*>> graph;
			convertBinaryTreeToUndirectedGraph(root, nullptr, graph);
#ifdef PRINTV
			for (auto& [key, val ]: graph)
			{
				cout << key->val << ":\t";
				for (auto& el: val)
				{
					cout << el->val << " ";
				}
				cout << "\n";
			}
#endif
			queue<TreeNode*> q;
			unordered_set<TreeNode*> visited;
			map<TreeNode*, int> distance;

			q.push(target);
			visited.insert(target);
			distance[target] = 0;

			vector<int> result;
			while (!q.empty())
			{
				auto node = q.front();
				q.pop();
				if (distance[node] == k)
				{
					result.push_back(node->val);
				}
				for (auto edge : graph[node])
				{
					if (!visited.contains(edge))
					{
						visited.insert(edge);
						distance[edge] = distance[node] + 1;
						q.push(edge);
					}
				}
			}

			return result;
		}
	};


	class Solution 
	{
	public:
		vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
		{
			if (k == 0)
			{
				return { target->val };
			}

			unordered_map<TreeNode*, vector<TreeNode*> > graph;
			queue<TreeNode*> q;

			q.push(root);

			while (q.size() > 0)
			{
				auto node = q.front();
				q.pop();

				if (node->left)
				{
					graph[node].push_back(node->left);
					graph[node->left].push_back(node);
					q.push(node->left);
				}
				if (node->right)
				{
					graph[node].push_back(node->right);
					graph[node->right].push_back(node);
					q.push(node->right);
				}
			}
			vector<int> res;
			set<TreeNode*> visited{ target };
			struct elem
			{
				TreeNode* node;
				int distance;
			};
			queue<elem> q2;
			q2.push({ target, 0 });

			while (q2.size() > 0)
			{
				elem el = q2.front();
				q2.pop();

				if (el.distance == k)
				{
					res.push_back(el.node->val);
				}
				else
				{
					for (auto& edge: graph[el.node])
					{
						if (!visited.contains(edge))
						{
							visited.insert(edge);
							q2.push({ edge, el.distance + 1 });
						}
					}
				}
			}
			return res;
		}
	};

	void process()
	{
		auto root = new TreeNode(3);

		root->left = new TreeNode(5);
		root->left->left = new TreeNode(6);
		root->left->right = new TreeNode(2);
		root->left->right->left = new TreeNode(7);
		root->left->right->right = new TreeNode(4);

		root->right = new TreeNode(1);
		root->right->left = new TreeNode(0);
		root->right->right = new TreeNode(8);

		SolutionCOPIED sol;
		auto res = sol.distanceK(root, root->left, 2);
		printv(res);

	}
}