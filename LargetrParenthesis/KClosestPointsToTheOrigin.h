#pragma once
namespace KClosestPointsToTheOrigin
{

	/*
	973. K Closest Points to Origin

	
	Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
	return the k closest points to the origin (0, 0).

	The distance between two points on the X-Y plane is the Euclidean distance 
	
	(i.e., √(x1 - x2)^2 + (y1 - y2)^2).

	You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

	Example 1:
	Input: points = [[1,3],[-2,2]], k = 1
	Output: [[-2,2]]

	Explanation:
	The distance between (1, 3) and the origin is sqrt(10).
	The distance between (-2, 2) and the origin is sqrt(8).
	Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
	We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

	Example 2:
	Input: points = [[3,3],[5,-1],[-2,4]], k = 2
	Output: [[3,3],[-2,4]]
	Explanation: The answer [[-2,4],[3,3]] would also be accepted.


	Constraints:

	1 <= k <= points.length <= 10^4
	-10^4 <= xi, yi <= 10^4

	Solution

	Uses a multiset to store pairs of distance and the corresponding point vector.
	The multiset automatically sorts the elements based on the first element (distance) in ascending order.
	Iterates through the multiset and extracts the first k elements (closest points) into the result vector.

	Time Complexity: O(n * log(n)) in the worst case. 
		This is because calculating the distance for each point and inserting it into the data structure takes O(n) time, 
		and extracting the k closest elements takes O(log(n)) per element (roughly k * log(n) in total).
	Space Complexity: O(n) due to the multiset potentially storing all distances and points.

	*/

	class Solution
	{
	public:
		vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
		{
			// store multiple equal results sorted from smaller to larger
			multiset< pair< double, vector<int> > > myset;

			for (auto& point : points)
			{
				auto dist = sqrt(pow(point[0], 2) + pow(point[1], 2));
				myset.insert({ dist, point });
			}

			vector<vector<int>> res;
			for (auto& element : myset)
			{
				res.push_back(element.second);
				if (res.size() == k)
					break;
			}
			return res;
		}
	};
	void process()
	{
		Solution sol;
		{
			vector<vector<int>> A
			{
				{1, 3},
				{-2, 2}
			};
			auto res = sol.kClosest(A, 1);
			for (auto& el : res)
			{
				printv(el);
			}
		}
		{
			cout << "\n";
			vector<vector<int>> A
			{
				{3, 3},
				{5, -1},
				{-2, 4}
			};
			auto res = sol.kClosest(A, 2);
			for (auto& el : res)
			{
				printv(el);
			}
		}
		{
			cout << "\n";
			vector<vector<int>> A
			{
				{-5,4},
				{-6,-5},
				{4,6}
			};
			auto res = sol.kClosest(A, 2);
			for (auto& el : res)
			{
				printv(el);
			}
		}
		{
			cout << "\n";
			vector<vector<int>> A
			{
				{2, 2},
				{2, 2},
				{3, 3},
				{2, -2},
				{1,1}
			};
			auto res = sol.kClosest(A, 4);
			for (auto& el : res)
			{
				printv(el);
			}
		}

	}
}