#pragma once
/*
* https://leetcode.com/problems/subsets-ii
90. Subsets II

Given an integer array nums that may contain duplicates, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10


## Algorithm Explanation

**Problem:** Find all subsets of a given array, including duplicates.

**Approach:** Backtracking with pruning for duplicates.

1. **Sorting:** Sort the input array to handle duplicates efficiently.
2. **Backtracking:**
   * `backtrack` function recursively explores all possible subsets.
   * At each level, decide whether to include the current element or not.
   * If the current element is the same as the previous one and we haven't processed it yet 
   (i.e., `i != index && nums[i] == nums[i - 1]`), skip it to avoid duplicates.
   * Add the current subset to the `Subsets` vector.
   * Include the current element in the `subset`, recursively explore the remaining elements, and then remove it (backtrack).

**Key Idea:**
* The backtracking approach explores all possible combinations by including or excluding each element.
* Pruning the search space by skipping duplicate elements ensures unique subsets.

## Time and Space Complexity

* **Time complexity:** O(2^n * n), where n is the length of the input array. This is because there are 2^n possible subsets, and 
for each subset, we need to copy its elements into a new vector.
* **Space complexity:** O(n * 2^n) for the `Subsets` vector, which can store up to 2^n subsets, each of size n in the worst case. 
The recursion stack also takes O(n) space.

**Overall:** The algorithm efficiently generates all possible subsets, including duplicates, by using backtracking and pruning.

*/
namespace SubSetsII
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
				if (i != index && nums[i] == nums[i - 1])
				{
					continue;
				}
				subset.push_back(nums[i]);
				backtrack(nums, i + 1);
				subset.pop_back();
			}
		}
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums)
		{
			sort(nums.begin(), nums.end());
			backtrack(nums);
			return Subsets;
		}
	};

	void process(){}
}
