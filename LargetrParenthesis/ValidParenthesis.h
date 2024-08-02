#pragma once
/*
https://leetcode.com/problems/valid-parentheses
20. Valid Parenthesis

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

## Algorithm Explanation

This algorithm checks if a given string `s` contains valid parentheses.

**Steps:**

1. **Initialize an empty stack:** This stack will be used to store opening parentheses.
2. **Iterate through the string:** For each character `s[i]`:
   * **Matching closing parenthesis:** If the current character is a closing parenthesis (')', '}', ']'):
	 * Check if the stack is empty. If it's empty, there's no corresponding opening parenthesis, so return `false`.
	 * Check if the top element in the stack matches the opening parenthesis type (e.g., ')' for '('). If they match, pop the element from the stack (meaning the pair is valid).
   * **Opening parenthesis:** If the current character is an opening parenthesis ('(', '{', '['), push it onto the stack.
   * **Invalid character:** Ignore any other characters (not parentheses).
3. **Check for remaining elements:** After iterating through the entire string, if the stack is empty, all parentheses were properly matched. Otherwise, there are unmatched opening parentheses, so return `false`.

## Time Complexity: O(n)

* The algorithm iterates through the string once, visiting each character and performing constant-time operations (stack push, pop, or comparison).
* Therefore, the time complexity is linear in the string length (`n`).

## Space Complexity: O(n)

* In the worst case, the stack could store all opening parentheses from the string.
* This happens if all parentheses are opening ones and no closing ones follow.
* Therefore, the space complexity is proportional to the string length (`n`) in the worst case.

## Key Points

* This algorithm efficiently utilizes a stack to keep track of opening parentheses and their potential closing counterparts.
* It handles different types of parentheses and ensures proper matching.
* The time and space complexities are optimal for this problem.

This is a well-known and efficient algorithm for checking balanced parentheses using a stack.
*/
namespace ValidParenthesis
{
	class Solution 
	{
	public:
		bool isValid(string s)
		{
			stack<char>helper;
			int i = 0;
			while (i < s.length())
			{
				if (s[i] == ')' && helper.size() > 0 && helper.top() == '(')
					helper.pop();
				else  if (s[i] == '}' && helper.size() > 0 && helper.top() == '{')
					helper.pop();
				else  if (s[i] == ']' && helper.size() > 0 && helper.top() == '[')
					helper.pop();
				else
					helper.push(s[i]);
				i++;
			}
			return helper.empty();

		}

	};
	void process(){}
}