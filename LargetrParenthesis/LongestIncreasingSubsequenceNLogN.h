#pragma once
namespace LongestIncreasingSubsequenceNLogN
{
	class Solution
	{
	public:
		int LengthOfLIS(vector<int> nums)
		{
			int n = nums.size();
			vector<int> LIS;
			for (int i = 0; i < n; i++)
			{
				auto lb = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
				if (lb == LIS.size())
				{
					LIS.push_back(nums[i]);
				} 
				else
				{
					LIS[lb] = nums[i];
				}
				printv(LIS);
			}
			return LIS.size();
		}
	};

	void process()
	{
		Solution sol;
		cout << sol.LengthOfLIS({8,10,9,4,2,6,3,5,9,5}) << "\n";
	}
}