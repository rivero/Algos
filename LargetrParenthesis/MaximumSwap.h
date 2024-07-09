#pragma once
/*
670. Maximum Swap

You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.

Constraints:

0 <= num <= 108

solution

Certainly! Let's analyze the given `maximumSwap` function.

1. **Function Description:**
   - The `maximumSwap` function takes an integer `num` as input and returns an integer.
   - If `num` is less than or equal to 11, it directly returns `num`.
   - Otherwise, it performs a series of swaps on the digits of `num` to find the maximum possible value.

2. **Algorithm Overview:**
   - Convert the input integer `num` to a string `s`.
   - Iterate through all pairs of indices `(i, j)` where `i` ranges from 0 to `s.size() - 1` and `j` ranges from 1 to `s.size() - 1`.
   - Swap the characters at indices `i` and `j` in the string `s`.
   - If the resulting integer after the swap is greater than the current maximum (`ans`), update `ans`.
   - Swap the characters back to their original positions.
   - Return the final value of `ans`.

3. **Complexity Analysis:**
   - Let `n` be the number of digits in the input `num`.
   - The nested loops iterate over all pairs of indices, resulting in a time complexity of O(n^2).
   - The space complexity is O(n) due to the string `s`.


*/
namespace MaximumSwap
{
	class Solution 
	{
	public:
		string s;
		int ans = 0;
		int maximumSwap(int num) 
		{
			if (num <= 11)
			{
				return num;
			}
			s = to_string(num);

			for (int i = 0; i < s.size(); i++) 
			{
				for (int j = 1; j < s.size(); j++) 
				{
					swap(s[i], s[j]);

					if (ans < stoi(s))
						ans = stoi(s);

					swap(s[i], s[j]);
				}
			}
			return ans;
		}
	};	
	void process()
	{
		Solution sol;
		cout << "input: 2736:\t Output:"  << sol.maximumSwap(2736) << "\n";
		cout << "input: 9973:\t Output:"  << sol.maximumSwap(9973) << "\n";
		cout << "input: 98368:\tOutput:" << sol.maximumSwap(98368) << "\n";
		cout << "input: 99901:\tOutput:" << sol.maximumSwap(99901) << "\n";
	}
}
