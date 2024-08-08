#pragma once
/*
* https://leetcode.com/problems/find-k-closest-elements
* 658. Find K Closest Elements

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 10^4
arr is sorted in ascending order.
-10^4 <= arr[i], x <= 10^4

In this implementation:
- We use a max heap to store pairs of the absolute difference between each element and *x*, along with the actual element value.
- We maintain the heap size to be *k* by popping the largest element whenever the size exceeds *k*.
- Finally, we extract the elements from the heap and sort them to get the result in ascending order.

1. **Time Complexity**:
In this implementation:
- We use a max heap to store pairs of the absolute difference between each element and *x*, along with the actual element value.
- We maintain the heap size to be *k* by popping the largest element whenever the size exceeds *k*.
- Finally, we extract the elements from the heap and sort them to get the result in ascending order.

2. **Space Complexity**:
   - We use a max heap (priority queue) to store at most *k* elements; we also utilize a vector for the k elements.
   Therefore, the space complexity is *O(k)*.

In summary:
- Time complexity: *O(n log k)*
- Space complexity: *O(k)*

*/
namespace FindKClosestElements
{
	class Solution
	{
	public:
		vector<int> findClosestElements(vector<int>& arr, int k, int x)
		{
			priority_queue < pair<int, int> > pq;
			for (int i = 0; i < arr.size(); i++)
			{
				pq.push({ abs(arr[i] - x), arr[i] });
				if (pq.size() > k)
					pq.pop();
			}
			vector<int> ans;
			while (!pq.empty())
			{
				auto [diff, elem] = pq.top(); pq.pop();
				ans.push_back(elem);
			}
			sort(ans.begin(), ans.end());
			return ans;
		}
	};
	
	void process() {}
}
