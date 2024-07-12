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

1. **Algorithm Explanation:**
   - The function iterates through the matrix diagonally, starting from the last row and the first column.
   - For each diagonal, it compares the value of the current element with the value of the previous element on the same diagonal.
   - If any two adjacent elements on a diagonal have different values, the matrix is not Toeplitz, and the function returns `false`.
   - Otherwise, it continues checking subsequent diagonals until all diagonals are processed.

2. **Implementation Details:**
   - `numCols` represents the number of columns in the matrix.
   - The outer loop iterates through rows (`row`), and the inner loop iterates through columns (`col`).
   - The variable `val` stores the value of the current element.
   - The algorithm compares `val` with the value of the previous element on the diagonal.

3. **Time Complexity:**
   - The outer loop iterates through rows, and the inner loop iterates through columns.
   - In the worst case, the algorithm examines all elements in the matrix.
   - Therefore, the time complexity is O(rows × columns), where rows and columns represent the dimensions of the matrix.

4. **Space Complexity:**
   - The space complexity is minimal because the algorithm only uses a few variables (`numCols`, `row`, `col`, and `val`).
   - There are no additional data structures that grow with the input size.
   - Thus, the space complexity is O(1).

5. **Summary:**
   - The `isToeplitzMatrix` function efficiently checks whether a matrix is Toeplitz by comparing adjacent diagonal elements.
*/
namespace Toeplitz
{
	struct Solution : public timeit
	{
		bool isToeplitzMatrix(vector<vector<int>>& matrix)
		{
			size_t numCols = matrix[0].size() - 1;
			int row = matrix.size() - 1;
			int col = 0;
			while (row > -1 && col <= numCols)
			{
				auto lastCol = col;
				auto lastRow = row;
				auto val = matrix[row][col];
				while (col >= 0 && row >= 0)
				{
					if (val != matrix[row--][col--])
					{
						return false;
					}
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
	void process()
	{
		{
			Solution t;
			vector<vector<int>> matrix
			{
				{1, 2, 3, 4},
				{5, 1, 2, 3},
				{9, 5, 1, 2}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Solution t;
			vector<vector<int>> matrix
			{
				{1, 2, 3},
				{5, 1, 2},
				{9, 5, 1}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Solution t;
			vector<vector<int>> matrix
			{
				{1, 2},
				{5, 1},
				{9, 5}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Solution t;
			vector<vector<int>> matrix
			{
				{1, 2},
				{5, 1}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
		{
			Solution t;
			vector<vector<int>> matrix
			{
				{1, 2},
				{2, 2}
			};
			for (auto elem : matrix)
			{
				printv(elem);
			}
			bool val = t.isToeplitzMatrix(matrix);
			cout << " this matrix  " << (val ? "is" : "is not") << " a Toeplitz matrix\n";
		}
	}
}
