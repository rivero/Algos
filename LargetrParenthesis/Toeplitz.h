#pragma once
/*
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

Example 1:

1 2 3 4
5 1 2 3
9 5 1 2

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Example 2:

1 2
2 2

Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99


Follow up:

What if the matrix is stored on disk, and the memory is limited such that you can only load at
most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?

curRow = num Rows - 1 Example 3-1 = 2
curCol = 0

vector 0 = [2,0]
vector 1 = [2,1][1,0]
vector 2 = [2,2][1,1][0,0]
vector 3 = [2,3][1,2][0,1]
vector 4 = [1,3][0,2]
vector 5 = [0,3]

we need to start at the bottom left this will be our base
go to the right, do row up, move left
 repeat until we reach our local top or left
 if we reach top move right
 if we reach left move up
 repeat
*/
struct Toeplitz : public timeit
{
	bool isToeplitzMatrix(vector<vector<int>>& matrix)
	{
		int numCols = matrix[0].size() - 1;
		int row = matrix.size() - 1;
		set<int> myset;
		int col = 0;

		while (row > -1 && col <= numCols)
		{
			auto lastCol = col;
			auto lastRow = row;
			myset.clear();
			while (col >= 0 && row >= 0)
			{
				myset.insert(matrix[row][col]);
				if (myset.size() > 1)
				{
					return false;
				}
				row--;
				col--;
			}
			col = ++lastCol;
			row = lastRow;
			if (col > numCols && row > 0)
			{
				col--;
				row--;
			}
		}

		return true;
	}
};
