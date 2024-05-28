#pragma once
/*
680. Valid Palindrome II
Easy
Topics
Companies
Given a string s, return true if the s can be palindrome after deleting at most
one character from it.


Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

Solution

Using two pointers, iterate them to meet in the middle
if there is one character not matching the other ignore this problem once.
continue iterating

Result: if the characters from the right and the left are the same return true

*/

struct ValidPalindrome : public timeit
{
	bool validPalindrome(string s) {
		size_t i = 0;
		size_t j = s.length() - 1;

		while (i < j)
		{
			if (s[i++] == s[j--])
			{
			}
			else
				return isPalindrome(s, i, j) || isPalindrome(s, i, j);
		}

		return true;
	}

	bool isPalindrome(string s, int i, int j)
	{
		while (i < j)
		{
			if (s[i++] != s[j--])
				return false;
		}

		return true;
	}
};
