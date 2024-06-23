#pragma once
namespace PlatesBetweenCandles
{
	/*
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

	class Solution 
	{
		int result(const string& s)
		{
			// edge case
			int res{};
			if (s.empty() || s.size() < 3)
			{
				return res;
			}

			int mid = s.size() / 2;
			int size = s.size();
			int left{mid-1}, right{mid};
			int indexLeft{INT_MAX}, indexRight{-INT_MAX};
			do
			{
				if (s[left] == '|' && indexLeft == INT_MAX)
				{
					indexLeft = left;
				}
				else if (left > 0)
					left--;
				
				if (s[right] == '|' && indexRight == -INT_MAX)
				{
					indexRight = right;
				}
				else if (right < size -1)
					right++;
				
				
				if (left < 0)
				{
					break;
				}
				if (right >= size)
				{
					break;
				}
				if (indexLeft < indexRight)
					break;
			} while (true);

			if (indexLeft < indexRight - 1)
			{
				string str = s.substr(indexLeft+1, indexRight-1);
				res = str.size();
			}
			return res;

		}
	public:
		vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) 
		{
			vector<int> res;
			for (auto& query:queries)
			{
				auto begin = query[0];
				auto end = query[1] - begin;
				string str  = s.substr(begin, end + 1);
				res.push_back(result(str));
			}
			return res;
		}
	};

	void process()
	{
		Solution sol;
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