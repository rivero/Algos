#pragma once
/*
18. 4Sum
Medium
Topics
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/
namespace FourSum
{
	class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target)
		{
			sort(nums.begin(), nums.end());
			vector<vector<int>> res;
			int i{}; // base Index
			int n = nums.size();

			while (i < n - 3)
			{
				while (i > 0 && nums[i] == nums[i - 1])
					i++;

				int j = i + 1;
				while (j < n - 2)
				{
					while (j > i + 1 && nums[j] == nums[j - 1])
						j++;

					int l = j + 1, r = n - 1;
					while (l < r)
					{
						auto sum = nums[i] + nums[j] + nums[l] + nums[r];
						if (sum == target)
						{
							res.push_back({ nums[i] , nums[j] , nums[l] , nums[r] });
							l++;
							while (l < r && nums[l] == nums[l - 1])
								l++;
							r--;
							while (l < r && nums[r] == nums[r + 1])
								r--;
						}
						else if (sum > target)
						{
							r--;
							while (l < r && nums[r] == nums[r + 1])
								r--;
						}
						else
						{
							l++;
							while (l < r && nums[l] == nums[l - 1])
								l++;
						}
					}
					j++;
				}
				i++;
			}
			return res;
		}
	};

	void process(){}
}