#pragma once
namespace PlatesBetweenCandles
{
	/*
	* https://leetcode.com/problems/plates-between-candles/description/
	* 2055. Plates Between Candles
Medium
Topics
Companies
Hint
There is a long table with a line of plates and candles arranged on top of it. 
You are given a 0-indexed string s consisting of characters '*' and '|' only, 
where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where 
queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). 
For each query, you need to find the number of plates between candles that are in the substring. 
A plate is considered between candles if there is at least one candle to its left and at least 
one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|".
query [3, 8]

||**||**|* <- len = 10 [0,9]
   ^     ^         
| | * * | | * * | *
0 1 2 3 4 5 6 7 8 9
      ^         ^ <- query 3, 8
The number of plates between candles in this substring is 2, as each of the two plates has at 
least one candle in the substring to its left and right.

Return an integer array answer where answer[i] is the answer to the ith query.

Example 1:

ex-1
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.

Example 2:

ex-2
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.


Constraints:

3 <= s.length <= 10^5
s consists of '*' and '|' characters.
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= lefti <= righti < s.length
	*/

	struct Solution 
	{
		// return the number of plates in the substring
		int numPlates(const string& subStr)
		{
			int count = 0;
			// find first '|'
			int li{};
			for (int i = 0; i < subStr.size(); i++)
			{
				if (subStr[i] == '|')
				{
					li = i;
					break;
				}
			}
			// find last '|'
			int ri{};
			for (int i = subStr.size() - 1; i >= 0; i--)
			{
				if (subStr[i] == '|')
				{
					ri = i;
					break;
				}
			}
			if (ri > li)
			{
				for (int i = li; i <= ri; i++)
				{
					if (subStr[i] == '*')
						count++;
				}
			}

			return count;
		}
		vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries)
		{
			vector<int> res;
			for (auto& query : queries)
			{
				auto len = query[1] - query[0] + 1;
				auto subStr = s.substr(query[0], len);
				auto n = numPlates(subStr);
				res.push_back(n);
			}
			return res;
		}
	};

	void process()
	{
		Solution sol;
		{
			string s = "||**||**|*";
			vector<vector<int>> queries
			{
				{3, 8}
			};
			// expected {2, 3}
			auto res = sol.platesBetweenCandles(s, queries);
			printv(res);

		}
		{
			string s = "**|**|***|";
			vector<vector<int>> queries
			{
				{2, 5},
				{5, 9}
			};
			// expected {2, 3}
			auto res = sol.platesBetweenCandles(s, queries);
			printv(res);

		}
		{
			string s = "***|**|*****|**||**|*";
			vector<vector<int>> queries
			{
							{1, 17},
							{4, 5},
							{14, 17},
							{5, 11},
							{15, 16}
			};
			// expected  [9,0,0,0,0]
			auto res = sol.platesBetweenCandles(s, queries);
			printv(res);

		}
	}
}