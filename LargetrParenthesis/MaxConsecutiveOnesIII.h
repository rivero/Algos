#pragma once
/*
https://leetcode.com/problems/max-consecutive-ones-iii
1004. Max  Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array 
if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length

## Understanding the Algorithm: Maximum Consecutive Ones III

### Problem Statement
Given a binary array `nums` (containing only 0s and 1s) and an integer `k`, the algorithm finds the maximum number of consecutive 1s in the array if you can flip at most `k` 0s to 1s.

### Algorithm Breakdown
This algorithm employs a sliding window technique to efficiently solve the problem.

* **Initialization:**
  * `left` and `right` pointers are initialized to 0, representing the start and end of the sliding window.
* **Sliding Window:**
  * The algorithm iterates over the array using the `right` pointer.
	* If the current element `nums[right]` is 1, it's a good element, so we can extend the window without affecting `k`.
	* If the current element `nums[right]` is 0, we decrement `k`. This signifies using one of the allowed flips to convert the 0 
	to 1.
	* If `k` becomes negative, it means we have exceeded the allowed number of flips for the current window. To maintain the 
	invariant, we need to shrink the window from the left.
	  * If the element at `left` is 0, we increment `k` back as we are effectively undoing a previous flip.
	  * We increment `left` to reduce the window size.
  * The `right` pointer is always incremented to expand the window.
* **Return Value:**
  * The final answer is the maximum size of the valid window, which is `right - left`.

### Key Idea
The algorithm maintains an expanding, sliding window where the number of zeros within the window is at most `k`. It expands the window as 
long as the number of zeros is within the limit. When the limit is exceeded, it shrinks the window from the left while adjusting 
the `k` value accordingly.

### Time and Space Complexity
* **Time complexity:** O(n), where n is the length of the input array.
* **Space complexity:** O(1), as the algorithm uses constant extra space.

### Example
## Understanding the Algorithm

**Key Idea:**

* Maintain a sliding window where the number of zeros within the window is less than or equal to `k`.
* Expand the window to the right as long as the number of zeros is less than or equal to `k`.
* If the number of zeros exceeds `k`, contract the window from the left by removing elements until the number of zeros becomes 
less than or equal to `k` again.

**Example:**

Consider the array `nums = [1,1,1,0,0,1,1,1,1,0,1,1,1,0]` and `k = 2`.

* Initially, `left = 0`, `right = 0`, and `k = 2`.
* The window expands to include `[1,1,1,0]`.
* The next element is `0`, so `k` decrements to 1.
* The window expands to include `[1,1,1,0,0]`.
* Now, `k` is 0, so we need to shrink the window.
* The leftmost element is `1`, so the window becomes `[1,1,0,0,1]`.
* The window continues to expand, and the maximum length is found when the right pointer reaches the end of the array.

* `left` and `right` are pointers defining the sliding window.
* `k` keeps track of the remaining allowed zeros.
* The loop iterates through the array, expanding the window as long as `k` is non-negative.
* When `k` becomes negative, it means there are too many zeros in the window, so the left pointer is moved to shrink the window.
* The maximum length of the valid window is returned.

*/
namespace MaxConsecutiveOnesIII
{
	class Solution 
	{
	public:
		// The algorithm maintains a sliding window where the number of zeros within the window is at most `k`
		// if we have at most k zeroses we can flip k of them to 1.
		int longestOnes(vector<int>& nums, int k)
		{
			int left = 0, right = 0;

			while (right < nums.size())
			{
				if (nums[right] == 0)
				{
					k--;
				}
				if (k < 0)
				{
					if (nums[left] == 0) // if the current left element is 0...
					{
						k++; // ...we increment `k` back as we are effectively undoing a previous flip
					}
					left++; // reduce window
				}
				right++; // extend window
			}
			return right - left;
		}
	};
	void process(){}
}
