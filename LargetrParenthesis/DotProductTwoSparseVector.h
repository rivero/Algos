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

Certainly! Let's analyze the provided `SparseVector` class and discuss its complexities.

1. **Algorithm Description**:
   - The given `SparseVector` class represents a sparse vector using an unordered map.
   - It initializes a hash map (`m_map`) to store non-zero elements of the input vector.
   - The class provides methods to construct a sparse vector, retrieve its internal map, and compute the dot product with 
   another sparse vector.

2. **Explanation**:
   - The class has the following components:
	 - `m_map`: An unordered map where the keys represent indices (positions) and the values represent non-zero elements.
	 - `SparseVector(const vector<int>& nums)`: The constructor initializes the sparse vector by iterating through the input 
	 vector `nums`. If an element at index `i` is non-zero, it adds it to `m_map`.
	 - `getMap()`: A method that returns a reference to the internal map.
	 - `dotProduct(SparseVector& vec)`: Computes the dot product between the current sparse vector and another sparse vector `vec`.
	   - It iterates through the elements in the internal map (`m_map`).
	   - For each non-zero element at index `index`, it checks if `vec` also has a non-zero element at the same index.
	   - If so, it adds the product of the values to the `sum`.

3. **Complexities**:
   - **Time Complexity**:
	 - Constructing the sparse vector in the constructor takes linear time (`O(n)`), where `n` is the size of the input vector.
	 - The `dotProduct` method iterates through the internal map, which has at most `n` elements (where `n` is the size of the 
	 input vector).
	 - The worst-case time complexity for computing the dot product is `O(n)` (when both vectors have non-zero elements at the 
	 same indices).
   - **Space Complexity**:
	 - The space complexity is determined by the size of the internal map (`m_map`).
	 - In the worst case, when all elements in the input vector are non-zero, the space complexity is `O(n)`.

4. **Sparse Vector Representation**:
   - The use of an unordered map allows efficient storage of non-zero elements without wasting space for zero elements.
   - This representation is particularly useful for sparse vectors, where most elements are zero.


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
