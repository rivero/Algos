#pragma once
/*
* https://leetcode.com/problems/search-in-rotated-sorted-array
33. Search in Rotated Sorted Array
Medium
Topics
Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4

All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4


*/
namespace SearchInRotatedSortedArray
{
	class Solution 
	{
	public:
		int search(vector<int> nums, int target) 
		{
			int n = nums.size();
			int l{ 0 }, r{ n - 1 };
			while (l < r)
			{
				int m = (l + r) / 2;
				if (nums[m] > nums[r])
					l = m + 1;
				else
					r = m;
			}
			auto min_i = l;

			// test boundaries
			if (min_i == 0) // sorted array
				l = 0, r = n - 1;
			else if (nums[0] <= target && target <= nums[min_i - 1]) // target in left side
				l = 0, r = min_i - 1;
			else // target in right side
				l = min_i, r = n - 1;

			while (l <= r && r > -1)
			{
				int m = (l + r) / 2;
				if (nums[m] == target)
					return m;
				else if (nums[m] < target)
					l = m + 1;
				else
					r = m - 1;
			}
			return -1;
		}
	};


	void process()
	{
		Solution sol;
		cout << sol.search({ 4,5,6,7,0,1,2 }, 0) << "\n";
		cout << sol.search({ 1 }, 0) << "\n";
		cout << sol.search({ 1,3 }, 0) << "\n";
	}
}
