#pragma once
namespace GroupShiftedStrings
{
	/*
	https://leetcode.com/problems/group-shifted-strings/description/

	249. Group Shifted Strings
	
	Perform the following shift operations on a string:

	Right shift: 
	Replace every letter with the successive letter of the English alphabet, where 'z' is replaced by 'a'. 
	
	For example, 
	"abc" can be right-shifted to "bcd" 
	or 
	"xyz" can be right-shifted to "yza".

	
	Left shift: 
	Replace every letter with the preceding letter of the English alphabet, where 'a' is replaced by 'z'. 
	
	For example, 
	"bcd" can be left-shifted to "abc" 
	or 
	"yza" can be left-shifted to "xyz".
	
	We can keep shifting the string in both directions to form an endless shifting sequence.

	For example, shift "abc" to form the sequence: 
	... <-> "abc" <-> "bcd" <-> ... <-> "xyz" <-> "yza" <-> .... <-> "zab" <-> "abc" <-> ...
	
	You are given an array of strings strings, group together all strings[i] that belong to the same shifting sequence. 
	You may return the answer in any order.



	Example 1:

	Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]

	Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]

	Example 2:

	Input: strings = ["a"]

	Output: [["a"]]



	Constraints:

	1 <= strings.length <= 200
	1 <= strings[i].length <= 50
	strings[i] consists of lowercase English letters.

	Solution

	The key to this problem is how to identify strings that are in the same shifting sequence. 
	There are different ways to encode this.

	In the following code, this manner is adopted: for a string s of length n, we encode its shifting feature as 
	
	"s[1] - s[0], s[2] - s[1], ..., s[n - 1] - s[n - 2],".

	Then we build an unordered_map, using the above shifting feature string as key and strings 
	that share the shifting feature as value. 
	We store all the strings that share the same shifting feature in a vector. 

	A final note, since the problem statement has given that "az" and "ba" belong to the same shifting sequence. 
	
	So if s[i] - s[i - 1] is negative, we need to add 26 to it to make it positive and give the correct result. 
	BTW, taking the suggestion of @StefanPochmann, we change the difference from numbers to lower-case alphabets 
	using 'a' + diff.
	*/
	class Solution 
	{
		string shift(const string& s)
		{
			string t;
			int n = s.length();
			for (int i = 1; i < n; i++)
			{
				int diff = s[i] - s[i - 1];
				if (diff < 0)
					diff += 26;

				t += 'a' + diff + ',';
			}
			return t;
		}
	public:
		vector<vector<string>> groupStrings(const vector<string>& strings) 
		{
			unordered_map<string, vector<string> > mp;
			for (string s : strings)
			{
				cout << "encoding " << s << "\n";
				mp[shift(s)].push_back(s);
			}

			for (auto& [str, vec]: mp)
			{
				cout << "str [" << str << "]\nvec:\n";
				printv(vec);
			}

			vector<vector<string> > groups;

			for (auto&[key, group] : mp)
			{
				groups.push_back(group);
			}
			return groups;
		}

	};	void process()
	{
		Solution sol;
		vector<string> strings
		{
			"abc","bcd","acef","xyz","az","ba","a","z"
		};
		auto res = sol.groupStrings(strings);
		for (auto& elem: res)
		{
			printv(elem);
		}
	}
}