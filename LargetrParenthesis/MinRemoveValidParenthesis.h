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

0. Use stack of indexes
1. scan the string
3. when close parenthesis is found pop index if stack not empty
4. if stack is empty and find close parenthesis mark that string element with '*' (to avoid).
2. when an open parenthesis is push index
5. If stack has elements, mark those elements (they are indexes) as invalid (*)
6. Create new string with valid indexes (not invalid)

Complexity: O(n)
*/
namespace MinRemoveValidParenthesis
{
	class Solution : protected timeit
	{
	public:
		string minRemoveToMakeValid(string s) 
		{
			stack<int> op;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == ')')
				{
					if (op.size() > 0)
						op.pop();
					else
						s[i] = '*';
				}
				else if (s[i] == '(')
				{
					op.push(i);
				}
			}
			while (!op.empty())
			{
				s[op.top()] = '*';
				op.pop();
			}
			string ans;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] != '*')
					ans += s[i];
			}
			return ans;
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
