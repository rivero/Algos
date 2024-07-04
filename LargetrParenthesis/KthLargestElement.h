#pragma once
namespace KthLargestElement
{
	/*
	215. Kth Largest Element in an Array
	Given an integer array nums and an integer k, return the kth largest element in the array.

	Note that it is the kth largest element in the sorted order, not the kth distinct element.

	Can you solve it without sorting?



	Example 1:
	Input: nums = [3,2,1,5,6,4], k = 2
	Output: 5

	Example 2:
	Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
	Output: 4

	Input = [6, 8, 7, 5, 9, 4, 2, 3] k = 6
	Output = 4

	Constraints:

	1 <= k <= nums.length <= 105
	-104 <= nums[i] <= 104
	
	*/
	class Solution 
	{
	public:
		int findKthLargest(vector<int>& nums, int k) 
		{ // 67 ms Beats 96.24 %
			/*Time Complexity: O(n log n)
			Space Complexity: O(1)*/
			sort(nums.begin(), nums.end());
			return nums[nums.size() - k];
		}

		int findKthLargest1(vector<int>& nums, int k)
		{
			// 84 ms Beats 79.83 %
			/*Time Complexity: O(n log k)
			Space Complexity: O(k)*/
			std::priority_queue<int, std::vector<int>, std::greater<int>>
				myq(nums.begin(), nums.begin()+k);

			for (size_t i = k; i < nums.size(); i++)
			{
				int val = myq.top();
				if (nums[i] > val)
				{
					if ((myq.size() + 1 )> k)
					{
						myq.pop();
					}
					myq.push(nums[i]);
				}
			}

			return myq.top();
		}
	};

	void process()
	{
		Solution sol;
		{
			vector<int> vec{ 3,2,1,5,6,4 };
			int k = 2;
			cout << sol.findKthLargest(vec, k) << "\n"; //5

		}
		{
			vector<int> vec{ 3,2,3,1,2,4,5,5,6 };
			int k = 4;
			cout << sol.findKthLargest(vec, k) << "\n"; //4 

		}
		{
			vector<int> vec{ 6, 8, 7, 5, 9, 4, 2, 3 };
			int k = 6;
			cout << sol.findKthLargest(vec, k) << "\n"; //4 

		}
	}
}