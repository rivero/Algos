#pragma once
namespace NumberOfIslands
{
























	class Solution
	{
		void mark_current_island(vector< vector<char> >& grid, int i, int j)
		{
			if (i < 0 || i >= m_rows || j < 0 || j >= m_cols || grid[i][j] != '1')
			{
				return;
			}
			grid[i][j] = '2';
			mark_current_island(grid, i + 1, j); // DOWN
			mark_current_island(grid, i, j + 1); // RIGHT
			mark_current_island(grid, i -1 , j); // TOP
			mark_current_island(grid, i, j - 1); // LEFT
		}
		int m_rows{}, m_cols{};
	public:
		void print(const vector<vector<char>>& matrix) const
		{
			cout << "\n";
			for (auto elem : matrix)
			{
				printv(elem);
			}
			cout << "\n";
		}
		int numberOfIslands(vector< vector<char> >& grid)
		{
			m_rows = grid.size();
			if (m_rows == 0)
			{
				return 0;
			}

			m_cols = grid[0].size();
			int no_of_islands{};
			for (int i = 0; i < m_rows; i++)
			{
				for (int j = 0; j < m_cols; j++)
				{
					if (grid[i][j] == '1')
					{
						mark_current_island(grid, i, j);
						no_of_islands++;
						print(grid);
					}
				}
			}
			return no_of_islands;
		}
	};
		

	void process()
	{
		vector<vector<char>> matrix
		{
			{'1','1','0','0','0',},
			{'1','1','0','0','0',},
			{'0','0','1','0','0',},
			{'0','0','0','1','1',}
		};
		Solution sol;
		sol.print(matrix);
		cout << sol.numberOfIslands(matrix) << "\n";
	}
}