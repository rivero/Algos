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


In this code:
- The `generateSubsets` function recursively generates all subsets by including or excluding the current element.
- We start with an empty subset and explore all possibilities.
- The base case is when we reach the end of the array.
- The `subsets` function initializes an empty vector for the result and an empty vector for the current subset, then calls `generateSubsets`.

The time complexity of this solution is O(2^N), where N is the number of elements in the input array. This is because there are 2^N possible subsets, and we explore each possibility once. The space complexity is also O(2^N) due to the result vector containing all subsets.

Feel free to adapt this code to your specific needs or further optimize it if necessary! 😊
*/
namespace SubSets
{
	class Solution
	{
		vector<vector<int>> result;
		vector<int> current;

		void generateSubsets(vector<int>& nums, int index)
		{
			// Add the current subset to the result
			result.push_back(current);

			// Explore all possible subsets by including or excluding the current element
			for (int i = index; i < nums.size(); ++i)
			{
				current.push_back(nums[i]);
				generateSubsets(nums, i + 1);
				current.pop_back();
			}
		}
	public:
		vector<vector<int>> subsets(vector<int> nums)
		{
			generateSubsets(nums, 0);
			return result;
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
