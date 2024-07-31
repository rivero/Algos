#pragma once
/*
https://leetcode.com/problems/contiguous-array
525. Contiguous Array
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
Solution

## Algorithm Explanation

**Problem:** Find the maximum length of a subarray with an equal number of 0s and 1s in a given binary array.

**Approach:** Hashmap and Counting

1. **Initialization:**
   * `seen_at`: A hashmap to store the index of the first occurrence of a particular `count` value.
   * `seen_at[0] = -1`: This initialization is a crucial optimization. It ensures that if we encounter a `count` of 0, the maximum 
   length subarray starting from the beginning is considered.
   * `ans`: Stores the maximum length of the subarray found so far.
   * `count`: Tracks the difference between the number of 1s and 0s encountered so far.

2. **Iterate through the array:**
   * For each element `nums[i]`:
	 * Update `count`: Increment `count` if the element is 1, otherwise decrement it.
	 * If `count` exists in `seen_at`, it means we have encountered a subarray with an equal number of 0s and 1s. Calculate the 
	 length of this subarray (`i - seen_at[count]`) and update `ans` if it's larger than the current maximum.
	 * If `count` doesn't exist in `seen_at`, store its current index in the hashmap.

3. **Return `ans`:** The final value of `ans` represents the maximum length of the subarray with equal numbers of 0s and 1s.

## Complexity Analysis

* **Time complexity:** O(n), where n is the length of the input array. The algorithm iterates through the array once.
* **Space complexity:** O(n) in the worst case, as the hashmap can potentially store all unique `count` values. However, in practice,
the space used is often less than O(n).

## Key Idea
The algorithm effectively utilizes a hashmap to keep track of the first occurrence of each `count` value. By calculating the 
difference between the current index and the previously seen index of the same `count`, we can efficiently find the length of 
subarrays with equal numbers of 0s and 1s. The initialization `seen_at[0] = -1` is crucial for handling subarrays starting from 
the beginning of the input array.

Example:
## Example: Finding Maximum Length Subarray with Equal 0s and 1s

**Input:** nums = [0, 1, 0]

### Step-by-Step Breakdown:

1. **Initialization:**
   * `seen_at = {0: -1}`
   * `ans = 0`, `count = 0`

2. **Iteration:**
   * **i = 0:**
	 * `nums[0] = 0`, so `count` becomes `-1`.
	 * `count` is not in `seen_at`, so add it: `seen_at = {-1: 0}`.
   * **i = 1:**
	 * `nums[1] = 1`, so `count` becomes `0`.
	 * `count` is in `seen_at`, so calculate the length: `ans = max(ans, i - seen_at[count]) = max(0, 1 - (-1)) = 2`.
	 * Update `seen_at` if necessary (no need in this case).
   * **i = 2:**
	 * `nums[2] = 0`, so `count` becomes `-1`.
	 * `count` is in `seen_at`, so calculate the length: `ans = max(ans, i - seen_at[count]) = max(2, 2 - 0) = 2`.
	 * Update `seen_at` if necessary (no need in this case).

3. **Return `ans`:** The maximum length found is 2.

**Explanation:**

* The algorithm effectively finds the longest subarray with an equal number of 0s and 1s by keeping track of the first occurrence of 
each `count` value.
* The initialization `seen_at[0] = -1` is crucial for handling subarrays starting from the beginning.
* By calculating the difference between the current index and the previously seen index of the same `count`, we efficiently determine
the length of the subarray.

In this example, the subarray [0, 1] has an equal number of 0s and 1s, and its length is 2, which is the maximum length found.


*/
namespace ContiguousArray
{
	class Solution 
	{
	public:
		int findMaxLength(vector<int>& nums) 
		{
			map<int, int> seen_at; // store tha last index where our counter was seen
			seen_at[0] = -1; // when we rest our index from our counter we need to inlcude the first element at 0
			int ans{}, count{};
			for (int i = 0; i < nums.size(); i++)
			{
				count += nums[i] != 0 ? 1 : -1; // increase for 1 decrease for 0
				if (seen_at.count(count) > 0)
					ans = max(ans, i - seen_at[count]);
				else
					seen_at[count] = i;

			}
			return ans;
		}
	};
	void process(){}
}