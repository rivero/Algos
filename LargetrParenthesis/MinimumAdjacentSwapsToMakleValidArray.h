#pragma once
namespace MinimumAdjacentSwapsToMakleValidArray
{
	/*
	* https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/description/
	
	2340. Minimum Adjacent Swaps to Make a Valid Array
	You are given a 0-indexed integer array nums.

	Swaps of adjacent elements are able to be performed on nums.

	A valid array meets the following conditions:

	The largest element (any of the largest elements if there are multiple)
	is at the rightmost position in the array.
	The smallest element (any of the smallest elements if there are multiple)
	is at the leftmost position in the array.
	Return the minimum swaps required to make nums a valid array.



	Example 1:

	Input: nums = [3,4,5,5,3,1]
	Output: 6
	Explanation: Perform the following swaps:
	- Swap 1: Swap the 3rd and 4th elements, nums is then [3,4,5,3,5,1].
	- Swap 2: Swap the 4th and 5th elements, nums is then [3,4,5,3,1,5].
	- Swap 3: Swap the 3rd and 4th elements, nums is then [3,4,5,1,3,5].
	- Swap 4: Swap the 2nd and 3rd elements, nums is then [3,4,1,5,3,5].
	- Swap 5: Swap the 1st and 2nd elements, nums is then [3,1,4,5,3,5].
	- Swap 6: Swap the 0th and 1st elements, nums is then [1,3,4,5,3,5].
	It can be shown that 6 swaps is the minimum swaps required to make a valid array.
	Example 2:
	Input: nums = [9]
	Output: 0
	Explanation: The array is already valid, so we return 0.


	Constraints:

	1 <= nums.length <= 105
	1 <= nums[i] <= 105


	Notice that in order to obtain the minimum swaps, we should focus on the 
	smallest element that is the leftmost and the largest element that is the rightmost.

	We can take those elements and greedily only do swaps that bring them closer to their 
	respective end positions.

	Solution
	Using hints
	E = end, B = beginning
	Compare B vs E and swap if needed.


	Original = [3,4,5,5,3,1]

	- Swap 1:  [1,4,5,3,5,3].
	- Swap 2:  [3,4,5,3,1,5].
	- Swap 3:  [3,4,5,1,3,5].
	- Swap 4:  [3,4,1,5,3,5].
	- Swap 5:  [3,1,4,5,3,5].
	- Swap 6:  [1,3,4,5,3,5].

	Solution

	find index of both the leftmost minimum and the rightmost maximum
	Calculate the size = the sum of index min + index Max

	*/
	class Solution 
	{
	public:
		int minimumSwaps(vector<int> nums) 
		{
			int n = nums.size();
			int min = INT_MAX;
			int max = -INT_MAX;
			
			int indexMin = 0;
			int indexMax = n - 1;
			
			for (int i = 0; i < n; ++i) 
			{
				if (min > nums[i]) 
				{
					min = nums[i];
					indexMin = i;
				}
				if (max < nums[n - i - 1]) 
				{
					max = nums[n - i - 1];
					indexMax = n - i - 1;
				}
			}
			int ans = (n - 1) - indexMax + indexMin;
			return indexMin > indexMax ? ans - 1 : ans;
			
		}
	};

	void process()
	{
		Solution sol;
		cout << sol.minimumSwaps({ 3,4,5,5,3,1 }) << "\n";
		cout << sol.minimumSwaps({ 9 }) << "\n";
	}
}