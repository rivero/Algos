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

## Understanding the Code and Its Complexities

### Algorithm Overview

The provided code implements an algorithm to merge accounts based on common emails. It utilizes a Disjoint-Set Union (DSU) 
data structure to efficiently group accounts with shared emails.

### Code Breakdown

**DSU Implementation:**
* `idMap`: Represents the parent of each element in the DSU.
* `getRootParent`: Performs path compression to find the root of an element.

**accountsMerge Function:**

1. **Initialization:**
   * Creates a DSU structure with `n` elements (where `n` is the number of accounts).
   * Initializes an `emailToIdMap` to map emails to account indices.

2. **Email Processing:**
   * Iterates through each account and its emails.
   * If an email is seen for the first time, maps it to the current account index.
   * If the email exists, merges the current account with the account associated with the email using DSU.

3. **Merging Accounts:**
   * Creates a `mergedMap` to store merged accounts.
   * Iterates through `emailToIdMap` and assigns emails to their respective merged account based on their root in the DSU.

4. **Constructing Result:**
   * Creates a `mergedAccounts` vector to store the final result.
   * For each merged account, sorts the emails and adds the account name to the beginning.

### Time Complexity

* **DSU operations:** Amortized O(α(n)) per operation, where α is the inverse Ackermann function, which is practically constant.
* **Iterating through accounts and emails:** O(n * m), where n is the number of accounts and m is the average number of emails 
per account.
* **Creating merged accounts:** O(n * m) in the worst case.
* **Sorting emails:** O(m log m) for each account, but this is generally dominated by the outer loop.

Overall, the time complexity is **O(n * m log m)** in the worst case.

### Space Complexity

* `idMap`: O(n)
* `emailToIdMap`: O(n * m)
* `mergedMap`: O(n * m) in the worst case, but often less due to merging.
* `mergedAccounts`: O(n * m) in the worst case.

Overall, the space complexity is **O(n * m)**.

### Key Points

* The DSU is crucial for efficiently merging accounts based on shared emails.
* The use of `emailToIdMap` helps in quickly finding the corresponding account for an email.
* The `mergedMap` is used to group emails by their account.
* The final result is constructed by sorting emails and adding the account name.

This implementation effectively merges accounts based on common emails, providing a clear and efficient solution.

**Would you like to explore any specific optimizations or alternative approaches?**



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