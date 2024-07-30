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
## Algorithm Explanation

**Problem:** Find the most visited website pattern among users.

**Algorithm Steps:**

1. **Group Websites by User and Timestamp:**
   * Create a map `usrTSwebsiteMap` to store user, timestamp, and website information.
   * Iterate through `username`, `timestamp`, and `website` arrays, populating the map.

2. **Generate Patterns for Each User:**
   * Iterate through each user's website visits.
   * Generate all possible triplets of websites.
   * Store these triplets in a set `pattern` to avoid duplicates.

3. **Count Pattern Occurrences:**
   * Create a map `count` to store the frequency of each pattern.
   * Iterate through each user's patterns and increment their count in the `count` map.

4. **Find Most Frequent Pattern:**
   * Iterate through the `count` map to find the pattern with the highest frequency.
   * If multiple patterns have the same maximum frequency, choose the lexicographically smallest pattern.

5. **Extract and Return Result:**
   * Convert the pattern string into a vector of websites and return it.

### Time Complexity

* **Grouping websites:** O(n), where n is the number of records.
* **Generating patterns:** O(n^3) in the worst case for each user, leading to O(n^4) overall.
* **Counting patterns:** O(n^3) in the worst case.
* **Finding most frequent pattern:** O(n^3) in the worst case.

**Total time complexity:** O(n^4)

### Space Complexity

* `usrTSwebsiteMap`: O(n)
* `count`: O(n^3) in the worst case (number of unique patterns)
* `pattern`: O(n^3) for each user
* `mergedAccounts`: O(n)

**Total space complexity:** O(n^3)

## Optimization Potential

* **Trimming website lists:** If a user's website list exceeds a certain length, consider only the most recent visits to reduce the number of pattern combinations.
* **Early stopping:** If a pattern's count exceeds the current maximum, stop generating patterns for the current user.
* **Data structures:** Explore using more efficient data structures for storing and processing patterns.

While the provided code correctly solves the problem, the time and space complexities are high due to the exhaustive generation of all possible patterns. Optimizations can significantly improve performance for larger datasets.


*/

#define PRINTV
//#define TEST_SEQUENCES
#define TEST_PROCESS
#define DISPLAY_SEQUENCES

namespace AnalyzeUserWebsiteVisit
{
	class Solution 
	{
	public:
		vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
			// 1. Group each user's visited website and sort by timestamp
			unordered_map<string, map<int, string>> usrTSwebsiteMap; // user: {timestamp, website}
			for (int i = 0; i < username.size(); i++) 
			{
				usrTSwebsiteMap[username[i]][timestamp[i]] = website[i];
			}

			cout << "\n\nuser timestamp website map:\n";
			for (auto [user, tswsmp] : usrTSwebsiteMap)
			{
				cout << user << "\n";
				for (auto [ts, ws] : tswsmp)
				{
					cout << "\tts:" << ts << "\tws:" << ws << "\n";
				} 
				cout << "\n";
			}

			// 2. Collect each user's pattern
			unordered_map<string, int> count; // pattern: user_count
			for (auto [user, TSwebsiteMap] : usrTSwebsiteMap)
			{
				unordered_set<string> pattern; // each user's pattern(triplets)
				for (auto i = TSwebsiteMap.begin(); i != TSwebsiteMap.end(); ++i) 
				{
					for (auto j = next(i); j != TSwebsiteMap.end(); ++j) 
					{
						for (auto k = next(j); k != TSwebsiteMap.end(); ++k) 
						{
							string p = i->second + "A" + j->second + "B" + k->second;
							pattern.insert(p);
						}
					}
				}
				// 3. Count each pattern's user
				for (auto p : pattern) 
				{
					count[p]++;
				}
			}
			cout << "counter:\n";
			for (auto [site, counter] : count)
			{
				cout << "site:" << site << "\tcounter: " << counter << "\n";
			}

			// 4. find largest count's pattern.
			//    If count is same, result is lexicographically small pattern.
			string res = "";
			int maxCount = 0;
			for (auto [site, counter] : count)
			{
				if (counter > maxCount) 
				{
					res = site;
					maxCount = counter;
				}
				else if (counter == maxCount && site < res) 
				{
					res = site; 
				}
			}
			// res looks like: "cartAmapsBhome

			// 5. return result
			vector<string> result;
			size_t first = res.find("A"), second = res.find("B");
			result.push_back(res.substr(0, first));
			result.push_back(res.substr(first + 1, second - first - 1));
			result.push_back(res.substr(second + 1));
			return result;
		}
	};

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
		Solution sol;
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
		if (true)
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
