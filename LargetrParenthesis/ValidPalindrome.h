#pragma once
/*
https://leetcode.com/problems/valid-palindrome/description

125. Valid Palindrome
Easy
Topics
Companies
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all 
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

*/
namespace ValidPalindrome
{
	class Solution 
	{
	public:
		bool isPalindrome(string s)
		{
			if (s.empty() || s.size() == 1)
				return true;

			int l{}, r = s.size() - 1;
			while (l < r)
			{
				// skip invalid chars at the left
				while ((!isalnum(s[l]) || isspace(s[l])) && l < r)
					l++;
				// skip invalid values at the right
				while((!isalnum(s[r]) || isspace(s[r])) && l < r)
					r--;
				if (tolower(s[l]) != tolower(s[r]))
					return false;
				l++;
				r--;
			}
			return true;

		}
	};

	void process() 
	{
		Solution sol;
		cout << sol.isPalindrome("A man, a plan, a canal: Panama") << "\n";
		cout << sol.isPalindrome("a.") << "\n";
		cout << sol.isPalindrome(".,") << "\n";
	}
}