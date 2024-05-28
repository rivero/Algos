#pragma once
/*
2 3 5 6 1
0 1 2 3 4

Max = 6


*/

namespace QuestionMarks
{
	/*
Questions Marks
Have the function QuestionsMarks(str) take the str string parameter,
which will contain single digit numbers, letters, and question marks,
and check if there are exactly 3 question marks between every pair of
two numbers that add up to 10.

If so, then your program should return the string true,
otherwise it should return the string false.
If there aren't any two numbers that add up to 10 in the string, then
your program should return false as well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true
because there are exactly 3 question marks between 6 and 4, and 3 question marks
between 5 and 5 at the end of the string.

Examples
Input: "aa6?9"
Output: false

Input: "acc?7??sss?3rr1??????5" (7??sss?3)
Output: true

*/

	string QuestionsMarks(string str) {

		int qmc{};
		int first_number{}, second_number{};
		for (auto elem : str)
		{
			if (isdigit(elem))
			{
				if (qmc == 0)
				{
					first_number = elem - '0';
				}
				if (qmc == 3)
				{
					qmc = 0;
					if (first_number != 0)
					{
						second_number = elem - '0';
						auto total = second_number + first_number;
						if (total == 10)
							return "true";
					}
				}
			}
			else if (elem == '?')
			{
				if (first_number != 0)
					qmc++;
			}
		}
		return "false";

	}

}
