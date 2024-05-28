#pragma once
/*
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
iterate add the lenghts of the string + the numbers and make sure they match the length of the string.

*/
struct ValidWordAbbreviation : public timeit
{
	bool validWordAbbreviation(string word, string abbr)
	{
		size_t wordIdx = 0;
		size_t abbrIdx = 0;

		while (abbrIdx < abbr.length() && wordIdx < word.length())
		{
			size_t num = 0;
			bool start{};
			while (isdigit(abbr[abbrIdx]))
			{
				if (!start && abbr[abbrIdx] == '0')
					return false; // starts with '0'

				start = true;
				num = num * 10 + abbr[abbrIdx] - '0'; // convert to number
				abbrIdx++;
			}

			if (num == 0)
			{
				if (word[wordIdx] != abbr[abbrIdx])
					return false; // no number and they are no equal.
				wordIdx++;
				abbrIdx++;
			}
			else
			{
				wordIdx += num;
			}
		}

		return wordIdx == word.length() && abbrIdx == abbr.length();
	}
};
