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

	// Soluition 1
	// using two pointers. move left pointer forward and right pointer backwards. 
	// if a zero is detected at the left swap it with the right element.
	// the number of zeroes whould be returned
	template <typename T>
	size_t move_zeroesV1(T& c) // Collection
	{
		size_t l{}, r{c.size() - 1};
		while (l < r)
		{
			if (c[l] == 0)
			{
				swap(c[l++], c[r]);
			}
			else
				l++;
			if (c[r] != 0)
			{
				swap(c[r--], c[l]);
			}
			else
				r--;
		}
		return l;
	}

	// Solution 2
	// start from the beginning, check if we have a zero.
	// find the first non zero to its right
	//if found swap it.
	template <typename T>
	size_t move_zeroesV2(T& c) // Collection
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
};

int main()
{
	Solution sol;
	sol.FindParenthesis("");
	sol.FindParenthesis("(){}[]");
	sol.FindParenthesis("(}");
	sol.FindParenthesis("(((((((}");
	sol.FindParenthesis("([]]){{}((}}");
	sol.FindParenthesis("(           )}");
	sol.FindParenthesis("(           {}");
	sol.FindParenthesis("([]]){{}((]]){{}((  ]]){{}((]]){{}((]]){{}((]]){{}((]]){{}(( ]]){{}((]]){{}((]]){{}((]]){{}(( }}");

	{
		vector<int> vec{ 2, 0, 3, 0, 4, 5, 0 };
		sol.printv(vec);
		cout << sol.move_zeroesV2(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}

	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroesV2(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroesV2(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroesV1(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroesV1(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroesV2(vec) << endl;
		sol.printv(vec);
		cout << endl;
	}
	{
		vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		sol.printv(vec);
		cout << sol.move_zeroesV2(vec) << endl;
		sol.printv(vec);
		cout << endl;
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
