#pragma once
/*
* https://leetcode.com/problems/nested-list-weight-sum/description/
339 Nested List Weight Sum

You are given a nested list of integers nestedList.
Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of.
For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.

Return the sum of each integer in nestedList multiplied by its depth.



Example 1:
Input: nestedList = [[1,1],2,[1,1]]
depth			       2   1   2
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.

Example 2:
Input: nestedList = [1,[4,[6]]]
depth                1  2  3
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3. 1*1 + 4*2 + 6*3 = 27.

Example 3:
Input: nestedList = [0]
Output: 0


Constraints:

1 <= nestedList.length <= 50
The values of the integers in the nested list is in the range [-100, 100].
The maximum depth of any integer is less than or equal to 50.

"We want to sum all the integers of in the list and multiply them by its depth.
The depth is the number of lists that the current object recursively has inside.
If an element is an integer, it value is multiplied by depth.
If the element is a nested list, the algo recursively processes that list increasing the depth by one."


"Time Complexity: O(n)
Space Complexity: O(d) where d is the max depth and it can be quite big or small depending on the lists sizes"



*/
namespace NestedListWeightSum
{
	class NestedInteger
	{
		int m_val{ INT_MAX };
		vector < NestedInteger > m_vec;
	public:
		// Constructor initializes an empty nested list.
		NestedInteger() = default;

		// Constructor initializes a single integer.
		NestedInteger(int value) : m_val(value) {};

		// Return true if this NestedInteger holds a single integer, rather than a nested list.
		bool isInteger() const { return m_val == INT_MAX; };

		// Return the single integer that this NestedInteger holds, if it holds a single integer
		// The result is undefined if this NestedInteger holds a nested list
		int getInteger() const { return m_val; }

		// Set this NestedInteger to hold a single integer.
		void setInteger(int value) { m_val = value; };

		// Set this NestedInteger to hold a nested list and adds a nested integer to it.
		void add(const NestedInteger& ni) { m_vec.push_back(ni); };

		// Return the nested list that this NestedInteger holds, if it holds a nested list
		// The result is undefined if this NestedInteger holds a single integer
		const vector<NestedInteger>& getList() const
		{
			return m_vec;
		}

	};

	struct Solution : protected timeit
	{

		int depthSum(vector<NestedInteger> nestedList, int depth = 1)
		{
			int sum{};
			for (auto& elem : nestedList)
			{
				if (elem.isInteger())
				{
					sum += elem.getInteger() * depth;
				}
				else
				{
					sum += depthSum(elem.getList(), depth + 1);
				}
			}
			return sum;
		}
	};

	void process()
	{
		NestedInteger n1(1);

		Solution n;

	}
}
