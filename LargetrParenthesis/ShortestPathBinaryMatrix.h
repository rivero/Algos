#pragma once
/*
* https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
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
If a neighboring cell is within bounds, unvisited, and has value 0, we enqueue it and mark it as visited and we oincrease the path.
We continue until we reach the bottom-right cell or exhaust the queue.


Time Complexity:
	Each cell is visited at most once (since we mark it as visited).
	In the worst case, we visit all n x n cells, resulting in a time complexity of O(n^2).
Space Complexity:
	We use a queue to store cells, which can have at most n x n elements.
	Additionally, we maintain the m_grid to track visited cells.
	Thus, the space complexity is O(n^2).


1. **Initialization**:
   - We start by initializing a queue `q` and a 2D vector `grid` to keep track of visited cells.
   - The `m_directions` vector contains eight possible directions (up, down, right, left, and diagonals).

2. **Edge Case Check**:
   - We check if the first and last elements of the grid are both zero. If not, we return -1 (indicating no valid path).

3. **BFS Exploration**:
   - We begin BFS by pushing the initial cell `{0, 0}` into the queue with a path length of 1.
   - Mark the initial cell as visited by setting `grid[0][0] = 1`.

4. **BFS Iteration**:
   - While the queue is not empty:
	 - Dequeue the front element `el`.
	 - If `el` is at the last cell of the grid, return its path length (`el.p`).
	 - Otherwise, explore all valid neighbors (within grid bounds and unvisited):
	   - Calculate new coordinates `new_x` and `new_y`.
	   - Mark the neighbor cell as visited (`grid[new_x][new_y] = 1`).
	   - Push the neighbor cell into the queue with an incremented path length (`el.p + 1`).

5. **Result**:
   - If no valid path is found, return -1.

**Complexities**:
- **Time Complexity**: The BFS traversal visits each cell at most once, so the time complexity is O(rows × cols), 
where `rows` and `cols` are the dimensions of the grid.
- **Space Complexity**: The additional space used for the queue and `grid` is also O(rows × cols).

This algorithm efficiently explores the grid to find the shortest path from the top-left corner to the bottom-right corner. 😊👍

*/
namespace ShortestPathBinaryMatrix
{


	class Solution
	{
		vector<vector<int>> directions
		{
			// x, y
			{0,1}, // up
			{0,-1}, // down
			{-1,0}, // left
			{1,0}, // right
			{1,1}, // ne
			{1,-1}, // se
			{-1,1}, // nw
			{-1,-1}  // sw
		};

		struct coord
		{
			int col{}, row{};
		};
		struct path : public coord
		{
			int pathSize{};
		};
	public:

		int shortestPathBinaryMatrix(vector<vector<int>>& grid)
		{
			auto maxCol = grid[0].size() - 1;
			auto maxRow = grid.size() - 1;
			// test if there is a possible path
			if (grid[0][0] != 0 || grid[maxRow][maxCol] != 0)
				return -1;

			queue<path> q;
			q.push({ 0,0,1 }); // 1 because the upper left counts as 1 element of the path
			grid[0][0] = 1; // mark upper left as visited

			// BFS
			while (q.size() > 0)
			{
				auto el = q.front();
				q.pop();

				// are we at the end?
				if (el.col == maxCol && el.row == maxRow)
					return el.pathSize;

				for (auto& dir : directions)
				{
					auto X = el.col + dir[0];
					auto Y = el.row + dir[1];
					// testing the path
					auto goodCol = 0 <= X && X <= maxCol;
					auto goodRow = 0 <= Y && Y <= maxRow;
					if (goodRow && goodCol && grid[X][Y] == 0)
					{
						grid[X][Y] = 1;
						q.push({ X, Y, el.pathSize + 1 }); // increase path
					}
				}
			}
			return -1;
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