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

The algorithm moves non-zero elements to the beginning of the vector.
the j index chases but never reaches i.
as we advance, the non zero elements on i are slowly moved to the j position.
the j position advances only if there is a swap. Because the j index stays until there is a number on i,
each time the i is swapped with j only the numbers != 0 are swapped and j then moves forward



0       1       0       3       12
0       1       0       3       12
swap
1       0       0       3       12
1       0       0       3       12
swap
1       3       0       0       12
swap
1       3       12      0       0
1       3       12      0       0

--

MoveZeroes
2       1
swap
2       1
swap
2       1
2       1



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
					swap(nums[j++], nums[i]);
					cout << "\n";
				}
				printv(nums);
			}
		}
	};

	void process()
	{
		cout << "MoveZeroes\n";
		Solution sol;
		{
			vector<int> vec{ 2, 1 };
			printv(vec);
			sol.moveZeroes(vec);
			printv(vec);
			cout << "\n";
		}
		if (false)
		{
			{
				vector<int> vec{ 0,1,0,3,12 };
				printv(vec);
				sol.moveZeroes(vec);
				printv(vec);
				cout << "\n";
			}
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
}
