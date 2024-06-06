#pragma once
namespace IntervalListIntersections
{
	/*
	https://leetcode.com/problems/interval-list-intersections/description/

	986. Interval List Intersections

	You are given two lists of closed intervals, firstList and secondList, 
	where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 

	Each list of intervals is pairwise disjoint and in sorted order.

	Return the intersection of these two interval lists.

	A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

	The intersection of two closed intervals is a set of real numbers that 
	are either empty or represented as a closed interval. 
	
	For example, the intersection of [1, 3] and [2, 4] is [2, 3].

	Example 1:

	Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
	Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
	Example 2:

	Input: firstList = [[1,3],[5,9]], secondList = []
	Output: []


	Constraints:

	0 <= firstList.length, secondList.length <= 1000
	firstList.length + secondList.length >= 1
	
	0 <= starti < endi <= 10^9
	endi < starti+1

	0 <= startj < endj <= 10^9
	endj < startj+1

	*/
	
	class Solution 
	{
	public:
		vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
		{

			vector<vector<int>> res;
			for (int i = 0, j = 0; i < A.size() && j < B.size();) 
			{
				auto alow = A[i][0];
				auto blow = B[j][0];
				auto ahigh = A[i][1];
				auto bhigh = B[j][1];
				int lo = max(alow, blow), 
					hi = min(ahigh, bhigh);

				if (lo <= hi) 
					res.push_back({ lo, hi });
				
				if (hi == ahigh) 
					i++;
				else 
					j++;
			}
			return res;
		}
	};
	void process()
	{
		/*
		firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
		*/
		vector<vector<int>> A
		{
			{0,2} ,{5,10},{13,23},{24,25}
		};
		vector<vector<int>> B
		{
			{1,5} ,{8,12},{15,24},{25,26}
		};
		Solution sol;
		auto res = sol.intervalIntersection(A, B); // Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
		for (auto& elem: res)
		{
			printv(elem);
		}
		vector<vector<int>> C
		{
			{1,3} ,{5,9}
		};
		vector<vector<int>> D
		{
			
		};
		res = sol.intervalIntersection(C, D); // Output: []
		for (auto& elem : res)
		{
			printv(elem);
		}


		
	}
}