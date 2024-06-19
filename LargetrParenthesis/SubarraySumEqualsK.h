#pragma once
namespace SubarraySumEqualsK
{
	/*
	
	https://leetcode.com/problems/subarray-sum-equals-k/description/

	560. Subarray Sum Equals K
	Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

	A subarray is a contiguous non-empty sequence of elements within an array.



	Example 1:

	Input: nums = [1,1,1], k = 2
	Output: 2
	Example 2:

	Input: nums = [1,2,3], k = 3
	Output: 2


	Constraints:

	1 <= nums.length <= 2 * 10^4
	-1000 <= nums[i] <= 1000
	-107 <= k <=


	*/
	class Solution {
	public:
		//PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
		// 	https://leetcode.com/problems/subarray-sum-equals-k/solutions/1760146/c-easy-solution-prefix-sum-map-easy-understanding-hashmap

		int subarraySum(vector<int> nums, int k) 
		{
			unordered_map<int, int> mp;
			int sum = 0, ans = 0;
			mp[sum] = 1;

			for (auto it : nums) 
			{
				sum += it;
				int find = sum - k;
				
				if (mp.find(find) != mp.end()) 
				{
					ans += mp[find];
				}
				mp[sum]++;
			}
			return ans;
			//PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
		}
	};


	class SolutionBruteForce 
	{
		// https://leetcode.com/problems/subarray-sum-equals-k/solutions/5281215/best-approach/
	public:
		int subarraySum(vector<int>& nums, int k) 
		{
			int count = 0;
			int n = nums.size();
			for (int i = 0; i < n; i++) 
			{
				int sum = 0;
				for (int j = i; j < n; j++) 
				{
					sum = sum + nums[j];
					if (sum == k)
						count++;
				}
			}
			return count;
		}
	};
	void process()
	{
		{
			Solution sol;
			cout << sol.subarraySum({ 1,1,1 }, 2) << "\n";
			cout << sol.subarraySum({ 1,2,3 }, 3) << "\n";
			cout << sol.subarraySum({ 1,-1,0 }, 0) << "\n";
		}

	}
}