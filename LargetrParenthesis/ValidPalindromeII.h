#pragma once
/*
* https://leetcode.com/problems/valid-palindrome-ii/description/
680. Valid Palindrome II

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

1. **Algorithm Explanation**:
   - The `validPalindrome` function checks whether a given string `s` is a valid palindrome after removing at most one character.
   - The algorithm follows these steps:
	 1. Initialize two pointers, `i` (starting from the beginning) and `j` (starting from the end) of the string `s`.
	 2. While `i` is less than `j`, do the following:
		- If `s[i]` is equal to `s[j]`, move both pointers inward (increment `i` and decrement `j`).
		- If `s[i]` is not equal to `s[j]`, it means we encountered a mismatch.
		  - We have two options:
			1. Skip the character at `i` and check if the remaining substring (`s[i+1:j]`) is a palindrome. 
				This is done by calling the helper function `pal(s, i + 1, j)`.
			2. Skip the character at `j` and check if the remaining substring (`s[i:j-1]`) is a palindrome. 
				This is also done by calling `pal(s, i, j - 1)`.
		  - If either of these options returns true, the string can be made a palindrome by removing one character.
	 3. If the loop completes without encountering any mismatches, return `true` (the original string is a valid palindrome).
	 4. Otherwise, return `false`.

2. **Complexities**:
   - Time Complexity: O(N), where N is the length of the string `s`.
	 - The algorithm processes each character in `s` once.
   - Space Complexity: O(1), as no additional data structures are used; the checks are performed in place using the two pointers.

3. **Example**:
   - Input: `"abca"`
	 - We can remove 'b' to make it a palindrome: `"aca"`.
	 - Output: `true`


*/

namespace ValidPalindromeII
{
	class Solution : public timeit
	{
	public:
		bool validPalindrome(const string& s)
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
					return pal(s, i + 1, j) || pal(s, i, j - 1);
			}
			return true;
		}
		bool pal(const string& s, int i, int j)
		{
			while (i < j)
				if (s[i++] != s[j--])
					return false;
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
