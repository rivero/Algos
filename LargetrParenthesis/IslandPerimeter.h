#pragma once
namespace IslandPerimeter
{
	/*
	https://leetcode.com/problems/island-perimeter/description/


Code
Testcase
Test Result
Test Result
463. Island Perimeter
Solved
Easy
Topics
Companies
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4


Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.

	
	*/

	class Solution 
	{
		vector<vector<int>> m_grid;
		int m_rows{}, m_cols{};

		int search_perimeter(int i, int j)
		{
			// reach out of bounds or water
			if (i < 0 || i >= m_rows || j < 0 || j >= m_cols || m_grid[i][j] == 0)
			{
				return 1;
			}
			if (m_grid[i][j] == 2)
			{
				return 0;
			}
			m_grid[i][j] = 2;
			auto perim = search_perimeter(i, j + 1);
			perim += search_perimeter(i, j - 1);
			perim += search_perimeter(i + 1, j);
			perim += search_perimeter(i - 1, j);
			return perim;
		}
	public:
		int islandPerimeter1(vector<vector<int>>& grid)
		{
			m_grid = grid;
			auto size = m_grid.size();
			m_rows = m_grid.size();
			m_cols = m_grid[0].size();

			int res{};
			for (int i = 0; i < m_rows; i++)
			{
				for (int j = 0; j < m_cols; j++)
				{
					if (m_grid[i][j] == 1)
					{
						res += search_perimeter(i, j);
					}
				}
			}
			return res;
		}

		int islandPerimeter(vector<vector<int>>& grid)
		{
			if (grid.size() == 0)
				return 0;
			int res{};
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if (grid[i][j] == 1)
					{
						res += 4;
						if (i > 0 && grid[i - 1][j] == 1)
							res -= 2;
						if (j > 0 && grid[i][j - 1] == 1)
							res -= 2;

					}

				}
			}
			return res;
		}

	};

	void process()
	{
		{
			Solution sol;
			vector<vector<int>> grid
			{
				{0,1,0,0} ,
				{1,1,1,0},
				{0,1,0,0},
				{1,1,0,0}
			};
			cout << sol.islandPerimeter(grid) << "\n";

		}
		{
			Solution sol;
			vector<vector<int>> grid
			{
				{1,0}
			};
			cout << sol.islandPerimeter(grid) << "\n";

		}
	}
}