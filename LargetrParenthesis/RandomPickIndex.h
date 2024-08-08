#pragma once
/*
* https://leetcode.com/problems/random-pick-index/description/
* 
398. Random Pick Index
Medium
Topics
Companies
Given an integer array nums with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, 
then each index should have an equal probability of returning.


Example 1:

Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]

Explanation
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.


Constraints:

1 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
target is an integer from nums.
At most 10^4 calls will be made to pick.

Naive solution and explanation

Using: [[[1, 2, 3, 3, 3]], [3], [1], [3]]

Dictionary:
{
    1 -> [0]
    2 -> [1]
    3 -> [2,3,4]
}
Solution is O(n)

Using reservoir sampling:

Certainly! Let's break down the algorithm implemented in the given `Solution` class:

1. **Constructor** (`Solution(vector<int> nums)`):
   - The constructor initializes the `m_nums` vector with the input `nums`.
   - This vector will be used for subsequent operations.

2. **Method** (`int pick(int target)`):
   - The `pick` method takes an integer `target` as input and aims to randomly select an index where `m_nums[i]` equals the target value.
   - It maintains two variables:
	 - `count`: The number of occurrences of the target value encountered so far.
	 - `result`: The index to return (initialized to -1).
   - The method iterates through the `m_nums` vector:
	 - If `m_nums[i]` equals the target value:
	   - It increments `count`.
	   - It generates a random number between 0 and `count-1`.
	   - If the random number is 0, it updates `result` to the current index `i`.
   - The final `result` contains the randomly selected index corresponding to the target value.

3. **Random Selection**:
   - The algorithm ensures that each occurrence of the target value has an equal probability of being selected.
   - By using `rand() % (++count) == 0`, it achieves this uniform random sampling.

4. **Efficiency**:
   - Time Complexity: *O(n)*, where *n* is the size of the `m_nums` vector (due to the linear scan).
   - Space Complexity: *O(n)* (due to the storage of the `m_nums` vector).

In summary, this algorithm provides a simple way to randomly select an index where the target value occurs in the given array. 

*/
namespace RandomPickIndex
{
	class Solution
	{
		const vector<int>& nums;
	public:
		Solution(vector<int> nums) : nums{ nums }
		{
		}

		int pick(int target)
		{
			int ind = rand() % nums.size();
			if (nums[ind] == target) return ind;
			else return pick(target);
		}
	};


	/*

	BAD solution
		class Solution
	{
		vector<int> m_nums;
	public:
		Solution(vector<int> nums)
		{
			m_nums = nums;
		}

		int pick(int target)
		{
			int count = 0; // Number of occurrences of target
			int result = -1; // Index to return
			for (int i = 0; i < m_nums.size(); ++i)
			{
				if (m_nums[i] == target)
				{
					// Randomly select an index with equal probability
					if (rand() % (++count) == 0)
					{
						result = i;
					}
				}
			}
			return result;
		}
	};


	*/
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * int param_1 = obj->pick(target);
     */

	void process()
	{
        Solution sol({ 1, 2, 3, 3, 3});

		cout << sol.pick(3) << "\n";
		cout << sol.pick(1) << "\n";
		cout << sol.pick(3) << "\n";

	}
}