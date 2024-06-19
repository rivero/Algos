#pragma once
namespace FindPeakElement
{
	/*
	*
	162. Find Peak Element

	A peak element is an element that is strictly greater than its neighbors.

	Given a 0-indexed integer array nums, find a peak element, and return its index. 
	If the array contains multiple peaks, return the index to any of the peaks.

	You may imagine that nums[-1] = nums[n] = -∞. 
	In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

	You must write an algorithm that runs in O(log n) time.

	Example 1:
	Input: nums = [1,2,3,1]
	Output: 2
	Explanation: 3 is a peak element and your function should return the index number 2.

	Example 2:
	Input: nums = [1,2,1,3,5,6,4]
	Output: 5
	Explanation: Your function can return either index number 1 where the peak element is 2, 
	or index number 5 where the peak element is 6.
	Constraints:

	1 <= nums.length <= 1000
	-2^31 <= nums[i] <= 2^31 - 1
	nums[i] != nums[i + 1] for all valid i.

	Binary search  has complexity of O(log n) BUT the input is not sorted!!
	sUse 2 pointers: l and r
	Choose the mid and check if it is either larger or smaller than the right and left neightbout 
	to see if we are increasing or decreasing.

	Edge case
	the last or first elements are peak but because anything outside the array is -∞ then they are peak

	Complexity of this solution: T O(log n)
	*/


	class SolutionNOPE 
	{
		// from: https://www.youtube.com/watch?v=tQpg6kcSAoY
	public:
		int findPeakElement(vector<int> nums) 
		{
			auto size = nums.size();
			if (size == 0)
			{
				return {};
			}
			if (size == 1)
			{
				return 0;
			}
			if (size == 2)
			{
				return (nums[0] > nums[1]) ? 0 : 1;
			}
			size_t l{}, r{size -1};

			while (l <= r) // less than equal because there will be a peak no worries about not finding it.
			{
				if (l >= size || r >= size)
				{
					return {};
				}
				auto mid = (l+r) / 2;
				auto mid_val = nums[mid];

				auto left = mid > 0 ? nums[mid - 1] : INT_MIN;
				auto right = mid < size - 1 ? nums[mid + 1] : INT_MIN;

				if ((left < mid_val) && (mid_val > right))
				{
					return mid;
				}
				else if ((left < mid_val) && (mid_val < right)) // example 1 3 5 where 3 is mid
					l++;
				else
					r++;

			}
			return {};
		}
	};

	struct Solution 
	{
		int findPeakElement(vector<int> nums) 
		{
			int n = nums.size();
			if (n <= 1)
				return 0;
			
			for (int i = 0; i < n; i++) 
			{
				if (i == 0 && nums[i] > nums[i + 1]) 
					return i;
				else if (i == n - 1 && nums[i] > nums[i - 1]) 
					return i;
				else if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) 
					return i;
			}
			return {};
		}
	};
	void process()
	{
		Solution sol;
		cout << sol.findPeakElement({ 1,2,3,1 }) << "\n";
		cout << sol.findPeakElement({ 1,2,1,3,5,6,4 }) << "\n";
		cout << sol.findPeakElement({ 3,2,1 }) << "\n";
		cout << sol.findPeakElement({ INT_MIN, INT_MIN+1 }) << "\n";
		cout << sol.findPeakElement({ 3,5,4,3,4,5,7 }) << "\n";
	}
}