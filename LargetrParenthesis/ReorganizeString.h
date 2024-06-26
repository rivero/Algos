#pragma once
/*
* https://leetcode.com/problems/reorganize-string/
* 
* 767. Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

Solution
https://leetcode.com/problems/reorganize-string/solutions/3967182/simple-c-solution-using-priority-queue-hash-map-and-pair/


ankitapatilcse
Aug 27, 2023
C++
Hash Table
Heap (Priority Queue)

Approach
	Determine character frequencies using a hashmap.
	We now repeatedly select the most frequent character that isn't previously selected.
	This can be done efficiently using a priority queue.
	The character and it's frequency is stored in the priority queue using a pair.

Complexity
	Let N be the total characters in the string.
	Let k be the total unique characters in the string.

	Time complexity: The time complexity of this approach is O(N*logk) as we add one character to the result string 
	per operation and each priority queue operation costs logk.
	Space complexity: The maximum size of the priority queue is O(k) as there k distinct characters.

*/
namespace ReorganizeString
{

	class Solution {
	public:
		string reorganizeString(string s) 
		{
			int n = s.length();
			unordered_map<char, int>mp;
			for (int i = 0; i < n; i++) 
			{
				mp[s[i]]++;
			}
			
			priority_queue<pair<int, char>>pq;
			for (auto [chr, counter] : mp)
			{
				pq.push({counter, chr});
			}
			
			string ans;
			while (!pq.empty()) 
			{
				auto [counter, chr] = pq.top(); pq.pop();
				if (ans.empty() || chr != ans.back()) 
				{
					ans += chr;
					if (--counter > 0) 
					{
						pq.push({counter, chr});
					}
				}
				else 
				{
					if (pq.empty()) 
					{
						return "";
					}
					auto [cnt, ch] = pq.top(); pq.pop();
					ans += ch;
					if (--cnt > 0) 
					{
						pq.push({cnt, ch});
					}
					pq.push({ counter, chr });
				}
			}
			return ans;
		}
	};
	void process()
	{
		Solution sol;
		cout << sol.reorganizeString("aab") << "\n";
		cout << sol.reorganizeString("aaab") << "\n";
	}
}