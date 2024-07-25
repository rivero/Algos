#pragma once
/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

Solution:
Certainly! Let's break down the algorithm and discuss its complexities:

1. **Algorithm Explanation**:
	- The given algorithm generates all possible letter combinations that a given string of digits (from 2 to 9) could represent.
	- It uses a recursive approach with backtracking.
	- The `letterCombinations` function initializes an empty result vector (`output`) and calls the `backtrack` helper function.
	- The `backtrack` function explores different choices (letters) for each position in the combination.
	- It maintains a mapping of digits to corresponding letters (stored in `phone_map`).
	- When the current combination is complete (i.e., `digits` is empty), it adds the combination to the result vector.
	- The algorithm backtracks by removing the last letter from the combination.

2. **Time Complexity**:
	- The time complexity of this algorithm depends on the total number of possible combinations.
	- Since each digit maps to a variable number of letters (e.g., '2' maps to 'abc', '3' maps to 'def', etc.), 
	the total number of combinations can vary.
	- In the worst case, when all digits map to the maximum number of letters ('7' and '9' map to 4 letters each), 
	the total number of combinations is 4^N, where N is the length of the input string.
	- Therefore, the time complexity is O(4^N).

3. **Space Complexity**:
	- The space complexity is O(N) due to the recursive call stack.
	- Additionally, the result vector (`output`) stores all valid combinations, which contributes to the space usage.
*/
namespace LetterCombinationOfAPhoneNumber
{
	class Solution
	{
		vector<string> combinations;
		static string lettersNum(const string& digits)
		{
			static const vector<string> phone_map
			{
				"abc",
				"def",
				"ghi",
				"jkl",
				"mno",
				"pqrs",
				"tuv",
				"wxyz",
			};
			return phone_map[digits[0] - '2'];
		}
		void backtrack(const string& digits, const string& combination = "")
		{
			// base case
			if (digits.empty())
				combinations.push_back(combination);
			else
			{
				auto letters = lettersNum(digits);
				for (auto letter : letters)
				{
					backtrack(digits.substr(1), combination + letter);
				}
			}
		}
	public:
		vector<string> letterCombinations(const string& digits)
		{
			if (digits.empty()) return {};

			backtrack(digits);
			return combinations;
		}
	};

	void process()
	{
		/*
		Example 1:
		Input: digits = "23"
		Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

		Example 2:
		Input: digits = ""
		Output: []

		Example 3:
		Input: digits = "2"
		Output: ["a","b","c"]
*/
		string digits = "23";
		Solution sol;
		auto res = sol.letterCombinations(digits);
		printv(res);
	}
}