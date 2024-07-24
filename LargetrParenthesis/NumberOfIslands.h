#pragma once
namespace NumberOfIslands
{
	/*
	https://leetcode.com/problems/number-of-islands/description/

	200. Number of Islands
	
	Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
	You may assume all four edges of the grid are all surrounded by water.

	Example 1:

	Input: grid = [
	  ["1","1","1","1","0"],
	  ["1","1","0","1","0"],
	  ["1","1","0","0","0"],
	  ["0","0","0","0","0"]
	]
	Output: 1
	Example 2:

	Input: grid = [
	  ["1","1","0","0","0"],
	  ["1","1","0","0","0"],
	  ["0","0","1","0","0"],
	  ["0","0","0","1","1"]
	]
	Output: 3


	Constraints:

	m == grid.length
	n == grid[i].length
	1 <= m, n <= 300
	grid[i][j] is '0' or '1'.

	Time complexity: O(n^2) or O(r*c)
	Space complexity: O(r * c) because the recursion ; if not couting recursion is O(1)

1. **Algorithm Explanation:**
   - The problem is to find the number of connected components (islands) in the binary matrix.
   - We use DFS to explore each island:
	 - For each cell with value '1', we perform a DFS to mark all connected land cells as part of the same island.
	 - We increment the island count after each DFS traversal.
	 - We also maintain an `island_id` to label different islands uniquely (using values greater than 1).

2. **Implementation Details:**
   - The given class `Solution` contains the following key methods:
	 - `search_for_more_land(i, j)`:
	   - Recursively explores the land cells connected to the cell at `(i, j)`.
	   - If the cell is out of bounds or not part of an island ('1'), it returns.
	   - Otherwise, it marks the cell with the current `island_id` and recursively explores its neighbors.
	 - `numIslands(grid)`:
	   - Initializes the matrix and other variables.
	   - Iterates through each cell in the grid:
		 - If the cell contains '1', it starts a new island exploration using `search_for_more_land`.
		 - Increments the island count.
		 - Updates the `island_id`.
	   - Returns the total number of islands.

3. **Complexities:**
   - **Time Complexity:**
	 - The DFS traversal visits each cell at most once.
	 - Therefore, the time complexity is O(rows × cols), where `rows` and `cols` are the dimensions of the matrix.
   - **Space Complexity:**
	 - The additional space used is for the recursive call stack during DFS (which is at most O(rows × cols)).
	 - The space for the `m_matrix`, `m_rows`, `m_cols`, and `m_island_id` variables is negligible.
	 - Thus, the overall space complexity is also O(rows × cols).

	*/
#define PRINTV


	class Solution
	{
		int m_rows{}, m_cols{};
		vector<vector<char>> m_grid;
		void searchLand(int row, int col)
		{
			if (row < 0 || row >= m_rows || col < 0 || col >= m_cols || m_grid[row][col] != '1')
				return;
			m_grid[row][col] = '*';
			searchLand(row + 1, col);
			searchLand(row - 1, col);
			searchLand(row, col + 1);
			searchLand(row, col - 1);
		}
	public:
		int numIslands(vector<vector<char>>& grid)
		{
			if (grid.empty())
				return 0;

			m_grid = grid;
			m_rows = grid.size();
			m_cols = grid[0].size();
			int no_islands{};
			// iterate rows and cols looking for '1' (land)
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					if (m_grid[row][col] == '1')
					{
						searchLand(row, col);
						no_islands++;
					}
				}
			}

			return no_islands;
		}
	};

	void process()
	{
		cout << "NumberOfIslands\n";
		{
			vector<vector<char>> matrix
			{
				{'1','1','0','0','0',},
				{'1','1','0','0','0',},
				{'0','0','1','0','0',},
				{'0','0','0','1','1',}
			};
			Solution sol;
			cout << sol.numIslands(matrix) << "\n"; // 3

		}
		{
			vector<vector<char>> matrix
			{
			  {'1','1','1','1','0'} ,
			  {'1','1','0','1','0'},
			  {'1','1','0','0','0'},
			  {'0','0','0','0','0'}
			};
			Solution sol;
			cout << sol.numIslands(matrix) << "\n"; // 1

		}
		{
			vector<vector<char>> matrix
			{
			  {'1','1','0','0','0'} ,
			  {'1','1','0','0','0'},
			  {'0','0','1','0','0'},
			  {'0','0','0','1','1'}
			};
			Solution sol;
			cout << sol.numIslands(matrix) << "\n"; // 3

		}
	}
}