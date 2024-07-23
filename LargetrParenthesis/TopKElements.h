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



	*/
namespace TopKElements
{
	class Solution 
	{
	public:
		vector<int> topKFrequent(vector<int>& nums, int k)
		{
			map<int, int> m;

			for (int i = 0; i < nums.size(); i++)
			{
				m[nums[i]]++;
			}
			priority_queue< pair <int, int> > q;
			for (auto [elem, counter] : m)
			{
				q.push({ counter , elem });
			}
			vector<int> res;
			while (k-- > 0)
			{
				auto x = q.top();
				res.push_back(x.second); q.pop();
			}
			return res;
		}
	};

}
