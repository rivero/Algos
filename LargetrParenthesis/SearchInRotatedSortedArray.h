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


Certainly! Let's break down the algorithm and discuss its complexities:

1. **Algorithm Explanation**:
	- The given algorithm searches for a target value in a rotated sorted array (also known as a rotated array).
	- The array is sorted in ascending order, but it has been rotated at some pivot point.
	- The algorithm first finds the index of the minimum element (the pivot) using binary search.
	- Then, it determines which half of the array (left or right of the pivot) contains the target value.
	- Finally, it performs binary search again within the appropriate half to find the target.

2. **Step-by-Step Explanation**:
	- **Finding the Pivot**:
		- The algorithm starts by finding the index of the minimum element (pivot) in the rotated array.
		- It uses binary search to locate the pivot index (`min_i`).
		- The pivot index divides the array into two sorted subarrays: `[0, min_i-1]` and `[min_i, n-1]`.
	- **Determining the Target Side**:
		- If `min_i` is 0, the entire array is sorted, and we search the entire array.
		- Otherwise, we compare the target with the first and last elements:
			- If `target` lies between `nums[0]` and `nums[min_i-1]`, we search the left side.
			- Otherwise, we search the right side.
	- **Binary Search for the Target**:
		- Within the chosen side, the algorithm performs binary search to find the target.
		- It adjusts the pointers (`l` and `r`) based on comparisons with `target`.

3. **Time Complexity**:
	- The time complexity of this algorithm is O(log N), where N is the size of the input array.
	- The initial binary search to find the pivot takes O(log N) time.
	- The second binary search within the chosen side also takes O(log N) time.

4. **Space Complexity**:
	- The space complexity is O(1) because the algorithm uses only a few variables (`l`, `r`, `m`, and `min_i`) 
	without any additional data structures.

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
				int m = l + (r - l) / 2;
				if (nums[m] > nums[r])
					l = m + 1;
				else
					r = m;
			}
			auto min_i = r; // l or r will do, they overlap

			// test boundaries
			if (min_i == 0) // sorted array
				l = 0, r = n - 1;
			else if (nums[0] <= target && target <= nums[min_i - 1]) // target in left side
				l = 0, r = min_i - 1;
			else // target in right side
				l = min_i, r = n - 1;

			while (l <= r && r > -1)
			{
				int m = l + (r - l) / 2;
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
