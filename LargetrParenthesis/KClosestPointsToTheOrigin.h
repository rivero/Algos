#pragma once
namespace KClosestPointsToTheOrigin
/*
* https://leetcode.com/problems/k-closest-points-to-origin/
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

1. **Time Complexity**:
   - The main part of the function involves iterating through the `points` vector and calculating the Euclidean 
   distance for each point.
   - The `for` loop that iterates through the `points` vector runs in linear time, O(n), where n is the number of points.
   - Inside the loop, we compute the Euclidean distance using `sqrt(pow(point[0], 2) + pow(point[1], 2))`. This operation 
   takes constant time for each point.
   - The `multiset` insertion operation (`myset.insert({ dist, point })`) also takes logarithmic time (O(log n)) because 
   it maintains the sorted order of distances.
   - Overall, the time complexity of the function is dominated by the loop and the insertion into the `multiset`.
   - Therefore, the time complexity is **O(n log n)**.

2. **Space Complexity**:
   - The function uses additional memory to store the `multiset` (`myset`) and the resulting `res` vector.
   - The `multiset` stores at most `n` elements so its space complexity is **O(n)**.
   - The `res` vector stores the `k` closest points, so its space complexity is **O(k)**.
   - Ignoring other constant-sized variables, the overall space complexity is **O(n)**.

In summary:
- **Time Complexity**: O(n log k)
- **Space Complexity**: O(n) ¹²

*/
{


	class Solution
	{
	public:
		vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
		{
			multiset< pair <double, vector<int> > > myset;
			for (auto& point : points)
			{
				auto dist = sqrt(pow(point[0], 2) + pow(point[1], 2));
				myset.insert({ dist, point });
			}
			vector<vector<int>> res;
			for (auto& [dist, point] : myset)
			{
				res.push_back(point);
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