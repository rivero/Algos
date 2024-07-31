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

## Understanding the Next Permutation Algorithm

### Core Idea

The next permutation of a number sequence is the lexicographically next greater permutation. 
To find this, we identify a decreasing suffix in the sequence and then rearrange the sequence to find the next larger permutation.

Locate the breakpoint
Is where the sequence starts decreasing from right to left

**This breakpoint is crucial because:**

* It indicates that the elements to the right of the breakpoint are in descending order.
* To find the next permutation, we need to modify the elements to the right of the breakpoint 
while keeping the left part unchanged.

### Elaboration

Let's break down the process further:

1. **Finding the Breakpoint:**
   * Iterate through the array from right to left.
   * The first element that is smaller than its next element is the breakpoint.

2. **Finding the Successor:**
   * Find the smallest element in the suffix (elements to the right of the breakpoint) that is greater than the element at 
   the breakpoint. This element is called the successor.

3. **Swapping:**
   * Swap the element at the breakpoint with the successor.

4. **Reversing the Suffix:**
   * Reverse the elements to the right of the breakpoint to form the smallest possible permutation with the swapped elements.

**Example:**

Consider the array `[1, 2, 3, 4, 5, 8, 7]`.

* Breakpoint: Index 4 (where 5 is less than 8)
* Successor: 7
* Swap 5 and 7: `[1, 2, 3, 7, 5, 8, 4]`
* Reverse the suffix: `[1, 2, 3, 7, 4, 5, 8]`

This is the next permutation of the given array.

* Understanding the breakpoint and successor is crucial for the process.
* Reversing the suffix ensures the smallest possible increase in the permutation.


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
			int pivot{-1};

			// iterate from the RIGHT to find the pivot
			auto n = nums.size() - 1;
			for (int i = n; i > -1; i--)
			{
				if (nums[i] > nums[i-1])
				{
					pivot = i - 1;
					break;
				}
			}

			if (pivot == -1) // no element pivot was found
			{
				reverse(nums.begin(), nums.end());
				return;
			}

			while (nums[n] <= nums[pivot]) // Find the first element greater than the pivot element FROM RIGHT TO LEFT
			{
				n--;
			}
			// swap the numbers
			swap(nums[n], nums[pivot]);
			// reverse from pivot to the end
			reverse(nums.begin() + pivot + 1,nums.end());
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