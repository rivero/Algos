#pragma once
/*
https://leetcode.com/problems/accounts-merge
721. Accounts Merge
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, 
and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to 
both 
accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same 
name. 
A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the 
rest 
of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:

Input: accounts = 
[["John","johnsmith@mail.com","john_newyork@mail.com"],
["John","johnsmith@mail.com","john00@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]

Output: 
[["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]

Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Example 2:

Input: accounts = 
[["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],
["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: 
[["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]


Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j

If any of my emails is included in the previous 
*/



namespace AccountsMerge
{
	class Solution {
	private:
		vector<int> idMap;

		int getRootParent(int x) {
			if (idMap[x] != x) {
				idMap[x] = getRootParent(idMap[x]);
			}
			return idMap[x];
		}

	public:
		vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
			int n = accounts.size();
			idMap.resize(n);
			for (int i = 0; i < n; ++i) {
				idMap[i] = i;
			}
			unordered_map<string, int> emailToIdMap;
			for (int i = 0; i < n; ++i) {
				const auto& account = accounts[i];
				for (int j = 1; j < account.size(); ++j) {
					const string& email = account[j];
					auto it = emailToIdMap.find(email);
					if (it != emailToIdMap.end()) {
						idMap[getRootParent(i)] = getRootParent(it->second);
					}
					else {
						emailToIdMap[email] = i;
					}
				}
			}
			unordered_map<int, vector<string>> mergedMap;
			for (const auto& entry : emailToIdMap) {
				int id = getRootParent(entry.second);
				mergedMap[id].push_back(entry.first);
			}
			vector<vector<string>> mergedAccounts;
			for (auto& entry : mergedMap) {
				vector<string>& emails = entry.second;
				sort(emails.begin(), emails.end());
				emails.insert(emails.begin(), accounts[entry.first][0]);
				mergedAccounts.push_back(move(emails));
			}
			return mergedAccounts;
		}
	};

	void process()
	{
		Solution sol;
		{
			vector<vector<string>> accounts
			{
				{"John","johnsmith@mail.com","john_newyork@mail.com"},
				{"John","johnsmith@mail.com","john00@mail.com"},
				{"Mary","mary@mail.com"},
				{"John","johnnybravo@mail.com"}
			};
			auto res = sol.accountsMerge(accounts);
			for (auto el : res)
				printv(el);
		}
		{
			vector<vector<string>> accounts
			{
				{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
				{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
				{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
				{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
				{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}
			};
			auto res = sol.accountsMerge(accounts);
			for (auto el : res)
				printv(el);
		}
	}
}