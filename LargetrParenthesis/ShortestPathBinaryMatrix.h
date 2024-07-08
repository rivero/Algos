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


	Solution
	Algorithm overview
	The goal is to find the shortest path from the top-left corner (0, 0) to the bottom-right corner (n - 1, n - 1) 
	in a binary matrix.
	The path consists of cells with value 0, and adjacent cells (including diagonally adjacent cells) are connected.
	We use BFS to explore neighboring cells layer by layer, incrementing the path length as we move.
	
	Implementation Details:
	The input is a 2D vector grid representing the binary matrix.
	We initialize a queue q with the starting cell (0, 0) and set it as visited (marking it as 1).
	The queue contains elements of the form {x, y, p}, where (x, y) represents the cell coordinates, and p represents the path length.
	We explore all 8 possible directions from each cell (horizontally, vertically, and diagonally).
	If a neighboring cell is within bounds, unvisited, and has value 0, we enqueue it and mark it as visited.
	We continue until we reach the bottom-right cell or exhaust the queue.


	Time Complexity:
		Each cell is visited at most once (since we mark it as visited).
		In the worst case, we visit all n x n cells, resulting in a time complexity of O(n^2).
	Space Complexity:
		We use a queue to store cells, which can have at most n x n elements.
		Additionally, we maintain the m_grid to track visited cells.
		Thus, the space complexity is O(n^2).


	*/


	class Solution 
	{
		vector<vector<int>> m_visitedCells;
		int m_row, m_col;

		struct coord
		{
			int x{ 0 }, y{ 0 };
		};
		struct elem : public coord
		{
			int p{ 1 };
		};

		vector <vector<int> > m_directions
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
			m_visitedCells = grid;
			auto maxRow = m_visitedCells.size() - 1;
			auto maxCol = m_visitedCells[0].size() - 1;

			// edge case 1 first and last elements are not 0
			auto firstelement = m_visitedCells[0][0];
			auto lastelement = m_visitedCells[maxRow][maxCol];

			if (firstelement != 0 || lastelement != 0)
			{
				return -1;
			}
			// BFS
			queue<elem> q; q.push({ 0,0,1 }); // initial x, initial y, initial path value
			m_visitedCells[0][0] = 1; // set this cell as visited

			while ( q.size() > 0)
			{
				auto& el = q.front();
				q.pop();
				// are we at the end?
				if (el.x == maxRow && el.y == maxCol)
				{
					return el.p; // p will contain the counter at the end: we increment this p (path) as we move
				}

				for (auto& dir: m_directions)
				{
					auto new_x = el.x + dir[0];
					auto new_y = el.y + dir[1];

					if ( (0 <= new_x && new_x <= maxRow) && ( 0 <= new_y && new_y <= maxCol) && m_visitedCells[new_x][new_y] == 0)
					{
						m_visitedCells[new_x][new_y] = 1;
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