#pragma once
/*
* https://leetcode.com/problems/valid-palindrome-ii/description/
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

namespace ValidPalindromeII
{
	struct Solution : public timeit
	{
		bool validPalindrome(const string& s) const
		{
			int i = 0;
			int j = s.length() - 1;

			while (i < j)
			{
				if (s[i] == s[j])
				{
					i++;
					j--;
				}
				else
					return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
			}

			return true;
		}

		bool isPalindrome(const string& s, int i, int j) const
		{
			while (i < j)
			{
				if (s[i++] != s[j--])
					return false;
			}

			return true;
		}
	};

	void process()
	{
		cout << "\nValidPalindrome\n";
		Solution v;
		auto val = v.validPalindrome("aba");
		cout << " Valid palindrome (1 char removed) [aba]: " << (val?"Valid" :"invalid") << "\n";
		assert(val);

		val = v.validPalindrome("abac");
		cout << " Valid palindrome (1 char removed) [abac]: " << (val ? "Valid" : "invalid") << "\n";
		assert(val);

		val = v.validPalindrome("medem");
		cout << " Valid palindrome (1 char removed) [medem]: " << (val ? "Valid" : "invalid") << "\n";
		assert(val);

		val = v.validPalindrome("medecm");
		cout << " Valid palindrome (1 char removed) [medecm]: " << (val ? "Valid" : "invalid") << "\n";
		assert(val);

		string tst = "mecdecm";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << (val ? "Valid" : "invalid") << "\n";
		assert(!val);

		tst = "mecdcem";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << (val ? "Valid" : "invalid") << "\n";
		assert(val);

		tst = "mecdcfm";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << (val ? "Valid" : "invalid") << "\n";
		assert(!val);

		tst = "abc";
		val = v.validPalindrome(tst);
		cout << " Valid palindrome (1 char removed) [" << tst << "]: " << (val ? "Valid" : "invalid") << "\n";
		assert(!val);

	}
}
