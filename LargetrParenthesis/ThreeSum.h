#pragma once
/*
15. 3Sum
Given an integer array nums, return all the triplets 
[nums[i], nums[j], nums[k]] 
such that 
i != j, i != k, and j != k, 
and 
nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5


1. **Sorting**: The function starts by sorting the input array `nums` in ascending order. 
Sorting is essential for efficient triplet detection.

2. **Iterating through `i`**: The outer loop iterates through the array indices from 0 to `nums.size() - 2`. 
This ensures that there's enough room for the two other indices (`j` and `k`) to form a triplet.

3. **Duplicate Handling**: Inside the outer loop, there's a check to skip duplicate values of `nums[i]`. 
If `nums[i]` is the same as the previous value, the loop increments `i` until it finds a distinct value.

4. **Two-Pointer Approach (`j` and `k`)**: Within the outer loop, two pointers (`j` and `k`) are used to
explore the remaining part of the array. These pointers start at the next index after `i` and the last index, respectively.

5. **Triplet Sum Comparison**: The algorithm calculates the sum `cur_sum` of `nums[i]`, `nums[j]`, 
and `nums[k]`. Depending on whether `cur_sum` is equal to, greater than, or less than the target value:

	- If `cur_sum` equals the target, a valid triplet is found, and it's added to the result vector `res`.
	- If `cur_sum` is greater than the target, decrement `k`.
	- If `cur_sum` is less than the target, increment `j`.

6. **Updating Pointers**: After each comparison, the algorithm adjusts the pointers `j` and `k` to avoid duplicates. 
If the values are the same as their previous counterparts, the pointers continue moving until they reach distinct values.

7. **Increment `i`**: Finally, the outer loop increments `i` to move to the next unique value.

**Time Complexity**:
- The sorting step takes O(n log n) time.
- The nested loops (two-pointer approach) iterate through the array, resulting in O(n^2) operations.
- Combining both, the overall time complexity of the `threeSum` algorithm is O(n^2).

*/
namespace ThreeSum
{
	class Solution 
	{
	public:
		vector<vector<int>> threeSum(vector<int>& nums, int target = 0) 
		{
			sort(nums.begin(), nums.end());
			vector<vector<int>> res;
			int i{};

			while (i < nums.size() - 2) // to have room for j and k
			{
				// remove dupes: is our current nums[i] equal to our last one?
				while (i > 0 && nums[i] == nums[i - 1] && i < nums.size() -1)
					i++;

				auto j = i + 1;
				auto k = nums.size() - 1;

				while (j < k)
				{
					auto cur_sum = nums[i] + nums[j] + nums[k];

					if (cur_sum == target)
					{
						res.push_back({ nums[i] , nums[j] , nums[k] });
						
						j++;
						while (nums[j] == nums[j - 1] && j < k)
							j++;

						k--;
						while (nums[k] == nums[k + 1] && k >= j)
							k--;
					}
					else if (cur_sum > target)
					{
						k--;
						while (nums[k] == nums[k + 1] && k >= j)
							k--;
					}
					else
					{
						j++;
						while (nums[j] == nums[j - 1] && j < k)
							j++;
					}
				}
				i++;
			}
			return res;
		}
	};
	void process()
	{
		cout << "ThreeSum\n";
		{
			Solution sol;
			/*Example 1:
			Input: nums = [-1,0,1,2,-1,-4]
			Output: [[-1,-1,2],[-1,0,1]]
			*/
			vector<int> nums
			{
				-1,0,1,2,-1,-4
			};
			printv(nums);
			int target = 0;
			auto res = sol.threeSum(nums, target);
			cout << "\n";
			for (auto& el: res)
			{
				printv(el);
			}
			cout << "\n";
			cout << "\n";
		}
		{
			Solution sol;
			/*Example 2:
			Input: nums = [0,1,1]
			Output: []
			Explanation: The only possible triplet does not sum up to 0.
			*/
			vector<int> nums
			{
				0,1,1
			};
			printv(nums);
			int target = 0;
			auto res = sol.threeSum(nums, target);
			cout << "\n";
			for (auto& el : res)
			{
				printv(el);
			}
			cout << "\n";
			cout << "\n";
		}
		{
			Solution sol;
			/*Example 3:
			Input: nums = [0,0,0]
			Output: [[0,0,0]]
			Explanation: The only possible triplet sums up to 0.
			*/
			vector<int> nums
			{
				0,0,0
			};
			printv(nums);
			int target = 0;
			auto res = sol.threeSum(nums, target);
			cout << "\n";
			for (auto& el : res)
			{
				printv(el);
			}
			cout << "\n";
			cout << "\n";
		}
	}
}