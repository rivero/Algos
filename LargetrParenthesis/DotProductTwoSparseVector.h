#pragma once
/*
* https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/
1570. Dot Product of Two Sparse Vectors

Given two sparse vectors, compute their dot product.

Implement class SparseVector:

- SparseVector(nums) Initializes the object with the vector nums
- dotProduct(vec) Compute the dot product between the instance of SparseVector and vec

A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute 
the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?



Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
Example 2:

Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
Example 3:

Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6


Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100


Because the vector is sparse, use a data structure that stores the index and value where the element is nonzero.
*/

namespace DotProductTwoSparseVector
{
	class SparseVector
	{
		unordered_map<int, int> m_map; // most efficient hash map O(1)
	public:
		SparseVector(const vector<int>& nums)
		{
			for (size_t i = 0; i < nums.size(); i++)
			{
				if (nums[i] != 0)
				{
					m_map[i] = nums[i];
				}
			}
		}
		const unordered_map<int, int>& getMap() const
		{
			return m_map;
		}
		// Return the dotProduct of two sparse vectors
		int dotProduct(SparseVector& vec)
		{
			int sum{};
			for (auto& [index, value] : m_map)
			{
				if (vec.getMap().count(index) > 0)
				{
					sum += value * vec.getMap().at(index);
				}
			}

			return sum;
		}

	};

	void process()
	{
		// Your SparseVector object will be instantiated and called as such:
		cout << "DotProductTwoSparseVector\n";
		{
			vector<int> nums1{ 1,0,0,2,3 };
			vector<int> nums2{ 0,3,0,4,0 };
			SparseVector v1(nums1);
			SparseVector v2(nums2);
			int ans = v1.dotProduct(v2);
			cout << ans << "\n";

		}
		{
			vector<int> nums1{ 0,1,0,0,0 };
			vector<int> nums2{ 0,0,0,0,2 };
			SparseVector v1(nums1);
			SparseVector v2(nums2);
			int ans = v1.dotProduct(v2);
			cout << ans << "\n";

		}
		{
			vector<int> nums1{ 0,1,0,0,2,0,0 };
			vector<int> nums2{ 1,0,0,0,3,0,4 };
			SparseVector v1(nums1);
			SparseVector v2(nums2);
			int ans = v1.dotProduct(v2);
			cout << ans << "\n";

		}
	}

}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
