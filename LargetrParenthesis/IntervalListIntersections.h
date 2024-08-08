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


	1. We have two input arrays, `A` and `B`, each containing intervals represented as pairs of integers: `[start, end]`.
	2. Initialize an empty result vector, `res`, to store the intersection intervals.
	3. Initialize two pointers, `i` and `j`, to traverse the intervals in `A` and `B`, respectively.
	4. While both pointers are within bounds (i.e., `i < A.size()` and `j < B.size()`):
	   - Get the start and end points of the current intervals from `A` and `B`: `alow`, `ahigh`, `blow`, and `bhigh`.
	   - Calculate the intersection interval:
		 - The start of the intersection interval is the maximum of `alow` and `blow`: `lo = max(alow, blow)`.
		 - The end of the intersection interval is the minimum of `ahigh` and `bhigh`: `hi = min(ahigh, bhigh)`.
	   - If `lo <= hi`, there is a valid intersection, so add `{lo, hi}` to the result vector.
	   - Update the pointers:
		 - If `hi` equals `ahigh`, move the pointer in `A` to the next interval (`i++`).
		 - Otherwise, move the pointer in `B` to the next interval (`j++`).
	5. Return the resulting vector `res` containing the intersection intervals.

	This algorithm efficiently finds the overlapping intervals between `A` and `B`. 
	It leverages the fact that the intervals are sorted by their start points. 
	By comparing the start and end points, we can identify the intersection intervals without unnecessary checks. 
	The time complexity of this algorithm is O(N + M), where N and M are the sizes of arrays `A` and `B`, respectively. 😊
	
	The space complexity of this algorithm is indeed O(1) because it doesn't use any additional data structures that 
	grow with the input size. 
	Instead, it operates directly on the input arrays `A` and `B`, reusing the same variables for the intersection intervals. 
	Well spotted! 😊👍

	*/
#define PRINTV
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
				int maxStart = max(alow, blow), 
					minEnd = min(ahigh, bhigh);
				cout << "\ni (" << i << ") j (" << j << ")\n";
				cout << "alow: " << alow << " blow: " << blow << " max(alow, blow) maxStart: " << maxStart << "\n";
				cout << "ahigh: " << ahigh << " bhigh: " << bhigh << " min(ahigh, bhigh) minEnd: " << minEnd << "\n";

				if (maxStart <= minEnd)
				{
					cout << "maxStart (" << maxStart << ") <= minEnd ("<< minEnd << ") => push\n";
					res.push_back({ maxStart, minEnd });
				}
				// Move the pointer that has the smaller end point (i.e., increment i or j).
				if (minEnd == ahigh)
				{
					cout << "minEnd ( " << minEnd << ") == ahigh (" << ahigh <<  "), increasing i: " << i << "\n";
					// if hi == ahigh (see they are compared in the min() ) then hi is the smallest pointer
					// because if the ahigh is the hi (which is the min) the next element in A might also fall within B
					i++;

				}
				else
				{
					cout << "minEnd ( " << minEnd << ") != ahigh (" << ahigh << "), increasing j: " << j << "\n";
					j++;

				}
			}
			return res;
		}

		vector<vector<int>> intervalIntersectionOpen(vector<vector<int>>& A, vector<vector<int>>& B) 
		{

			vector<vector<int>> res;
			for (int i = 0, j = 0; i < A.size() && j < B.size();) 
			{
#ifdef PRINTV
				cout << "A is: \n";
				printv(A[i]);

				cout << "B is: \n";
				printv(B[j]);
#endif
				auto alow = A[i][0];
				auto blow = B[j][0];
				auto ahigh = A[i][1];
				auto bhigh = B[j][1];

				// Check for intersection. Since intervals are open, elements at the endpoints are not included. 
				if (alow < bhigh && blow < ahigh) 
				{
					// Intersection starts at the larger lower bound and ends at the smaller upper bound (excluding endpoints).
					res.push_back({ max(alow, blow), min(ahigh, bhigh) });
				}

				// Update pointers based on which interval ends first (excluding the endpoint)
				if (ahigh <= blow) 
				{
					i++;
				}
				else if (bhigh <= alow) 
				{
					j++;
				}
				else {
					// If neither interval ends first (they completely overlap), move both pointers
					i++;
					j++;
				}
			}
			return res;
		}

	};
	void printVs(vector<vector<int>>& v)
	{
		for (auto& eleme: v)
		{
			cout << "[";
			printv(eleme, false);
			cout << "]\t";
		}

	}
	void process()
	{
		cout << "IntervalListIntersections\n";
		Solution sol;
		/*
		firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
		*/
		vector<vector<int>> A
		{
			{0,2} ,{5,10},{13,23},{24,25}
		};
		cout << "Vector A is\n";
		printVs(A);
		vector<vector<int>> B
		{
			{1,5} ,{8,12},{15,24},{25,26}
		};
		cout << "\nVector B is\n";
		printVs(B);
		cout << "Closed intersection\n";
		auto res = sol.intervalIntersection(A, B); // Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
		cout << "\nClosed (inclusive) Intersection A B\n";
		for (auto& elem : res)
		{
			printv(elem);
		}

		if (false)
		{
			cout << "\n\n";
			vector<vector<int>> C
			{
				{1,3} ,{5,9}
			};
			cout << "Vector C is\n";
			printVs(C);
			vector<vector<int>> D
			{

			};
			cout << "\nVector D is\n";
			printVs(D);
			res = sol.intervalIntersection(C, D); // Output: []
			cout << "\nClosed (inclusive) Intersection C D\n";
			for (auto& elem : res)
			{
				printv(elem);
			}
			cout << "Open intersection\n";
			auto res = sol.intervalIntersectionOpen(A, B);
			cout << "\nOpen Intersection A B\n";
			for (auto& elem : res)
			{
				printv(elem);
			}
			res = sol.intervalIntersectionOpen(C, D);
			cout << "\nOpen Intersection C D\n";
			for (auto& elem : res)
			{
				printv(elem);
			}

		}
		cout << "-------------------------------------------------------------------------\n";
	}
}