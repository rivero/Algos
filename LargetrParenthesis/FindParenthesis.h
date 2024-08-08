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
	size_t FindParenthesis(const string& s)
	{
		cout << "FindParenthesis: \"" << s << "\"\n";
		size_t initialSquare{ numeric_limits<unsigned>::max() }
			, initialCurly{ numeric_limits<unsigned>::max() }
			, initialRound{ numeric_limits<unsigned>::max() }
		,   lastSquare{ 0 }, 
			lastCurly { 0 }, 
			lastRound { 0 };

		int longestSquare = 0;
		int longestRound =  0;
		int longestCurly =  0;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (initialSquare == numeric_limits<unsigned>::max() && s[i] == '[')
			{
				initialSquare = i;
				continue;
			}
			if (initialRound == numeric_limits<unsigned>::max() && s[i] == '(')
			{
				initialRound = i;
				continue;
			}
			if (initialCurly == numeric_limits<unsigned>::max() && s[i] == '{')
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
				lastRound = i;
				continue;
			}
			if (s[i] == ']')
			{
				lastSquare = i;
				continue;
			}
		}
		if(lastSquare > 0 && initialSquare != numeric_limits<unsigned>::max())
			longestSquare = lastSquare - initialSquare;
		if(lastRound > 0 && initialRound != numeric_limits<unsigned>::max())
			longestRound = lastRound - initialRound;
		if(lastCurly > 0 && initialCurly != numeric_limits<unsigned>::max())
			longestCurly = lastCurly - initialCurly;

		size_t maxLen = max(longestSquare, max(longestRound, longestCurly));

		cout << "Max length: " << maxLen << "\n\n";
		return maxLen;
	}
	// move all zeroes to the right side

	size_t findLongestValidParenthesis(const string& s) 
	{
		cout << "findLongestValidParenthesis: \"" << s << "\"\n";
		size_t maxLen = 0;
		// first index for [, (, {
		size_t firstIndex[3] = { numeric_limits<unsigned>::max(), numeric_limits<unsigned>::max(), numeric_limits<unsigned>::max() };

		for (int i = 0; i < s.size(); ++i) 
		{
			if (s[i] == '[' || s[i] == '(' || s[i] == '{') 
			{
				auto x = s[i] - '(';
				auto y = firstIndex[x];
				firstIndex[s[i] - '('] = i; // Efficiently map character to index
			}
			else 
			{
				auto openIndex = firstIndex[s[i] - ']']; // Efficiently map closing to opening
				if (openIndex != numeric_limits<unsigned>::max()) {
					maxLen = max(maxLen, i - openIndex + 1);
				}
			}
		}
		cout << "Max length: " << maxLen << "\n\n";
		return maxLen;
	}

	void process()
	{
		FindParenthesis("");
		auto res1 = FindParenthesis("(){}[]");
		//auto res2 = findLongestValidParenthesis("(){}[]");
		FindParenthesis("(}");
		FindParenthesis("(((((((}");
		FindParenthesis("([]]){{}((}}");
		FindParenthesis("(           )}");
		FindParenthesis("(           {}");
		FindParenthesis("([]]){{}((]]){{}((  ]]){{}((]]){{}((]]){{}((]]){{}((]]){{}(( ]]){{}((]]){{}((]]){{}((]]){{}(( }}");

	}

}
