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

## Understanding the Algorithm: Subarray Sum Equals K

### Problem Statement
Given an array of integers `nums` and an integer `k`, the algorithm calculates the total number of contiguous subarrays whose 
sum equals `k`.

### Algorithm Breakdown

#### Initialization
* **`unordered_map<int, int> m`**: A hash map to store the frequency of prefix sums encountered so far. The key is the prefix sum, 
and the value is its frequency.
* **`int prefix_sum{}, ans{}`**: `prefix_sum` to keep track of the current running sum, initialized to 0. `ans` to store the final 
count of subarrays with sum `k`, initialized to 0.
* **`m[prefix_sum] = 1`**: Initially, the prefix sum is 0, and it occurs once.

#### Iteration and Calculation
* Iterates through each element `num` in the `nums` array.
  * **`prefix_sum += num`**: Updates the `prefix_sum` by adding the current element.
  * **`auto diff = prefix_sum - k`**: Calculates the difference between the current `prefix_sum` and the target sum `k`.
  * **`if (m.count(diff) > 0)`**: Checks if the calculated `diff` exists in the hash map. If it does, it means there was a previous 
  subarray ending at an earlier index whose sum was `diff`. Adding the current element to that subarray would result in a subarray 
  with sum `k`. Therefore, `ans` is incremented by the frequency of `diff` in the hash map.
  * **`m[prefix_sum]++`**: Updates the frequency of the current `prefix_sum` in the hash map.

#### Return Value
* Returns the final count of subarrays with sum `k`, stored in the `ans` variable.

### Key Idea
The algorithm leverages the concept of prefix sums and a hash map to efficiently count the number of subarrays with a given sum. 
storing the frequency of prefix sums, we can quickly determine if a subarray with the desired sum exists by calculating the 
difference between the current prefix sum and the target sum.

### Time and Space Complexity
* **Time complexity**: O(n), where n is the length of the input array.
* **Space complexity**: O(n) in the worst case, due to the hash map.

### Example
Consider the input array `nums = [1, 1, 1]` and `k = 2`.

* Initially, `prefix_sum = 0`, `m[0] = 1`, and `ans = 0`.
* For the first element `1`, `prefix_sum = 1`, `diff = -1` (not in the map), `m[1] = 1`.
* For the second element `1`, `prefix_sum = 2`, `diff = 0`, `m[0] = 1`, so `ans` becomes 1, `m[2] = 1`.
* For the third element `1`, `prefix_sum = 3`, `diff = 1`, `m[1] = 1`, so `ans` becomes 2, `m[3] = 1`.

The final answer is `2`, which is the correct number of subarrays with sum `2`.

By effectively using prefix sums and a hash map, this algorithm provides an efficient solution to the problem of counting subarrays 
with a given sum.


## Example with Different Values

Let's consider the input array `nums = [3, 4, -7, 3, 1, 1, 1, 1]` and `k = 3`.

### Step-by-Step Breakdown

**Initialization:**
* `prefix_sum = 0`
* `ans = 0`
* `m = {0: 1}`

**Iteration:**

1. **num = 3:**
   * `prefix_sum = 3`
   * `diff = 0`
   * `m[3] = 1`

2. **num = 4:**
   * `prefix_sum = 7`
   * `diff = 4`
   * `m[7] = 1`

3. **num = -7:**
   * `prefix_sum = 0`
   * `diff = -3`
   * `m[0] += 1` (now `m[0] = 2`)

4. **num = 3:**
   * `prefix_sum = 3`
   * `diff = 0`
   * `ans += m[0]` (now `ans = 2`)
   * `m[3] += 1` (now `m[3] = 2`)

5. **num = 1:**
   * `prefix_sum = 4`
   * `diff = 1`
   * `m[4] = 1`

6. **num = 1:**
   * `prefix_sum = 5`
   * `diff = 2`
   * `m[5] = 1`

7. **num = 1:**
   * `prefix_sum = 6`
   * `diff = 3`
   * `m[6] = 1`

8. **num = 1:**
   * `prefix_sum = 7`
   * `diff = 4`
   * `m[7] += 1` (now `m[7] = 2`)

**Final Answer:**
* `ans = 2`

There are two subarrays with sum 3: `[3]` and `[-7, 3, 3]`.

This example demonstrates how the algorithm effectively calculates the number of subarrays with the given sum by utilizing the 
prefix sum and hash map to keep track of the frequencies.

**Would you like to try another example?**

EQUALS to K follow same pattern all are solved with prefix sum: a prefix sum is like an accumulated sum
1, 2, 3 = 1, 3, 6

When we have two equal prefix sums: 
1, 2, 3, -3 = 1, 3, 6, 3
                 ^     ^  <- these two are the same

	*/
	class Solution {
	public:
		int subarraySum(vector<int> nums, int k)
		{
			if (nums.empty())
				return {};

			unordered_map<int, int> freqPrefixSumsMap;
			int prefix_sum{}, ans{};
			freqPrefixSumsMap[prefix_sum] = 1;

			for (auto num : nums)
			{
				prefix_sum += num;
				auto diff = prefix_sum - k;
				if (freqPrefixSumsMap.count(diff) > 0)
				{
					ans += freqPrefixSumsMap[diff];
				}
				freqPrefixSumsMap[prefix_sum]++;
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