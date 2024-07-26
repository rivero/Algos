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

1. **Algorithm Explanation**:
   - The `twoSum` function aims to find a pair of indices in the given integer vector `nums` such that the corresponding elements add up to the given `target`.
   - The algorithm follows these steps:
	 1. Create an unordered map (hash table) called `hash` to store each element of `nums` along with its index.
	 2. Iterate through `nums`:
		- For each element `nums[i]`, calculate the complement (`complement = target - nums[i]`).
		- Check if the complement exists in the `hash`.
		- If found, return the pair of indices `{i, hash[complement]}`.
		- Add that value, index to map
	 3. If no valid pair is found, return an empty vector (indicating no solution).

2. **Complexities**:
   - Time Complexity: O(N), where N is the size of the input vector `nums`.
	 - The algorithm processes each element in `nums` once while building the hash table.
   - Space Complexity: O(N), due to the space used by the hash table (`hash`).

3. **Example**:
   - Input: `nums = [2, 7, 11, 15], target = 9`
	 - The pair `[0, 1]` (indices of elements 2 and 7) adds up to the target.
	 - Output: `[0, 1]`

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