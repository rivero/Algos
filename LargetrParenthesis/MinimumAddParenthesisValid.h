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

Certainly! Let's dive into the `minAddToMakeValid` function, its algorithm, and complexities.

1. **Algorithm Explanation**:
	 1. Initialize an empty stack (`st`) to keep track of opening parentheses indices.
	 2. Iterate through each character in the input string `s`.
		- If the character is ')':
		  - If the stack is not empty, pop an opening parenthesis index from the stack (matching the current closing parenthesis).
		  - Otherwise, record the current closing parenthesis index in the `invalidIdx` vector.
		- If the character is '(', push its index onto the stack.
	 3. After the first pass, any remaining opening parentheses indices in the stack are considered invalid.
	 4. Collect all invalid indices in the `invalidIdx` vector.
	 5. Return the size of the `invalidIdx` vector, which represents the minimum number of additions needed to balance the 
	 parentheses.

2. **Complexities**:
   - Time Complexity: O(N), where N is the length of the input string `s`.
	 - The algorithm processes each character in `s` once.
   - Space Complexity: O(N) for the stack and the `invalidIdx` vector.

3. **Example**:
   - Input: `"())"`
	 - After processing: `invalidIdx = [0]`, so the result is 1.
   - Input: `"((("`
	 - After processing: `invalidIdx = [0, 1, 2]`, so the result is 3.

*/
namespace MinimumAddParenthesisValid
{
	class Solution
	{
	public:
		int minAddToMakeValid(string s)
		{
			stack<size_t> st;
			vector<size_t> invalidIdx;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == ')')
				{
					if (st.size() > 0)
						st.pop();
					else
						invalidIdx.push_back(i);
				}
				else if (s[i] == '(')
					st.push(i);
			}
			while (!st.empty())
			{
				invalidIdx.push_back(st.top()); st.pop();
			}
			return invalidIdx.size();
		}
	};

	void process()
	{
		Solution sol;
		cout << sol.minAddToMakeValid("())") << "\n";
		cout << sol.minAddToMakeValid("(((") << "\n";

	}
}