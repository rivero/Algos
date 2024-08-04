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
## Algorithm: Subarray with Equal Number of 0s and 1s

**Core Idea:** using a map to track the cumulative sum of (1s - 0s) encountered so far and the index where this sum was first seen.

* **Maximizing Length:** By storing the index of the first occurrence of a particular sum, we can calculate the maximum length of 
such a subarray.

**Process:**

1. Initialize a HashMap to store cumulative sum and its first index.
2. Iterate through the array, incrementing the count for 1 and decrementing for 0.
3. If the current count exists in the HashMap, calculate the length of the subarray and update the maximum length if needed.
4. Otherwise, store the current count and its index in the HashMap.

* Why Finding the Same Count Indicates Equal Numbers
If we encounter the same count value again, it means that the number of times we've incremented count (due to 1s) is equal to the 
number of times we've decremented count (due to 0s) between the two occurrences of this count.
This implies that the subarray between the two indices where count had this value contains an equal number of 0s and 1s.

**Time Complexity:** O(n) due to single pass through the array.
**Space Complexity:** O(n) in worst case for the HashMap.

Example:

Consider the array [0, 1, 0].

Initially, count is 0.
We encounter 0, so count becomes -1.
We encounter 1, so count becomes 0 again.
Since we've seen count = 0 before, we know that the subarray from index 0 to index 1 has an equal number of 0s and 1s.

**Example:**

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

In this example, the subarray [0, 1] has an equal number of 0s and 1s, and its length is 2, which is the maximum length found.


*/
namespace ContiguousArray
{
	class Solution 
	{
	public:
		int findMaxLength(vector<int>& nums)
		{
			unordered_map<int, int> countIndexMap;
			countIndexMap[0] = -1; // fake index to include element 0 in calculation
			int ans = 0, count = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				count += nums[i] == 1 ? 1 : -1;// increment for 1s decrement for 0s
				if (countIndexMap.count(count) > 0)
					ans = max(ans, i - countIndexMap[count]); // calculating dist bet indexes
				else
					countIndexMap[count] = i;
			}
			return ans;
		}
	};

	void process() {}
}