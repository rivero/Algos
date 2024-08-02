#pragma once
/*
	Ref: https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
* 88. Merge Sorted Array
*	You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
	and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

	Merge nums1 and nums2 into a single array sorted in non-decreasing order.

	The final sorted array should not be returned by the function, but instead be stored
	inside the array nums1.

	To accommodate this, nums1 has a length of m + n,

	where the first m elements denote the elements that should be merged, and the last n elements
	are set to 0 and should be ignored. nums2 has a length of n.

	Example 1:

	Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
	Output: [1,2,2,3,5,6]
	Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
	The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
	Example 2:

	Input: nums1 = [1], m = 1, nums2 = [], n = 0
	Output: [1]
	Explanation: The arrays we are merging are [1] and [].
	The result of the merge is [1].
	Example 3:

	Input: nums1 = [0], m = 0, nums2 = [1], n = 1
	Output: [1]
	Explanation: The arrays we are merging are [] and [1].
	The result of the merge is [1].
	Note that because m = 0, there are no elements in nums1. The 0 is only there to
	ensure the merge result can fit in nums1.

	Constraints:

	nums1.length == m + n
	nums2.length == n
	0 <= m, n <= 200
	1 <= m + n <= 200
	-109 <= nums1[i], nums2[j] <= 109

	Solution
**Explanation:**
* 
* **Merges two sorted arrays into a single sorted array.**

- Overlaps `nums1` and `nums2` from the end.
- Compares elements from both arrays.
- Copies the larger element to the end of `nums1`.
- Repeats until `nums2` is empty.
- Remaining elements in `nums1` are already in correct position.


## Understanding the Merge Algorithm: An Example

**Problem:** Merge two sorted arrays, `nums1` and `nums2`, into `nums1`.

**Approach:**
* Start from the end of both arrays.
* Compare elements from `nums1` and `nums2`.
* Place the larger element at the end of `nums1`.
* Decrement the corresponding index.
* Repeat until `nums2` is empty.

**Example:**

nums1   1       2       3       0       0       0
nums2   2       5       6

1       2       3       0       0       6

1       2       3       0       5       6

1       2       3       3       5       6

1       2       2       3       5       6
1       2       2       3       5       6


**Explanation:**
* The algorithm starts from the end of both arrays.
* It compares the last elements of `nums1` and `nums2` (3 and 6).
* Since 6 is larger, it's placed at the end of `nums1`, and `j` is decremented.
* This process continues until `nums2` is empty.
* The remaining elements in `nums1` are already sorted, so no further operations are needed.

This efficient approach merges two sorted arrays in-place while maintaining the sorted order.

**Would you like to see another example?**

## Understanding Time and Space Complexity

### Time Complexity

**For the optimized merge function:**
* **Time complexity: O(m + n)**
  - The algorithm iterates through both `nums1` (length m) and `nums2` (length n) exactly once.
  - The total number of operations is directly proportional to the sum of the lengths of the two input arrays.

### Space Complexity
Space complexity measures the amount of additional memory an algorithm uses relative to the input size.

**For the optimized merge function:**
* **Space complexity: O(1)**
  - The algorithm only uses a constant amount of extra space for the three integer variables `i`, `j`, and `k`.
  - The space used doesn't grow with the input size.



*/
namespace MergeSortedArray
{
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		for (size_t i = 0; i < nums2.size(); i++)
		{
			nums1[m++] = nums2[i];
		}
		sort(nums1.begin(), nums1.end());
	}
	void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		for_each(nums2.begin(), nums2.end(), [&](int x) { nums1[m++] = x; });
		sort(nums1.begin(), nums1.end());
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		cout << "nums1\t";
		printv(nums1);
		cout << "nums2\t";
		printv(nums2);
		int i = m - 1, j = n - 1, k = m + n - 1;

		while (j >= 0)
		{
			if (i >= 0 && nums1[i] > nums2[j])
			{
				nums1[k] = nums1[i];
				i--;
			}
			else
			{
				nums1[k] = nums2[j];
				j--;
			}
			k--;
			cout << "\n";

			printv(nums1);
		}
	}
	void process()
	{
		vector<int> nums1{ 1,2,3,0,0,0 };
		vector<int> nums2{ 2,5,6 };

		merge(nums1, 3, nums2, 3);
		printv(nums1);
	}
}
