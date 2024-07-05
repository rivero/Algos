#pragma once
namespace CustomSortString
{
	/*
	* 
	* https://leetcode.com/problems/custom-sort-string/description/
	* 
	791. Custom Sort String

	You are given two strings order and s. 
	
	All the characters of order are unique and were sorted in some custom order previously.

	Permute the characters of s so that they match the order that order was sorted. 
	
	More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

	Return any permutation of s that satisfies this property.

	Example 1:
	Input: order = "cba", s = "abcd"
	Output: "cbad"

	Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

	Since "d" does not appear in order, it can be at any position in the returned string. 
	
	"dcba", "cdba", "cbda" are also valid outputs.

	
	
	Example 2:
	Input: order = "bcafg", s = "abcd"
	Output: "bcad"

	Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. 
	The character "d" in s does not appear in order, so its position is flexible.

	Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". 
	"d" can be placed at any position since it's not in order. 
	The output "bcad" correctly follows this rule. 
	Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.



	Constraints:

	1 <= order.length <= 26
	1 <= s.length <= 200
	order and s consist of lowercase English letters.
	All the characters of order are unique.
	

	Intuition
	The intuition behind this approach is to use a custom comparator 
	function to sort the characters in string s based on their order in string order. 
	
	By mapping each character to its corresponding order in order, 
	we can then use this information to sort the characters in s accordingly.

	Solution

	Creating the Order Map:
		The algorithm starts by creating an unordered map called orderMap.
		For each character in the order string, it assigns the index (position) of that character in the order string 
		as its value in the map.
		Essentially, orderMap stores the custom order of characters based on their appearance in the order string.
	Custom Comparator Function:
		The algorithm defines a custom comparator function using a lambda expression.
		This comparator compares two characters, a and b, based on their corresponding indices in orderMap.
		If the index of a is less than the index of b in orderMap, the function returns true, indicating that a should come before b in the sorted order.
	Sorting the String:
		Finally, the algorithm sorts the input string s using the custom comparator.
		The std::sort function rearranges the characters in s according to their custom order specified by orderMap.

	Time Complexity:
		Constructing the orderMap takes O(n) time, where n is the length of the order string.
		Sorting the string s using the custom comparator takes O(n log n) time (since the sorting algorithm is used).
		Overall, the time complexity is O(n log n).
	Space Complexity:
		The algorithm uses additional space for the orderMap.
		Thus, the space complexity is O(n)

	Lambda
	[capture clause](parameters){function definition}
	*/

	class Solution 
	{
	public:
		string customSortString(string order, string s) 
		{
			// Create a map to store the order of each character in 'order'
			std::unordered_map<char, int> orderMap;
			for (int i = 0; i < order.length(); ++i) 
			{
				orderMap[order[i]] = i;
			}

			// Custom comparator function to sort characters in 's' based on their order in 'order'
			auto customComparator = [&](char a, char b) {
				return orderMap[a] < orderMap[b];
				};

			// Sort string 's' using the custom comparator
			std::sort(s.begin(), s.end(), customComparator);

			return s;
		}
	};	
	
	void process()
	{
		Solution sol;
		cout << sol.customSortString("cba", "abcd") << "\n"; // Output: "cbad"
		cout << sol.customSortString("bcafg", "abcd") << "\n"; // Output: "bcad"
		/*
		order = "kqep"
		s = "pekeq"
		Expected : "kqeep"
		*/
		cout << sol.customSortString("kqep", "pekeq") << "\n"; // Expected : "kqeep"

	}
}