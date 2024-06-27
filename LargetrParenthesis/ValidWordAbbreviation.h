#pragma once
/*
* https://leetcode.com/problems/valid-word-abbreviation/description/
* 
408. Valid Word Abbreviation
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings
with their lengths.
The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):
"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)

The following are not valid abbreviations:
"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)

Given a string word and an abbreviation abbr, return whether the string matches
the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.

Example 1:
Input: word = "internationalization", abbr = "i12iz4n"
Output: true
Explanation: The word "internationalization" can be abbreviated as
"i12iz4n" ("i nternational iz atio n").

Example 2:
Input: word = "apple", abbr = "a2e"
Output: false
Explanation: The word "apple" cannot be abbreviated as "a2e".

Constraints:
1 <= word.length <= 20
word consists of only lowercase English letters.
1 <= abbr.length <= 10
abbr consists of lowercase English letters and digits.
All the integers in abbr will fit in a 32-bit integer.

Solution

Get length of the string.
find the numbers and where they are in the string.
iterate add the lengths of the string + the numbers and make sure they match the length of the string.

Complexity
Time: O(n^2)
*/
namespace ValidWordAbbreviation
{
	struct ValidWordAbbreviation : public timeit
	{
		bool validWordAbbreviation(string word, string abbr)
		{
			size_t wordIdx = 0;
			size_t abbrIdx = 0;

			while (abbrIdx < abbr.length() && wordIdx < word.length())
			{
				size_t num = 0;
				bool startedWithDigit{};
				while (isdigit(abbr[abbrIdx]))
				{
					// Its a digit
					if (!startedWithDigit && abbr[abbrIdx] == '0')
						return false; // ...cannot start with '0'

					startedWithDigit = true; // mark is as true to avoid false flags
					num = num * 10 + abbr[abbrIdx] - '0'; // convert to number and add it to the number counter
					abbrIdx++; // increase the abbreviation index
				}

				if (num == 0)
				{ // no digits found
					if (word[wordIdx] != abbr[abbrIdx])
						return false; // no digits found and they are no equal => FALSE.
					wordIdx++; // move word index ahead
					abbrIdx++; // move abbreviation index ahead
				}
				else
				{
					wordIdx += num; // Digits found: increase the word index by the number found
				}
			}

			return wordIdx == word.length() && abbrIdx == abbr.length();
		}
	};

	void process()
	{
		cout << "ValidWordAbbreviation\n";

		ValidWordAbbreviation v;
		auto val = v.validWordAbbreviation("substitution", "s10n");
		cout << "substitution : s10n : " << (val ? "VALID": "-invalid-") << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "sub4u4");
		cout << "substitution : sub4u4 : " << (val ? "VALID": "-invalid-") << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "12");
		cout << "substitution : 12 : " << (val ? "VALID": "-invalid-") << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "su3i1u2on");
		cout << "substitution : su3i1u2on : " << (val ? "VALID": "-invalid-") << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "s55n");
		cout << "substitution : s55n : " << (val ? "VALID": "-invalid-") << "\n";
		assert(!val);

		val = v.validWordAbbreviation("substitution", "s010n");
		cout << "substitution : s010n : " << (val ? "VALID": "-invalid-") << "\n";
		assert(!val);

		val = v.validWordAbbreviation("substitution", "s0ubstitution");
		cout << "substitution : s0ubstitution : " << (val ? "VALID": "-invalid-") << "\n";
		assert(!val);

		val = v.validWordAbbreviation("word", "3e");
		cout << "word : 3e : " << (val ? "VALID": "-invalid-") << "\n";
		assert(!val);

	}
}
