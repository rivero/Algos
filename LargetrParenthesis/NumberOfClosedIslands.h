#pragma once
namespace NumberOfClosedIslands
{
	/**
	 * https://leetcode.com/problems/number-of-closed-islands/
	 *
	1254. Number of Closed Islands
	 * Given a 2D grid consists of 0s (land) and 1s (water).  
	 An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally 
	 (all left, top, right, bottom) surrounded by 1s.

	Return the number of closed islands.

	Example 1:



	Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
	Output: 2
	Explanation:
	Islands in gray are closed because they are completely surrounded by water (group of 1s).
	Example 2:



	Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
	Output: 1
	Example 3:

	Input: grid = [[1,1,1,1,1,1,1],
				   [1,0,0,0,0,0,1],
				   [1,0,1,1,1,0,1],
				   [1,0,1,0,1,0,1],
				   [1,0,1,1,1,0,1],
				   [1,0,0,0,0,0,1],
				   [1,1,1,1,1,1,1]]
	Output: 2


	Constraints:

	1 <= grid.length, grid[0].length <= 100
	0 <= grid[i][j] <=1


## Algorithm Explanation: Counting Closed Islands

### Problem:
Given a 2D grid map of '1's (land) and '0's (water), count the number of closed islands. A closed island is a group of connected 
1s that is completely surrounded by 0s, and is not connected to any edge of the grid.

### Algorithm:
The provided code implements a depth-first search (DFS) approach to count the number of closed islands in a given grid.

**Key steps:**

1. **Initialization:**
   - `Land`, `Water`, and `Visited` are defined as constants for clarity.
   - `m_grid` stores the input grid.
   - `m_rows` and `m_cols` store the dimensions of the grid.

2. **`search_land` function:**
   - Performs DFS to explore a connected land region.
   - Takes the current row and column as input.
   - Returns 1 if the land region is a closed island, 0 otherwise.
   - Base cases:
	 - If the current position is out of bounds, return 0 (not a closed island).
	 - If the current position is water or already visited, return 1 (closed island so far).
   - Mark the current position as visited.
   - Recursively explore the four neighboring cells (up, down, left, right).
   - Return the minimum value returned by the recursive calls. This ensures that the land region is completely surrounded by 
   water for it to be considered a closed island.

3. **`closedIsland` function:**
   - Iterates through the grid, excluding the border cells.
   - For each land cell, calls `search_land` to check if it's part of a closed island.
   - Increments the `counter` if `search_land` returns 1 (indicating a closed island).
   - Returns the final count of closed islands.

### Time and Space Complexity:

- **Time complexity:** O(M * N), where M and N are the dimensions of the grid. Each cell is visited at most once during the DFS.
- **Space complexity:** O(M * N) in the worst case, due to the recursion stack and the `m_grid` matrix.

### Explanation:
The algorithm effectively counts closed islands by exploring connected land regions using DFS. By marking visited cells and 
checking if all neighboring cells are water or out of bounds, it determines if a land region is completely enclosed. 
The minimum value returned from recursive calls ensures that the island is surrounded by water on all sides.

This approach efficiently handles the problem by avoiding unnecessary exploration and accurately identifying closed islands.

**Would you like to explore any specific part of the code in more detail?**

	 */

	class Solution
	{
		enum
		{
			Land
			, Water
			, Visited
		};
		vector<vector<int>> m_grid;
		int m_rows{}, m_cols{};
		int search_land(int row, int col)
		{
			if (row < 0 || row == m_rows || col < 0 || col == m_cols)
			{
				return 0;
			}
			if (m_grid[row][col] == Water || m_grid[row][col] == Visited)
			{
				return 1; // close island so far
			}
			m_grid[row][col] = Visited;
			// If any of these calls return 0 it is NOT a closed island
			auto resUp = search_land(row - 1, col); // UP
			auto resDn = search_land(row + 1, col); // DOWN
			auto resLf = search_land(row, col - 1); // LEFT
			auto resRt = search_land(row, col + 1); // RIGHT
			return min(resUp, min(resDn, min(resLf, resRt)));

		}
	public:
		int closedIsland(vector<vector<int>>& grid)
		{
			if (grid.size() == 0)
			{
				return {};
			}
			m_grid = grid;
			m_rows = grid.size();
			m_cols = grid[0].size();
			int counter{};
			for (int row = 1; row < m_rows - 1; row++)
			{
				for (int col = 1; col < m_cols - 1; col++)
				{
					if (m_grid[row][col] == Land)
					{
						counter += search_land(row, col);
					}
				}
			}
			return counter;
		}
	};

	void process()
	{
		cout << "NumberOfClosedIslands\n";
		vector<vector<int>> grid
		{
			{1,1,1,1,1,1,1,0},
			{1,0,0,0,0,1,1,0},
			{1,0,1,0,1,1,1,0},
			{1,0,0,0,0,1,0,1},
			{1,1,1,1,1,1,1,0}
		};
		Solution sol;
		cout << sol.closedIsland(grid);
	}
}