#pragma once
/*
*

56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4

Solution

The provided C++ code efficiently merges overlapping intervals using the following approach:

1. Sort the input intervals based on their start values.
2. Initialize an empty vector `ans` to store the merged intervals.
3. Iterate through the sorted intervals:
   - If the current interval's start value is greater than the end value of the last interval in `ans`, add it to `ans`.
   - Otherwise, merge the current interval with the last interval in `ans` by updating the end value.
4. Return the merged intervals stored in `ans`.

**Time Complexity:**
- Sorting the intervals takes O(n log n) time.
- Merging the intervals in a single pass takes O(n) time.
- Overall, the time complexity is O(n log n).

**Space Complexity:**
- The additional space used for storing the merged intervals is O(n).
- Hence, the space complexity is O(n).

This algorithm efficiently handles overlapping intervals and provides the desired non-overlapping intervals.


*/
namespace MergeIntervals
{
	class Solution {
	public:
		vector<vector<int>> merge(vector<vector<int>>& arr) 
		{
			sort(arr.begin(), arr.end());
			int n = arr.size();

			vector<vector<int>> ans;
			ans.push_back(arr[0]);
			for (int i = 1; i < n; i++) 
			{
				auto nextFirstElement = arr[i][0];
				auto nextSecondElement = arr[i][1];
				auto previousSecondElement = ans.back()[1];
				if (nextFirstElement > previousSecondElement)
				{
					ans.push_back(arr[i]);
				}
				else 
				{
					ans.back()[1] = max(previousSecondElement, nextSecondElement);
				}
			}

			return ans;
		}
	};
	void process()
	{
		Solution sol;
		vector<vector<int>> vec =
		{
			{1,3  },
			{8,10 },
			{2,6  },
			{15,18}
		};
		auto res = sol.merge(vec);
		for (auto el: res)
		{
			printv(el);
		}
	}
}