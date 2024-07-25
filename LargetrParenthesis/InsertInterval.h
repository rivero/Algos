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

Certainly! Let's dive into the algorithm and discuss its complexities:

1. **Algorithm Explanation**:
	- The given algorithm inserts a new interval (`newInterval`) into a sorted vector of intervals (`intervals`).
	- It handles both overlapping and non-overlapping intervals.
	- The algorithm iterates through the existing intervals and merges overlapping intervals with `newInterval`.
	- The result is a vector of intervals that covers the combined range.

2. **Step-by-Step Explanation**:
	- **Non-Overlapping Intervals**:
		- The algorithm starts by adding non-overlapping intervals (those before `newInterval`) directly to the result vector.
		- It compares the end of each existing interval with the start of `newInterval`.
		- If the end of an interval is less than the start of `newInterval`, they don't overlap, so we add that interval to 
		the result.
	- **Merging Overlapping Intervals**:
		- While iterating through the existing intervals, if an interval overlaps with `newInterval`, we update `newInterval` 
		to cover both intervals.
		- We adjust the start and end of `newInterval` to include the maximum range.
	- **Remaining Intervals**:
		- After merging, we add the updated `newInterval` to the result.
		- Finally, we add any remaining intervals (those after `newInterval`) to the result.

3. **Time Complexity**:
	- The time complexity of this algorithm is O(N), where N is the number of existing intervals.
	- We iterate through the existing intervals once to find the correct position for `newInterval`.
	- The merging step also takes linear time.

4. **Space Complexity**:
	- The space complexity is O(N) because the result vector stores the merged intervals.
	- The algorithm modifies the input vector in-place, so no additional space is used.

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