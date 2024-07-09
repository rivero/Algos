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
