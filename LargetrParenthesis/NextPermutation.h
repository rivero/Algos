#pragma once
/*
https://leetcode.com/problems/next-permutation

31. Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
then the next permutation of that array is the permutation that follows it in the sorted container.

If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example,
for arr = [1,2,3], the following are all the permutations of arr: 
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
	-> the next permutation of arr = [1,2,3] is [1,3,2].

Similarly, the next permutation of arr = [2,3,1] is [3,1,2].

While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100

Solution

Find the pivot FROM RIGHT TO LEFT
pivot is the index where the elements are no longer increasing FROM RIGHT TO LEFT

if the pivot is not found, the numbers are increasing FROM LEFT TO RIGHT.
reverse and return

If the pivot index is found, look for the next element that is smaller FROM RIGHT TO LEFT
at that index, reverse the vector.

1. **Problem Description**:
	- Given an array of integers, we want to find the next lexicographically greater permutation of the array.
	- If such an arrangement is not possible, we need to rearrange the array to the lowest possible order (sorted in ascending order).

2. **Solution Explanation**:
	- The provided solution aims to find the next permutation by following these steps:
		1. **Find the Pivot**:
			- Iterate from **right to left** through the array to find the pivot index.
			- The pivot index is the first element that is smaller than the element to its right (i.e., `nums[i] > nums[i-1]`).
		2. **No Pivot Found**:
			- If no pivot element is found (i.e., the array is sorted in descending order), reverse the entire array to get the lowest possible order.
		3. **Find the Next Greater Element**:
			- Starting from the right end of the array, find the first element greater than the pivot element.
			- Swap this element with the pivot element.
		4. **Reverse the Remaining Elements**:
			- Reverse the subarray from the pivot index + 1 to the end of the array.
			- This ensures that the remaining elements are in ascending order.
		5. **Result**:
			- The modified array represents the next lexicographically greater permutation.

3. **Complexities**:
	- Time Complexity: The solution iterates through the array twice (finding the pivot and reversing the subarray), 
	which results in linear time complexity: O(n).
	- Space Complexity: The solution uses only a constant amount of extra space, so the space complexity is O(1).

*/
namespace NextPermutation
{
	class Solution
	{
	public:
		void nextPermutation(vector<int>& nums)
		{
			int pivot_index{-1};

			// iterate from the RIGHT to find the pivot
			auto nums_len = nums.size() - 1;
			for (int i = nums_len; i >= 0; i--)
			{
				if (nums[i] > nums[i-1])
				{
					pivot_index = i - 1;
					break;
				}
			}

			if (pivot_index == -1) // no element pivot was found
			{
				reverse(nums.begin(), nums.end());
				return;
			}

			while (nums[nums_len] <= nums[pivot_index]) // Find the first element greater than the pivot element FROM RIGHT TO LEFT
			{
				nums_len--;
			}
			// swap the numbers
			swap(nums[nums_len], nums[pivot_index]);
			// reverse from pivot to the end
			reverse(nums.begin() + pivot_index + 1,nums.end());
		}
	};

	void process()
	{
		{

			vector<int> vec
			{
				1,1,5
			};
			cout << "begin\n";
			printv(vec);
			Solution sol;
			sol.nextPermutation(vec);
			cout << "end\n";
			printv(vec);
		}
		{

			vector<int> vec
			{
				1,2,3
			};
			cout << "begin\n";
			printv(vec);
			Solution sol;
			sol.nextPermutation(vec);
			cout << "end\n";
			printv(vec);
		}
		{

			vector<int> vec
			{
				1, 4, 5, 8, 7
			};
			cout << "begin\n";
			printv(vec);
			Solution sol;
			sol.nextPermutation(vec);
			cout << "end\n";
			printv(vec);
		}
	}
}