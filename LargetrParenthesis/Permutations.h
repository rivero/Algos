#pragma once
/*
* https://leetcode.com/problems/permutations/description/

46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

Certainly! Let's break down the algorithm and discuss its complexities:

1. **Algorithm Explanation**:
	- The given algorithm generates all possible permutations of the input vector `nums`.
	- It uses a recursive approach with backtracking.
	- The `permute` function initializes an empty result vector (`res`) and calls the `permutations` helper function.
	- The `permutations` function generates permutations by swapping elements and recursively exploring different combinations.
	- When the current permutation is complete (i.e., `l` reaches the last index), it adds the permutation to the result vector.
	- The algorithm backtracks by swapping elements again to explore other possibilities.

2. **Time Complexity**:
	- The time complexity of this algorithm is O(N * N!), where N is the size of the input vector.
	- The recursive function generates N! permutations, and for each permutation, we swap elements N times (in the worst case).
	- The total number of recursive calls is N! (factorial of N).

3. **Space Complexity**:
	- The space complexity is O(N) due to the recursive call stack.
	- Additionally, the result vector (`res`) stores all permutations, which contributes to the space usage.
*/
namespace Permutations
{
	class Solution : protected timeit 
	{
		vector<vector<int>> res;
		void permutations(vector<int> nums, int l)
		{
			// Base case: when the current permutation is complete
			if (l == nums.size() - 1)
			{
				res.push_back(nums);
				return;
			}

			// Generate permutations by swapping elements
			for (int i = l; i < nums.size(); i++)
			{
				swap(nums[l], nums[i]);
				permutations(nums, l + 1);
				swap(nums[l], nums[i]); // Backtrack
			}
		}
	public:
		vector<vector<int>> permute(vector<int>& nums)
		{
			permutations(nums, 0);
			return res;
		}
	};
	class Solution2 : protected timeit
	{
		vector<vector<int>> res;
		vector<int> permutation;
		void backtrack(vector<int>& nums, vector<bool>& used)
		{
			if (permutation.size() == nums.size())
			{
				res.push_back(permutation);
				return;
			}
			for (int i = 0; i< nums.size(); i++)
			{
				if (!used[i])
				{
					// make a choice
					used[i] = true;
					permutation.push_back(nums[i]);
					backtrack(nums, used);
					// undo choice
					used[i] = false;
					permutation.pop_back();
				}
			}
		}
	public:
		vector<vector<int>> permute(vector<int>& nums)
		{
			vector<bool> used(nums.size(), false);
			backtrack(nums, used);
			return res;
		}

	};
	void process() 
	{
		cout << "Permutations\n";
		vector<int> vec{ 1,2,3 };

		{
			Solution sol;
			auto res = sol.permute(vec);
			for (auto el : res)
			{
				printv(el);
			}

		}
		{
			cout << "\nSolution 2\n";
			Solution2 sol2;
			auto res = sol2.permute(vec);
			for (auto el : res)
			{
				printv(el);
			}
		}

	}
}
