#pragma once
/*
https://leetcode.com/problems/rotate-image?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days&difficulty=MEDIUM
48. Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Yes, the code you've provided rotates a 2D matrix 90 degrees clockwise. Let's break down how it accomplishes this:

1. It initializes two variables, `l` (left) and `r` (right), representing the indices of the matrix boundaries.
2. The `while` loop runs as long as `l` is less than `r`.
3. Inside the loop, a `for` loop iterates from `l` to `r - 1`.
4. For each iteration of the inner loop:
   - It calculates the indices for the top, bottom, and left corners of the current layer.
   - It swaps the values in the four corners of the layer, effectively rotating the layer 90 degrees clockwise.
5. After processing the entire layer, it moves the boundaries inward by incrementing `l` and decrementing `r`.

The time complexity of the provided matrix rotation code is **O(N^2)**, 
where **N** represents the size of the square matrix (number of rows or columns). Let's break it down:

1. The outer `while` loop runs for **N/2** iterations (since we move inwards from both ends).
2. Within each iteration of the outer loop:
   - The inner `for` loop iterates from **l** to **r - 1**, which has a maximum of **N** iterations.
   - The four value swaps (top left, bottom left, bottom right, and top right) are constant time operations.
3. Overall, the total number of swaps is proportional to the number of elements in the matrix, which is **N^2**.

Good solution

1. **Algorithm Explanation**:
	- The given algorithm rotates an **N x N** matrix (represented as a vector of vectors) by 90 degrees clockwise.
	- It performs two steps:
		1. **Transpose**: Swap elements across the main diagonal (i.e., take the transpose of the matrix).
		2. **Reverse Rows**: Reverse each row to get the final rotated matrix.

2. **Step-by-Step Explanation**:
	- **Transpose**:
		- The outer loop (`i`) iterates over rows from 0 to `n-1`.
		- The inner loop (`j`) iterates over columns from `i+1` to `n-1`.
		- For each pair of indices (`i`, `j`), the algorithm swaps `matrix[i][j]` with `matrix[j][i]`.
		- This step effectively transposes the matrix.
	- **Reverse Rows**:
		- After the transpose, the matrix has been rotated 90 degrees counterclockwise.
		- To get the clockwise rotation, we reverse each row.
		- The second loop (`i`) iterates over rows from 0 to `n-1`.
		- For each row, we reverse its elements using `reverse(matrix[i].begin(), end(matrix[i]))`.

3. **Time Complexity**:
	- The time complexity of this algorithm is O(N^2), where N is the size of the matrix.
	- The transpose step takes O(N^2) time (since we visit each element once).
	- The row reversal step also takes O(N^2) time (since we reverse each row).

4. **Space Complexity**:
	- The space complexity is O(1) because the algorithm modifies the input matrix in-place without using additional data structures.


 */
namespace RotateImage
{
	class SolutionJr
	{
	public:
		void rotate(vector<vector<int>>& matrix)
		{
			size_t l{}, r{ matrix.size() - 1 };

			while (l < r)
			{
				for (int i = l; i < r; ++i)
				{
					auto top{ l }, bottom{ r };
					auto topLeft{ matrix[top][l + i] };

					// move bottom left into top left
					matrix[top][l + i] = matrix[bottom - i][l];
					// move bottom right into bottom left
					matrix[bottom - i][l] = matrix[bottom][r - i];
					// move top right into bottom right
					matrix[bottom][r - i] = matrix[top + i][r];
					// move top left into top right
					matrix[top + i][r] = topLeft;
				}
				// move inwards
				l += 1;
				r -= 1;
			}
		}
	};
	class Solution 
	{
	public:
		void rotate(vector<vector<int>>& matrix) 
		{

			int n = matrix.size();

			// Take a transpose of the matrix (rotates counterclockwise)
			for (int i = 0; i < n - 1; i++) 
			{
				for (int j = i + 1; j < n; j++) 
				{
					swap(matrix[i][j], matrix[j][i]);
				}
			}

			// Reverse each row of the matrix to get the output
			for (int i = 0; i < n; i++) {
				reverse(matrix[i].begin(), end(matrix[i]));
			}
		}

	};
	void process()
	{
		cout << "RotateImage\n";
		{
			Solution sol;
			vector<vector<int>> matrix
			{
				{1,2,3},
				{4,5,6},
				{7,8,9}
			};
			for (auto el: matrix)
			{
				printv(el);
			}
			cout << "\n";

			sol.rotate(matrix);

			for (auto el : matrix)
			{
				printv(el);
			}
			cout << "\n";

		}
		{
			Solution sol;
			vector < vector<int>> matrix
			{
				{5,1,9,11} ,
				{2,4,8,10},
				{13,3,6,7},
				{15,14,12,16}
			};
			for (auto el : matrix)
			{
				printv(el);
			}
			cout << "\n";

			sol.rotate(matrix);

			for (auto el : matrix)
			{
				printv(el);
			}
			cout << "\n";
		}
	}
}