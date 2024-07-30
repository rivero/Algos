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

	My Solution

		abc ->encoding ->   vector {1, 1} => map key
		bcd ->              vector {1, 1}
		acef ->             vector {2, 2, 1}

		["a","z", "abc","bcd","acef","xyz","az","ba"]

		vector<int> encode (string str)
		{
		  vector <int> res;
		  // edge case str.len == 1
		  if (str.size() == 1)
		  {
			res.push_back(0);
			return res;
		  }
		a
		  for (int i = 1; i < str.size(); i++)
		  {
			auto dist = str[i] - str[i-1];
			res.push_back(dist);
		  }
		  return res;
		}

		vector< vector<string> >groupStrings(vector<string> strings)
		{
		  map< vector<int>, vector<string> > m;
		  for(auto s: strings)
		  {
			auto enc = encode(s);
			m[enc].push_back(s);
		  }
		  vector <  vector<string> > res;
		  for (auto [envec, strvec]: m)
		  {
			res.push_back(strvec);
		  }
		  return res;
		}


		Input: strings = ["abc","bcd","acef"]

		Time complexity is O(n * m) where n is the length of the string vector and 
		m is the lenght of the longest string in the vector.

		feedback:
			1. read and understand the question very well and ask clarification from your interviewer.
			2. Dry run.
			3. Communication O(), you need to explain what is n / m or any other variable.
			4. you still taking too much time for any problem, , more practice is required. 6 months.

			1. Read the question / ask clarifying questions.
			2. Think about the edge cases.
			3. Think about the solutions.different run time complexities
			4. Coding
			5. Verification / dry run
			6. Run edge cases.
			7. Tell your interviewer that it is ready.


				HW:
			1. Again practicing more.
			2. Practice system design.
			3. Behavioral : LP 16, you need to make stories for all the 16 LP.

	Time Complexity:
		Let’s analyze the time complexity step by step:
		The shift function processes each character in the input string once, resulting in a linear time complexity of O(n), 
		where n is the length of the input string.
		The loop that iterates over the input strings (in the groupStrings function) also takes linear time, as it processes 
		each string once.
		The insertion and lookup operations in the unordered map (mp) take average constant time (amortized O(1)) for each string.
		Therefore, the overall time complexity is dominated by the linear processing of the input strings, resulting in O(N), 
		where N is the total length of all input strings combined.
	Space Complexity:
		The space complexity includes the memory required by data structures used in the algorithm.
		The primary data structures are:
		The unordered map (mp), which stores the transformed strings as keys and vectors of strings as values. 
		The space required for this map is proportional to the number of unique transformed strings, which can 
		be at most the total number of input strings.
		The vector of vectors (groups), which stores the grouped strings. The space required here is proportional 
		to the total number of input strings.
		Therefore, the space complexity is O(N), where N represents the total length of all input strings combined.
	In summary:

		Time Complexity: O(N)
		Space Complexity: O(N)

		From AI
		Certainly! Let's delve into the algorithm and discuss its complexities.

The given code snippet defines a function called `groupStrings` that groups strings based on a specific property. 

1. **String Shifting**:
   - The `shift` function takes a string `s` as input and computes a shifted representation of it.
   - For each adjacent pair of characters in `s`, it calculates the difference (modulo 26) between their ASCII values.
   - If the difference is negative, it wraps around by adding 26.
   - The resulting shifted string is constructed by appending these differences (represented as characters) with commas.

2. **Grouping Strings**:
   - The main function `groupStrings` processes an input vector of strings (`strings`).
   - It maintains an unordered map (`mp`) where the keys are the shifted representations of strings, and the values are vectors 
   of original strings.
   - For each input string `s`, the algorithm computes its shifted representation using the `shift` function and adds it to the 
   corresponding group in the map.
   - This step ensures that strings with the same shifted representation are grouped together.

3. **Output**:
   - After processing all input strings, the algorithm constructs the final result.
   - It iterates through the map entries and appends the grouped strings to the `groups` vector.

**Time Complexity**:
- The `shift` function processes each character in a string, resulting in linear time complexity (O(n)) for each string.
- The overall time complexity depends on the total number of characters across all input strings.
- Let `N` be the total number of characters in all strings combined.
- Constructing the map (`mp`) takes O(N) time.
- Constructing the output vector (`groups`) also takes O(N) time.
- Therefore, the overall time complexity of the `groupStrings` algorithm is O(N).

**Space Complexity**:
- The space complexity is determined by the additional data structures used:
  - The map (`mp`) stores shifted representations as keys and vectors of strings as values. Its space complexity is O(N).
  - The output vector (`groups`) also contributes to the space complexity.
- Thus, the overall space complexity is O(N).

*/

	class Solution : public timeit
	{
		/*For each adjacent pair of characters in `s`, it calculates the difference (distance) between their ASCII values.
			- If the difference is negative, it wraps around by adding 26.
			it creates a string containing the differences (represented as characters) with commas as a string
		*/
		string shift(const string& s)
		{
			string t;
			auto n = s.size();
			for (int i = 1; i < n; i++)
			{
				char diff = s[i] - s[i - 1];
				if (diff < 0)
					diff += 26;
				t += diff;
			}
			return t;
		}
	public:
		vector<vector<string>> groupStrings(const vector<string>& strings) 
		{
			unordered_map<string, vector<string> > mp;
			for (string s : strings)
			{
				mp[shift(s)].push_back(s);
			}

			/*For each input string `s`, the algorithm computes its shifted representation using the `shift` function and adds it to the
   corresponding group in the map.
   - This step ensures that strings with the same shifted representation are grouped together.*/
			vector<vector<string> > groups;

			for (auto&[key, group] : mp)
			{
				groups.push_back(group);
			}
			return groups;
		}

	};		

	class SolutionJ : public timeit
	{
		/*
		My Solution

		abc ->encoding ->   vector {1, 1} => map key
		bcd ->              vector {1, 1}
		acef ->             vector {2, 2, 1}
		*/
		vector<int> encode(string str)
		{
			vector <int> res;
			// edge case 1: empty string
			if (str.empty())
			{
				return res;
			}
			// edge case 2: str.len == 1
			if (str.size() == 1)
			{
				res.push_back(0);
				return res;
			}

			for (int i = 1; i < str.size(); i++)
			{
				auto dist = str[i] - str[i - 1];
				if (dist < 0)
					dist += 26;

				res.push_back(dist);
			}
			return res;
		}
	public:
		vector< vector<string> >groupStrings(vector<string> strings)
		{
			map< vector<int>, vector<string> > m;
			for (auto& s : strings)
			{
				auto enc = encode(s);
				m[enc].push_back(s);
			}
			vector <  vector<string> > res;
			for (auto& [envec, strvec] : m)
			{
				res.push_back(strvec);
			}
			return res;
		}

	};
	
	void process()
	{
		{
			Solution sol;
			vector<string> strings
			{
				"abc","bcd","acef","xyz","az","ba","a","z"
			};
			auto res = sol.groupStrings(strings);
			for (auto& elem : res)
			{
				printv(elem);
			}

		}
		{
			SolutionJ sol;
			vector<string> strings
			{
				"abc","bcd","acef","xyz","az","ba","a","z"
			};
			auto res = sol.groupStrings(strings);
			for (auto& elem : res)
			{
				printv(elem);
			}

		}
	}
}