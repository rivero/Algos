#pragma once
namespace par
{
	// find the longest valid parenthesis
	void FindParenthesis(const string& s)
	{
		int initialSquare{ INT_MAX }
			, initialCurly{ INT_MAX }
			, initialRound{ INT_MAX }
		, lastSquare{ -1 }, lastCurly{ -1 }, lastround{ -1 };

		for (size_t i = 0; i < s.size(); i++)
		{
			if (initialSquare == INT_MAX && s[i] == '	')
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

		cout << "Max length: " << masimum << "\n";
	}
	// move all zeroes to the right side

}
