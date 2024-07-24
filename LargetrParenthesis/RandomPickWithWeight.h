#pragma once
/*
* // https://leetcode.com/problems/random-pick-with-weight/description/
	* 528. Random Pick with Weight
Medium

You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1]
(inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index
0 is
1 / (1 + 3) = 0.25
(i.e., 25%)

, and the
probability of picking index
1 is
3 / (1 + 3) = 0.75 (i.e., 75%).


Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
Example 2:

Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

Since this is a randomization problem, multiple answers are allowed.
All of the following outputs can be considered correct:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.


Constraints:

1 <= w.length <= 104
1 <= w[i] <= 105
pickIndex will be called at most 104 times.


For [1,3,4,6] the probablity of choosing index 0 is 1/14, 1 is 3/14, 2 is 4/14 and 3 is 6/14.
Using Prefix sum I have converted the weight vector into a

vector v:- [1,1+3, 1+3+4, 1+3+4+6].
= [1, 4, 8 , 14]


The key idea here is that the cumulative sum array v allows us to map the random number to an index 
based on the weight distribution. 
The larger the cumulative sum, the higher the probability of selecting that index.

1. **Algorithm Description**:
   - The given class `Solution` implements a weighted random index picker.
   - It initializes an internal vector `m_AccumWeights` to store the cumulative weights of the input vector `w`.
   - The cumulative weight at each index `i` represents the sum of weights from index 0 to `i`.
   - The `pickIndex` function generates a random number `n` between 0 (inclusive) and the total cumulative weight (exclusive).
   - It then finds the first index in `m_AccumWeights` where the cumulative weight is greater than or equal to `n`.

2. **Explanation**:
   - The algorithm starts by constructing the cumulative weights vector `m_AccumWeights`.
   - The cumulative weight at index `i` is calculated as `m_AccumWeights[i] = m_AccumWeights[i-1] + w[i]`.
   - The cumulative weights represent the "ranges" of weights for each index. Larger weights contribute more to the cumulative sum.
   - When picking an index, the algorithm generates a random number `n` within the range `[0, total_cumulative_weight)`.
   - By using `upper_bound`, it finds the first index in `m_AccumWeights` where the cumulative weight exceeds or equals `n`.
   - The selected index corresponds to the weight range that contains the random value `n`.

3. **Probability Explanation**:
   - The probability of selecting a specific index `i` is proportional to its cumulative weight.
   - Larger cumulative weights mean that the corresponding index has a greater share of the total weight.
   - Therefore, indices with larger cumulative weights have a higher probability of being selected.
   - This property ensures that the selection process is weighted according to the input weights.

4. **Example**:
   - Suppose we have weights `[2, 3, 1]`.
   - The cumulative weights are `[2, 5, 6]`.
   - The total cumulative weight is 6.
   - If we generate a random number `n` between 0 and 5:
	 - If `n` is in the range `[0, 2)`, we select index 0 (weight 2).
	 - If `n` is in the range `[2, 5)`, we select index 1 (weight 3).
	 - If `n` is in the range `[5, 6)`, we select index 2 (weight 1).

5. **Complexities**:
   - **Time Complexity**:
	 - Constructing `m_AccumWeights` takes linear time (`O(n)`), where `n` is the size of the input vector.
	 - The `pickIndex` function performs a binary search using `upper_bound`, which takes logarithmic time (`O(log n)`).
	 - Overall, the time complexity is `O(n + log n)`, which simplifies to `O(n)`.
   - **Space Complexity**:
	 - The algorithm uses additional space for `m_AccumWeights`, which is linear (`O(n)`).


	*/
#define PRINTV
namespace RandomPickwithWeight
{


	class Solution 
	{
	public:
		vector<int> m_AccumWeights;
		/*
		Initialization:
		The constructor Solution(vector<int> w) initializes a vector v to store cumulative sums of the weights.
		It starts by pushing the first weight w[0] into v.
		Cumulative Sums:
		The loop iterates from index 1 to w.size() - 1.
		For each index i, it calculates v[i] = v[i - 1] + w[i], which represents the cumulative sum of weights up to index i.
		This cumulative sum array v allows us to map the random number to an index with the desired probability distribution
		*/
		Solution(vector<int> WeightsVector) 
		{
#ifdef PRINTV
			cout << "vector WeightsVector containing the weights. w[i] describes the weight of the ith index.\n";
			printv(WeightsVector, true, true);
			cout << "\n";
#endif
			m_AccumWeights.push_back(WeightsVector[0]);

			for (size_t i = 1; i < WeightsVector.size(); i++) 
			{
				m_AccumWeights.push_back(m_AccumWeights[i - 1] + WeightsVector[i]);
			}
#ifdef PRINTV
			cout << "vector v to store cumulative sums of the weights\n";
			printv(m_AccumWeights);
			cout << "\n";
#endif
		}
		/*Random Index Selection:
		In the pickIndex() function:
		Generate a random integer n in the range [0, v[v.size() - 1]).
		Find the first element in v that is greater than n using upper_bound.
		The index of this element corresponds to the chosen index.
		Return the distance from the beginning of v to this chosen index.

		The key idea here is that the cumulative sum array v allows us to map 
		the random number to an index based on the weight distribution. 
		The larger the cumulative sum, the higher the probability of selecting that index.
		*/
		int pickIndex() 
		{
			// Generate a random integer n in the range [0, v[v.size() - 1]) from the weights vector.
			int n = rand() % m_AccumWeights[m_AccumWeights.size() - 1]; 
			// finds the first element greater than since the choice is inclusive
			auto it = upper_bound(m_AccumWeights.begin(), m_AccumWeights.end(), n); 
#ifdef PRINTV
			cout << "from weights vector random integer n [" << n << "] *it (upper bound) [" << *it;
			cout << "] distance from the beginning to the upper bound [" << distance(m_AccumWeights.begin(), it) << "]\n";
#endif
			return distance(m_AccumWeights.begin(), it); // calculate the distance from the beginning to the chosen upper bound
		}
	};


	void process()
	{
		cout << "\nRandomPickwithWeight\n";

		{
			// Your Solution object will be instantiated and called as such:
			// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
			Solution* obj = new Solution({ 1, 3 });

			for (int i = 0; i < 2; i++)
			{
				cout << obj->pickIndex() << "\n";
			}
			cout << "\n";

		}
		{
			// Your Solution object will be instantiated and called as such:
			// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
			Solution* obj = new Solution({ 1, 3, 2, 4, 5, 6 });

			for (int i = 0; i < 5; i++)
			{
				cout << obj->pickIndex() << "\n";
			}
			cout << "\n";

		}
	}
}