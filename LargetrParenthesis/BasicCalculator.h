#pragma once
/*
* https://leetcode.com/problems/basic-calculator-ii/description/
227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return
its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results 
will be in the 
range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as
mathematical expressions, 
such as eval().



Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5


Constraints:

1 <= s.length <= 3 * 10^5
s consists of integers and operators ('+', '-', '*', '/') separated by some number of 
spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/
namespace basiccalc
{
	class Solution 
	{
	public:
		int calculate(string s) 
		{
			int num = 0;
			char opr = '+';
			stack<int>st;

			for (size_t i = 0; i < s.length(); i++)
			{
				char c = s[i];

				//if char is digit,convert char c to numeric val
				if (isdigit(c))
				{
					num = num * 10 + (c - '0');
				}

				if ((!isdigit(c) && c != ' ') || i == s.size() - 1)
				{
					if (opr == '+')
					{
						st.push(num);
					}
					else if (opr == '-')
					{
						st.push(-num);
					}
					else if (opr == '*')
					{
						int temp = st.top() * num;
						st.pop();
						st.push(temp);
					}
					else if (opr == '/')
					{
						int tmp = st.top() / num;
						st.pop();
						st.push(tmp);
					}
					opr = c;
					num = 0;
				}
			}

			int ans = 0;
			while (!st.empty())
			{
				ans += st.top();
				st.pop();
			}
			return ans;
		}
	};
	void process()
	{
		Solution sol;
		cout << sol.calculate("300+2*2") << "\n";
	}
}