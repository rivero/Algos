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

void FindParenthesis(const string& s)
{
    int initialSquare{ INT_MAX }
        , initialCurly{ INT_MAX }
        , initialRound{ INT_MAX }
    , lastSquare{ -1 }, lastCurly{ -1 }, lastround{ -1 };

    for (int i = 0; i < s.size(); i++)
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

int main()
{
	FindParenthesis("");
	FindParenthesis("(){}[]");
	FindParenthesis("(}");
	FindParenthesis("(((((((}");
	FindParenthesis("([]]){{}((}}");
	FindParenthesis("(           )}");
	FindParenthesis("([]]){{}((]]){{}((  ]]){{}((]]){{}((]]){{}((]]){{}((]]){{}(( ]]){{}((]]){{}((]]){{}((]]){{}(( }}");
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
