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
Solution 2
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

Solution 

## Algorithm Explanation

**Problem:** Generate all permutations of a given array of integers.

**Approach:** Backtracking

1. **Initialization:**
   * `res` stores all generated permutations.
   * `permutation` stores the current permutation being built.
   * `used` is a boolean array to track if a number has been used in the current permutation.

2. **Backtracking:**
   * The `backtrack` function recursively explores all possible permutations.
   * If the current permutation's length equals the original array's length, it's a complete permutation, so add it to `res`.
   * Iterate through the numbers in the array:
	 * If the number hasn't been used:
	   * Mark the number as used.
	   * Add the number to the current permutation.
	   * Recursively call `backtrack` to explore further permutations.
	   * Remove the number from the current permutation (backtrack).
	   * Mark the number as unused.

**Time Complexity:** O(n * n!)
* There are n! permutations for an array of length n.
* For each permutation, we build it and copy it into `res`, which takes O(n) time.

**Space Complexity:** O(n)
* The `permutation` vector and `used` array take O(n) space.
* The recursion stack depth can also be up to n.

**Key Idea:** Backtracking explores all possible choices by trying to include each number in the current permutation and then 
undoing the choice if it doesn't lead to a valid solution. The `used` array prevents duplicate elements from being used multiple 
times in the same permutation.


	------------------------
	## Permutation vs. Combination

**Permutation** refers to the number of ways you can arrange a set of items in a specific order. **Order matters** in permutations.

**Combination** refers to the number of ways you can select a group of items from a set, where the order of the items doesn't matter. **Order doesn't matter** in combinations.

### Example:

Let's say you have three letters: A, B, C.

* **Permutations** of these letters would include: ABC, ACB, BAC, BCA, CAB, CBA. There are 6 permutations.
* **Combinations** of these letters, taking two at a time, would include: AB, AC, BC. There are 3 combinations. 
Notice that AB is the same as BA for combinations, but they are different for permutations.

### Summary Table:

| Feature | Permutation | Combination |
|---|---|---|
| Order | Matters | Doesn't matter |
| Focus | Arrangement | Selection |
| Notation | nPr | nCr |

**In essence:**
* **Permutations** are about arranging items in a specific order.
* **Combinations** are about selecting items without considering the order.

Would you like to see some examples of when to use permutations and combinations?


*/
namespace Permutations
{
	class Solution2 : protected timeit 
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
	class Solution : protected timeit
	{
		vector<vector<int>> permutations;
		vector<int> permutation;
		void backtrack(vector<int>& nums, vector<bool>& used)
		{
			if (permutation.size() == nums.size())
			{
				permutations.push_back(permutation);
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
			return permutations;
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
