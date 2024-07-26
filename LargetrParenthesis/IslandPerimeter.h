#pragma once
namespace IslandPerimeter
{
	/*
	https://leetcode.com/problems/island-perimeter/description/


463. Island Perimeter
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is 
exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square 
with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



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

**Problem:** Given a 2D grid map of '1's (land) and '0's (water), count the number of islands.

**Approach:** Counting Sides

**Code Breakdown:**

1. **Initialization:**
   - `res` is initialized to 0 to store the total perimeter.

2. **Iterate through the grid:**
   - For each cell in the grid:
	 - If the cell is land (value 1):
	   - Add 4 to `res` as initially, each land cell contributes 4 sides to the perimeter.
	   - Check the top neighbor:
		 - If the top neighbor is also land, subtract 2 from `res` as one side is shared.
	   - Check the left neighbor:
		 - If the left neighbor is also land, subtract 2 from `res` as one side is shared.

3. **Return the final perimeter:**
   - Return the calculated `res` as the total perimeter of the island(s).

## Time and Space Complexity:

- **Time complexity:** O(M * N), where M and N are the dimensions of the grid. We iterate through each cell once.
- **Space complexity:** O(1), as we only use constant extra space for variables.

## Explanation:

The algorithm efficiently calculates the island perimeter by considering each land cell as contributing 4 sides to the perimeter initially. Then, it corrects for overlapping sides by subtracting 2 for each shared side with an adjacent land cell. This approach avoids the need for complex data structures or recursion, making it efficient for this problem.

**Key points:**

- The algorithm assumes that there is only one island in the grid.
- It leverages the observation that each land cell contributes 4 sides to the perimeter initially, and then corrects for shared sides.

This direct approach is suitable for the given problem and provides an efficient solution.

	
	*/
	struct OtherSolutions
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

	};
	struct Solution 
	{

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