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

#define PRINTV
//#define TEST_SEQUENCES
#define TEST_PROCESS


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

	class Solution
	{
		strrow m_username;
		vector<int> m_timestamp;
		vector<int> m_toAvoid;
		strrow m_website;
		map<strrow, int> m_resultMap;

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

		void organize_data()
		{
			// Organize the data by user, timestamp, website
			for (size_t i = 0; i < m_username.size(); i++)
			{
				auto time_web = make_pair(m_timestamp[i], m_website[i]);

				m_usersTsWsMap[m_username[i]].m_set.insert(time_web);
			}
			
			for (auto& [name, visits]: m_usersTsWsMap)
			{
				// Get the websites visits ordered by timestamp
				visits.process_row();

#ifdef PRINTV
				cout << "\n\nUsername: [" << name << "]\nSites visited:\t\n";
				printv(visits.m_workingRow);
				auto s = visits.m_set;
				cout << "Visits organized by timestamp:\n";
				help::printSet(s);
				cout << "Visits counter:\n";
#endif
				// get the matrix of sequences of visits
				/*
				* visits ordered by timestamp
				* home carst maps home
				* sequences in sets of three (function is parametrized):
				* home carts maps
				* home carts	   home
				*	   carts maps  home
				* 
				* so we have three sequences of size 3 ordered by timestamp
				*/

				// Finally we count the visits for this user - it 
				// will get accumulated when we count for all users.
				visits.m_matrixOfSequences = allSequences(visits.m_workingRow);
				for (auto& row: visits.m_matrixOfSequences)
				{
					m_resultMap[row]++;
#ifdef PRINTV

					printv(row, false);
					cout << " counter: " << m_resultMap[row] << "\n";
#endif
				}
			}
		}


		void reset()
		{
			m_usersTsWsMap.clear();
			m_resultMap.clear();
			m_toAvoid.clear();
			m_username.clear();
			m_timestamp.clear();
			m_website.clear();

		}
	public:
		strmatrix allSequences(strrow sequence, size_t setSize = 3)
		{
			strrow workingRow;
			strmatrix result;
			auto sequenceSize = sequence.size();
			auto found = [&](int x) 
			{ 
				auto it = find(m_toAvoid.begin(), m_toAvoid.end(), x);
				return it != m_toAvoid.end()  ; 
			};
#ifdef TEST_SEQUENCES
			cout << "Sequence with a size of ["<< sequenceSize << "]:\n--------------------------------------------\n";
			printv(sequence);
			cout << "--------------------------------------------\n";
#endif
			/*
			keep decreasing the size of the sequence by advancing from the left.
			we will use two loops to keep advancing
			we break the inner loop when we meet the proper set size.

			["ldigebxndh","jxm","iit","ldigebxndh","dut","oxkr","dut","ldigebxndh","iit"]
			0 1 2
			0 1   3
			0 1     4
			0 1       5
			0 1         6
			0 1           7
			0 1             8
			  1 2 3
			  1 2   4
			  1 2     5
			  1 2		6
			  1 2		  7
			  1 2			8
				2 3 4
				2 3	  5
				2 3		6
				2 3		  7
				2 3			8
				  3 4 5
				  3 4	6
				  3 4	  7
				  3 4		8
				    4 5 6
					4 5   7
					4 5		8
					  5 6 7
					  5 6   8
					    6 7 8

			*/

			int right = setSize;
			auto lastRight = right;
			for (int i = 0; i < sequenceSize && right <= sequenceSize; i++)
			{
				for (int j = i; j < sequenceSize; j++)
				{
					if (workingRow.size() < setSize)
					{
						if (found(j)) continue;
						workingRow.push_back(sequence[j]);
						if (workingRow.size() == setSize)
						{
							m_toAvoid.push_back(j);
							result.push_back(workingRow);
							j = i - 1;
							workingRow.clear();
							if (++right > sequenceSize)
							{
								m_toAvoid.clear();
								break;
							}
						}
					}

				}
				right = ++lastRight;

			}

#ifdef TEST_SEQUENCES
			cout << "Organized in sets of [" << setSize << "]:\n--------------------------------------------\n";
			for (auto& elem : result)
			{
				printv(elem);
			}
			cout << "--------------------------------------------\n\n";
#endif // TEST_SEQUENCES
			return result;
		}

		
		strrow mostVisitedPattern(strrow username,
			vector<int> timestamp, strrow website)
		{
			reset();
			m_username = username;
			m_timestamp = timestamp;
			m_website = website;

			organize_data();

			// at this point we have all the visits counted: we find the largest
			strrow res;
			int lastCounter = -INT_MAX;
			for (auto& [row, counter]: m_resultMap)
			{
				if (counter > lastCounter)
				{
					lastCounter = counter;
					res = row;
				}
				
			}
			// finally we assign the top to our result
			// return the result
			return res;
		}


	};

	void process()
	{
		Solution sol;
#ifdef TEST_SEQUENCES
		{
			sol.allSequences({ "0","1","2","3","4","5","6","7","8" });
		}
		{
			sol.allSequences({ "home", "carts", "maps", "home" });
		}
		{
			sol.allSequences({ "home", "carts", "maps" });
		}
		{
			sol.allSequences({ "y","loedo","y" });
		}
		{
			sol.allSequences({ "wnaaxbfhxp","mryxsjc","oz","wlarkzzqht" });
		}
		{
			sol.allSequences({ "kzx","bsmy","qhmiliihh","txvn","snf","nrtj","ksakw","bsmy","txvn" });
		}
#endif
#ifdef TEST_PROCESS
		{
			strrow username{ "joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary" };
			vector<int> timestamp{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			strrow website{ "home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			cout << "\n\nResult: \n";
			printv(r);
		}
		{
			/*
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
			cout << "\n\nResult: \n";
			printv(r);

		}
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
			cout << "\n\nResult: \n";
			printv(r);
		}
		{
			/*
			Expected: ["kzx","txvn","bsmy"]
			*/
			strrow username{ "ldigebxndh","jxm","iit","ldigebxndh","dut","oxkr","dut","ldigebxndh","iit" };
			vector<int> timestamp{ 246561774,336877562,613255786,581611682,67005296,164162280,644105652,998777950,962088025 };
			strrow website{ "kzx","bsmy","qhmiliihh","txvn","snf","nrtj","ksakw","bsmy","txvn" };

			auto r = sol.mostVisitedPattern(username, timestamp, website);
			cout << "\n\nResult: \n";
			printv(r);

		}
#endif
	}
}