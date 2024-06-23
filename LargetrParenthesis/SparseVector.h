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

namespace sparsevec
{
	class SparseVector
	{
		set<int> m_indexNotZero;
		vector<int> m_nums;
	public:
		const vector<int>& getNums() const
		{
			return m_nums;
		}
		const set<int>& GetSet() const
		{
			return m_indexNotZero;
		}

		set<int> GetIntersection(set<int> otherSet)
		{
			set<int> result;
			set_intersection(
				m_indexNotZero.begin(), m_indexNotZero.end(),
				otherSet.begin(), otherSet.end(),
				inserter(result, result.begin()));
			return result;
		}

		SparseVector(vector<int>& nums)
		{
			m_nums = nums;
			for (size_t i = 0; i < nums.size(); i++)
			{
				if (nums[i] != 0)
				{
					m_indexNotZero.insert(i);
				}
			}
		}

		// Return the dotProduct of two sparse vectors
		int dotProduct(SparseVector& vec)
		{
			auto interSectionSet = GetIntersection(vec.GetSet());
			int sum{};
			for (auto intersectionIndex : interSectionSet)
			{
				sum += m_nums[intersectionIndex] * vec.getNums()[intersectionIndex];
			}
			return sum;
		}

	};

	void process()
	{
		// Your SparseVector object will be instantiated and called as such:
		vector<int> nums1{ 1,0,0,2,3 };
		vector<int> nums2{ 0,3,0,4,0 };
		 SparseVector v1(nums1);
		 SparseVector v2(nums2);
		 int ans = v1.dotProduct(v2);
		 cout << ans << "\n";
	}

}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
