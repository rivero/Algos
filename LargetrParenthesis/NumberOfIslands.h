#pragma once
namespace NumberOfIslands
{
	/*
	https://leetcode.com/problems/number-of-islands/description/

	200. Number of Islands
	
	Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.

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

	## Apologies for the oversight.

**Algorithm Explanation:**

This code implements a depth-first search (DFS) approach to count the number of islands in a given matrix.

1. **Initialization:** The `numIslands` function initializes the dimensions of the grid and a counter for the number of islands.
2. **Iterate through the grid:** The outer loop iterates through each cell of the grid.
3. **Identify land:** If a cell contains '1' (land), it calls the `searchLand` function.
4. **DFS:** The `searchLand` function recursively explores adjacent land cells, marking them as visited ('*') and calling itself 
recursively for unvisited neighbors.
5. **Count islands:** For each connected land component (island), the `numIslands` function increments the `no_islands` counter.

**Time Complexity:** O(M * N)
* The outer loop iterates through each cell of the grid, which takes O(M * N) time.
* The `searchLand` function visits each cell at most once, so its time complexity is also O(M * N) in the worst case.

**Space Complexity:** O(1)
* The algorithm modifies the input grid in-place to mark visited cells, eliminating the need for extra space.
* The recursion stack in `searchLand` can go as deep as the maximum length of the grid, which is O(max(M, N)). However, this is 
considered constant space in terms of input size.

	*/
#define PRINTV


	class Solution
	{
		int m_rows{}, m_cols{};
		void searchLand(vector<vector<char>>& grid, int row, int col)
		{
			if (row < 0 || row >= m_rows || col < 0 || col >= m_cols || grid[row][col] != '1')
				return;
			grid[row][col] = '*';
			searchLand(grid, row - 1, col);
			searchLand(grid, row + 1, col);
			searchLand(grid, row, col - 1);
			searchLand(grid, row, col + 1);
		}

	public:
		int numIslands(vector<vector<char>>& grid)
		{
			if (grid.empty()) return 0;
			m_rows = grid.size();
			m_cols = grid[0].size();
			int no_islands{};
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					if (grid[row][col] == '1')
					{
						searchLand(grid, row, col);
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