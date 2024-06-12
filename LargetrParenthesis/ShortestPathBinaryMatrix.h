#pragma once
namespace ShortestPathBinaryMatrix
{
	/*
	1091. Shortest Path in Binary Matrix

	Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix.
	
	If there is no clear path, return -1.

	A clear path in a binary matrix is a path 
		from the top - left cell(i.e., (0, 0)) 
		to the bottom - right cell(i.e., (n - 1, n - 1)) 
		
	such that :

		All the visited cells of the path are 0.
		All the adjacent cells of the path are 
			8 - directionally connected(i.e., they are different and they share an edge or a corner).
	The length of a clear path is the number of visited cells of this path.

	Example 1:
	Input: grid = [[0, 1], [1, 0]]
	Output : 2

	Example 2 :
	Input : grid = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
	Output : 4

	Example 3 :
	Input : grid = [[1, 0, 0], [1, 1, 0], [1, 1, 0]]
	Output : -1

	Constraints :

	n == grid.length
	n == grid[i].length
	1 <= n <= 100
	grid[i][j] is 0 or 1

	Edge cases

	If the first element is not 0 we cant make a path, return -1;
	Because: All the visited cells of the path are 0.
	
	Time complexity: O(R * C)
	Space: O(R * C) because of the queue

	-------------
	Shortest path is a graph.
	DFS undirected graph

	*/


	class Solution 
	{
		vector<vector<int>> m_grid;
		int row, col;

		struct coord
		{
			int x{ 0 }, y{ 0 };
		};
		struct elem : public coord
		{
			int p{ 1 };
		};

		vector <vector<int> > directions
		{
			{0 , 1}, // up
			{0 ,-1}, // down
			{1 , 0}, // right
			{-1, 0}, // left
			{1 , 1}, // ne
			{1 ,-1}, // se
			{-1, 1}, // nw
			{-1,-1}  // sw
		};
	public:
		int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
		{
			m_grid = grid;
			auto maxRow = m_grid.size() - 1;
			auto maxCol = m_grid[0].size() - 1;

			// edge case 1 first and last elements are not 0
			auto firstelement = m_grid[0][0];
			auto lastelement = m_grid[maxRow][maxCol];

			if (firstelement != 0 || lastelement != 0)
			{
				return -1;
			}
			// BFS
			queue<elem> q; q.push({ 0,0,1 }); // initial x, initial y, initial path value
			
			m_grid[0][0] = 1;

			while ( q.size() > 0)
			{
				auto& el = q.front();
				q.pop();
				// are we at the end?
				if (el.x == maxRow && el.y == maxCol)
				{
					return el.p;
				}

				for (auto& dir: directions)
				{
					auto new_x = el.x + dir[0];
					auto new_y = el.y + dir[1];

					if ( (0 <= new_x && new_x <= maxRow) && ( 0 <= new_y && new_y <= maxCol) && m_grid[new_x][new_y] == 0)
					{
						m_grid[new_x][new_y] = 1;
						q.push({new_x, new_y, el.p + 1});
					}
				}
			}
			return - 1;
		}
	};

	void printmatrix(const vector<vector<int>>& vec)
	{
		for (auto& v: vec)
		{
			printv(v);
		}
	}

	void process()
	{
		cout << "ShortestPathBinaryMatrix\n";
		/*
		Example 1:
		Input: grid = [[0, 1], [1, 0]]
		Output : 2

		Example 2 :
		Input : grid = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
		Output : 4

		Example 3 :
		Input : grid = [[1, 0, 0], [1, 1, 0], [1, 1, 0]]
		Output : -1
		*/
		{
			Solution sol;
			vector<vector<int>> vec
			{
				{0,1},
				{1,0}
			};
			printmatrix(vec);
			cout << sol.shortestPathBinaryMatrix(vec) << "\n";

		}
		{
			Solution sol;
			vector<vector<int>> vec
			{
				{0,0,0},
				{1,1,0},
				{1,1,0}
			};
			printmatrix(vec);
			cout << sol.shortestPathBinaryMatrix(vec) << "\n";

		}
		{
			Solution sol;
			vector<vector<int>> vec
			{
				{1,0,0},
				{1,1,0},
				{1,1,0}
			};
			printmatrix(vec);
			cout << sol.shortestPathBinaryMatrix(vec) << "\n";

		}
		{
				Solution sol;
			vector<vector<int>> vec
			{
				{0, 0, 0, 0, 0, 0, 0, 0}, 
				{0, 0, 1, 0, 0, 0, 0, 1}, 
				{1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 1, 0}, 
				{0, 0, 1, 0, 1, 0, 1, 1}, 
				{0, 0, 0, 0, 0, 0, 0, 0}, 
				{0, 0, 0, 1, 1, 1, 0, 0}, 
				{1, 0, 1, 1, 1, 0, 0, 0}
			};
			printmatrix(vec);
			cout << sol.shortestPathBinaryMatrix(vec) << "\n";
		}
	}
}