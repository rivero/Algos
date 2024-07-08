#pragma once
/*
* https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

921. Minimum Add to Make Parentheses Valid

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s.

In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))",
you can insert an opening parenthesis to be "(()))"
or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.



Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3


Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.
*/
namespace MinimumAddParenthesisValid
{
	class Solution 
	{
	public:
		int minAddToMakeValid(string s)
		{
			queue<int> q; // stores opening '(' indexes
			vector<int> invalidIdxVec; // stores invalid indexes (where there was not closing ')' )
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '(')
				{
					q.push(i);
				}
				else if (s[i] == ')')
				{
					if (q.size() > 0) // did we already have a')' index?...
					{
						q.pop(); // ...pop it.
					}
					else
					{
						invalidIdxVec.push_back(i); //... else invalid index found
					}
				}
			}
			while (!q.empty())
			{ // if we have invalid indexes left add them to the invalidIdxVec vector
				invalidIdxVec.push_back(q.front());
				q.pop();
			}

			return invalidIdxVec.size(); // returning the number of moves to make this string valid parenthesized
		}
	};

	void process()
	{
		Solution sol;
		cout << sol.minAddToMakeValid("())") << "\n";
		cout << sol.minAddToMakeValid("(((") << "\n";

	}
}