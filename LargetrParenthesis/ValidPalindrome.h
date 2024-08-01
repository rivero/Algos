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

## Algorithm Explanation

**Purpose:** Determines if a given string is a palindrome, ignoring non-alphanumeric characters and case sensitivity.

**Steps:**

1. **Base cases:** If the string is empty or has only one character, it's a palindrome.
2. **Initialize pointers:** `l` points to the beginning, `r` points to the end of the string.
3. **Iterate and compare:**
   * **Skip non-alphanumeric characters:** Increment `l` or decrement `r` as long as the current character is not 
   alphanumeric or whitespace.
   * **Compare characters:** If the characters at `l` and `r` are different (ignoring case), the string is not a palindrome.
   * **Advance pointers:** Move `l` forward and `r` backward.
4. **Return result:** If the loop completes without finding a mismatch, the string is a palindrome.

## Time Complexity

* **O(n):** In the worst case, the entire string is scanned once, where n is the length of the string. 
The inner loops for skipping non-alphanumeric characters don't affect the overall time complexity because 
they only skip characters and don't iterate through the whole string again.

## Space Complexity

* **O(1):** The algorithm uses constant extra space for the variables `l`, `r`, and possibly temporary 
variables for character comparisons. The space used doesn't grow with the input size.

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