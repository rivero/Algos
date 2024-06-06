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
	*/

	class Solution
	{
	public:
		double myPow(double x, int n)
		{
			// edge cases
			if (n == 0)
			{
				return 1;
			}

			if (n == INT_MAX)
				return (x == 1) ? 1 : (x == -1) ? -1 : 0;

			if (n == INT_MIN)
				return (x == 1 || x == -1) ? 1 : 0;

			auto pwr = abs(n);
			auto base = x;
			for (int i = 1; i < pwr; i++)
			{
				x *= base;
			}
			if (n < 0)
			{
				x = 1 / x;
			}
			return x;
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