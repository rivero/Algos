#pragma once
/*
* https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions )
so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.


Constraints:

1 <= s.length <= 105
s[i] is either '(' , ')', or lowercase English letter.

0. Use queue of indexes
1. scan the string
2. when an open parenthesis is push index
3. when close parenthesis is found pop index
4. if queue is empty and find close parenthesis store index in vector5.
5. Store rest of indexes in queue in vector
6. Create new string with valid indexes (not in vector)

Complexity: O(n)
*/
namespace MinRemoveValidParenthesis
{
	struct Solution : public timeit
	{
		string minRemoveToMakeValid(string s)
		{
			queue<int> q;
			vector<int> invalidIdxVec;
			for (size_t i = 0; i < s.size(); i++)
			{
				if (s[i] == '(')
				{
					q.push(i);
				}
				else if (s[i] == ')')
				{
					if (q.size() > 0)
					{
						q.pop();
					}
					else
						invalidIdxVec.push_back(i);
				}
			}
			while (!q.empty())
			{
				invalidIdxVec.push_back(q.front());
				q.pop();
			}
			string res;
			for (size_t i = 0; i < s.size(); i++)
			{
				auto found = find(invalidIdxVec.begin(), invalidIdxVec.end(), i) != invalidIdxVec.end();
				if (!found)
				{
					res += s[i];
				}
			}
			return res;
		}
	};

	void process()
	{
		{
			Solution v;
			cout << v.minRemoveToMakeValid("lee(t(c)o)de)") << "\n";

		}
		{
			Solution v;
			cout << v.minRemoveToMakeValid("a)b(c)d") << "\n";

		}
		{
			Solution v;
			cout << v.minRemoveToMakeValid("))((") << "\n";

		}

	}

}
