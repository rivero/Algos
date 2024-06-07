#pragma once
namespace LargeIsland
{
	/*
	https://www.youtube.com/watch?v=_426VVOB8Vo

	https://leetcode.com/problems/making-a-large-island/description/

	827. Making A Large Island

	You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

	Return the size of the largest island in grid after applying this operation.

	An island is a 4-directionally connected group of 1s.



	Example 1:

	Input: grid = [[1,0],[0,1]]
	Output: 3
	Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
	Example 2:

	Input: grid = [[1,1],[1,0]]
	Output: 4
	Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
	Example 3:

	Input: grid = [[1,1],[1,1]]
	Output: 4
	Explanation: Can't change any 0 to 1, only one island with area = 4.


	Constraints:

	n == grid.length
	n == grid[i].length
	1 <= n <= 500
	grid[i][j] is either 0 or 1.


	*/
	class Solution
	{
		int m_rows{}, m_cols{};
		vector< vector<int> > m_matrix;
		size_t m_island_id{ 2 };

		void search_for_more_land(int i, int j)
		{
			if (i < 0 || i >= m_rows || j < 0 || j >= m_cols || m_matrix[i][j] != 1)
			{
				return;
			}
			m_matrix[i][j] = m_island_id;
			search_for_more_land(i + 1, j); // DOWN
			search_for_more_land(i, j + 1); // RIGHT
			search_for_more_land(i - 1, j); // TOP
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
		int largestIsland(vector< vector<int> >& grid)
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
			m_island_id = 2;
			for (int i = 0; i < m_rows; i++)
			{
				for (int j = 0; j < m_cols; j++)
				{
					if (m_matrix[i][j] == 1)
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
		vector<vector<int>> matrix
		{
			{1,1,0,0,0,},
			{1,1,0,0,0,},
			{0,0,1,0,0,},
			{0,0,0,1,1,}
		};
		Solution sol;
		cout << sol.largestIsland(matrix) << "\n";
	}
}