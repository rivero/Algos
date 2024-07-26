#pragma once
/*
https://leetcode.com/problems/binary-tree-right-side-view/
Intuition
Approach
In solving this problem, we'll use the BFS algorithm.
That means we'll evaluate each depth of the binary tree individually and move on to the next depth.

Here's how the code works:
I've created a queue structure and pushed the root into this queue.
Then, within a loop, I'll push one depth of the tree, starting from the right.
After this process, the first element I see in the queue will be the first non-null element in that depth.
I'll add this element to the result vector, and after checking the child nodes of each element to create the next depth,
I'll push itself into the queue.

To explain the code with an example,
Example: root = [1,2,3,null,5,null,4]

Initialization (root push):
queue = [1]
result = [0]

First iteration:
queue = [3,2]
result = [1]

Second iteration:
queue = [4,5]
result = [1,3]

Third iteration:
queue = []
result = [1,3,4]

End of loop !

Complexity
Time complexity:
O(n)

Space complexity:
O(n)
Solution

1. **Function Description:**
   - The `rightSideView` function takes a binary tree's root node as input and returns a vector of integers representing the right 
   view of the tree.
   - The right view of a binary tree is the set of nodes visible when the tree is visited from the right side.

2. **Algorithm Overview:**
   - We perform a level-order traversal (BFS) using a queue to explore the tree level by level.
   - At each level, we add the value of the rightmost node to the result vector.
   - We enqueue the right child before the left child to ensure that the rightmost node at each level is processed first.

3. **Complexity Analysis:**
   - Let `N` be the number of nodes in the binary tree.
   - **Time Complexity**: The level-order traversal visits each node once, so the time complexity is O(N).
   - **Space Complexity**:
	 - The queue stores at most one level of nodes, so the space complexity is O(N) due to the queue.

4. **Example:**
   - For a binary tree with the following structure:
	 ```
		 1
		/ \
	   2   3
	  / \   \
	 4   5   6
	  \
	   7
	 ```
	 - The right view would be `[1, 3, 6, 7]`.


	 ## Why Pop Within the Iteration?

The primary reason for popping the current node within the iteration is to **process each node at the current level exactly once**.

Here's a breakdown of the logic:

1. **`size = levels.size();`**: This line captures the number of nodes at the current level.
2. **Process the current node:**
   - `auto node = levels.front();`: This line retrieves the first node of the current level.
   - `res.push_back(node->val);`: Adds the value of the current node to the result.
3. **Process children:**
   - `if (node->right) levels.push(node->right);`: Enqueues the right child if it exists.
   - `if (node->left) levels.push(node->left);`: Enqueues the left child if it exists.
4. **Pop the processed node:**
   - `levels.pop();`: Removes the current node from the queue. This is crucial because we've finished processing it, 
   and we want to move on to the next node at the current level.
5. **Update the current node:**
   - `node = levels.front();`: Sets the current node to the next node in the queue.

By popping the current node after processing its children, we ensure that:

- We accurately calculate the `size` of the current level at the beginning of the iteration.
- We process each node at the current level exactly once.
- We move on to the next node in the queue for the next iteration.

This approach guarantees that we process all nodes at each level and correctly identify the rightmost node for each level.

**Would you like to delve deeper into any other aspect of this code?**


*/
namespace BinaryTreeRightSideView
{
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		
	};

	class Solution {
	public:
		vector<int> rightSideView(TreeNode* root)
		{
			if (!root) return {};

			vector<int> res;

			// BFS use queue
			queue<TreeNode*> levels;
			levels.push(root); // root always going to be seen

			while (!levels.empty())
			{
				int size = levels.size();
				auto node = levels.front();
				res.push_back(node->val);
				for (int i = 0; i < size; i++)
				{
					if (node->right)
						levels.push(node->right);
					if (node->left)
						levels.push(node->left);
					levels.pop();
					node = levels.front();
				}
			}
			return res;

		}
	};

	void process()
	{
        {
			auto root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(3);
			root->left->right = new TreeNode(5);
			root->right->right = new TreeNode(4);

			Solution sol;
			auto res = sol.rightSideView(root);
			printv(res);

        }
		{
			auto root = new TreeNode(1);
			root->left = new TreeNode(2);

			Solution sol;
			auto res = sol.rightSideView(root);
			printv(res);

		}
	}
}