#pragma once
namespace NumberOfIslands
{
























	class Solution
	{
		int m_rows{}, m_cols{};
		vector< vector<char> > m_matrix;
		size_t m_island_id{ 2 };

		void search_for_more_land(int i, int j)
		{
			if (i < 0 || i >= m_rows || j < 0 || j >= m_cols || m_matrix[i][j] != '1')
			{
				return;
			}
			m_matrix[i][j] = '0' + m_island_id;
			search_for_more_land(i + 1, j); // DOWN
			search_for_more_land(i, j + 1); // RIGHT
			search_for_more_land(i -1 , j); // TOP
			search_for_more_land(i, j - 1); // LEFT
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
			m_rows = m_matrix.size();
			if (m_rows == 0)
			{
				return 0;
			}
			print();

			m_cols = m_matrix[0].size();
			int no_of_islands{};
			for (int i = 0; i < m_rows; i++)
			{
				for (int j = 0; j < m_cols; j++)
				{
					if (m_matrix[i][j] == '1')
					{
						search_for_more_land(i, j);
						no_of_islands++;
						m_island_id++;
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