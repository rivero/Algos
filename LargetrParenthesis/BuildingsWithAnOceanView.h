#pragma once
/*
* https://leetcode.com/problems/buildings-with-an-ocean-view/description/
1762. Buildings With an Ocean View
There are n buildings in a line.

You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings.
A building has an ocean view if the building can see the ocean without obstructions.

Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

Example 1:
Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

Example 2:
Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.

Example 3:
Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.


Constraints:

1 <= heights.length <= 105
1 <= heights[i] <= 109


HINT You can traverse the buildings from the nearest to the ocean to the furthest.

Solution
Certainly! Let's break down the provided `findBuildings` algorithm and discuss its complexities.

1. **Algorithm Description**:
   - The given function `findBuildings` takes a vector of integers `heights`, representing the heights of buildings.
   - It aims to find the indices of buildings that can see the sunset (i.e., buildings taller than all the buildings to their right).
   - The algorithm iterates through the `heights` array from right to left, maintaining a record of the maximum height encountered 
   so far.
   - Buildings that are taller than the current maximum height are added to the result vector.

2. **Explanation**:
   - The algorithm proceeds as follows:
	 1. Initialize an empty vector `res` to store the indices of buildings that can see the sunset.
	 2. Calculate the total number of buildings (`numBuildings`) by subtracting 1 from the size of the `heights` vector.
	 3. Add the index of the last building (which is always visible) to `res`.
	 4. Initialize `lastHeight` with the height of the last building (`heights[numBuildings]`).
	 5. Iterate through the remaining buildings from right to left (starting at index `numBuildings - 1`):
		- If the height of the current building (`heights[i]`) is greater than `lastHeight`, it means this building can see the 
		sunset.
		- Add its index to `res` and update `lastHeight` to the current building's height.
	 6. Reverse the order of elements in `res` (since we processed buildings from right to left).
	 7. Return the resulting vector `res`.

3. **Complexities**:
   - **Time Complexity**:
	 - The algorithm iterates through the `heights` vector once, performing constant-time operations (comparisons, additions, and 
	 updates).
	 - Thus, the overall time complexity is linear: `O(n)`, where `n` is the number of buildings.
   - **Space Complexity**:
	 - The space complexity is determined by the additional memory used to store the result vector `res`.
	 - In the worst case, when all buildings are visible, the space complexity is also linear: `O(n)`.

4. **Example**:
   - Suppose we have `heights = [4, 5, 2, 9, 1, 6]`.
   - The algorithm proceeds as follows:
	 - Initialize `res = []`.
	 - Add the index of the last building (index 5) to `res`.
	 - Initialize `lastHeight = 6`.
	 - Iterate from right to left:
	   - Building at index 4 (height 1) is shorter than `lastHeight : 6`, so skip.
	   - Building at index 3 (height 9) is taller than `lastHeight : 6`, so add its index (3) to `res` and update `lastHeight` to 9.
	   - Building at index 2 (height 2) is shorter than `lastHeight : 9 `, so skip.
	   - Building at index 1 (height 5) is shorter than `lastHeight : 9`, so skip.
	 - Reverse `res` to get `[1, 3, 5]`.

	*/
namespace BuildingsWithAnOceanView
{
	class Solution 
	{
	public:
		vector<int> findBuildings(vector<int>& heights) 
		{
			vector<int> res;
			auto numBuildings = heights.size() - 1;
			res.push_back(numBuildings);
			int lastHeight{ heights[numBuildings]};
			int i = numBuildings - 1;
			for (; i >= 0; i--)
			{
				if (heights[i] > lastHeight)
				{
					res.push_back(i);
					lastHeight = heights[i];
				}
			}
			reverse(res.begin(), res.end());
			return res;
		}
	};

	void process()
	{
		cout << "\nBuildings With an Ocean View\n";
		Solution sol;
		{
			vector<int> vec{ 4, 2, 3, 1 };
			auto res = sol.findBuildings(vec);
			printv(res);

		}
		{
			vector<int> vec{ 4, 3, 2, 1 };
			auto res = sol.findBuildings(vec);
			printv(res);

		}
		{
			vector<int> vec{ 1, 2, 3, 4 };
			auto res = sol.findBuildings(vec);
			printv(res);

		}
		{
			vector<int> vec{ 4, 5, 2, 9, 1, 6 };
			auto res = sol.findBuildings(vec);
			printv(res);

		}
	}
}