#pragma once
/*
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

#define PRINTV
	using strrow = vector <string >;
	using strmatrix = vector < strrow >;
	using wsts = pair<int, string>;

	class Solution
	{
		set<size_t> m_visited;
		map<string, strmatrix> m_map;
		strrow m_username;
		vector<int> m_timestamp;
		strrow m_website;
		struct Visits
		{
			set<wsts> m_set;
			strmatrix m_matrixOfSequences;
			strrow m_workingRow;
			void process_row()
			{
				for (auto el: m_set)
				{
					m_workingRow.push_back(el.second);
				}
			}
		};
		map<string, Visits > m_usersTsWsMap;

		void create_users_matrix_map()
		{
			strrow workingrow;
			string name = m_username[0];
			for (size_t i = 0; i < m_username.size(); i++)
			{
				if (m_username[i] != name)
				{
					m_map[name] = allSequences(workingrow);
					name = m_username[i];
					workingrow.clear();
				}
				workingrow.push_back(m_website[i]);
			}
			m_map[name] = allSequences(workingrow);
		}

		void organize_data()
		{
			for (size_t i = 0; i < m_username.size(); i++)
			{
				auto kk = make_pair(m_timestamp[i], m_website[i]);

				m_usersTsWsMap[m_username[i]].m_set.insert(kk);
			}
			// Organize rows in map
			for (auto& el: m_usersTsWsMap)
			{
				el.second.process_row();

#ifdef PRINTV
				printv(el.second.m_workingRow);
#endif
				el.second.m_matrixOfSequences = allSequences(el.second.m_workingRow);
			}
#ifdef PRINTV
			for (auto& elem : m_usersTsWsMap)
			{
				cout << elem.first << "\n";
				auto s = elem.second.m_set;
				help::printSet(s);
			}
#endif
		}


		void reset()
		{
			m_visited.clear();
			m_map.clear();
		}
	public:
		strmatrix allSequences(strrow sequence, size_t setSize = 3)
		{
			strrow workingRow;
			strmatrix result;
			auto sequenceSize = sequence.size();
			size_t i = 0;
			size_t col{};
			auto found = [&](int i) { return m_visited.end() != m_visited.find(i); };

			while (sequenceSize - i >= setSize)
			{
				for (;workingRow.size() < setSize; i++)
				{
					if (found(i))
						continue;
					workingRow.push_back(sequence[i]);
				}
				result.push_back(workingRow);
				m_visited.insert(i-1);
				if (found(sequenceSize-1))
				{
					i = ++col;
					m_visited.clear();
				}
				else
					i = 0;
				workingRow.clear();

			}
			return result;
		}

		
		vector<string> mostVisitedPattern(strrow username,
			vector<int> timestamp, strrow website)
		{
			reset();
			m_username = username;
			m_timestamp = timestamp;
			m_website = website;

			organize_data();
			//create_users_matrix_map();
			map<strrow, size_t> m;

			for (auto& [name, matrix]: m_map)
			{
				for (auto row: matrix)
				{
					m[row]++;
				}
			}
			strrow res;
			size_t s = 0;
			for (auto [row, theSize] : m)
			{
				if (s < theSize)
				{
					res = row;
					s = theSize;
				}
			}


			return res;
		}


	};

	void process()
	{
		Solution sol;
#pragma region KK
#if 0
		{
			auto res = sol.allSequences({ "home", "carts", "maps", "home" });
			for (auto elem : res)
			{
				printv(elem);
			}
			cout << "\n\n";

		}
		{
			auto res = sol.allSequences({ "home", "carts", "maps" });
			for (auto elem : res)
			{
				printv(elem);
			}
			cout << "\n\n";
		}
		{
			strrow username{ "joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary" };
			vector<int> timestamp{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			strrow website{ "home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			printv(r);
		}
		{
			auto res = sol.allSequences({ "y","loedo","y" });
			for (auto elem : res)
			{
				printv(elem);
			}
			cout << "\n\n";

		}
		{
			/*
			*
			*
			* username =
	["dowg","dowg","dowg"]
	timestamp =
	[158931262,562600350,148438945]
	website = ["y","loedo","y"]


			Expected ["y","y","loedo"]
			*/
			strrow username{ "dowg","dowg","dowg" };
			vector<int> timestamp{ 158931262,562600350,148438945 };
			strrow website{ "y","loedo","y" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			printv(r);

		}
#endif
#pragma endregion
		{
			/*
			username =
			["zkiikgv","zkiikgv","zkiikgv","zkiikgv"]
			timestamp =
			[436363475,710406388,386655081,797150921]
			website = ["wnaaxbfhxp","mryxsjc","oz","wlarkzzqht"]

			Expected:
			["oz","mryxsjc","wlarkzzqht"]
			*/
			strrow username{ "zkiikgv","zkiikgv","zkiikgv","zkiikgv" };
			vector<int> timestamp{ 436363475,710406388,386655081,797150921 };
			strrow website{ "wnaaxbfhxp","mryxsjc","oz","wlarkzzqht" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			printv(r);
		}
	}
}