#pragma once
/*
* https://leetcode.com/problems/4sum/
18. 4Sum
Medium
Topics
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

## Algorithm Explanation

**Here's a breakdown of the algorithm:**

1. **Sort the array:** The array `nums` is sorted in ascending order. This step is crucial for efficient two-pointer traversal.
2. **Initialize variables:**
   - `res`: A vector to store the resulting quadruplets.
   - `i`, `j`, `l`, `r`: Indices used for iterating through the array.
3. **Outer loop (i):** Iterates through the array from the beginning, representing the first element of the potential quadruplet.
   - **Skip duplicates:** If the current element is the same as the previous one, increment `i` to avoid duplicate quadruplets.
4. **Inner loop (j):** Iterates from `i + 1` to `n - 2`, representing the second element of the potential quadruplet.
   - **Skip duplicates:** Similar to the outer loop, skip duplicate elements.
5. **Two-pointer approach (l and r):**
   - `l` points to the element after `j`, representing the third element.
   - `r` points to the last element of the array, representing the fourth element.
   - Calculate the sum of the four elements at `i`, `j`, `l`, and `r`.
   - If the sum is equal to the target, add the quadruplet to the `res` vector and increment `l` and `r`, while skipping duplicates.
   - If the sum is greater than the target, decrement `r` to decrease the sum.
   - If the sum is less than the target, increment `l` to increase the sum.
6. **Return the result:** After iterating through all possible combinations, return the `res` vector containing the valid quadruplets.

## Time Complexity

The time complexity of this algorithm is **O(n^3)**, where `n` is the length of the input array. This is due to the three nested 
loops:

- The outer loop iterates `n - 3` times.
- The middle loop iterates approximately `n - 2` times in the worst case.
- The inner two-pointer loop iterates at most `n` times.

Although the inner loop might not iterate `n` times in all cases, the overall complexity remains O(n^3) in the worst-case scenario.

## Space Complexity

The space complexity of the algorithm is **O(n)**, primarily due to the sorted copy of the input array and the `res` vector to 
store the result. In the worst case, the `res` vector can contain up to `n^4 / 4` quadruplets, but this is still considered O(n) in 
terms of space complexity.

**Key points to remember:**

- Sorting the array is crucial for the efficient two-pointer approach.
- Skipping duplicate elements helps to avoid redundant calculations and ensures unique quadruplets in the result.
- The two-pointer technique effectively explores all possible combinations of four elements.
- The time complexity is O(n^3) due to the nested loops.
- The space complexity is O(n) for the sorted array and the result vector.

*/
namespace FourSum
{
	class Solution 
	{
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target)
		{
			sort(nums.begin(), nums.end());
			vector<vector<int>> res;
			int i{}; // base Index
			int n = nums.size();

			while (i < n - 3)
			{
				while (i > 0 && nums[i] == nums[i - 1])
					i++;

				int j = i + 1;
				while (j < n - 2)
				{
					while (j > i + 1 && nums[j] == nums[j - 1])
						j++;

					int l = j + 1, r = n - 1;
					while (l < r)
					{
						auto sum = nums[i] + nums[j] + nums[l] + nums[r];
						if (sum == target)
						{
							res.push_back({ nums[i] , nums[j] , nums[l] , nums[r] });
							l++;
							while (l < r && nums[l] == nums[l - 1])
								l++;
							r--;
							while (l < r && nums[r] == nums[r + 1])
								r--;
						}
						else if (sum > target)
						{
							r--;
							while (l < r && nums[r] == nums[r + 1])
								r--;
						}
						else
						{
							l++;
							while (l < r && nums[l] == nums[l - 1])
								l++;
						}
					}
					j++;
				}
				i++;
			}
			return res;
		}
	};

	void process(){}
}