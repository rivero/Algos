#pragma once
namespace IncreasingTripleSequence
{
	/*
	https://www.youtube.com/watch?v=i340M1N4i8Y
	
	*/
	class Solution
	{
	public:
		string increasingTriplet(vector<int> nums) // O(nLogn)
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
				if (LIS.size() > 2)
				{
					break;
				}
			}
			return LIS.size() > 2 ? "true" : "false";
		}

		bool increasingTripletOpt(vector<int> nums)
		{
			printv(nums);
			long n = nums.size();
			if (n < 3)
			{
				return false;
			}

			auto first = LONG_MAX;
			auto second = LONG_MAX;

			for (int i = 0; i < n; i++)
			{
				if (first >= nums[i])
				{
					first = nums[i];
				} 
				else if (second >= nums[i])
				{
					second = nums[i];
				}
				else
				{
					return true;
				}
			}
			return false;

		}
		bool increasingKnthGen(vector<int> nums, int k = 3)
		{
			printv(nums);
			long n = nums.size();
			if (n < k)
			{
				return false;
			}
			vector<long long> increasing(k, LONG_MAX);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < k; j++)
				{
					if (increasing[j] >= nums[i])
					{
						increasing[j] = nums[i];
						break;
					}
				}
				if (increasing[k-1] != LONG_MAX)
				{
					return true;
				}
			}
			return false;
		}
	};

	void process()
	{
		Solution sol;
		cout << sol.increasingTriplet({ 8,10,9,4,2,6,3,5,9,5 }) << "\n\n";
		cout << sol.increasingTriplet({ 5,4,5,7,6,9 }) << "\n";
		cout << "\n\n\n";
		cout << sol.increasingTripletOpt({ 8,10,9,4,2,6,3,5,9,5 }) << "\n";
		cout << sol.increasingTripletOpt({ 5,4,5,7,6,9 }) << "\n";
		cout << sol.increasingTripletOpt({ 1,1,1,2,2,2 }) << "\n";
		cout << "\n\n\n";
		cout << sol.increasingKnthGen({ 8,10,9,4,2,6,3,5,9,5 }, 4) << "\n";
		cout << sol.increasingKnthGen({ 5,4,5,7,6,9 }, 4) << "\n";
		cout << sol.increasingKnthGen({ 1,1,1,2,2,2 }) << "\n";
		cout << sol.increasingKnthGen({ 1,1,1,2,2,2 }, 2) << "\n";
		cout << "\n\n\n";
	}

}