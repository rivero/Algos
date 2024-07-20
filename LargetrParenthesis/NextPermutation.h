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

			while (nums[nums_len] <= nums[pivot_index]) // look for the first number grater than the pivot FROM RIGHT TO LEFT
			{
				nums_len--;
			}
			// swap the numbers
			swap(nums[nums_len], nums[pivot_index]);
			// reverse from pivot to the end
			auto itbeg = nums.begin() + pivot_index + 1;
			reverse(itbeg,nums.end());



		}
	};

	void process()
	{
		{

			vector<int> vec
			{
				1,2,3
			};
			Solution sol;
			sol.nextPermutation(vec);
			printv(vec);
		}
		{

			vector<int> vec
			{
				1, 4, 5, 8, 7
			};
			Solution sol;
			sol.nextPermutation(vec);
			printv(vec);
		}
	}
}