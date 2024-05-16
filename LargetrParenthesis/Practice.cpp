// LargetrParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <map>
#include <utility>
#include <chrono>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <stack>
using namespace std;

struct timeit
{
	chrono::duration<double> m_dur{};
	chrono::steady_clock::time_point m_tp1;
	chrono::steady_clock::time_point m_tp2;
	timeit()
	{
		m_tp1 = chrono::high_resolution_clock::now();
	}
	~timeit()
	{
		m_tp2 = chrono::high_resolution_clock::now();
		m_dur = m_tp2 - m_tp1;
		cout << "duration seconds: " <<  fixed << setprecision(12)<< m_dur.count() << "\n";
	}


};
struct Solution
{
	// find the longest valid parenthesis
	void FindParenthesis(const string& s)
	{
		int initialSquare{ INT_MAX }
			, initialCurly{ INT_MAX }
			, initialRound{ INT_MAX }
		, lastSquare{ -1 }, lastCurly{ -1 }, lastround{ -1 };

		for (size_t i = 0; i < s.size(); i++)
		{
			if (initialSquare == INT_MAX && s[i] == '[')
			{
				initialSquare = i;
				continue;
			}
			if (initialRound == INT_MAX && s[i] == '(')
			{
				initialRound = i;
				continue;
			}
			if (initialCurly == INT_MAX && s[i] == '{')
			{
				initialCurly = i;
				continue;
			}
			if (s[i] == '}')
			{
				lastCurly = i;
				continue;
			}
			if (s[i] == ')')
			{
				lastround = i;
				continue;
			}
			if (s[i] == ']')
			{
				lastSquare = i;
				continue;
			}
		}

		int longestSquare = lastSquare - initialSquare;
		int longestRound = lastround - initialRound;
		int longestCurly = lastCurly - initialCurly;

		int masimum = max(longestSquare, max(longestRound, longestCurly));

		cout << "Max length: " << masimum << "\n";
	}
	// move all zeroes to the right side

	// Solution 1
	// using pointer move left pointer forward . 
	// if a zero is detected at the left swap it with the right element.
	// the number of zeroes whould be returned
	template <typename T>
	size_t move_zeroes(T& c) // Collection
	{
		size_t l{};
		auto r{ c.size() - 1 }; 
		size_t counter{};

		while (l < r)
		{
			if (c[l] == 0)
			{
				if ( c[r] != 0)
				{
					swap(c[l++], c[r--]);
					counter++;
				}
			}
			else
				l++;

			if (l < r && c[r] != 0)
			{
				if (c[l] == 0)
				{
					swap(c[l++], c[r--]);
					counter++;
				}
			}
			else
				r--;
		}
		return counter;
	}


	// Solution 2 NAIVE
	// start from the beginning, check if we have a zero.
	// find the first non zero to its right
	//if found swap it.
	template <typename T>
	size_t move_zeroes_Naive(T& c) // Collection
	{
		size_t counter{};
		for (size_t i = 0; i < c.size(); i++)
		{
			if (c[i] == 0)
			{
				// find the first non-zero and swap it
				for (size_t j = i + 1; j < c.size(); j++)
				{
					if (c[j] != 0)
					{
						swap(c[i], c[j]);
						counter++;
						break;
					}
				}
			}
		}
		return counter;
	}
	template <typename T>
	void printv(const T& v) const
	{
		for (const auto& elem: v)
		{
			cout << elem << " ";
		}
		cout << "\n";
	}
	template <typename T>
	void printm(const map<T, T>& counts) const
	{
		for (auto elem : counts)
		{
			cout << elem.first << " = " << elem.second << "\n";
		}
		cout << "\n";
	}

	struct Something
	{
		void operator()(int x)
		{
			cout << x << "\n";
		}
	};
	void lambda_expression()
	{
		// [cc](p){fd}
		// cc = capture clause
		// p = parameters
		// fd = function definition
		int d = 3;
		vector<int> v{2, 3, 7, 14, 23};
		Something something;
		for_each(v.begin(), v.end(), something);
		for_each(v.begin(), v.end(), [&](int x) { cout << "lambda " << x * d << "\n"; d += 1; });
	}

	/*
	Given a non-empty array of integers, return the k most frequent elements

	Example 1:
	k = 2
	Input = [1,1,1,2,2,3]
	output [1, 2]

	Example 2
	k = 1
	Input = [1]
	output [1]

	if nums = [1,1,2,2,3,3] k cannot be 2 because there are not k unique numbers
	in this example, the only valid k is 3

	*/
	template <typename T>
	void TopKElements(T& c, size_t k = 2) //c = collection
	{
		cout << "\n\ninput vector (k [most frequent elements]= "<< k << ")" << "\n";
		printv(c);

		cout << "\nCreating map to count occurrences: <elements, occurrences>" << "\n";
		map<int, int> counts;
		// O(n)
		for (auto const& elem : c)
		{
			counts[elem]++;
		}
		printm(counts);

		cout << "\nAdding the generated pairs to priority_queue< pair<int, int> >, "
			"note that the pairs are sorted by the priority_queue by <first>"
			", then <second>" << "\n";
		priority_queue < pair<int, int> > minHeap;
		// O(m)
		for (auto elem: counts)
		{
			auto key = elem.second;
			auto val = elem.first;
			auto curPair = std::make_pair(key, val);
			minHeap.push(curPair);
		}

		cout << "...priority queue looks like this: (note the sorted pairs) " << "\n";

		vector<int> res;
		for (; !minHeap.empty() ; minHeap.pop())
		{
			auto p = minHeap.top();
			cout << p.first << " = " << p.second << "\n";
			if (res.size() < k)
			{
				cout << "adding to res vector: " << p.second << "\n";
				res.push_back(p.second);
			}
		}
		cout << "\nresult (Display the first k (" << k << ") elements" << "\n";
		printv(res);
	}


	/*
	*	You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
		and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

		Merge nums1 and nums2 into a single array sorted in non-decreasing order.

		The final sorted array should not be returned by the function, but instead be stored 
		inside the array nums1. 
		
		To accommodate this, nums1 has a length of m + n, 
		
		where the first m elements denote the elements that should be merged, and the last n elements 
		are set to 0 and should be ignored. nums2 has a length of n.

		Example 1:

		Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
		Output: [1,2,2,3,5,6]
		Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
		The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
		Example 2:

		Input: nums1 = [1], m = 1, nums2 = [], n = 0
		Output: [1]
		Explanation: The arrays we are merging are [1] and [].
		The result of the merge is [1].
		Example 3:

		Input: nums1 = [0], m = 0, nums2 = [1], n = 1
		Output: [1]
		Explanation: The arrays we are merging are [] and [1].
		The result of the merge is [1].
		Note that because m = 0, there are no elements in nums1. The 0 is only there to 
		ensure the merge result can fit in nums1.

		Constraints:

		nums1.length == m + n
		nums2.length == n
		0 <= m, n <= 200
		1 <= m + n <= 200
		-109 <= nums1[i], nums2[j] <= 109

		Solution
		1. Iterate on nums2
		2. look in nums1 for the first element that is larger than nums2[i]
		3. If found shift nums1 and insert element there
		4. if not found append it at the end

		Ref: https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

	*/
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		for (size_t i = 0; i < nums2.size(); i++)
		{
			nums1[m++] = nums2[i];
		}
		sort(nums1.begin(), nums1.end());
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		for_each(nums2.begin(), nums2.end(), [&](int x) { nums1[m++] = x; });
		sort(nums1.begin(), nums1.end());
	}

	/*
	Given the root node of a binary search tree and two integers low and high, 
	return the sum of values of all nodes with a value in the inclusive range [low, high].

	Example 1
	Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
	Output: 32
	Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

				  10
			5			15
		3		7	null	18

 Definition for a binary tree node.
	*/
	struct TreeNode
	{
		int val{};
		TreeNode* left{ nullptr };
		TreeNode* right{ nullptr };
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	};
	int sum{};

	int rangeSumBST(TreeNode* root, int low, int high) 
	{
		preorder(root, low, high);
		return sum;
	
	}

	void preorder(TreeNode* root, int low, int high)
	{
		if (root)
		{
			if (root->val >= low && root->val <= high)
				sum += root->val;
			preorder(root->left, low, high);
			preorder(root->right, low, high);
		}
	}
	int doRangeSumBST()
	{
		auto root = new TreeNode(10);

		root->left = new TreeNode(5);
		root->left->left = new TreeNode(3);
		root->left->right = new TreeNode(7);

		root->right = new TreeNode(15);
		root->right->right = new TreeNode(18);

		return rangeSumBST(root, 7, 15);
	}

	/*
	Given two string arrays word1 and word2, return true if the two arrays represent the same string,
	and false otherwise.

	A string is represented by an array if the array elements concatenated in order forms the string.



	Example 1:

	Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
	Output: true
	Explanation:
	word1 represents string "ab" + "c" -> "abc"
	word2 represents string "a" + "bc" -> "abc"
	The strings are the same, so return true.
	Example 2:

	Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
	Output: false
	Example 3:

	Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
	Output: true


	Constraints:

	1 <= word1.length, word2.length <= 103
	1 <= word1[i].length, word2[i].length <= 103
	1 <= sum(word1[i].length), sum(word2[i].length) <= 103
	word1[i] and word2[i] consist of lowercase letters.
	*/
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
	{
		string s1, s2;
		for_each(word1.begin(), word1.end(), [&](string& s) { s1 += s; });
		for_each(word2.begin(), word2.end(), [&](string& s) { s2 += s; });
		return s1 == s2;
	}
	/*
		2956. Find Common Elements Between Two Arrays
		Easy
		Topics
		Companies
		Hint
		You are given two 0-indexed integer arrays nums1 and nums2 of sizes n and m, respectively.

		Consider calculating the following values:

		The number of indices i such that 0 <= i < n and nums1[i] occurs at least once in nums2.
		The number of indices i such that 0 <= i < m and nums2[i] occurs at least once in nums1.
		Return an integer array answer of size 2 containing the two values in the above order.

		Example 1:

		Input: nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
		Output: [3,4]
		Explanation: We calculate the values as follows:
		- The elements at indices 1, 2, and 3 in nums1 occur at least once in nums2. 
			So the first value is 3.
		- The elements at indices 0, 1, 3, and 4 in nums2 occur at least once in nums1. 
			So the second value is 4.
		
		Example 2:

		Input: nums1 = [3,4,2,3], nums2 = [1,5]
		Output: [0,0]
		Explanation: There are no common elements between the two arrays, so the two values will be 0.


		Constraints:

		n == nums1.length
		m == nums2.length
		1 <= n, m <= 100
		1 <= nums1[i], nums2[i] <= 100
*/
	vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> res{0,0};
		for_each(nums1.begin(), nums1.end(), [&](int x) 
			{
				if (find(nums2.begin(), nums2.end(), x) != nums2.end())
				{
					res[0]++;
				}

			});

		for_each(nums2.begin(), nums2.end(), [&](int x)
			{
				if (find(nums1.begin(), nums1.end(), x) != nums1.end())
				{
					res[1]++;
				}

			});

		return res;
	}
};

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []
 
 */
struct ReverseLinkedList : public timeit
{
	struct ListNode 
	{
		int val{};
		ListNode* next{nullptr};
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* reverseList(ListNode* head) 
	{
		ListNode* prev {nullptr};
		ListNode* curr = head;
		ListNode* forward{ nullptr };
		reverse(curr, forward, prev);
		return prev;
	}

	void reverse(ListNode*& curr, ListNode*& forward, ListNode*& prev)
	{
		if (!curr)
			return;

		forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;
		reverse(curr, forward, prev);
	}

	ListNode* reverseListPrint(ListNode* head)
	{
		ListNode* prev{ nullptr };
		ListNode* curr = head;
		while (curr)
		{
			cout << " curr " << curr->val << " ";

			ListNode* forward = curr->next;
			if (forward)
			{
				cout << " forward " << forward->val << " ";
			}


			curr->next = prev;
			prev = curr;

			cout << " prev " << prev->val << " ";
			if (curr->next)
			{
				cout << "curr->next " << curr->next->val;
			}

			curr = forward;

			if (curr)
			{
				cout << " after curr = forward : curr " << curr->val;
			}
			cout << "\n";
		}
		return prev;
	}
	void printList(ListNode* head)
	{
		if (head)
		{
			cout << head->val << " ";
			printList(head->next);
		}

	}
};
/*
58. Length of Last Word
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring s consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/
struct LenghtOfLastWord : public timeit
{
	int lengthOfLastWord(string s)
	{

		stack<int> myset;
		string tmp;
		for_each(s.begin(), s.end(), [&](auto c) 
			{
				if (c != ' ')
				{
					tmp += c;
				}
				else
				{
					if (tmp.size() > 0)
					{
						myset.push(tmp.size());
						tmp.clear();
					}
				}
			});

		if (tmp.size() > 0)
		{
			myset.push(tmp.size());
			tmp.clear();
		}
		return myset.top();
	}

};
/*

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
struct ValidAnagram : public timeit
{
	bool isAnagram1(string s, string t) 
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
	bool isAnagram(string s, string t) 
	{
		//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

		vector<int> r1(26), r2(26);

		for (auto c1 : s) 
		{
			r1[c1 - 'a']++;
		}

		for (auto c2 : t) 
		{
			r2[c2 - 'a']++;
		}

		for (size_t i = 0; i < r1.size(); i++) 
		{
			if (r1[i] != r2[i])
				return false;
		}
		return true;
	}
};
/*
Given an integer x, return true if x is a palindrome , and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1


Follow up: Could you solve it without converting the integer to a string?
*/
struct PalindromeNumber : public timeit
{
	bool isPalindrome(int num) 
	{
		if (num < 0)
		{
			return false;
		}

		int n = num;
		unsigned int rev = 0;
		unsigned int dig;
		while (num > 0)
		{
			dig = num % 10;
			rev = rev * 10 + dig;
			num = num / 10;
		}
		return n == rev;
	}
};
/*
408. Valid Word Abbreviation
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings 
with their lengths. 
The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):
"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)

The following are not valid abbreviations:
"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)

Given a string word and an abbreviation abbr, return whether the string matches 
the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.

Example 1:
Input: word = "internationalization", abbr = "i12iz4n"
Output: true
Explanation: The word "internationalization" can be abbreviated as 
"i12iz4n" ("i nternational iz atio n").

Example 2:
Input: word = "apple", abbr = "a2e"
Output: false
Explanation: The word "apple" cannot be abbreviated as "a2e".

Constraints:
1 <= word.length <= 20
word consists of only lowercase English letters.
1 <= abbr.length <= 10
abbr consists of lowercase English letters and digits.
All the integers in abbr will fit in a 32-bit integer.

Solution

Get length of the string.
find the numbers and where they are in the string.
iterate add the lenghts of the string + the numbers and make sure they match the length of the string.

*/
struct ValidWordAbbreviation : public timeit 
{
	bool validWordAbbreviation(string word, string abbr) 
	{
		vector<string> str;
		string tmpNum;
		for_each(abbr.begin(), abbr.end(), [&](auto c)
			{
				if (isdigit(c))
				{
					tmpNum += c;
				} 
				else
				{
					if (!tmpNum.empty())
					{
						str.push_back(tmpNum);
						tmpNum.clear();
					}
					string x;
					x.push_back(c);
					str.push_back(x);
				}
			});
		if (!tmpNum.empty())
		{
			str.push_back(tmpNum);
			tmpNum.clear();
		}
		bool valid{true};
		size_t counter{};
		string lastString;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (isdigit(str[i][0]))
			{
				if (str[i][0] == '0' || str[i] == lastString)
				{
					valid = false;
					break;
				}
				counter += stol(str[i]);
			}
			else
			{
				counter += str[i].size();
			}

			lastString = str[i];
		}
		if (valid)
		{
			valid = word.size() == counter;
		}
		return valid;
	}
};
int main()
{
	Solution sol;
	if (false)
	{
		sol.FindParenthesis("");
		sol.FindParenthesis("(){}[]");
		sol.FindParenthesis("(}");
		sol.FindParenthesis("(((((((}");
		sol.FindParenthesis("([]]){{}((}}");
		sol.FindParenthesis("(           )}");
		sol.FindParenthesis("(           {}");
		sol.FindParenthesis("([]]){{}((]]){{}((  ]]){{}((]]){{}((]]){{}((]]){{}((]]){{}(( ]]){{}((]]){{}((]]){{}((]]){{}(( }}");
	}
	if(false)
	{
		vector<int> vec{ 2, 0, 3, 0, 4, 5, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << "\n";
		sol.printv(vec);
		cout << "\n";
	}

	if (false)
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << "\n";
		sol.printv(vec);
		cout << "\n";
	}
	if (false)
	{
		vector<int> vec{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << "\n";
		sol.printv(vec);
		cout << "\n";
	}
	if (false)
	{
		vector<int> vec{ 0, 1, 0, 1, 0, 1, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << "\n";
		sol.printv(vec);
		cout << "\n";
	}
	if (false)
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << "\n";
		sol.printv(vec);
		cout << "\n";
	}
	if (false)
	{
		vector<int> vec{ 0, 1, 2, 0, 0, 3,4 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << "\n";
		sol.printv(vec);
		cout << "\n";
	}
	if (false)
	{
		vector<int> vec{ 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,4 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << "\n";
		sol.printv(vec);
		cout << "\n";
	}
	if (false)
	{
		sol.lambda_expression();
	}
	if (false)
	{
		{
			vector<int> vec{ 1,1,1,2,2,3, 7, 7, 7 };
			sol.TopKElements(vec);

		}
		{
			vector<int> vec{ 1,1,2,2,3,3 };
			sol.TopKElements(vec, 3);

		}
	}
	if (false)
	{
		vector<int> nums1{ 1,2,3,0,0,0 };
		vector<int> nums2{ 2,5,6 };

		sol.merge(nums1, 3, nums2, 3);
		sol.printv(nums1);
	}
	if (false)
	{
		cout << sol.doRangeSumBST();
	}
	if (false)
	{
		vector<string> v1{ "ab", "c" }, v2{ "a", "bc" };
		cout << (sol.arrayStringsAreEqual(v1, v2) ? " True" : "false");
	}
	if (false)
	{
		timeit t;
		vector<int> v1{ 4,3,2,3,1 }, v2{ 2,2,5,2,3,6 };
		auto res = sol.findIntersectionValues(v1, v2);
		sol.printv(res);
	}
	if (false)
	{
		auto head = new ReverseLinkedList::ListNode(1);
		head->next = new ReverseLinkedList::ListNode(2);
		head->next->next = new ReverseLinkedList::ListNode(3);
		head->next->next->next = new ReverseLinkedList::ListNode(4);
		head->next->next->next->next = new ReverseLinkedList::ListNode(5);
		ReverseLinkedList r;
		r.printList(head);
		cout << "\n";
		auto newHead = r.reverseList(head);
		r.printList(newHead);
		cout << "\n";
	}
	if (false)
	{
		LenghtOfLastWord l;
		auto val = l.lengthOfLastWord("   fly me   to   the moon  ");
		assert(val == 4);
		cout <<  val <<  "\n";
		val = l.lengthOfLastWord("Hello World");
		assert(val == 5);
		cout << val << "\n";
		val = l.lengthOfLastWord("luffy is still joyboy");
		assert(val == 6);
		cout << val << "\n";
	}
	if (false)
	{
		ValidAnagram v;
		auto val = v.isAnagram("anagram","nagaram");
		assert(val);
		val = v.isAnagram("rat", "car");
		assert(!val);
	}
	if (false)
	{
		PalindromeNumber p;
		auto val = p.isPalindrome(121);
		assert(val);
		val = p.isPalindrome(-121);
		assert(!val);
		val = p.isPalindrome(10);
		assert(!val);
		val = p.isPalindrome(1234567899);
		assert(!val);
		
	}
	if (true)
	{
		ValidWordAbbreviation v;
		auto val = v.validWordAbbreviation("substitution", "s10n");
		cout << "substitution : s10n : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "sub4u4");
		cout << "substitution : sub4u4 : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "12");
		cout << "substitution : 12 : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "su3i1u2on");
		cout << "substitution : su3i1u2on : valid " << val << "\n";
		assert(val);

		val = v.validWordAbbreviation("substitution", "s55n");
		cout << "substitution : s55n : valid " << val << "\n";
		assert(!val);

		val = v.validWordAbbreviation("substitution", "s010n");
		cout << "substitution : s010n : valid " << val << "\n";
		assert(!val);

		val = v.validWordAbbreviation("substitution", "s0ubstitution");
		cout << "substitution : s0ubstitution : valid " << val << "\n";
		assert(!val);
	}
}
    