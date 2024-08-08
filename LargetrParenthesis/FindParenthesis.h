#pragma once
/*

1. **Algorithm Explanation**:
   - The purpose of this function is to find the maximum length of a balanced substring within the input string `s`. A balanced substring consists of matching pairs of opening and closing brackets ('[', ']', '{', '}', '(', and ')').
   - The algorithm follows these steps:
	 1. Initialize variables (`initialSquare`, `initialCurly`, and `initialRound`) to store the indices of the first occurrence of each type of opening bracket (square, curly, and round).
	 2. Initialize variables (`lastSquare`, `lastCurly`, and `lastround`) to store the indices of the last occurrence of each type of closing bracket.
	 3. Iterate through the characters in the input string `s`.
		- If the current character is an opening square bracket ('['), curly bracket ('{'), or round bracket ('('), update the corresponding initial index if it hasn't been set yet.
		- If the current character is a closing square bracket (']'), curly bracket ('}'), or round bracket (')'), update the corresponding last index.
	 4. Calculate the lengths of the balanced substrings for each type of bracket pair (square, curly, and round).
	 5. Find the maximum length among these three types.
	 6. Print the maximum length.

2. **Complexities**:
   - Time Complexity: O(N), where N is the length of the input string `s`.
	 - The algorithm processes each character in `s` once.
   - Space Complexity: O(1), as the algorithm uses a fixed number of variables to store indices.

3. **Example**:
   - Input: `"{}[()]"`
	 - Initial indices: `{` at 0, `[` at 2, `(` at 3
	 - Last indices: `}` at 4, `]` at 5, `)` at 6
	 - Balanced substrings: `{[()]}` (length 6)
	 - Output: `Max length: 6`

*/
namespace FindParenthesis
{
	// find the longest valid parenthesis
	void FindParenthesis(const string& s)
	{
		cout << "\"" << s << "\"\n";
		int initialSquare{ INT_MAX }
			, initialCurly{ INT_MAX }
			, initialRound{ INT_MAX }
		, lastSquare{ INT_MIN }, lastCurly{ INT_MIN }, lastround{ INT_MIN };

		for (size_t i = 0; i < s.size(); i++)
		{
			if (initialSquare == INT_MAX && s[i] == '[')
			{
				initialSquare = i;
				continue;
			}
			if (initialRound == INT_MAX && s[i] == '(')
			{
				initialRound = i;
				continue;
			}
			if (initialCurly == INT_MAX && s[i] == '{')
			{
				initialCurly = i;
				continue;
			}
			if (s[i] == '}')
			{
				lastCurly = i;
				continue;
			}
			if (s[i] == ')')
			{
				lastround = i;
				continue;
			}
			if (s[i] == ']')
			{
				lastSquare = i;
				continue;
			}
		}

		int longestSquare = lastSquare - initialSquare;
		int longestRound = lastround - initialRound;
		int longestCurly = lastCurly - initialCurly;

		int masimum = max(longestSquare, max(longestRound, longestCurly));

		cout << "Max length: " << masimum << "\n\n";
	}
	// move all zeroes to the right side

	int findLongestValidParenthesis(const string& s) 
	{
		int maxLen = 0;
		int lastIndex[3] = { INT_MIN, INT_MIN, INT_MIN }; // last index for [, (, {

		for (int i = 0; i < s.size(); ++i) 
		{
			if (s[i] == '[' || s[i] == '(' || s[i] == '{') 
			{
				lastIndex[s[i] - '('] = i; // Efficiently map character to index
			}
			else 
			{
				int openIndex = lastIndex[s[i] - ']']; // Efficiently map closing to opening
				if (openIndex != INT_MIN) {
					maxLen = max(maxLen, i - openIndex + 1);
				}
			}
		}

		return maxLen;
	}

	void process()
	{
		cout << "FindParenthesis\n";
		FindParenthesis("");
		FindParenthesis("(){}[]");
		FindParenthesis("(}");
		FindParenthesis("(((((((}");
		FindParenthesis("([]]){{}((}}");
		FindParenthesis("(           )}");
		FindParenthesis("(           {}");
		FindParenthesis("([]]){{}((]]){{}((  ]]){{}((]]){{}((]]){{}((]]){{}((]]){{}(( ]]){{}((]]){{}((]]){{}((]]){{}(( }}");

	}

}
