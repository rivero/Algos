#pragma once
/*
* https://leetcode.com/problems/basic-calculator-ii/description/
227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return
its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results 
will be in the 
range of [-2^31, 2^31 - 1].

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

## Algorithm and Complexity Explanation: Expression Calculation

This code implements an algorithm to evaluate a mathematical expression represented as a string. It uses a stack to handle operator precedence and parentheses are not supported.

**Algorithm Breakdown:**

1. **Initialization:**
   * `num` stores the current number being built.
   * `opr` stores the last encountered operator.
   * `st` (stack) stores intermediate results and operands.

2. **Iterate through the string:**
   * For each character `c`:
	  * If `c` is a digit:
		 * Append the digit to `num` by multiplying by 10 and adding the character's numeric value (converted from ASCII).
	  * If `c` is an operator (`+`, `-`, `*`, `/`) or the end of the string (`i == s.size() - 1`):
		 * Process the built `num` based on the previous operator (`opr`):
			* Push `num` onto the stack for `+`.
			* Push the negation of `num` onto the stack for `-`.
			* Perform multiplication with the top element of the stack and push the result back onto the stack for `*`.
			* Perform division with the top element of the stack and push the result back onto the stack for `/`.
		 * Update `opr` with the current operator.
		 * Reset `num` to 0.

3. **Calculate final result:**
   * Pop and add all remaining elements from the stack to get the final result.

**Complexity Analysis:**

* **Time complexity:** O(n), where n is the length of the expression string. This is because the loop iterates through each character once.
* **Space complexity:** O(n) in the worst case, as the stack can hold all operands and intermediate results for a long expression.

**Additional Notes:**

* The algorithm assumes that the expression is well-formed, meaning no missing operands or invalid operators.
* The code doesn't handle parentheses currently.
* The operators are evaluated based on their left-to-right order.

This approach efficiently evaluates expressions using a stack and provides a linear time solution.
*/
namespace BasicCalculatorII
{
	class Solution {
	public:
		int calculate(string s)
		{
			stack<int> operands;
			int sum = 0;
			char op = '+';
			int n = s.size();
			for (int i = 0; i < n; i++)
			{
				char c = s[i];
				if (isdigit(c))
					sum = sum * 10 + (c - '0');
				bool isOp = !isdigit(c) && !isspace(c);
				if (isOp || i == n - 1)
				{
					if (op == '+')
						operands.push(sum);
					else if (op == '-')
						operands.push(-sum);
					else if (op == '*')
					{
						int temp = operands.top() * sum;
						operands.pop();
						operands.push(temp);
					}
					else if (op == '/')
					{
						int temp = operands.top() / sum;
						operands.pop();
						operands.push(temp);
					}
					op = c;
					sum = 0;
				}
			}
			int ans = 0;
			while (!operands.empty())
				ans += operands.top(), operands.pop();
			return ans;
		}
	};	void process()
	{
		Solution sol;
		string calc("300 + 2 * 2");
		cout << sol.calculate(calc) << "\n";
	}
}