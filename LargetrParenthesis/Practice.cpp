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

using namespace std;

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

		cout << "Max length: " << masimum << endl;
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
		cout << endl;
	}

	struct Something
	{
		void operator()(int x)
		{
			cout << x << endl;
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
		for_each(v.begin(), v.end(), [&](int x) { cout << "lambda " << x * d << endl; d += 1; });
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
		cout << "\n\ninput vector" << endl;
		printv(c);
		cout << endl;

		map<int, int> counts;
		// O(n)
		for (auto const& elem : c)
		{
			counts[elem]++;
		}
		cout << "map vector elements vs occurrences" << endl;
		for (auto elem: counts)
		{
			cout << elem.first << " = " << elem.second << endl;
		}
		cout << endl;

		priority_queue < pair<int, int> > minHeap;

		cout << "Adding to priority_queue" << endl;
		// O(m)
		for (auto elem: counts)
		{
			auto key = elem.second;
			auto val = elem.first;
			auto curPair = std::make_pair(key, val);
			minHeap.push(curPair);
		}

		cout << "...priority queue looks like this: " << endl;

		vector<int> res;
		for (; !minHeap.empty() ; minHeap.pop())
		{
			auto p = minHeap.top();
			cout << p.first << " = " << p.second << endl;
			if (res.size() < k)
			{
				res.push_back(p.second);
			}
		}
		cout << "\nresult" << endl;
		printv(res);
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
		cout << sol.move_zeroes(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}

	if (false)
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	if (false)
	{
		vector<int> vec{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	if (false)
	{
		vector<int> vec{ 0, 1, 0, 1, 0, 1, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	if (false)
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	if (false)
	{
		vector<int> vec{ 0, 1, 2, 0, 0, 3,4 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	if (false)
	{
		vector<int> vec{ 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,4 };
		sol.printv(vec);
		cout << sol.move_zeroes(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	{
		sol.lambda_expression();
	}
	if (true)
	{
		vector<int> vec{ 1,1,1,2,2,3, 7, 7, 7 };
		sol.TopKElements(vec);
	}
}
    

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
