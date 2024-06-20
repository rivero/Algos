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

	DFS Testing for land
	T: O(n*m)
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