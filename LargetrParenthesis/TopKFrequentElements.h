#pragma once
/*
* https://leetcode.com/problems/top-k-frequent-elements/description/
347 Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Solution


### Algorithm Explanation:

1. **Frequency Counting:**
   - We create a `map<int, int>` called `m` to store the frequency of each element in the input array `nums`.
   - The loop iterates through `nums`, incrementing the count for each element in `m`.
   - This step takes **O(n)** time, where **n** is the size of the input array.

2. **Priority Queue (Max Heap):**
   - We use a max heap (priority queue) `q` to keep track of the **k** most frequent elements.
   - For each key-value pair in `m`, we push it onto the heap with the frequency as the key.
   - This step takes **O(n log k)** time because inserting an element into a max heap takes logarithmic time, 
   and we do this for all **n** elements.

3. **Extracting Top k Elements:**
   - We pop the top element from the heap **k** times and add its corresponding element to the result vector `res`.
   - Each pop operation takes **O(log k)** time, so this step also takes **O(k log k)** time.

4. **Overall Complexity:**
   - The total time complexity is **O(n log k)**.

### Space Complexity:

- The additional space used includes:
  - The `map<int, int>` (`m`) for frequency counting, which takes **O(n)** space.
  - The max heap (`q`) for the top **k** elements, which takes **O(k)** space.
  - The result vector (`res`), which takes **O(k)** space.
- Hence, the space complexity is **O(n + k)**.

*/
namespace TopKFrequentElements
{

	class Solution {
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
				q.push({ counter , elem});
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
	void process()
	{
		Solution sol;
		vector<int> nums
		{
			1,1,1,2,2,3
		};
		int k = 2;
		auto res = sol.topKFrequent(nums, k);
		printv(res);
	}
}