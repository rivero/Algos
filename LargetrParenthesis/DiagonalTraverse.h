#pragma once
/*
498. Diagonal Traverse
https://leetcode.com/problems/diagonal-traverse/description/

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.



Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
-10^5 <= mat[i][j] <= 10^5

Certainly! Let's break down the algorithm and analyze its time and space complexities.

1. **Algorithm Explanation**:
   - The given function `findDiagonalOrder` traverses the matrix in a zigzag diagonal order.
   - It starts at the top-left corner and moves either up or down diagonally, depending on the current direction.
   - When moving up, it checks if it can continue moving diagonally up (within the matrix bounds). 
   If not, it adjusts the row or column to continue the traversal.
   - When moving down, it similarly checks if it can continue moving diagonally down.
   - The direction is reversed after each diagonal traversal.

2. **Time Complexity**:
   - The outer loop runs until both `row` and `col` are within the matrix bounds (i.e., `row < rows` and `col < columns`).
   - The inner loops (one for moving up and one for moving down) traverse the diagonals.
   - In the worst case, the total number of elements visited is approximately `rows * columns`.
   - Therefore, the time complexity is O(rows * columns).

3. **Space Complexity**:
   - The `result` vector stores the diagonal elements.
   - The space required for the `result` vector is proportional to the number of elements in the matrix.
   - Thus, the space complexity is O(rows * columns).

   */


namespace DiagonalTraverse
{
	struct Solution
	{

		vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
		{
			int rows = matrix.size();
			int cols = matrix[0].size();
			int row = 0;
			int col = 0;
			bool up = true;
			vector<int> result;

			while (result.size() != rows * cols)
			{
				if (up) 
				{
					// Moving in the up direction
					while (row > 0 && col < cols - 1) 
					{
						result.push_back(matrix[row][col]);
						row--;
						col++;
					}
					result.push_back(matrix[row][col]);
					if (col == cols - 1) 
						row++;
					else 
						col++;
				}
				else 
				{
					// Moving in the down direction
					while (col > 0 && row < rows - 1) 
					{
						result.push_back(matrix[row][col]);
						row++;
						col--;
					}
					result.push_back(matrix[row][col]);
					if (row == rows - 1) 
						col++;
					else 
						row++;
				}
				up = !up; // Reversing the direction
			}

			return result;
		}

	};
	void process()
	{
		Solution sol;
		vector< vector<int> > matrix
		{
			 {1,2,3} 
			,{4,5,6}
			,{7,8,9}
		};

		auto res = sol.findDiagonalOrder(matrix);
		printv(res);
	}
}