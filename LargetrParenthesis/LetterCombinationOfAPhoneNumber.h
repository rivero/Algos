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

## Algorithm Explanation

**Problem:** Given a string of digits, return all possible letter combinations that the number could represent. 
A mapping of digit to letters is given below:
```
2: abc
3: def
4: ghi
5: jkl
6: mno
7: pqrs
8: tuv
9: wxyz
```

**Approach:** Backtracking

**Code Breakdown:**

1. **`vector<string> combinations;`:** This vector will store all the generated letter combinations.
2. **`static string lettersNum(const string& digits)`:**
   - A helper function to map a digit to its corresponding letters.
   - Uses a static `phone_map` to store the digit-to-letter mapping.
   - Returns the letters corresponding to the first digit of the input `digits`.
3. **`void backtrack(const string& digits, const string& combination = "")`:**
   - Recursive function to generate letter combinations.
   - `digits`: The remaining digits to process.
   - `combination`: The current letter combination being built.
   - Base case: If `digits` is empty, add the current `combination` to `combinations`.
   - Recursive case:
	 - Get the letters corresponding to the first digit of `digits`.
	 - For each letter, recursively call `backtrack` with the remaining digits and the updated `combination`.
4. **`vector<string> letterCombinations(const string& digits)`:**
   - Public function to initiate the combination generation process.
   - Checks if `digits` is empty and returns an empty vector if so.
   - Calls `backtrack(digits)` to start the backtracking.
   - Returns the `combinations` vector containing all generated letter combinations.

	Let n be the length of the input digits.
	The total number of possible letter combinations is exponential (up to 4^n).
	Therefore, the time complexity of this algorithm is O(4^n) since we explore all possible combinations.
	The space complexity is also O(4^n) because we store all valid combinations in the output vector.


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