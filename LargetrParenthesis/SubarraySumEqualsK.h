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

The given code snippet defines an algorithm to find the number of subarrays in an array `nums` 
whose sum equals a given target value `k`. Here's how it works:

1. **Prefix Sums and Frequencies Map**:
   - The algorithm uses a prefix sums approach to keep track of cumulative sums as it iterates through the array.
   - It maintains an unordered map (`prefixSums_frequencies_map`) where keys represent prefix sums, 
   and values represent the frequency of each prefix sum encountered so far.
   - Initially, the map contains one entry: `prefix_sum = 0` with a frequency of 1.

2. **Iterating Through `nums`**:
   - The algorithm processes each element `num` in the array.
   - It updates the `prefix_sum` by adding the current `num`.
   - Calculates the difference `difference = prefix_sum - k`.

3. **Counting Subarrays**:
   - If the map contains an entry for `difference`, it means there exists a subarray with a sum equal to `k`.
   - The algorithm increments the answer (`ans`) by the frequency of `difference` in the map.
   - This step ensures that all subarrays ending at the current index contribute to the count.

4. **Updating the Map**:
   - The algorithm increments the frequency of the current `prefix_sum` in the map.
   - This accounts for subarrays starting from the beginning of the array.

5. **Final Result**:
   - The final result is the value of `ans`, representing the total number of subarrays with a sum equal to `k`.

**Time Complexity**:
- The algorithm iterates through the array once, performing constant-time operations for each element.
- Constructing the `prefixSums_frequencies_map` takes O(n) time.
- Therefore, the overall time complexity of the `subarraySum` algorithm is O(n).

**Space Complexity**:
- The space complexity is determined by the additional data structure (`prefixSums_frequencies_map`).
- In the worst case, the map can store all distinct prefix sums, resulting in O(n) space.
- Thus, the overall space complexity is O(n).

	*/
	class Solution {
	public:
		int subarraySum(vector<int> nums, int k)
		{
			if (nums.empty())
				return {};

			unordered_map<int, int> m;
			int prefix_sum{}, ans{};
			m[prefix_sum] = 1;

			for (auto num : nums)
			{
				prefix_sum += num;
				auto diff = prefix_sum - k;
				if (m.count(diff) > 0)
				{
					ans += m[diff];
				}
				m[prefix_sum]++;
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