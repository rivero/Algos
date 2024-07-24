#pragma once
/*
* https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii
3202. Find the Maximum Length of Valid Subsequence II
You are given an integer array nums and a positive integer k.
A subsequence  sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
Return the length of the longest valid subsequence of nums.


Example 1:

Input: nums = [1,2,3,4,5], k = 2

Output: 5

Explanation:

The longest valid subsequence is [1, 2, 3, 4, 5].

Example 2:

Input: nums = [1,4,2,3,1,4], k = 3

Output: 4

Explanation:

The longest valid subsequence is [1, 4, 1, 4].



Constraints:

2 <= nums.length <= 10^3
1 <= nums[i] <= 10^7
1 <= k <= 10^3

We use a dp vector to store the length of the longest valid subsequence ending at each index.
The base case is dp[0] = 1 since a single element subsequence is always valid.
We iterate through the array starting from the second element.
For each element, we calculate the remainder after adding it to the previous subsequence length and taking modulo k.
If the remainder is 0, the current subsequence is valid, and its length is updated.
Otherwise, we check for a valid subsequence with a remainder of (k - remainder). 
This is because the sum of two remainders with this relationship will be a multiple of k, making the combined subsequence valid.
If a valid subsequence with the complementary remainder exists, the current length is updated.
We keep track of the maximum valid subsequence length seen so far.
Finally, we return the maximum length.

*/
namespace FindMaxLenValidsubsequenceII
{

	class Solution
	{
		int longestValidSubsequence(vector<int>& nums, int k) {
			// Initialize a dp vector to store the length of the longest valid subsequence ending at each index.
			vector<int> dp(nums.size(), 0);

			// Handle the base case: a single element subsequence is always valid.
			dp[0] = 1;

			int maxLength = 1;

			// Iterate through the array starting from the second element.
			for (int i = 1; i < nums.size(); i++) {
				// Calculate the remainder for the current element.
				int remainder = (nums[i] + dp[i - 1]) % k;

				// If the remainder is 0, the current subsequence is valid and its length is 
				// the sum of the previous subsequence length and 1.
				if (remainder == 0) {
					dp[i] = dp[i - 1] + 1;
				}
				else {
					// Check for subsequences with a remainder of (k - remainder).
					int complementaryRemainder = (k - remainder) % k;

					// If a valid subsequence exists with the complementary remainder, update the current length.
					if (i - complementaryRemainder >= 0 && dp[i - complementaryRemainder] > 0) {
						dp[i] = dp[i - complementaryRemainder] + 1;
					}
				}

				// Update the maximum valid subsequence length seen so far.
				maxLength = max(maxLength, dp[i]);
			}

			return maxLength;
		}
	};

	void process() {}
}
