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
Initialize an empty vector res to store the indices of the visible buildings.
Compute the total number of buildings (numBuildings) by subtracting 1 from the size of the heights vector.
Push numBuildings (the last index) into res since the last building always sees the sunset.
Initialize lastHeight with the height of the last building (heights[numBuildings]).
Iterate from the second-to-last building (index numBuildings - 1) to the first building (index 0):
If the height of the current building (heights[i]) is greater than lastHeight, it can see the sunset.
Add its index (i) to the res vector and update lastHeight.
Reverse the order of elements in res to match the original order of buildings from west to east.
Return the res vector containing the indices of the visible buildings.

	*/
namespace buildingsoceanview
{
	class Solution {
	public:
		vector<int> findBuildings(vector<int>& heights) 
		{
			vector<int> res;
			auto numBuildings = heights.size() - 1;
			res.push_back(numBuildings);
			int lastHeight{ heights[numBuildings ]};
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
	}
}