#pragma once
/*
*
https://leetcode.com/problems/find-peak-element/
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

Solution O(log n)

1. **Problem Statement**:
   - Given an array `nums`, find a peak element.
   - A peak element is an element that is greater than or equal to its neighbors.

2. **Approach**:
   - We'll use a binary search approach to find the peak element efficiently.
   - The key observation is that if we compare the middle element (`mid`) with its neighbors, we can determine
   whether the peak lies to the left or right of `mid`.

3. **Algorithm Steps**:
   - Initialize two pointers: `Left` and `Right` to cover the entire array.
   - While `Left` is less than or equal to `Right`:
	 - Calculate the middle index: `mid = (Left + Right) / 2`.
	 - Get the values of `mid`, `mid - 1`, and `mid + 1` (if they exist).
	 - Compare these values:
	   - If `mid_val` is greater than both `left_val` and `right_val`, we've found a peak, so return `mid`.
	   - If `mid_val` is greater than `left_val` but less than `right_val`, the peak lies to the right. Set `Left = mid + 1`.
	   - Otherwise, the peak lies to the left. Set `Right = mid - 1`.

4. **Edge Cases**:
   - If the array has only one or zero elements, return the first index (since it's a peak by default).
   - Check if the first or last element is a peak.

5. **Time Complexity**:
   - The binary search runs in O(log n) time, where `n` is the size of the input array.

6. **Space Complexity**:
   - The algorithm uses only a few variables, so the space complexity is O(1).

   ## Why `l <= r` in Binary Search

**The condition `l <= r` ensures that the binary search loop terminates correctly.**

### Understanding the Logic:

* **Binary search** works by repeatedly dividing a sorted array into two halves.
* The `l` and `r` pointers represent the left and right boundaries of the search space, respectively.
* The condition `l <= r` guarantees that there is at least one element in the search space to consider.

### Consequences of using `l < r`:

* If you use `l < r`, the loop might terminate prematurely when there's only one element left in the search space.
* This can lead to incorrect results in certain cases, especially when the target element is the last element in the array.

### Example:
Consider an array `[1, 2, 3]` and you're searching for the element `3`.

* If you use `l < r`, the loop might terminate when `l` becomes equal to `r`, and you might miss the target element.

By using `l <= r`, you ensure that the loop continues until `l` becomes greater than `r`, guaranteeing that all elements in the array are considered.

**In conclusion:**
The `l <= r` condition is essential for the correct functioning of the binary search algorithm, preventing premature termination and ensuring that all possible elements are considered.



*/
namespace FindPeakElement
{

	struct SolutionBruteForce 
	{
		int findPeakElement(vector<int> nums) 
		{
			int n = nums.size();
			if (n <= 1)
				return 0;
			
			// Test first element: Test if first element is greater than second element
			if (nums[0] > nums[1])
				return 0;
			// Test last element: test of the last element is bigger than the previous
			else if (nums[n - 1] > nums[n - 1 - 1])
				return n - 1;

			for (int i = 1; i < n - 1; i++)
			{
				// Otherwise test if the current element is larger than the previous and larger than the next elements
				if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) 
					return i;
			}
			return {};
		}
	};
	class Solution
	{
	public:
		int findPeakElement(vector<int> nums)
		{
			int n = nums.size();
			if (n <= 1) return 0;

			if (nums[0] > nums[1])
				return 0; // first element is a peak
			if (nums[n - 1] > nums[n - 2]) // last element is a peak
				return n - 1;

			size_t l = 1, r = n - 2; // no need to test first and last elements
			while (l <= r)
			{
				auto m = l + (r - l) / 2;
				auto lv = m > 0 ? nums[m - 1] : INT_MIN;
				auto rv = m < n - 1 ? nums[m + 1] : INT_MIN;
				auto mv = nums[m];
				if (lv < mv && mv > rv)
					return m;
				else if (lv < mv && mv < rv)
					l = m + 1; // peak is at the right
				else
					r = m - 1; // peak is at the left
			}
			return {};
		}
	};
	void process()
	{
		{
			Solution sol;
			cout << sol.findPeakElement({ 1,2,3,1 }) << "\n";
			cout << sol.findPeakElement({ 1,2,1,3,5,6,4 }) << "\n";
			cout << sol.findPeakElement({ 3,2,1 }) << "\n";
			cout << sol.findPeakElement({ INT_MIN, INT_MIN + 1 }) << "\n";
			cout << sol.findPeakElement({ 3,5,4,3,4,5,7 }) << "\n";

		}
		{
			cout << "CF\n";
			SolutionBruteForce sol;
			cout << sol.findPeakElement({ 1,2,3,1 }) << "\n";
			cout << sol.findPeakElement({ 1,2,1,3,5,6,4 }) << "\n";
			cout << sol.findPeakElement({ 3,2,1 }) << "\n";
			cout << sol.findPeakElement({ INT_MIN, INT_MIN + 1 }) << "\n";
			cout << sol.findPeakElement({ 3,5,4,3,4,5,7 }) << "\n";

		}

	}
}