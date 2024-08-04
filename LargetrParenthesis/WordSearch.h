#pragma once
/*
https://leetcode.com/problems/word-search/

79. Word Search
Solved
Medium
Topics
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically 
neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


## Algorithm and Complexity: Word Search

### Algorithm Explanation
The code implements a backtracking algorithm to determine if a word exists in a given grid of characters.

**Key steps:**
1. **Iterate through the grid:**
   * For each cell in the grid, start a depth-first search (DFS) to check if the word can be formed starting from that cell.

2. **DFS function:**
   * **Base cases:**
	 * If the current position is out of bounds, return false.
	 * If the current character doesn't match the character at the corresponding position in the word, return false.
	 * If the end of the word is reached, return true.
   * **Recursive exploration:**
	 * Mark the current cell as visited (by changing its value to '*').
	 * Recursively explore the four neighboring cells.
	 * Unmark the current cell (restore its original value) before returning.

### Time Complexity: O(m * n * 3^L)
* **m * n:** Iterating through each cell of the grid takes O(m * n) time.
* **3^L:** In the worst case, each cell can lead to 4 recursive calls (up, down, left, right), and the depth of recursion is the 
length of the word (L). However, due to pruning, the actual number of recursive calls is often less than 4^L.

### Space Complexity: O(L)
* The recursion depth is at most the length of the word (L), which determines the space used by the call stack.

### Example:
Consider the following grid and word:

```
board = [
  ['A', 'B', 'C'],
  ['D', 'E', 'F'],
  ['G', 'H', 'I']
]
word = "ABE"
```

The algorithm would iterate through each cell of the board. When it reaches the cell containing 'A', it starts a DFS. It explores 
the paths 'AB' and 'AD'. Since 'AB' matches the beginning of the word, it continues exploring in that direction until it finds 'E', returning true.

*/
namespace WordSearch
{
	class Solution
	{
		int rows, cols;
		string wordToFind;

		bool dfs(vector<vector<char>>& board, int row, int col, int charIndex = 0)
		{
			if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != wordToFind[charIndex])
				return false;

			if (charIndex == wordToFind.length() - 1)
				return true;

			auto temp = board[row][col];
			board[row][col] = '*';

			bool found = dfs(board, row + 1, col, charIndex + 1) ||
				dfs(board, row - 1, col, charIndex + 1) ||
				dfs(board, row, col + 1, charIndex + 1) ||
				dfs(board, row, col - 1, charIndex + 1);

			board[row][col] = temp;

			return found;
		}
	public:
		bool exist(vector<vector<char>>& board, string word)
		{
			rows = board.size();
			cols = board[0].size();
			wordToFind = word;

			for (int row = 0; row < rows; ++row)
			{
				for (int col = 0; col < cols; ++col)
				{
					if (dfs(board, row, col))
					{
						return true;
					}
				}
			}
			return false;
		}

	};


	void process(){}
}