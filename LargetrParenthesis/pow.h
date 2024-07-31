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

**Algorithm Breakdown:**

This code implements a recursive function `fast_power` to efficiently calculate `base` raised to the power of `pwr`. 
It uses a divide-and-conquer approach with memoization to optimize performance:

1. **Base Cases:**
   - If `pwr` is 0, return 1 (any number raised to the power of 0 is 1).
   - If `pwr` is 1, return `base` (any number raised to the power of 1 is itself).

2. **Memoization Check:**
   - The function first checks if the result for `pwr` has already been calculated and stored in the `powers` map. 
   If found, it directly returns the cached value. This saves redundant calculations for frequently used powers.

3. **Recursive Call with Half Power:**
   - If `pwr` is not found in the map, the function calculates the result for `base` raised to `pwr / 2` recursively. 
   This reduces the problem size by half in each recursive call.

4. **Squaring the Result (`result *= result`):**
	 - Since we're calculating powers that are often even (`pwr` is divisible by 2), 
	 raising `base` to `pwr` can be efficiently computed by squaring the result obtained for `pwr / 2`.
	 - Squaring essentially multiplies the base by itself `pwr / 2` times, which is equivalent 
	 to calculating `base ^ (pwr / 2) * base ^ (pwr / 2)`.

5. **Handling Odd Powers:**
   - After squaring, if `pwr` is odd (`pwr % 2 == 1`), the function multiplies the result by `base` one more time. 
   This accounts for the additional base needed for an odd power.

6. **Memoization and Return:**
   - The final result for `base ^ pwr` is calculated and stored in the `powers` map for future use.
   - The function then returns the calculated result.

**Why `result *= result` is Necessary:**
- This step exploits the property of exponentiation that `a ^ n = (a ^ (n / 2)) ^ 2` (for even `n`).
- The `result *= result` essentially squares the base raised to half the power, effectively achieving `base ^ pwr` for even `pwr`.
- We are working with even poiwers and then correct for odd in the last step when we result *= base

**Overall, the `fast_power` function provides a time-efficient solution for calculating exponentiations by:**

- Reducing the problem size with divide-and-conquer.
- Avoiding redundant calculations with memoization.
- Optimizing even power calculations with squaring.

	3. Recursion:
		- The `fast_power` function continues this process recursively until it reaches the base cases (when `n` is 0 or 1).

	## Example: Calculating 2^8 using the `fast_power` algorithm

	### Breakdown

	Let's break down the calculation of `2^8` using the `fast_power` algorithm:

	1. **Initial call:** `fast_power(2, 8)`
	2. **Recursive call:** `fast_power(2, 4)`
	3. **Recursive call:** `fast_power(2, 2)`
	4. **Base case:** `fast_power(2, 1)` returns 2
	5. **Squaring:** `result = 2 * 2 = 4`
	6. **Memoization:** Store `4` in `powers` for `pwr = 2`
	7. **Return:** `4`
	8. **Squaring:** `result = 4 * 4 = 16`
	9. **Memoization:** Store `16` in `powers` for `pwr = 4`
	10. **Return:** `16`
	11. **Squaring:** `result = 16 * 16 = 256`
	12. **Memoization:** Store `256` in `powers` for `pwr = 8`
	13. **Return:** `256`

	### Explanation

	The algorithm effectively calculates `2^8` by recursively dividing the power by 2, squaring the result at each step, 
	and handling odd powers appropriately. Memoization is used to store intermediate results, preventing redundant calculations.

	The final result is `256`.


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