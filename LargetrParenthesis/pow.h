#pragma once
namespace mypow
{
	/*
	* https://leetcode.com/problems/powx-n/
	* 
	* 50. Pow(x, n)
	Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

	Example 1:
	Input: x = 2.00000, n = 10
	Output: 1024.00000

	Example 2:
	Input: x = 2.10000, n = 3
	Output: 9.26100

	Example 3:
	Input: x = 2.00000, n = -2
	Output: 0.25000
	Explanation: 2-2 = 1/22 = 1/4 = 0.25

	Constraints:

	-100.0 < x < 100.0
	-2^31 <= n <= 2^31-1
	n is an integer.
	Either x is not zero or n > 0.
	-10^4 <= xn <= 10^4

	x = 0.00001
	n = 2147483647

	Output 1.00000
	Expected 0.00000

	x = 1.00000
	n = 2147483647

	Output 0.00000
	Expected 1.00000



	Input
	x = 1.0000000000001
	n = -2147483648

	Output 0.00000
	Expected 0.99979

	Solution
	We use a memoization table (memo) to store previously computed results.
	The power() function recursively calculates the value of x raised to the power of n.
	It splits the problem into smaller subproblems by dividing the exponent by 2.
	If n is odd, we multiply the result by x once more.
	The memoization table ensures that we avoid redundant calculations

	1. `fast_power(x, n/2)`:
			- When computing `x^n`, we can divide the problem into smaller subproblems by considering `x^(n/2)`.
			- By recursively calculating `fast_power(x, n/2)`, we effectively split the problem in half.
			- The idea is to compute the result for `n/2` and then use it to build the result for `n`.
			- This approach reduces the number of multiplications needed to compute the final result.

	2. Example:
		- Suppose we want to calculate `x^8`.
		- Instead of directly multiplying `x` eight times, we can break it down as follows:
			- Compute `x^4` by calling `fast_power(x, 8/2)`.
			- Then square the result: `(x^4)^2`.
			- This gives us `x^8`.

	3. Recursion:
		- The `fast_power` function continues this process recursively until it reaches the base cases (when `n` is 0 or 1).
		- By dividing the problem into smaller halves, it efficiently computes the final result.

In summary, `fast_power(x, n/2)` is a crucial step in the algorithm for calculating `x` raised to the power of `n`.

	Time Complexity:
		The function uses a divide-and-conquer approach by recursively computing the power of x to the n/2 and 
		then combining the results.
		The recursive call occurs for each halving of n, which means the number of recursive calls is 
		proportional to the number of bits in n.
		Therefore, the time complexity can be expressed as O(log n), where n represents the exponent.
		This logarithmic behavior arises because each recursive step reduces the problem size by half.
		The memoization (caching) of previously computed results further optimizes the time complexity 
		by avoiding redundant calculations.
	Space Complexity:
		The space complexity refers to the amount of memory required by the algorithm.
		In this case, the memoization table (memo) stores previously computed results.
		Since the table has at most n entries (one for each unique pair of x and n), the space complexity is O(n).
		Note that the space complexity is not affected by the recursive call stack, as it remains constant 
		regardless of the recursion depth.
	In summary:

		Time Complexity: O(log n)
		Space Complexity: O(n)
*/

	class Solution
	{
		unordered_map<int, double> m_map;
		double fast_power(double x, int n)
		{
			if (n == 0)
				return 1;
			if (n == 1)
				return x;

			if (m_map.find(n) != m_map.end())
			{
				return m_map.at(n);
			}

			auto result = fast_power(x, n / 2);
			result *= result;
			if (n % 2 == 1) 
			{
				result *= x;
			}

			m_map[n] = result;
			return result;
		}
	public:
		double myPow(double x, int n)
		{

			if (n == INT_MAX)
				return (x == 1) ? 1 : (x == -1) ? -1 : 0;

			if (n == INT_MIN)
				return (x == 1 || x == -1) ? 1 : 0;

			auto pwr = abs(n);
			double res = fast_power(x, pwr);
			if (n<0)
			{
				res = 1 / res;
			}
			return res;
		}
	};

	void process()
	{
		Solution sol;
		cout << sol.myPow(2.0, 10) << "\n";
		cout << sol.myPow(2.1, 3) << "\n";
		cout << sol.myPow(2.0, -2) << "\n";
		cout << sol.myPow(1.0, -2147483648) << "\n"; // expected 1
		cout << sol.myPow(0.00001, 2147483648) << "\n"; // expected 0
		cout << sol.myPow(-1, 2147483647) << "\n"; // expected 0
		cout << sol.myPow(1.0000000000001, -2147483648) << "\n"; // expected 0.99979
		cout << sol.myPow(1.0000000000002, -2147483648) << "\n"; // expected 0.99957
	}
}