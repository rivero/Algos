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

Consider the following example:

```cpp
vector<int> nums1 = {1, 3, 5, 0, 0, 0};
vector<int> nums2 = {2, 4, 6};
```

**Initial State:**

```
nums1: [1, 3, 5, 0, 0, 0]
nums2: [2, 4, 6]
i = 2 (index of last element in nums1)
j = 2 (index of last element in nums2)
k = 5 (index of last position in nums1)
```

**Iteration 1:**

- Compare `nums1[i] = 5` and `nums2[j] = 6`.
- Since `5` is smaller, place `5` at `nums1[k]`.
- Decrement `i` and `k`.

```
nums1: [1, 3, 5, 0, 0, 5]
nums2: [2, 4, 6]
i = 1
j = 2
k = 4
```

**Iteration 2:**

- Compare `nums1[i] = 3` and `nums2[j] = 6`.
- Since `3` is smaller, place `3` at `nums1[k]`.
- Decrement `i` and `k`.

```
nums1: [1, 3, 5, 3, 0, 5]
nums2: [2, 4, 6]
i = 0
j = 2
k = 3
```

**Iteration 3:**

- Compare `nums1[i] = 1` and `nums2[j] = 6`.
- Since `1` is smaller, place `1` at `nums1[k]`.
- Decrement `i` and `k`.

```
nums1: [1, 3, 5, 3, 1, 5]
nums2: [2, 4, 6]
i = -1
j = 2
k = 2
```

**Iteration 4:**

- Since `i` is -1, all elements from `nums1` have been processed.
- Copy remaining elements from `nums2` to `nums1`.

```
nums1: [1, 2, 3, 4, 5, 6]
nums2: [2, 4, 6]
```

**Final State:**

```
nums1: [1, 2, 3, 4, 5, 6]
```

## Understanding Time and Space Complexity

### Time Complexity
Time complexity measures how the runtime of an algorithm grows as the input size increases. It's typically expressed using Big O 
notation.

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
