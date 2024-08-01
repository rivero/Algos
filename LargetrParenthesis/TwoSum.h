#pragma once
/*
https://leetcode.com/problems/two-sum/
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

## Understanding the Two-Sum Algorithm

### Problem Statement
Given an array of integers `nums` and an integer `target`, find the indices of the two numbers such that they add up to the target.

### Algorithm Explanation
This algorithm uses a hash map to efficiently solve the two-sum problem.

1. **Create a hash map:** An empty hash map `hash` is created to store elements and their corresponding indices.
2. **Iterate through the array:**
   * For each number `num` in the array:
	 * Calculate the `complement` as `target - num`.
	 * If the `complement` exists in the hash map, it means we found a pair that adds up to the target. Return the indices of 
	 the current number and the complement.
	 * Otherwise, store the current number and its index in the hash map for potential future matches.
3. **Return an empty vector:** If no pair is found, return an empty vector.

### Why Does It Work?
 For any two numbers to add up to a target, one number is the complement of the other with respect to the target.

* **Hash map efficiency:** Using a hash map provides efficient lookup for elements. The average time complexity for searching, 
insertion, and deletion in a hash map is O(1).
* **One-pass solution:** The algorithm iterates through the array only once, making it an efficient solution.

By storing elements and their indices in the hash map, we can quickly check if the complement of a number exists, avoiding the 
need for nested loops.

**Example:**
For `nums = [2, 7, 11, 15]` and `target = 9`,
* The algorithm iterates through the array:
  * `num = 2`, `complement = 7`. Since `7` is not in the hash map, store `(2, 0)` in the hash map.
  * `num = 7`, `complement = 2`. Since `2` is in the hash map, return the indices `[1, 0]`.

**Time complexity:** O(n) due to the single pass through the array.
**Space complexity:** O(n) for the hash map in the worst case.

(7) Two Sum Problems - 4+ ways to solve. - DEV Community. https://dev.to/ggorantala/two-sum-problems-4c9j.

*/
namespace TwoSum
{
	class Solution
	{
	public:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			unordered_map<int, int> hash;
			for (int i = 0; i < nums.size(); i++)
			{
				int complement = target - nums[i];
				if (hash.count(complement) > 0)
				{
					return { i, hash[complement] };
				}
				hash[nums[i]] = i;
			}
			return {};
		}
	};

	void process(){}
}