#pragma once
namespace IslandPerimeter
{

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
		int islandPerimeter(vector<vector<int>>& grid)
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