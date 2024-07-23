#pragma once
/*
* https://leetcode.com/problems/top-k-frequent-elements/description/

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

The priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, 
at the expense of logarithmic insertion and extraction.

A user-provided Compare can be supplied to change the ordering, e.g. using std::greater<T> would cause the smallest 
element to appear as the top().

in this example: priority_queue< pair < int, int>, vector< pair<int, int>, greater< pair< int, int > >

	*/
namespace TopKElements
{
	class Solution 
	{
	public:
		vector<int> topKFrequent(vector<int>& nums, int k)
		{
			// count occurrences
			map<int, int> m;
			for (int i = 0; i < nums.size(); i++)
			{
				m[nums[i]]++;
			}
			// use priority queue to store: the largest will come at the top
			// queue sorts using its elements' sorting capabilities
			priority_queue< pair <int, int> > q;
			for (auto& [elem, counter] : m)
			{
				q.push({ counter, elem });
			}
			// collect first k elements and return result
			vector<int> res;
			while (k-- > 0)
			{
				auto [counter, elem] = q.top(); q.pop();
				res.push_back(elem);
			}
			return res;
		}
	};

}
