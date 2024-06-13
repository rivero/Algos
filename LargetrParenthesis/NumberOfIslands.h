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

	*/
#define PRINTV


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
#ifdef PRINTV
			cout << "\n";
			for (auto elem : m_matrix)
			{
				printv(elem);
			}
			cout << "\n";
#endif
		}

	public:
		int numIslands(vector< vector<char> >& grid)
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