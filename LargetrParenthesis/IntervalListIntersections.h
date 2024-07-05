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

	Time Complexity (T):
		You’re iterating through both lists of intervals (A and B) in a single loop.
		The loop runs until either i reaches the end of A or j reaches the end of B.
		Since you’re processing each interval once, the total number of iterations is proportional to the sum of the lengths of both lists: (n + m).
		Therefore, the time complexity is (O(n + m)).
	Space Complexity (S):
		You’re using a constant amount of additional space (variables like alow, blow, ahigh, bhigh, lo, and hi).
		These variables don’t depend on the input size; they remain the same regardless of the input.
		Thus, the space complexity is (O(1)).


	Approach
		The intersection of two closed intervals is either:
			An empty set (if there is no overlap between the intervals).
			A closed interval [c, d] (if there is an overlap).
		To find the intersection, we can use the following rule:
			If the intervals [a, b] and [c, d] overlap (i.e., max(a, c) ≤ min(b, d)), 
			then their intersection is [max(a, c), min(b, d)].

	Solution
		Initialize two pointers, i and j, to iterate through firstList and secondList, respectively.
		While both pointers are within bounds:
		Calculate the maximum of the start points: maxStart = max(firstList[i][0], secondList[j][0]).
		Calculate the minimum of the end points: minEnd = min(firstList[i][1], secondList[j][1]).
		If maxStart is less than or equal to minEnd, there is an intersection.
		Add [maxStart, minEnd] to the result.
		Move the pointer that has the smaller end point (i.e., increment i or j).
		Repeat until one of the pointers reaches the end of its list.

		The provided code for finding the intersection of intervals has the following time and space complexity:

**Time Complexity:** O(n + m)

* **n** is the number of intervals in the first list (A).
* **m** is the number of intervals in the second list (B).

**Reasoning:**

* The code uses two nested loops that iterate through both lists A and B. 
* In the worst case, both loops might iterate through all elements of their respective lists.
* The operations inside the loops (comparisons, pushing to the result vector) are constant time operations (O(1)).
* Therefore, the overall time complexity is dominated by the nested loops, resulting in O(n + m).

**Space Complexity:** O(min(n, m))

* The code uses a single vector `res` to store the intersection intervals.
* In the worst case, the number of intersections will be equal to the number of intervals in the smaller list (either n or m).
* Since each intersection is stored as a vector of size 2, the space complexity is proportional to the number of intersections, 
* which is O(min(n, m)).

**Note:**

* This analysis assumes that the size of each interval (constant space) is negligible compared to the total number of intervals.
* If there's a need to optimize space further, techniques like modifying the original lists (if allowed) to store the intersections 
* can be explored, but this might trade space for code complexity.

	*/
//#define PRINTV
	class Solution 
	{
	public:
		vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
		{

			vector<vector<int>> res;
			for (int i = 0, j = 0; i < A.size() && j < B.size();) 
			{
				
#ifdef PRINTV
				cout << "A[" << i << "]:\t";
				printv(A[i]);

				cout << "B[" << j << "]:\t";
				printv(B[j]);
				cout << "\t^\t^\n";
				cout << "\tlow\thigh\n";
#endif
				auto alow = A[i][0];
				auto blow = B[j][0];
				auto ahigh = A[i][1];
				auto bhigh = B[j][1];
				int maxStart = max(alow, blow), 
					minEnd = min(ahigh, bhigh);

#ifdef PRINTV
				cout << "lo max(alow, blow): " << maxStart << " hi min(ahigh, bhigh): " << minEnd << "\n";
#endif // PRINTV
				if (maxStart <= minEnd)
				{
					res.push_back({ maxStart, minEnd });
#ifdef PRINTV
					cout << "\t* pushing {" << maxStart << "," << minEnd << "}\n\n";
#endif
				}
#ifdef PRINTV
				else
					cout << "NOT AN INTERSECTION\n\n";
#endif
				// Move the pointer that has the smaller end point (i.e., increment i or j).
				if (minEnd == ahigh) 
								 // if hi == ahigh (see they are compared in the min() ) then hi is the smallest pointer
								 // because if the ahigh is the hi (which is the min) the next element in A might also fall within B
					i++;
				else 
					j++;
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
			printv(eleme);
		}

	}
	void process()
	{
		cout << "IntervalListIntersections\n";
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
		cout << "-------------------------------------------------------------------------\n";

		Solution sol;
		if(true)
		{
			cout << "Closed intersection\n";
			auto res = sol.intervalIntersection(A, B); // Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
			cout << "\nClosed (inclusive) Intersection A B\n";
			for (auto& elem : res)
			{
				printv(elem);
			}
			res = sol.intervalIntersection(C, D); // Output: []
			cout << "\nClosed (inclusive) Intersection C D\n";
			for (auto& elem : res)
			{
				printv(elem);
			}
		}
		if(false)
		{
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

		
	}
}