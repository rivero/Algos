#pragma once
/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

The code implements a binary search approach to find the first and last positions of a target element in a sorted array.

Base case: If the array is empty, return [-1, -1].
Find leftmost occurrence:
Perform a binary search to find the leftmost occurrence of the target.
When a target is found, update leftIndex and adjust the right boundary to search for a potentially earlier occurrence.
Find rightmost occurrence:
Perform another binary search to find the rightmost occurrence of the target.
When a target is found, update rightIndex and adjust the left boundary to search for a potentially later occurrence.
Return result: Return the leftIndex and rightIndex as the result.

Time and Space Complexity
Time complexity: O(log n) due to the two binary searches.
Space complexity: O(1) as constant extra space is used.
This solution efficiently finds the first and last positions of a target element in a sorted array while meeting the O(log n) 
time complexity requirement.
*/
namespace FindFirstAndLastPositionOfelementInSortedArray
{

	class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			int n = nums.size();
			if (n == 0) {
				return { -1, -1 };
			}

			// Find the leftmost occurrence
			int left = 0, right = n - 1;
			int leftIndex = -1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] >= target)
				{
					if (nums[mid] == target)
						leftIndex = mid;
					right = mid - 1; // Look for the leftmost occurrence
				}
				else
					left = mid + 1;
			}

			// Find the rightmost occurrence
			left = 0, right = n - 1;
			int rightIndex = -1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] <= target)
				{
					if (nums[mid] == target)
						rightIndex = mid;
					left = mid + 1; // Look for the rightmost occurrence
				}
				else
					right = mid - 1;
			}

			return { leftIndex, rightIndex };
		}
	};

	void process() {}
}