#pragma once
/*
https://leetcode.com/problems/insert-interval/
57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and 
intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.



Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

3 cases:
insert at start push
insert at end : push-back
insert in the middle

## Understanding the Algorithm: Merging Overlapping Intervals

**Problem:** Insert a new interval into a list of non-overlapping intervals, merging if necessary.

**Algorithm Breakdown:**

1. **Initialization:**
   * `result` vector to store the merged intervals.
   * `i` as an index to iterate through the `intervals` vector.

2. **Add non-overlapping intervals before newInterval:**
   * Iterate through `intervals` until an interval overlaps with `newInterval`.
   * Add non-overlapping intervals to `result`.

3. **Merge overlapping intervals:**
   * While the current interval overlaps with `newInterval`:
	 * Update `newInterval`'s start and end to encompass the current interval.
	 * Increment `i` to move to the next interval.
   * Add the merged `newInterval` to the `result`.

4. **Add remaining intervals:**
   * Add the remaining intervals (if any) to the `result`.

**Key points:**

* The condition `intervals[i][1] < newInterval[0]` checks if the current interval ends before the new interval starts, indicating 
no overlap.
* The condition `intervals[i][0] <= newInterval[1]` checks if the current interval starts before the new interval ends, indicating
a potential overlap.
* By updating `newInterval[0]` and `newInterval[1]` with the minimum and maximum start and end times of overlapping intervals, we 
effectively merge them into a single interval.

**Time Complexity:** O(n), where n is the number of intervals.
**Space Complexity:** O(n) for the `result` vector.

**Example:**

```
intervals = [[1,3],[6,9]], newInterval = [2,5]
```

* The first interval [1, 3] is added to `result`.
* The second interval [6, 9] is added to `result`.
* The new interval [2, 5] overlaps with the previous intervals, so they are merged into [1, 5].

**Result:** [[1, 5], [6, 9]]

## Complexity Analysis

### Time Complexity: O(n)
* The algorithm iterates through the `intervals` array at most twice: once to find the insertion point for the `newInterval` and once to copy the remaining intervals.
* Each iteration involves constant time operations (comparisons, array access, vector push_back).
* Therefore, the overall time complexity is linear with respect to the number of intervals (n).

### Space Complexity: O(n)
* The `result` vector can potentially store all intervals, leading to a space complexity of O(n) in the worst case.

*/
namespace InsertInterval
{
	class Solution
	{
	public:
		vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
		{
			vector<vector<int>> result;
			int n = intervals.size();
			int i = 0;

			// Add non-overlapping intervals before newInterval
			while (i < n && intervals[i][1] < newInterval[0])
				result.push_back(intervals[i++]);

			// Merge overlapping intervals
			while (i < n && intervals[i][0] <= newInterval[1])
			{
				newInterval[0] = min(newInterval[0], intervals[i][0]);
				newInterval[1] = max(newInterval[1], intervals[i][1]);
				i++;
			}
			result.push_back(newInterval);

			// Add remaining intervals after newInterval
			while (i < n)
				result.push_back(intervals[i++]);

			return result;
		}
	};

	void process()
	{
		Solution sol;
		vector<vector<int>> intervals
		{
			{1,2} ,
			{3,5},
			{6,7},
			{8,10},
			{12,16}
		};
		vector<int> newInterval{4,8};
		auto res = sol.insert(intervals, newInterval);
		for (auto interval : res)
		{
			printv(interval);
		}
	}
}