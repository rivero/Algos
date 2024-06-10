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
#define PRINTV

	class Solution
	{
		vector <vector<int> > m_directions{ {0,1},{0,-1},{1,0},{-1,0}, };// up, down, right, left
		int m_rows{}, m_cols{}, m_max{INT_MIN};
		vector< vector<int> > m_matrix;
		size_t m_island_id{ 2 };
		map<int, int> m_IdAreaMap;

		int landSize(int row, int col)
		{
			if (row < 0 || row >= m_rows || col < 0 || col >= m_cols || m_matrix[row][col] != 1)
				return 0;
			
			m_matrix[row][col] = m_island_id;
			auto down = landSize(row + 1, col); // DOWN
			auto right = landSize(row, col + 1); // RIGHT
			auto up = landSize(row - 1, col); // UP
			auto left = landSize(row, col - 1); // LEFT
			return down + up + left + right + 1; // return 1 because we need to at least add this cell since it is == 1
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

		void get_areas(int row, int col)
		{
			auto size = landSize(row, col);
			m_max = max(m_max, size);
			m_IdAreaMap[m_island_id++] = size;
			print();
		}

		bool get_all_areas()
		{
			m_rows = m_matrix.size();
			if (m_rows == 0)
			{
				return false;
			}
			print();

			m_cols = m_matrix[0].size();
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					if (m_matrix[row][col] == 1)
					{
						get_areas(row, col);
					}
				}
			}
			return true;
		}

	public:
		int maxAreaOfIsland(vector<vector<int>>& grid) 
		{
			m_matrix = grid;
			auto res = get_all_areas();
			if (!res)
			{
				return 0;
			}
			m_max = INT_MIN;
			for (auto& [is1landId, size]: m_IdAreaMap)
			{
				m_max = max(m_max, size);
			}
			return m_max;
		}

		int largestIsland(vector< vector<int> >& grid)
		{
			m_matrix = grid;
			auto res = get_all_areas();
			if (!res)
			{
				return 0;
			}
			//now we need to iterate the grid to find 0s and then move up and down.
			// we will find area ids. We get the in our set of island ids.
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					if (m_matrix[row][col] == 0)
					{
						// here we obtain a set of unique island ids thanks to the sorting and unique set capabilities
						set<int> island_ids; 
						for (auto& direction : m_directions)
						{
							// check all directions
							auto x = direction[0] + row;
							auto y = direction[1] + col;
							// boundaries check and make sure our current cell is no 0: if it is 0 it is not an island
							if (x > -1 && y > -1 && x < m_rows && y < m_cols && m_matrix[x][y] != 0)
							{
								island_ids.insert(m_matrix[x][y]);
							}
						}
						int sum{ 1 }; // init to 1 because we initialize cell from 0 -> 1
						for (auto& islandid: island_ids)
						{
							sum += m_IdAreaMap[islandid];
						}
						m_max = max(m_max, sum);

					}
				}
			}

			return m_max;
		}



	};


	void process()
	{
		if (true)
		{
			{
				// find largest island
				vector<vector<int>> matrix
				{
					{1,1,0,0,0,},
					{1,1,0,0,0,},
					{0,0,1,0,0,},
					{0,0,0,1,1,}
				};
				Solution sol;
				cout << sol.maxAreaOfIsland(matrix) << "\n";
			}
		}
		if(false)
		{
			// find largest if we change from 0 to 1
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
}