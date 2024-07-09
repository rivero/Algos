#pragma once
// https://leetcode.com/problems/binary-tree-right-side-view/solutions/5144012/c-simple-solution-by-using-bfs-and-queue-detailed-explanation/
/*
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
   - The `rightSideView` function takes a binary tree's root node as input and returns a vector of integers representing the right view of the tree.
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

Feel free to ask if you have any further questions! 😊

Source: Conversation with Copilot, 7/9/2024
(1) Print Right View of a Binary Tree - GeeksforGeeks. https://www.geeksforgeeks.org/print-right-view-binary-tree-2/.
(2) 199. Binary Tree Right Side View — Hands-On Problem-Solving in Python .... https://mohsentabibian.github.io/LeetCode-Solutions/07.%20Trees/199.%20Binary%20Tree%20Right%20Side%20View.html.
(3) Binary Tree Right Side View | CodePath Cliffnotes. https://guides.codepath.org/compsci/Binary-Tree-Right-Side-View.
(4) Binary Tree Right Side View LeetCode Solution - TutorialCup. https://tutorialcup.com/leetcode-solutions/binary-tree-right-side-view-leetcode-solution.htm.
(5) LeetCode: 199. Binary Tree Right Side View. https://blog.salvatorelabs.com/leetcode/199-binary-tree-right-side-view/.

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

    class Solution 
    {
    public:
        vector<int> rightSideView(TreeNode* root) 
        {
            vector<int> result;
            if (!root)
                return result;

            // Level order traversal BFS with a queue
            queue<TreeNode*> levels;
            levels.push(root);

            while (!levels.empty()) 
            {
                int size = levels.size();

                TreeNode* current = levels.front();
                result.push_back(current->val);

                for (int i = 0; i < size; i++) 
                {
                    current = levels.front();
                    if (current->right)
                        levels.push(current->right);
                    if (current->left)
                        levels.push(current->left);
                    levels.pop();
                }
            }
            return result;
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