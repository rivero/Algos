#pragma once
/*
https://leetcode.com/problems/subsets/

78. Subsets
Given an integer array nums of unique elements, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.


**Algorithm Explanation:**

**Problem:** Find all possible subsets of a given set of numbers.

**Approach:** Backtracking

**Code Breakdown:**

1. **`vector<vector<int>> Subsets;`:** This vector will store all the generated subsets.
2. **`vector<int> subset;`:** This vector temporarily holds a subsSet during the backtracking process.
3. **`backtrack(vector<int>& nums, int index = 0)`:**
   - Recursive function to generate subsets.
   - `nums`: The input array of numbers.
   - `index`: The starting index for considering elements in the current backtracking step.
4. **`Subsets.push_back(subset);`:** Adds the current `subset` to the `Subsets` vector.
5. **`for(int i = index; i < nums.size(); i++)`:** Iterates through the remaining elements in `nums`.
   - `subset.push_back(nums[i])`:** Adds the current element to the `subset`.
   - `backtrack(nums, i + 1)`: Recursively calls `backtrack` with the next index.
   - `subset.pop_back()`: Removes the current element from the `subset` to backtrack.
6. **`vector<vector<int>> subsets(vector<int>& nums)`:**
   - Public function to initiate the subset generation process.
   - Calls `backtrack(nums)` to start the backtracking.
   - Returns the `Subsets` vector containing all generated subsets.

**Time Complexity:**

- The time complexity is O(2^n), where n is the number of elements in the input array. 
  This is because for each element, there are two choices: include it in the subset or exclude it. 
  This leads to an exponential growth in the number of subsets.

**Space Complexity:**

- The space complexity is O(n) in the worst case, where n is the number of elements in the input array. 
  This is due to the recursion depth and the size of the `subset` vector.

*/
namespace SubSets
{
	class Solution
	{
		vector<vector<int>> Subsets;
		vector<int> subset;
		void backtrack(vector<int>& nums, int index = 0)
		{
			Subsets.push_back(subset);

			for (int i = index; i < nums.size(); i++)
			{
				subset.push_back(nums[i]);
				backtrack(nums, i + 1);
				subset.pop_back();
			}
		}
	public:
		vector<vector<int>> subsets(vector<int> nums)
		{
			backtrack(nums);
			return Subsets;
		}
	};

	void process()
	{
		cout << "Subsets\n";
		Solution sol;
		auto res = sol.subsets({1, 2, 3});
		for (auto& el : res)
		{
			printv(el);
		}
	}
}
