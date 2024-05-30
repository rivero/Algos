#pragma once
namespace NumberOfIslands
{
























	class Solution
	{
		int m_rows{}, m_cols{};
		vector< vector<char> > m_matrix;

		void mark_current_island(int i, int j)
		{
			if (i < 0 || i >= m_rows || j < 0 || j >= m_cols || m_matrix[i][j] != '1')
			{
				return;
			}
			m_matrix[i][j] = '2';
			mark_current_island(i + 1, j); // DOWN
			mark_current_island(i, j + 1); // RIGHT
			mark_current_island(i -1 , j); // TOP
			mark_current_island(i, j - 1); // LEFT
		}

		void print() const
		{
			cout << "\n";
			for (auto elem : m_matrix)
			{
				printv(elem);
			}
			cout << "\n";
		}

	public:
		int numberOfIslands(vector< vector<char> >& grid)
		{
			m_matrix = grid;
			
			print();

			m_rows = m_matrix.size();
			if (m_rows == 0)
			{
				return 0;
			}

			m_cols = m_matrix[0].size();
			int no_of_islands{};
			for (int i = 0; i < m_rows; i++)
			{
				for (int j = 0; j < m_cols; j++)
				{
					if (m_matrix[i][j] == '1')
					{
						mark_current_island(i, j);
						no_of_islands++;
						print();
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
		cout << sol.numberOfIslands(matrix) << "\n";
	}
}