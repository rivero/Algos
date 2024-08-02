#pragma once
/*
* https://leetcode.com/problems/3sum/description/
* https://www.youtube.com/watch?v=8IjCNFIo8YI  with prefix
* https://www.youtube.com/watch?v=wTZC9jFZpSI this solution
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

Time Complexity
Sorting: O(n log n) using a typical sorting algorithm like quicksort or merge sort.
Iterating and finding triplets: O(n^2) in the worst case, as the outer loop iterates through n elements, 
and the inner two-pointer loop iterates through n elements for each outer loop iteration.
Overall time complexity: O(n^2) due to the nested loops.

Space Complexity
O(n) for sorting the input array (in-place sorting algorithms like quicksort have O(1) extra space).
O(n) for the res vector to store the result triplets.
Overall space complexity: O(n).

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
			int i{}; // base Index
			while (i < nums.size() - 2) // to accommodate l and r
			{
				// remove dupes in i
				while (i > 0 && nums[i] == nums[i - 1] && i < nums.size() - 1)
					i++;

				int l = i + 1, r = nums.size() - 1;
				while (l < r)
				{
					auto cur_sum = nums[i] + nums[l] + nums[r];
					if (cur_sum == target)
					{
						res.push_back({ nums[i] , nums[l] , nums[r] });
						// shrink window to avoid l and r
						l++;
						while (nums[l] == nums[l - 1] && l < r)
							// remove dupes in l
							l++;
						r--;
						while (nums[r] == nums[r + 1] && l < r)
							// remove dupes in r
							r--;
					}
					else if (cur_sum > target)
					{
						r--;
						while (nums[r] == nums[r + 1] && l < r)
							r--;
					}
					else
					{
						l++;
						while (nums[l] == nums[l - 1] && l < r)
							l++;
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