#pragma once
namespace BinaryTreeRightSideView
{

    /**

	199. Binary Tree Right Side View
    Given the root of a binary tree, imagine yourself standing on the right side of it, 
    return the values of the nodes you can see ordered from top to bottom.
    Example 1:
    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]

    Example 2:
    Input: root = [1,null,3]
    Output: [1,3]

    Example 3:
    Input: root = []
    Output: []

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
  
 * Definition for a binary tree node.
 */
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		
	};
    class SolutionNaive
    {
        vector<int> m_res;
    public:
        vector<int> rightSideView(TreeNode* root)
        {
            if (!root)
                return m_res;

            m_res.push_back(root->val);
            if (root->right)
            {
				rightSideView(root->right);
			}
            else if (root->left)
            {
				rightSideView(root->left);
            }

            return m_res;
        }
    };
    class Solution 
    {
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
        */
    public:
        vector<int> rightSideView(TreeNode* root) 
        {
            vector<int> result;
            if (root == nullptr)
                return result;

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