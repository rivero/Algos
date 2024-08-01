#pragma once
/*
https://leetcode.com/problems/move-zeroes
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1

1. **Algorithm Explanation**:
   - The purpose of the `moveZeroes` function is to move all zeros to the end of the given integer vector `nums` while maintaining
   the relative order of the non-zero elements.
   - The algorithm follows these steps:
	 1. Initialize a pointer `j` to keep track of the position where the next non-zero element should be placed.
	 2. Iterate through the vector `nums` using a pointer `i`.
		- If `nums[i]` is not zero, swap `nums[j]` with `nums[i]` (placing the non-zero element at position `j`).
		- Increment `j`.
	 3. After the loop, all non-zero elements will be in their correct positions, and zeros will be at the end of the vector.

2. **Complexities**:
   - Time Complexity: O(N), where N is the size of the input vector `nums`.
	 - The algorithm processes each element in `nums` once.
   - Space Complexity: O(1), as no additional data structures are used; the swaps are performed in place.

3. **Example**:
   - Input: `nums = [0, 1, 0, 3, 12]`
	 - After processing: `nums = [1, 3, 12, 0, 0]`

*/
namespace MoveZeroes
{

	class Solution 
	{
	public:
		void moveZeroes(vector<int>& nums) 
		{
			int j = 0;
			for (int i = 0; i < nums.size(); i++) 
			{
				if (nums[i] != 0) 
				{
					swap(nums[j], nums[i]);
					j++;
				}
			}
		}
	};

	void process()
	{
		cout << "MoveZeroes\n";
		Solution sol;
		{
			vector<int> vec{ 2, 0, 3, 0, 4, 5, 0 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 1, 0, 1, 0, 1, 0 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 1, 2, 0, 0, 3,4 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}
		{
			vector<int> vec{ 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,4 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}

	}
}
