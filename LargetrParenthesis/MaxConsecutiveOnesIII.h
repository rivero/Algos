#pragma once
/*
https://leetcode.com/problems/max-consecutive-ones-iii
1004. Max  Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array 
if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length

This algorithm aims to find the maximum consecutive number of ones in an array `nums` after flipping at most `k` zeros.

Certainly! Let's break down the given algorithm step by step. This algorithm aims to find the maximum consecutive number of ones 
in an array `nums` after flipping at most `k` zeros.

1. **Initialization**:
   - Initialize two pointers, `left` and `right`, both initially pointing to the start of the array.

2. **Sliding Window Approach**:
   - As we iterate through the array from left to right (using the pointer `right`), we adjust the window based on the value of `k`.

3. **Updating the Window**:
   - If `nums[right]` is 0, we decrement `k` (since we are flipping a zero to one).
   - If `k` becomes negative, we need to shrink the window from the left side.
	 - If `nums[left]` is 0 (i.e., the leftmost element was flipped from 1 to 0), we increment `k` by 1.
	 - Increment `left` to exclude the leftmost element from the window.
   - Continue extending the window by incrementing `right`.

5. **Final Result**:
   - After processing the entire array, the value of `right - left` represents the maximum consecutive ones achievable by flipping 
   at most `k` zeros.

- **Time Complexity**: The algorithm iterates through the array once, so the time complexity is *O(n)*, where *n* is the size of 
the input array.
- **Space Complexity**: The algorithm uses only a few variables (pointers and counters), so the space complexity is *O(1)* 
	(constant space).

*/
namespace MaxConsecutiveOnesIII
{
	class Solution 
	{
	public:
		int longestOnes(vector<int>& nums, int k)
		{
			int left = 0, right = 0;

			while (right < nums.size())
			{
				if (nums[right] == 0)
				{
					k--;
				}
				if (k < 0)
				{
					if (nums[left] == 0) // we increment k only if the element is zero since we need to flip it
					{
						k++;
					}
					left++; // reduce window
				}
				right++; // extend window
			}
			return right - left;
		}
	};
	void process(){}
}
