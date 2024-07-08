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

	Subarray equals k or divisable by k  and the like are always solved with prefix sum.



	Certainly! Let's break down the algorithm step by step:

	1. **Initialization**:
	   - We create an unordered map (hash table) called `mp` to store prefix sums and their frequencies.
	   - Initialize `prefix_sum` to 0 (the sum of an empty subarray).
	   - Initialize `ans` to 0 (the count of subarrays with sum equal to `k`).
	   - Set `mp[0] = 1` to account for the case where the entire array has a sum of `k`.

	2. **Iterating through the array**:
	   - For each element `it` in the `nums` array:
		 - Update `prefix_sum` by adding `it`.
		 - Calculate the difference `difference = prefix_sum - k`.
		 - Check if `difference` exists in the map (`mp`). If it does, add the frequency of `difference` to `ans`.
		 - Increment the frequency of the current `prefix_sum` in the map.

	3. **Return the answer**:
	   - The final value of `ans` represents the total count of subarrays with sum equal to `k`.

	4. **Time Complexity**:
	   - The algorithm iterates through the array once, so the time complexity is O(n), where `n` is the size of the input array.

	5. **Space Complexity**:
	   - The space complexity is O(n) due to the hash map (`mp`) storing prefix sums and their frequencies.

	In summary, this algorithm efficiently counts subarrays with a target sum of `k` using a hash map to keep track of prefix sums. 
	
	It's a great example of how hash maps can be used to optimize certain problems! 😊👍
	*/
	class Solution 
	{
	public:

		int subarraySum(vector<int> nums, int k) 
		{
			if (nums.size() == 0)
			{
				return 0;
			}
#ifdef PRINTV
			cout << "Sum should equal k [" << k << "] input vector:\n";
			printv(nums);
#endif
			unordered_map<int, int> prefixSums_frequencies_map;
			int prefix_sum = 0, ans = 0;
			prefixSums_frequencies_map[prefix_sum] = 1; // To make ans += to count for the first time.

			for (auto num : nums) 
			{
				prefix_sum += num;
				int difference = prefix_sum - k;
#ifdef PRINTV
				cout << "prefix sum: " << prefix_sum << " difference with k [" << k << "]: " << difference << "\n";
#endif // PRINTV
				if (prefixSums_frequencies_map.find(difference) != prefixSums_frequencies_map.end()) 
				{
					// we have seen this difference before, meaning prefix - k already counted
					// we have see this sum before, then between this time and the previous time we found a subarray
#ifdef PRINTV
					cout << "found " << difference << "\n";
#endif
					ans += prefixSums_frequencies_map[difference];
				}
#ifdef PRINTV
				cout << "increasing prefixSums_frequencies_map[" << prefix_sum << "]\n";
#endif
				prefixSums_frequencies_map[prefix_sum]++;
#ifdef PRINTV
				cout << "prefix Sums to frequencies map:\n";
				printm(prefixSums_frequencies_map);
#endif // PRINTV
			}
			return ans;
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
			cout << sol.subarraySum({ 1,1,1 }, 2) << "\n------------------\n\n";
			cout << sol.subarraySum({ 1,2,3 }, 3) << "\n------------------\n\n";
			cout << sol.subarraySum({ 1,-1,0 }, 0) << "\n------------------\n\n";
		}

	}
}