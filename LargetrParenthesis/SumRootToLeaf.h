#pragma once
namespace SumRootToLeaf
{
	/*
	https://leetcode.com/problems/sum-root-to-leaf-numbers/description/


129. Sum Root to Leaf Numbers

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the 
answer will fit in a 32-bit integer.

A leaf node is a node with no children.



Example 1:

	1
  /   \
 2	   3


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.


Example 2:

		4
	  /   \
	 9	   0
	/ \
   5   1

Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.


Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
	
	Solution

	multiply the val by 10 each recursion and add the results

	example
		4
	   / \
	  9	  0

	root (4) : 10 * 0 + val = 0 + 4 = 4
	left (9) : 10 * 4 + 9 = 40 + 9 = 49
	right (0): 10 * 4 + 0 = 40 + 0 = 40
	
	Time complexity: O(n) where n is the number of elements in the tree
	Space complexity: O(n) where n is the hight of the tree because the recursion.




1. **Algorithm Explanation**:
   - The **sumNumbers** function calculates the sum of all numbers formed by traversing a binary tree from the root to leaf nodes.
   - It maintains a `tempans` variable that accumulates the value formed by concatenating digits as we traverse the tree.

2. **Algorithm Steps**:
   - If the `root` is null (i.e., an empty tree), return 0.
   - Update `tempans` by multiplying it by 10 and adding the value of the current `root`.
   - If the `root` has no left or right child (i.e., it's a leaf node), return `tempans`.
   - Otherwise, recursively compute the sum of numbers for the left and right subtrees and return their sum.

3. **Example**:
   - Consider a binary tree with the following structure:
	 ```
		 1
		/ \
	   2   3
	 ```
   - The sum of numbers formed by traversing from root to leaf nodes:
	 - Path 1 → 2: 12
	 - Path 1 → 3: 13
	 - Total sum: 12 + 13 = 25

4. **Time Complexity**:
   - The algorithm traverses each node once, so the time complexity is O(n), where `n` is the number of nodes in the tree.

5. **Space Complexity**:
   - The space complexity is O(h), where `h` is the height of the tree (recursion stack space).

In summary, the **sumNumbers** algorithm efficiently computes the sum of numbers formed by traversing a binary tree. Great job implementing this! 😊👍¹².

Source: Conversation with Copilot, 7/8/2024
(1) Big O, what is the complexity of summing a series of n numbers?. https://stackoverflow.com/questions/9252891/big-o-what-is-the-complexity-of-summing-a-series-of-n-numbers.
(2) Big O Cheat Sheet – Time Complexity Chart - freeCodeCamp.org. https://www.freecodecamp.org/news/big-o-cheat-sheet-time-complexity-chart/.
(3) Integer complexity - Wikipedia. https://en.wikipedia.org/wiki/Integer_Complexity.	*/


 struct TreeNode 
 {
	 int val{};
	 TreeNode* left{};
	 TreeNode* right{};
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 class Solution 
 {
 public:
	 int sumNumbers(TreeNode* root, int tempans = 0) 
	 {
		 if (!root) 
			 return 0;
		 
		 tempans = 10 * tempans + root->val;

		 if (!root->left && !root->right) 
			 return tempans;
		 
		 return sumNumbers(root->left, tempans) + sumNumbers(root->right, tempans);
	 }
 };
	void process()
	{
		{
			Solution sol;
			auto root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(3);
			cout << sol.sumNumbers(root) << "\n";
		}
		{
			Solution sol;
			auto root = new TreeNode(4);
			root->left = new TreeNode(9);
			root->right = new TreeNode(0);
			root->left->left = new TreeNode(5);
			root->left->right = new TreeNode(1);
			cout << sol.sumNumbers(root) << "\n";
		}

	}
}