#pragma once
/*
* https://leetcode.com/problems/analyze-user-website-visit-pattern/description/
* 
1152. Analyze User Website Visit Pattern

You are given two string arrays username and website and an integer array timestamp. 

All the given arrays are of the same length 
and the tuple [username[i], website[i], timestamp[i]] 
indicates that the user username[i] visited the website website[i] at time timestamp[i].


A pattern is a list of three websites (not necessarily distinct).

For example, 
["home", "away", "love"], 
["leetcode", "love", "leetcode"], and 
["luffy", "luffy", "luffy"] 

are all patterns.

The score of a pattern is the number of users that visited all the websites in the 
pattern in the same order they appeared in the pattern.

For example, if the pattern is ["home", "away", "love"], the score is the number of 
users x such that x visited "home" then visited "away" and visited "love" after that.

Similarly, if the pattern is ["leetcode", "love", "leetcode"], the score is the number 
of users x such that x visited "leetcode" then visited "love" and visited "leetcode" 
one more time after that.

Also, if the pattern is ["luffy", "luffy", "luffy"], the score is the number of users
x such that x visited "luffy" three different times at different timestamps.

Return the pattern with the largest score. If there is more than one pattern with the 
same largest score, return the lexicographically smallest such pattern.

Example 1:

Input: 
username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], 
timestamp = [1,2,3,4,5,6,7,8,9,10], 
website = ["home","about","career","home","cart","maps","home","home","about","career"]

Output: ["home","about","career"]

Explanation: The tuples in this example are:
["joe","home",1],
["joe","about",2],
["joe","career",3],
["james","home",4],
["james","cart",5],
["james","maps",6],
["james","home",7],
["mary","home",8],
["mary","about",9], and 
["mary","career",10].

The pattern ("home", "about", "career") has score 2 (joe and mary).
The pattern ("home", "cart", "maps") has score 1 (james).
The pattern ("home", "cart", "home") has score 1 (james).
The pattern ("home", "maps", "home") has score 1 (james).
The pattern ("cart", "maps", "home") has score 1 (james).
The pattern ("home", "home", "home") has score 0 (no user visited home 3 times).

Example 2:

Input: 
username = ["ua","ua","ua","ub","ub","ub"], 
timestamp = [1,2,3,4,5,6], 
website = ["a","b","a","a","b","c"]

ua 1 a
ua 2 b
ua 3 a
ub 4 a
ub 5 b
ub 6 c

Output: ["a","b","a"]


Constraints:

3 <= username.length <= 50
1 <= username[i].length <= 10
timestamp.length == username.length
1 <= timestamp[i] <= 109
website.length == username.length
1 <= website[i].length <= 10
username[i] and website[i] consist of lowercase English letters.

It is guaranteed that there is at least one user who visited at least three websites.
All the tuples [username[i], timestamp[i], website[i] are unique

Solution
- Create an algorithm to obtain all the possible 3 sequences (n sequences)
- Create a collection of users plus all the sequences
- Compare the all the users's sequences against everyone else
*/


namespace SOLUTION
{
	class Solution {
	public:
		vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) 
		{
			map<string, vector<pair<int, string>>> mp;
			set<string> web;
			int n = username.size();

			for (int i = 0; i < n; i++)
			{
				mp[username[i]].push_back({ timestamp[i],website[i] });
				web.insert(website[i]);
			}

			for (auto& it : mp)
			{
				sort(it.second.begin(), it.second.end());
			}

			vector<string> ans;
			int maxCount = 0;
			for (auto& u : web)
			{
				for (auto& v : web)
				{
					for (auto& w : web)
					{
						int currentCount = 0;
						for (auto& it : mp)
						{
							auto& sites = it.second;
							int current = 0;

							for (auto& [_, site] : sites)
							{
								if (current == 0 && u == site)
								{
									current++;
								}
								else if (current == 1 && v == site)
								{
									current++;
								}
								else if (current == 2 && w == site)
								{
									current++;
									currentCount++;
									break;
								}
							}

						}
						if (maxCount < currentCount)
						{
							ans = { u,v,w };
							maxCount = currentCount;
						}
					}
				}
			}
			return ans;

		}
	};
}

#define PRINTV
//#define TEST_SEQUENCES
#define TEST_PROCESS
#define DISPLAY_SEQUENCES


namespace AnalyzeUserWebsiteVisit
{
	struct help
	{
		static void printSet(auto s)
		{
			for (auto el : s)
			{
				cout << el.first << ":" << el.second << "\n";
			}
			cout << "\n";
		}

	};


	using strrow = vector <string >;
	using strmatrix = vector < strrow >;
	using wsts = pair<int, string>;
	using t_vecInt = vector<int>;
	using intmatrix = vector< t_vecInt >;

	void process()
	{
		SOLUTION::Solution sol;
#ifdef TEST_SEQUENCES
		if (false)
		{
			sol.allSequences({ "0","1","2","3" });
		}
		if (false)
		{
			sol.allSequences({ "0","1","2","3","4","5","6","7","8" });
		}
		if (true)
		{
			sol.allSequences({ "home", "carts", "maps", "home" });
		}
		if (true)
		{
			sol.allSequences({ "home", "carts", "maps" });
		}
		if (false)
		{
			sol.allSequences({ "y","loedo","y" });
		}
		if (true)
		{
			sol.allSequences({ "wnaaxbfhxp","mryxsjc","oz","wlarkzzqht" });
		}
		if (false)
		{
			sol.allSequences({ "kzx","bsmy","qhmiliihh","txvn","snf","nrtj","ksakw","bsmy","txvn" });
		}
		if (true)
		{
			sol.allSequences({ "kzx","bsmy","qhmiliihh","txvn","snf","nrtj","ksakw","bsmy","txvn" })
		}
#endif
#ifdef TEST_PROCESS
		if(true)
		{
			strrow username{ "joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary" };
			t_vecInt timestamp{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			strrow website{ "home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			cout << "\n\nResult: \n";
			printv(r);
		}
		if (true)
		{
			/*
			Expected ["y","y","loedo"]
			*/
			strrow username{ "dowg","dowg","dowg" };
			t_vecInt timestamp{ 158931262,562600350,148438945 };
			strrow website{ "y","loedo","y" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			cout << "\n\nResult: \n";
			printv(r);

		}
		if (true)
		{
			/*
			Expected:
			["oz","mryxsjc","wlarkzzqht"]
			*/
			strrow username{ "zkiikgv","zkiikgv","zkiikgv","zkiikgv" };
			t_vecInt timestamp{ 436363475,710406388,386655081,797150921 };
			strrow website{ "wnaaxbfhxp","mryxsjc","oz","wlarkzzqht" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			cout << "\n\nResult: \n";
			printv(r);
		}
		if (true)
		{
			/*
			Expected:
			["kzx","txvn","bsmy"]
			*/
			strrow username{ "ldigebxndh","jxm","iit","ldigebxndh","dut","oxkr","dut","ldigebxndh","iit" };
			t_vecInt timestamp{ 246561774,336877562,613255786,581611682,67005296,164162280,644105652,998777950,962088025 };
			strrow website{ "kzx","bsmy","qhmiliihh","txvn","snf","nrtj","ksakw","bsmy","txvn" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			cout << "\n\nResult: \n";
			printv(r);
		}
#endif
	}
}