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
The backtrack function is a recursive helper function that generates the letter combinations.

It takes two parameters:
combination: A string representing the current combination of letters.
next_digits: The remaining digits to process.

If next_digits is empty (i.e., all digits have been processed), the current combination is added to the output vector.

Otherwise, it iterates through the letters corresponding to the first digit in next_digits (retrieved using the numLetters function).

For each letter, it recursively calls backtrack with an updated combination (adding the letter) and the remaining 
next_digits (excluding the first digit).

Complexity:

"Let n be the length of the input digits.
The total number of possible letter combinations is exponential (up to 4^n).
Therefore, the time complexity of this algorithm is O(4^n) since we explore all possible combinations.
The space complexity is also O(4^n) because we store all valid combinations in the output vector."



*/
namespace LetterCombinationOfAPhoneNumber
{
	class Solution 
	{
		vector<string> output;
	public:
		vector<string> letterCombinations(string digits) 
		{
			if (digits.empty()) return {};

			backtrack("", digits);
			return output;
		}
		string numLetters(string next_digits)
		{
			static const vector<string> phone_map{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
			return phone_map[next_digits[0] - '2'];
		}

	private:
		void backtrack(string combination, string next_digits)
		{
			if (next_digits.empty()) 
			{
				output.push_back(combination);
			}
			else 
			{
				string letters = numLetters(next_digits);
				for (char letter : letters) 
				{
					backtrack(combination + letter, next_digits.substr(1));
				}
			}
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