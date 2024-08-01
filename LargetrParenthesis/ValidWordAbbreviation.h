#pragma once
/*
* https://leetcode.com/problems/valid-word-abbreviation/description/
* 
408. Valid Word Abbreviation
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths.
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

## Algorithm Explanation

**Purpose:** Determines if an abbreviation `abbr` is valid for a given word `word`.

**Logic:**

1. **Initialize indices:** `wordIdx` and `abbrIdx` point to the current characters in `word` and `abbr`, respectively.
2. **Iterate through both strings:**
   * **Handle digits:**
	 * If the current character in `abbr` is a digit:
	   * Ensure the digit is not a leading zero.
	   * Convert the consecutive digits to a number `num`.
	   * Increment `wordIdx` by `num` to skip the corresponding characters in `word`.
   * **Handle characters:**
	 * If the current characters in `word` and `abbr` match, increment both indices.
	 * Otherwise, return `false`.
3. **Check for complete match:** After the loop, return `true` if both indices reached the end of their respective strings, 
indicating a valid abbreviation. Otherwise, return `false`.

## Time Complexity: O(m + n)
* `m` is the length of `word`.
* `n` is the length of `abbr`.
* The algorithm iterates through both strings at most once, resulting in a linear time complexity.

## Space Complexity: O(1)
* The algorithm uses a constant amount of extra space for variables, regardless of the input size.

**Key points:**

* The algorithm efficiently handles both characters and numeric abbreviations.
* It correctly handles leading zeros in the abbreviation.
* The time and space complexities are optimal for this problem.

---
**Succinct Explanation:**

The algorithm validates if an abbreviation matches a word. And abbreviation subtitutes letters with numbers. 
It iterates through both strings simultaneously, handling digits in the abbreviation by skipping corresponding characters in the 
word, avoiding leading zeroes. 
The process continues until both strings are fully processed, and a boolean result indicates a match or mismatch.

*/
namespace ValidWordAbbreviation
{
	struct ValidWordAbbreviation : public timeit
	{
		/*
		Using two pointers/indexes one to the abbreviation and the other to the original word.
		start both from zero and proceed to move forward in the string in a while loop. We will test 
		to find the first digit which shoult *NOT* be zero. It it is return false.
		In the loop, create a boolean to start digits with zero and another one to numerically sum the abbreviated number.
		Otherwise set our startWihtdigitFlag to true and convert the char to numeric and add it to the numeric counter.
		After we finish couting and adding the numeric characters, test to see if the in-loop local num value is different from 0.
		If it is 0, there where no digits found. Test to see if both abbr and word index are the same (they should be). If they
		are not, return false.
		If the num is not zero, add that number to the word index. This will move that pointer num positions ahead and it must stil match
		the original char counter of the word parameter.
		*/
		bool validWordAbbreviation(string word, string abbr)
		{
			size_t wIdx = 0;
			size_t aIdx = 0;
			while (aIdx < abbr.size() && wIdx < word.size())
			{
				size_t num = 0;
				bool isDig = false;
				while (isdigit(abbr[aIdx]))
				{
					if (abbr[aIdx] == '0' && !isDig)
						return false;
					isDig = true;
					num = num * 10 + abbr[aIdx] - '0'; // convert to num and add
					aIdx++;
				}

				if (num == 0) // no abbr found
				{
					if (word[wIdx] != abbr[aIdx])
						return false;
					wIdx++, aIdx++;
				}
				else // nu found
				{
					wIdx += num; // skip num spaces in word
				}
			}
			return wIdx == word.size() && aIdx == abbr.size();
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
