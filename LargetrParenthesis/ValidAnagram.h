#pragma once

/*

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
struct ValidAnagram : public timeit
{
	bool isAnagram1(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
	bool isAnagram(string s, string t)
	{
		//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

		vector<int> r1(26), r2(26);

		for (auto c1 : s)
		{
			r1[c1 - 'a']++;
		}

		for (auto c2 : t)
		{
			r2[c2 - 'a']++;
		}

		for (size_t i = 0; i < r1.size(); i++)
		{
			if (r1[i] != r2[i])
				return false;
		}
		return true;
	}
};
