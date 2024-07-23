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
*/
namespace MaxConsecutiveOnesIII
{
	class Solution
	{
	public:
		int longestOnes(vector<int>& nums, int k) 
		{
			int l{}, max_cons{};

			for (int r = 0; r < nums.size(); r++)
			{
				k -= 1 - nums[r];
				if (k < 0)
				{
					k += 1 - nums[l];
					l++;
				}
				else
					max_cons = max(max_cons, r - l + 1);
			}
			return max_cons;
		}
	};
	void process(){}
}
